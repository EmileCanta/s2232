#include "RCMPHelper.hh"

#include "ChannelMapping.h"

using namespace std;

void RCMPHelper::CreateHistograms(unsigned int slot)
{
    fH1[slot]["Energy"] = new TH1F("Energy", "Energy", 10000, 0, 10000);
    fH1[slot]["EnergyGriffin"] = new TH1F("EnergyGriffin", "EnergyGriffin", 10000, 0, 10000);
    fH1[slot]["Time"] = new TH1F("Time", "Time", 60000, 0, 60000e9);
    fH1[slot]["Multiplicity"] = new TH1F("Multiplicity", "Multiplicity", 100, 0, 100);

    fH1[slot]["FrontOrBack"] = new TH1F("FrontOrBack", "FrontOrBack", 2, 0, 2);

    fH2[slot]["HitMap"] = new TH2F("HitMap", "HitMap", 34, -1, 33, 34, -1, 33);
    fH2[slot]["FrontHitCorrelation"] = new TH2F("FrontHitCorrelation", "FrontHitCorrelation", 34, -1, 33, 34, -1, 33);
    fH2[slot]["BackHitCorrelation"] = new TH2F("BackHitCorrelation", "BackHitCorrelation", 34, -1, 33, 34, -1, 33);
    fH2[slot]["SideVSMultiplicity"] = new TH2F("SideVSMultiplicity", "SideVSMultiplicity", 100, 0, 100, 2, 0, 2);
    fH2[slot]["DetectorVSMultiplicity"] = new TH2F("DetectorVSMultiplicity", "DetectorVSMultiplicity", 8, 0, 8, 100, 0, 100);
    fH2[slot]["EnergyVSFrontStrip"] = new TH2F("EnergyVSFrontStrip", "EnergyVSFrontStrip", 34, 0, 34, 10000, 0, 10000);
    fH2[slot]["EnergyVSBackStrip"] = new TH2F("EnergyVSBackStrip", "EnergyVSBackStrip", 34, 0, 34, 10000, 0, 10000);

    fH2[slot]["FrontVSBackEnergy"] = new TH2F("FrontVSBackEnergy", "FrontVSBackEnergy", 1000, 0, 10000, 1000, 0, 10000);
}

void RCMPHelper::Exec(unsigned int slot, TRcmp& rcmp, TGriffin& griffin, TGriffinBgo& griffinbgo)
{
    TRcmpHit* hit1;
    TRcmpHit* hit2;
    TRcmpHit* hit3;

    vector<TRcmpHit*> frontHits;
    vector<TRcmpHit*> backHits;

    double mult = rcmp.GetMultiplicity();
    double multGriffin = griffin.GetMultiplicity();

    if(mult == 3) 
    {
        for(int i = 0; i < mult; i++)
        {
            if(rcmp.GetRcmpHit(i)->GetChannel()->GetMnemonic()->CollectedChargeString() == "P") frontHits.push_back(rcmp.GetRcmpHit(i));

            else backHits.push_back(rcmp.GetRcmpHit(i));
        }

        int det1 = hit[0]->GetDetector();
        int det2 = hit[1]->GetDetector();
        int det3 = hit[2]->GetDetector();

        int strip1 = hit[0]->GetSegment();
        int strip2 = hit[1]->GetSegment();
        int strip3 = hit[2]->GetSegment();

        string side1 = hit[0]->GetChannel()->GetMnemonic()->CollectedChargeString();
        string side2 = hit[1]->GetChannel()->GetMnemonic()->CollectedChargeString();
        string side3 = hit[2]->GetChannel()->GetMnemonic()->CollectedChargeString();

        if((det1 == 6) && (det1 == det2) && (det2 == det3) && (strip1 != 666))
        {
            fH1[slot].at("Energy")->Fill(hit1->GetEnergy());
            fH2[slot].at("FrontVSBackEnergy")->Fill(hit1->GetEnergy(), hit2->GetEnergy());
            fH2[slot].at("EnergyVSFrontStrip")->Fill(strip1, hit1->GetEnergy());
            fH2[slot].at("EnergyVSBackStrip")->Fill(strip2, hit1->GetEnergy());
        }

        if((det1 == det2 && det1 == 6) && (side1 != side2))
        {
            fH2[slot].at("HitMap")->Fill(frontMaps[det1][hit1->GetSegment()], backMaps[det2][hit2->GetSegment()]);
        }

        if((det1 == det2) && (side1 == side2 && side1 == "P"))
        {
            fH2[slot].at("FrontHitCorrelation")->Fill(frontMaps[det1][hit1->GetSegment()], frontMaps[det2][hit2->GetSegment()]);
        }

        if((det1 == det2) && (side1 == side2 && side1 == "N"))
        {
            fH2[slot].at("BackHitCorrelation")->Fill(backMaps[det1][hit1->GetSegment()], backMaps[det2][hit2->GetSegment()]);
        }
    }

    for(int i = 0; i < mult; i++)
    {
        TRcmpHit* hit = rcmp.GetRcmpHit(i);

        int det = hit->GetDetector();
        string side = hit->GetChannel()->GetMnemonic()->CollectedChargeString();

        fH2[slot].at("DetectorVSMultiplicity")->Fill(det, mult, 1./mult); // Careful, weighted histogram here

        if(det == 6)
        {
            if(side == "P") 
            {
                fH2[slot].at("SideVSMultiplicity")->Fill(mult, 0);

                // fH1[slot].at("Energy")->Fill(hit->GetEnergy());
                fH1[slot].at("Time")->Fill(hit->GetTime());
            }

            if(side == "N") 
            {
                fH2[slot].at("SideVSMultiplicity")->Fill(mult, 1);
            }

            if(mult > 0) fH1[slot].at("Multiplicity")->Fill(mult, 1./mult); // Careful, weighted histogram here
        }
    }

    for(int i = 0; i < multGriffin; i++)
    {
        TGriffinHit* hit = griffin.GetGriffinHit(i);
        fH1[slot].at("EnergyGriffin")->Fill(hit->GetEnergy());
    }
}

void RCMPHelper::EndOfSort(std::shared_ptr<std::map<std::string, TList>>& list)
{

}
