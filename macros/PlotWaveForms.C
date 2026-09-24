TFile*     treeFile = nullptr;
TTree*     tree = nullptr;
TFragment* frag = new TFragment;

Long64_t eventNumber = 0;
TCanvas* waveCanvas = nullptr;


// Find and draw the next waveform
void NextWaveForm()
{
    if(tree == nullptr) {
        std::cerr << "No run is loaded. Use PlotWaveFormes(run) first."
                  << std::endl;
        return;
    }

    Long64_t nentries = tree->GetEntries();

    // Find the next event containing a waveform
    while(eventNumber < nentries) {

        tree->GetEntry(eventNumber++);

        if(frag->HasWave())
            break;
    }

    // Check if we reached the end
    if(eventNumber >= nentries && !frag->HasWave()) {
        std::cout << "Reached the end of the run." << std::endl;
        return;
    }

    std::cout << "Event number "
              << eventNumber - 1
              << std::endl;

    frag->Print();

    // Get waveform
    const std::vector<int16_t>* waveform =
        frag->GetWaveform();

    if(waveform == nullptr) {
        std::cerr << "Waveform is nullptr." << std::endl;
        return;
    }

    // Remove previous histogram
    TH1* old = dynamic_cast<TH1*>(gROOT->FindObject("waveform"));

    if(old != nullptr)
        delete old;

    // Make histogram
    TH1D* h = new TH1D(
        "waveform",
        "Waveform",
        waveform->size(),
        0,
        waveform->size()
    );

    for(size_t i = 0; i < waveform->size(); ++i)
        h->SetBinContent(i + 1, waveform->at(i));

    h->GetXaxis()->SetTitle("Sample");
    h->GetYaxis()->SetTitle("ADC");

    // Give the histogram the channel name, if available
    TChannel* chan = frag->GetChannel();

    if(chan != nullptr)
        h->SetTitle(chan->GetName());

    // Draw
    if(waveCanvas != nullptr)
        waveCanvas->cd();

    h->Draw();

    if(waveCanvas != nullptr) {
        waveCanvas->Modified();
        waveCanvas->Update();
    }
}


// Open a run and display the first waveform
void PlotWaveForms(int run)
{
    // Close any previously opened file
    if(treeFile != nullptr) {
        treeFile->Close();
        delete treeFile;
        treeFile = nullptr;
    }

    tree = nullptr;
    eventNumber = 0;

    // Change this if your files have a different naming convention
    TString filename = Form("/home/emile/postdoc/data/s2232/sorted/fragment/fragment%d_000.root", run);

    treeFile = TFile::Open(filename, "READ");

    if(treeFile == nullptr || treeFile->IsZombie()) {
        std::cerr << "Could not open "
                  << filename << std::endl;
        return;
    }

    std::cout << "Opened " << filename << std::endl;

    tree = dynamic_cast<TTree*>(
        treeFile->Get("FragmentTree")
    );

    if(tree == nullptr) {
        std::cerr << "Could not find FragmentTree."
                  << std::endl;
        return;
    }

    std::cout << "Found "
              << tree->GetEntries()
              << " entries." << std::endl;

    // Connect TFragment branch
    tree->SetBranchAddress("TFragment", &frag);

    // Create canvas
    if(waveCanvas == nullptr) {
        waveCanvas = new TCanvas(
            "waveCanvas",
            "Waveform",
            1000,
            600
        );
    }

    // Show first waveform
    NextWaveForm();
}
