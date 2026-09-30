void FitMylarThickness()
{
    std::ifstream file;
    file.open("./mylar.dat");

    double a, b;

    TGraph* g1 = new TGraph();

    TF1* f1 = new TF1("f1","[0]/TMath::Cos(x*TMath::DegToRad())",-180,180);

    while(file >> a >> b)
    {
        g1->AddPoint(a,b);
    }


    g1->Fit("f1","R");
    f1->Draw();
    g1->Draw("Psame");
}
