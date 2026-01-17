#include "TMath.h"

using namespace TMath;

void AngleHist()
{	
    TFile *filein = TFile::Open("~/postdoc/data/RCMPsim_data/alpha_3MeV_fullstats.root", "READ");
    
    TFile *fileout = new TFile("./anglehist.root","RECREATE");
    
    TTree* tree = (TTree*)filein->Get("ntuple");
   
    ofstream out1("anglesDet6.txt");
    ofstream out2("anglesDet1.txt");
    ofstream out3("anglesDet5.txt");
    ofstream out4("anglesDet2.txt");
    ofstream out5("anglesDet3.txt");
    ofstream out6("anglesDet4.txt");

    int detnbr;
    double posx;
    double posy;
    double posz;
   
    vector<vector<double>> thetaVec(6144);
    vector<vector<double>> phiVec(6144);

    tree->SetBranchAddress("detNumber", &detnbr);
    tree->SetBranchAddress("posx",&posx);
    tree->SetBranchAddress("posy",&posy);
    tree->SetBranchAddress("posz",&posz);

    TH2D *histsTheta[6]; 
    TH2D *histsPhi[6]; 
    TH2D *histsHits[6];

    TH3D *hist3D = new TH3D("hist", "hist", 200, -100., 100., 200, -100., 100., 200, -100., 100.);

    int fEntries = tree->GetEntries();
    
    for(int i =0; i<6; i++) 
    {
        TString nameHistTheta = Form("histTheta%d",i+1);
        TString nameHistPhi = Form("histPhi%d",i+1);
        TString nameHistHits = Form("histHits%d",i+1);
        
        histsTheta[i] = new TH2D(nameHistTheta, nameHistTheta, 6146, 0, 6146, 10000, -200, 200);
        histsPhi[i] = new TH2D(nameHistPhi, nameHistPhi, 6146, 0, 6146, 10000, -200, 200);
        histsHits[i] = new TH2D(nameHistHits, nameHistHits, 32, 1, 33, 32, 1, 33);
    }
    
    for(int j = 0; j < fEntries; j++)
    {
        tree->GetEntry(j);

        hist3D->Fill(posx, posy, posz);

        if(1<=detnbr && detnbr<=1024)
        {
            histsTheta[5]->Fill(detnbr, ATan2(posx,posz)*180./Pi()*(-1.)+180.);
            histsPhi[5]->Fill(detnbr, ACos(posy/(Sqrt(pow(posx,2)+pow(posy,2)+pow(posz,2))))*180./Pi()*(-1)+90.);

            int modDet = detnbr - 0*1024;

            histsHits[5]->Fill(((modDet - 1) % 32 + 1), ((modDet - 1) / 32) + 1);
            
            thetaVec[detnbr-1].push_back(ATan2(posx,posz)*180./Pi()*(-1.)+180.);
            phiVec[detnbr-1].push_back(ACos(posy/(Sqrt(pow(posx,2)+pow(posy,2)+pow(posz,2))))*180./Pi()*(-1)+90.);

        }

        else if(1025 <= detnbr && detnbr <= 2048)
        {
            histsTheta[0]->Fill(detnbr, ATan2(posx,posz)*180./Pi()*(-1.));
            histsPhi[0]->Fill(detnbr, ACos(posy/(Sqrt(pow(posx,2)+pow(posy,2)+pow(posz,2))))*180./Pi()*(-1.)+90.);
           
            int modDet = detnbr - 1*1024;

            histsHits[0]->Fill(((modDet - 1) % 32 + 1), ((modDet - 1) / 32) + 1);
            
            thetaVec[detnbr-1].push_back(ATan2(posx,posz)*180./Pi()*(-1.));
            phiVec[detnbr-1].push_back(ACos(posy/(Sqrt(pow(posx,2)+pow(posy,2)+pow(posz,2))))*180./Pi()*(-1.)+90.);
        }

        else if(2049<= detnbr && detnbr <=3072)
        {
            histsTheta[4]->Fill(detnbr, ATan2(posx,posz)*180./Pi()+90.);
            histsPhi[4]->Fill(detnbr, ACos(posy/(Sqrt(pow(posx,2)+pow(posy,2)+pow(posz,2))))*180./Pi()*(-1.)+90.);
            
            int modDet = detnbr - 2*1024;

            histsHits[4]->Fill(((modDet - 1) % 32 + 1), ((modDet - 1) / 32) + 1);

            thetaVec[detnbr-1].push_back(ATan2(posx,posz)*180./Pi()+90.);
            phiVec[detnbr-1].push_back(ACos(posy/(Sqrt(pow(posx,2)+pow(posy,2)+pow(posz,2))))*180./Pi()*(-1.)+90.);

        }
        
        else if(3073<= detnbr && detnbr <=4096)
        {
            histsTheta[1]->Fill(detnbr, ATan2(posx,posz)*180./Pi()*(-1.));
            histsPhi[1]->Fill(detnbr, ACos(posy/(Sqrt(pow(posx,2)+pow(posy,2)+pow(posz,2))))*180./Pi()*(-1.)+90.);
            
            int modDet = detnbr - 3*1024;

            histsHits[1]->Fill(((modDet - 1) % 32 + 1), ((modDet - 1) / 32) + 1);

            thetaVec[detnbr-1].push_back(ATan2(posx,posz)*180./Pi()*(-1.));
            phiVec[detnbr-1].push_back(ACos(posy/(Sqrt(pow(posx,2)+pow(posy,2)+pow(posz,2))))*180./Pi()*(-1.)+90.);

        }

        else if(4097<= detnbr && detnbr <=5120)
        {
            histsTheta[2]->Fill(detnbr, ATan2(posx,posz)*180./Pi());
            histsPhi[2]->Fill(detnbr, ACos(posy/(Sqrt(pow(posx,2)+pow(posy,2)+pow(posz,2))))*180./Pi()*(-1.)+90.);
            
            int modDet = detnbr - 4*1024;

            histsHits[2]->Fill(((modDet - 1) % 32 + 1), ((modDet - 1) / 32) + 1);

            thetaVec[detnbr-1].push_back(ATan2(posx,posz)*180./Pi());
            phiVec[detnbr-1].push_back(ACos(posy/(Sqrt(pow(posx,2)+pow(posy,2)+pow(posz,2))))*180./Pi()*(-1.)+90.);

        } 

        else if(5121<= detnbr && detnbr <=6144)
        {
            histsTheta[3]->Fill(detnbr, ATan2(posx,posz)*180./Pi());
            histsPhi[3]->Fill(detnbr, ACos(posy/(Sqrt(pow(posx,2)+pow(posy,2)+pow(posz,2))))*180./Pi()*(-1.)+90.);
            
            int modDet = detnbr - 5*1024;

            histsHits[3]->Fill(((modDet - 1) % 32 + 1), ((modDet - 1) / 32) + 1);

            thetaVec[detnbr-1].push_back(ATan2(posx,posz)*180./Pi());
            phiVec[detnbr-1].push_back( ACos(posy/(Sqrt(pow(posx,2)+pow(posy,2)+pow(posz,2))))*180./Pi()*(-1.)+90.);

        }              
        
        //std::cout << std::setprecision(3) << std::setw(5) << (100.*j/fEntries) << " %\r";

    }

    out1 << "Det6 " << "phi " << "theta" << '\n';
    out2 << "phi " << "std_phi " << "theta " << "std_theta" << '\n';
    out3 << "Det5 " << "phi " << "theta" << '\n';
    out4 << "Det2 " << "phi " << "theta" << '\n';
    out5 << "Det3 " << "phi " << "theta" << '\n';
    out6 << "Det4 " << "phi " << "theta" << '\n';

    for(int i = 0; i<1024; i++)
    { 
        double phiSum=0.;    
        double thetaSum=0.;    
        
        for(int j = 0; j<phiVec[i].size(); j++)
        {
            phiSum += phiVec[i][j];
            thetaSum += thetaVec[i][j];
        }
        
        if(i % 32 == 0)
        {
            out1 << "---" << '\n';
        }

        out1 << fixed << setprecision(3) << phiSum/phiVec[i].size() << " " << thetaSum/thetaVec[i].size() << '\n';
    }
    
    for(int i = 1024; i<2048; i++)
    { 
        double phiSum=0.;    
        double thetaSum=0.;    
        double phiSum2=0.;    
        double thetaSum2=0.;    
        
        double Nevents = phiVec[i].size();

        for(int j = 0; j<Nevents; j++)
        {
            phiSum += phiVec[i][j];
            thetaSum += thetaVec[i][j];
            
            phiSum2 += phiVec[i][j]*phiVec[i][j];
            thetaSum2 += thetaVec[i][j]*thetaVec[i][j];
        }
        
        if(i % 32 == 0)
        {
            out2 << "---" << '\n';
        
        }
        double meanPhi = phiSum/Nevents;
        double meanPhi2 = phiSum2/Nevents;
        double meanTheta = thetaSum/Nevents;
        double meanTheta2 = thetaSum2/Nevents;

        double stdPhi = sqrt(meanPhi2-(meanPhi*meanPhi));
        double stdTheta = sqrt(meanTheta2-(meanTheta*meanTheta));

        out2 << fixed << setprecision(3) << meanPhi << " " << stdPhi << " " << meanTheta << " " << stdTheta << '\n';
    }
    
    for(int i = 2048; i<3072; i++)
    { 
        double phiSum=0.;    
        double thetaSum=0.;    
   
        for(int j = 0; j<phiVec[i].size(); j++)
        {
            phiSum += phiVec[i][j];
            thetaSum += thetaVec[i][j];
        }
        
        if(i % 32 == 0)
        {
            out3 << "---" << '\n';
        }
        
        out3 << fixed << setprecision(3) << phiSum/phiVec[i].size() << " " << thetaSum/thetaVec[i].size() << '\n';
    }
    
    for(int i = 3072; i<4096; i++)
    { 
        double phiSum=0.;    
        double thetaSum=0.;    
   
        for(int j = 0; j<phiVec[i].size(); j++)
        {
            phiSum += phiVec[i][j];
            thetaSum += thetaVec[i][j];
        }
        
        if(i % 32 == 0)
        {
            out4 << "---" << '\n';
        }
        
        out4 << fixed << setprecision(3) << phiSum/phiVec[i].size() << " " << thetaSum/thetaVec[i].size() << '\n';
    }
    
    for(int i = 4096; i<5120; i++)
    { 
        double phiSum=0.;    
        double thetaSum=0.;    
   
        for(int j = 0; j<phiVec[i].size(); j++)
        {
            phiSum += phiVec[i][j];
            thetaSum += thetaVec[i][j];
        }
        
        if(i % 32 == 0)
        {
            out5 << "---" << '\n';
        }
        
        out5 << fixed << setprecision(3) << phiSum/phiVec[i].size() << " " << thetaSum/thetaVec[i].size() << '\n';
    }
    
    for(int i = 5120; i<6144; i++)
    { 
        double phiSum=0.;    
        double thetaSum=0.;    
   
        for(int j = 0; j<phiVec[i].size(); j++)
        {
            phiSum += phiVec[i][j];
            thetaSum += thetaVec[i][j];
        }
        
        if(i % 32 == 0)
        {
            out6 << "---" << '\n';        
        }
        
        out6 << fixed << setprecision(3) << phiSum/phiVec[i].size() << " " << thetaSum/thetaVec[i].size() << '\n';
    }
    
    out1.close();
    out2.close();
    out3.close();
    out4.close();
    out5.close();
    out6.close();

    fileout->Write();
}
