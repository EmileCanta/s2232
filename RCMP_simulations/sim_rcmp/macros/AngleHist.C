#include "TMath.h"

using namespace TMath;

void AngleHist()
{	
    TFile *filein = TFile::Open("../build/g4out.root", "READ");
    
    TFile *fileout = new TFile("./anglehist.root","RECREATE");
    
    TTree* tree = (TTree*)filein->Get("ntuple");
    
    int detnbr;
    double posx;
    double posy;
    double posz;
    
    tree->SetBranchAddress("detNumber", &detnbr);
    tree->SetBranchAddress("posx",&posx);
    tree->SetBranchAddress("posy",&posy);
    tree->SetBranchAddress("posz",&posz);

    TH2D *histPhi = new TH2D("histPhi", "histPhi", 6500, 0, 6500, 1000,-TwoPi(),TwoPi());
    TH2D *histTheta = new TH2D("histTheta", "histTheta", 6500, 0, 6500,1000,-TwoPi(),TwoPi());
    TH2D *histsThetaPhi[6]; 
    TH2D *histThetaPhi = new TH2D("histThetaPhi", "histThetaPhi", 1000, -TwoPi(), TwoPi(),1000,-TwoPi(),TwoPi());
    TH2D *histHits[6];

    int fEntries = tree->GetEntries();
    
    for(int i =0; i<6; i++) 
    {
        TString namehist = Form("histAngle%d",i);
        TString namehisthits = Form("histHits%d",i);
        
        histsThetaPhi[i] = new TH2D(namehist, "histThetaPhi", 1000, -TwoPi(), TwoPi(),1000,-TwoPi(),TwoPi());
        histHits[i] = new TH2D(namehisthits, "histHits", 32, 1, 33, 32, 1, 33);
    }
    
    for(int j = 0; j < fEntries; j++)
    {
        tree->GetEntry(j);

        histPhi->Fill(detnbr, ATan2(posx,posz));
        histTheta->Fill(detnbr, ACos(posy/(Sqrt(pow(posx,2)+pow(posy,2)+pow(posz,2)))));
        histThetaPhi->Fill(ATan2(posx,posz), ACos(posy/(Sqrt(pow(posx,2)+pow(posy,2)+pow(posz,2)))));
        
        if(1<=detnbr && detnbr<=1024)
        {
            histsThetaPhi[0]->Fill(ATan2(posx,posz), ACos(posy/(Sqrt(pow(posx,2)+pow(posy,2)+pow(posz,2)))));
            
            int modDet = detnbr - 0*1024;

            histHits[0]->Fill(((modDet - 1) % 32 + 1), ((modDet - 1) / 32) + 1);
        }

        else if(1025 <= detnbr && detnbr <= 2048)
        {
            histsThetaPhi[1]->Fill(ATan2(posx,posz), ACos(posy/(Sqrt(pow(posx,2)+pow(posy,2)+pow(posz,2)))));
           
            int modDet = detnbr - 1*1024;

            histHits[1]->Fill(((modDet - 1) % 32 + 1), ((modDet - 1) / 32) + 1);
        }

        else if(2049<= detnbr && detnbr <=3072)
        {
            histsThetaPhi[2]->Fill(ATan2(posx,posz), ACos(posy/(Sqrt(pow(posx,2)+pow(posy,2)+pow(posz,2)))));
            
            int modDet = detnbr - 2*1024;

            histHits[2]->Fill(((modDet - 1) % 32 + 1), ((modDet - 1) / 32) + 1);
        }
        
        else if(3073<= detnbr && detnbr <=4096)
        {
            histsThetaPhi[3]->Fill(ATan2(posx,posz), ACos(posy/(Sqrt(pow(posx,2)+pow(posy,2)+pow(posz,2)))));
            
            int modDet = detnbr - 3*1024;

            histHits[3]->Fill(((modDet - 1) % 32 + 1), ((modDet - 1) / 32) + 1);
        }

        else if(4097<= detnbr && detnbr <=5120)
        {
            histsThetaPhi[4]->Fill(ATan2(posx,posz), ACos(posy/(Sqrt(pow(posx,2)+pow(posy,2)+pow(posz,2)))));
            
            int modDet = detnbr - 4*1024;

            histHits[4]->Fill(((modDet - 1) % 32 + 1), ((modDet - 1) / 32) + 1);
        } 

        else if(5121<= detnbr && detnbr <=6144)
        {
            histsThetaPhi[5]->Fill(ATan2(posx,posz), ACos(posy/(Sqrt(pow(posx,2)+pow(posy,2)+pow(posz,2)))));
            
            int modDet = detnbr - 5*1024;

            histHits[5]->Fill(((modDet - 1) % 32 + 1), ((modDet - 1) / 32) + 1);
        }              
        
        std::cout << std::setprecision(3) << std::setw(5) << (100.*j/fEntries) << " %\r";

    }
   
    

    fileout->Write();
}
