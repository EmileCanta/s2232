#include "RCMPHelper.hh"

#include "ChannelMapping.h"

#include <cmath>

using namespace std;

void RCMPHelper::CreateHistograms(unsigned int slot)
{
    /*fH1[slot]["EnergyAll_MultTwo"] = new TH1F("EnergyAll_MultTwo", "EnergyAll_MultTwo", 10000, 0, 10000);
    fH1[slot]["TimeAll_MultTwo"] = new TH1F("TimeAll_MultTwo", "TimeAll_MultTwo", 6000, 0, 60e9); //1 bin = 0.01e9 ns = 10 ms

    fH1[slot]["EnergyGriffin_Singles"] = new TH1F("EnergyGriffin_Singles", "EnergyGriffin_Singles", 10000, 0, 10000);
    fH1[slot]["TimeGriffin_Singles"] = new TH1F("TimeGriffin_Singles", "TimeGriffin_Singles", 6000, 0, 60e9); //1 bin = 0.01e9 ns = 10 ms
    fH1[slot]["AbsTimeGriffin_Singles"] = new TH1F("AbsTimeGriffin_Singles", "AbsTimeGriffin_Singles", 600000, 0, 6000e9); //1 bin = 0.01e9 ns = 10 ms

    fH2[slot]["EnergyFront1VSTimeDiffFrontFront_Det5Or6"] = new TH2F("EnergyFront1VSTimeDiffFrontFront_Det5Or6", "EnergyFront1VSTimeDiffFrontFront_Det5Or6", 500, -2500, 2500, 1000, 0, 10000); //Less bins

    fH2[slot]["FrontHitCorrelation_MultTwo"] = new TH2F("FrontHitCorrelation_MultTwo", "FrontHitCorrelation_MultTwo", 32, 0, 32, 32, 0, 32);
    fH2[slot]["BackHitCorrelation_MultTwo"] = new TH2F("BackHitCorrelation_MultTwo", "BackHitCorrelation_MultTwo", 32, 0, 32, 32, 0, 32);
    fH2[slot]["DetRepartition_MultTwo"] = new TH2F("DetRepartition_MultTwo", "DetRepartition_MultTwo", 6, 1, 7, 6, 1, 7);*/
   
    /*fH2[slot]["DetectorVSMultiplicity_Singles"] = new TH2F("DetectorVSMultiplicity_Singles", "DetectorVSMultiplicity_Singles", 100, 0, 100, 6, 1, 7);

    fH2[slot]["EnergyFrontVSTimeFront_CondGRIF"] = new TH2F("EnergyFrontVSTimeFront_CondGRIF", "EnergyFrontVSTimeFront_CondGRIF", 6000, 0, 60e9, 1000, 0, 10000); //1 bin = 0.01e9 ns = 10 ms //Less bins
    fH2[slot]["EnergyFrontVSTimeFront_Singles"] = new TH2F("EnergyFrontVSTimeFront_Singles", "EnergyFrontVSTimeFront_Singles", 6000, 0, 60e9, 1000, 0, 10000); //1 bin = 0.01e9 ns = 10 ms //Less bins
    fH2[slot]["EnergyGriffinVSTimeGriffin_CondRCMP"] = new TH2F("EnergyGriffinVSTimeGriffin_CondRCMP", "EnergyGriffinVSTimeGriffin_CondRCMP", 6000, 0, 60e9, 10000, 0, 10000); //1 bin = 0.01e9 ns = 10 ms
    fH2[slot]["EnergyGriffinVSTimeGriffin_Singles"] = new TH2F("EnergyGriffinVSTimeGriffin_Singles", "EnergyGriffinVSTimeGriffin_Singles", 6000, 0, 60e9, 10000, 0, 10000); //1 bin = 0.01e9 ns = 10 ms
                     */                                                                                                                                                       
    /*fH2[slot]["E1VSE2_Mult6RCMP"] = new TH2F("E1VSE2_Mult6RCMP", "E1VSE2_Mult6RCMP", 1000, 0, 10000, 1000, 0, 10000);
    fH2[slot]["E1VSE2_Mult6RCMPBgd"] = new TH2F("E1VSE2_Mult6RCMPBgd", "E1VSE2_Mult6RCMPBgd", 1000, 0, 10000, 1000, 0, 10000);
    fH1[slot]["Etot_Mult6RCMP"] = new TH1F("Etot_Mult6RCMP", "Etot_Mult6RCMP", 10000, 0, 10000);
    fH1[slot]["Etot_Mult6RCMPBgd"] = new TH1F("Etot_Mult6RCMPBgd", "Etot_Mult6RCMPBgd", 10000, 0, 10000);
    fH1[slot]["E1_Mult6RCMP"] = new TH1F("E1_Mult6RCMP", "E1_Mult6RCMP", 10000, 0, 10000);
    fH1[slot]["E2_Mult6RCMP"] = new TH1F("E2_Mult6RCMP", "E2_Mult6RCMP", 10000, 0, 10000);
    fH1[slot]["Erejected_Mult6RCMP"] = new TH1F("Erejected_Mult6RCMP", "Erejected_Mult6RCMP", 10000, 0, 10000);
    fH1[slot]["Erejected_Mult6RCMPBgd"] = new TH1F("Erejected_Mult6RCMPBgd", "Erejected_Mult6RCMPBgd", 10000, 0, 10000);
    fH1[slot]["E1_Mult6RCMPBgd"] = new TH1F("E1_Mult6RCMPBgd", "E1_Mult6RCMPBgd", 10000, 0, 10000);
    fH1[slot]["E2_Mult6RCMPBgd"] = new TH1F("E2_Mult6RCMPBgd", "E2_Mult6RCMPBgd", 10000, 0, 10000);
    fH1[slot]["T3minusPair"] = new TH1F("T3minusPair", "T3minusPair", 500, -5000, 5000);
    fH2[slot]["E1vsElow"] = new TH2F("E1vsElow", "E1vsElow", 1000, 0, 10000, 1000, 0, 10000);
    fH2[slot]["E1vsElowBgd"] = new TH2F("E1vsElowBgd", "E1vsElowBgd", 1000, 0, 10000, 1000, 0, 10000);
    fH2[slot]["E1vsEmid"] = new TH2F("E1vsEmid", "E1vsEmid", 1000, 0, 10000, 1000, 0, 10000);
    fH2[slot]["E1vsEmidBgd"] = new TH2F("E1vsEmidBgd", "E1vsEmidBgd", 1000, 0, 10000, 1000, 0, 10000);
    fH2[slot]["Det1vsDetlow"] = new TH2F("Det1vsDetlow", "Det1vsDetlow", 7, 0, 7, 7, 0, 7);
    fH2[slot]["Det1vsDetlowBgd"] = new TH2F("Det1vsDetlowBgd", "Det1vsDetlowBgd", 7, 0, 7, 7, 0, 7);
    fH2[slot]["Det1vsDetmid"] = new TH2F("Det1vsDetmid", "Det1vsDetmid", 7, 0, 7, 7, 0, 7);
    fH2[slot]["Det1vsDetmidBgd"] = new TH2F("Det1vsDetmidBgd", "Det1vsDetmidBgd", 7, 0, 7, 7, 0, 7);*/

    fH2[slot]["E1VSE2_Mult4RCMP"] = new TH2F("E1VSE2_Mult4RCMP", "E1VSE2_Mult4RCMP", 1000, 0, 10000, 1000, 0, 10000);
    fH2[slot]["E1VSE2Bgd_Mult4RCMP"] = new TH2F("E1VSE2Bgd_Mult4RCMP", "E1VSE2Bgd_Mult4RCMP", 1000, 0, 10000, 1000, 0, 10000);
    fH1[slot]["TimeDiff_Mult4RCMP"] = new TH1F("TimeDiff_Mult4RCMP", "TimeDiff_Mult4RCMP", 500, -5000, 5000);
    fH1[slot]["Etot_Mult4RCMP"] = new TH1F("Etot_Mult4RCMP", "Etot_Mult4RCMP", 10000, 0, 10000);
    fH1[slot]["EtotBgd_Mult4RCMP"] = new TH1F("EtotBgd_Mult4RCMP", "EtotBgd_Mult4RCMP", 10000, 0, 10000);
    fH1[slot]["E1_Mult4RCMP"] = new TH1F("E1_Mult4RCMP", "E1_Mult4RCMP", 10000, 0, 10000);
    fH1[slot]["E2_Mult4RCMP"] = new TH1F("E2_Mult4RCMP", "E2_Mult4RCMP", 10000, 0, 10000);
    fH1[slot]["E1Bgd_Mult4RCMP"] = new TH1F("E1Bgd_Mult4RCMP", "E1Bgd_Mult4RCMP", 10000, 0, 10000);
    fH1[slot]["E2Bgd_Mult4RCMP"] = new TH1F("E2Bgd_Mult4RCMP", "E2Bgd_Mult4RCMP", 10000, 0, 10000);

    fH1[slot]["TimeDiff_Mult2RCMP"] = new TH1F("TimeDiff_Mult2RCMP", "TimeDiff_Mult2RCMP", 500, -5000, 5000);
    fH2[slot]["EbVSEf_Mult2RCMP"] = new TH2F("EbVSEf_Mult2RCMP", "EbVSEf_Mult2RCMP", 1000, 0, 10000, 1000, 0, 10000);
    fH2[slot]["EbVSEfBgd_Mult2RCMP"] = new TH2F("EbVSEfBgd_Mult2RCMP", "EbVSEfBgd_Mult2RCMP", 1000, 0, 10000, 1000, 0, 10000);

    for(int ndet = 1; ndet <= 6; ndet++)
    {
        /*fH2[slot][Form("EnergyVSFrontStrip_MultTwo%d", ndet)] = new TH2F(Form("EnergyVSFrontStrip_MultTwo%d", ndet), Form("EnergyVSFrontStrip_MultTwo%d", ndet), 32, 0, 32, 10000, 0, 10000);
        fH2[slot][Form("EnergyVSBackStrip_MultTwo%d", ndet)] = new TH2F(Form("EnergyVSBackStrip_MultTwo%d", ndet), Form("EnergyVSBackStrip_MultTwo%d", ndet), 32, 0, 32, 10000, 0, 10000);

        fH2[slot][Form("ChargeVSFrontStrip_MultTwo%d", ndet)] = new TH2F(Form("ChargeVSFrontStrip_MultTwo%d", ndet), Form("ChargeVSFrontStrip_MultTwo%d", ndet), 32, 0, 32, 2500, 0, 10000); //Less bins
        fH2[slot][Form("ChargeVSBackStrip_MultTwo%d", ndet)] = new TH2F(Form("ChargeVSBackStrip_MultTwo%d", ndet), Form("ChargeVSBackStrip_MultTwo%d", ndet), 32, 0, 32, 2500, 0, 10000); //Less bins
        
        fH2[slot][Form("ChargeVSPixelFront_MultTwo%d", ndet)] = new TH2F(Form("ChargeVSPixelFront_MultTwo%d", ndet), Form("ChargeVSPixelFront_MultTwo%d", ndet), 1023, 0, 1023, 1000, 0, 10000); //Less bins
        fH2[slot][Form("ChargeVSPixelBack_MultTwo%d", ndet)] = new TH2F(Form("ChargeVSPixelBack_MultTwo%d", ndet), Form("ChargeVSPixelBack_MultTwo%d", ndet), 1023, 0, 1023, 1000, 0, 10000); //Less bins

        fH2[slot][Form("HitMapNonCorrected_MultTwo%d", ndet)] = new TH2F(Form("HitMapNonCorrected_MultTwo%d", ndet), Form("HitMapNonCorrected_MultTwo%d", ndet), 32, 0, 32, 32, 0, 32);
        fH2[slot][Form("HitMapCorrectedGood_MultTwo%d", ndet)] = new TH2F(Form("HitMapCorrectedGood_MultTwo%d", ndet), Form("HitMapCorrectedGood_MultTwo%d", ndet), 32, 0, 32, 32, 0, 32);
        fH2[slot][Form("HitMapCorrectedWeird_MultTwo%d", ndet)] = new TH2F(Form("HitMapCorrectedWeird_MultTwo%d", ndet), Form("HitMapCorrectedWeird_MultTwo%d", ndet), 32, 0, 32, 32, 0, 32);

        fH2[slot][Form("HitMapCorrectedWeird_MultTwo%d", ndet)] = new TH2F(Form("HitMapCorrectedWeird_MultTwo%d", ndet), Form("HitMapCorrectedWeird_MultTwo%d", ndet), 32, 0, 32, 32, 0, 32);

        fH2[slot][Form("EnergyBackVSEnergyFront_MultTwo%d", ndet)] = new TH2F(Form("EnergyBackVSEnergyFront_MultTwo%d", ndet), Form("EnergyBackVSEnergyFront_MultTwo%d", ndet), 1000, 0, 10000, 1000, 0, 10000); //Less bins

        fH1[slot][Form("TimeDiffBackFront_MultTwo%d", ndet)] = new TH1F(Form("TimeDiffBackFront_MultTwo%d", ndet), Form("TimeDiffBackFront_MultTwo%d", ndet), 500, -2500, 2500);
*/
        /*fH2[slot][Form("EnergyVSFrontStrip_Singles%d", ndet)] = new TH2F(Form("EnergyVSFrontStrip_Singles%d", ndet), Form("EnergyVSFrontStrip_Singles%d", ndet), 32, 0, 32, 10000, 0, 10000);
        fH2[slot][Form("EnergyVSBackStrip_Singles%d", ndet)] = new TH2F(Form("EnergyVSBackStrip_Singles%d", ndet), Form("EnergyVSBackStrip_Singles%d", ndet), 32, 0, 32, 10000, 0, 10000);

        fH2[slot][Form("EnergyFrontVSMult_Singles%d", ndet)] = new TH2F(Form("EnergyFrontVSMult_Singles%d", ndet), Form("EnergyFrontVSMult_Singles%d", ndet), 20, 0, 20, 1000, 0, 10000); //Less bins

        fH2[slot][Form("EnergyFrontVSEnergyGriffin_CondRCMP%d", ndet)] = new TH2F(Form("EnergyFrontVSEnergyGriffin_CondRCMP%d", ndet), Form("EnergyFrontVSEnergyGriffin_CondRCMP%d", ndet), 10000, 0, 10000, 1000, 0, 10000); //Less bins

        fH2[slot][Form("EnergyVSTimeDiffFrontGriffin_CondGRIF%d", ndet)] = new TH2F(Form("EnergyVSTimeDiffFrontGriffin_CondGRIF%d", ndet), Form("EnergyVSTimeDiffFrontGriffin_CondGRIF%d", ndet), 500, -2500, 2500, 1000, 0, 10000); //Less bins
        fH2[slot][Form("EnergyVSTimeDiffBackGriffin_CondGRIF%d", ndet)] = new TH2F(Form("EnergyVSTimeDiffBackGriffin_CondGRIF%d", ndet), Form("EnergyVSTimeDiffBackGriffin_CondGRIF%d", ndet), 500, -2500, 2500, 1000, 0, 10000); //Less bins

        fH2[slot][Form("EnergyBackVSEnergyFront_Gated%d", ndet)] = new TH2F(Form("EnergyBackVSEnergyFront_Gated%d", ndet), Form("EnergyBackVSEnergyFront_Gated%d", ndet), 1000, 0, 10000, 1000, 0, 10000); //Less bins
        
        fH1[slot][Form("TimeDiffBackFront_Gated%d", ndet)] = new TH1F(Form("TimeDiffBackFront_Gated%d", ndet), Form("TimeDiffBackFront_Gated%d", ndet), 500, -2500, 2500);*/
    }

    /*for(int multi = 1; multi <= 10; multi++)
    {
        fH2[slot][Form("EnergyFront1VSEnergyFront2Mult%d_Det5Or6", multi)] = new TH2F(Form("EnergyFront1VSEnergyFront2Mult%d_Det5Or6", multi), Form("EnergyFront1VSEnergyFront2Mult%d_Det5Or6", multi), 1000, 0, 10000, 1000, 0, 10000); //Less bins
        fH2[slot][Form("EnergyFront1VSEnergyFront2BgdMult%d_Det5Or6", multi)] = new TH2F(Form("EnergyFront1VSEnergyFront2BgdMult%d_Det5Or6", multi), Form("EnergyFront1VSEnergyFront2BgdMult%d_Det5Or6", multi), 1000, 0, 10000, 1000, 0, 10000); //Less bins
    }*/
}

void RCMPHelper::Exec(unsigned int slot, TRcmp& rcmp, TGriffin& griffin, TGriffinBgo& griffinbgo)
{
    TRcmpHit* hit1;
    TRcmpHit* hit2;

    int mult = rcmp.GetMultiplicity();
    int multGriffin = griffin.GetMultiplicity();

    vector<HitInfo> frontvec;
    vector<HitInfo> backvec;

    // MULT 2 ROUTINE

    if(mult == 2)
    {
        for(int i = 0; i < mult; i++)
        {
            TRcmpHit* hit = rcmp.GetRcmpHit(i);

            int det = hit->GetDetector();
            double energy = hit->GetEnergy();
            double time = hit->GetTimeStampNs();
            string side = hit->GetChannel()->GetMnemonic()->CollectedChargeString();
            int strip;

            if(side == "P") strip = frontMaps[det][hit->GetSegment()];
            if(side == "N") strip = backMaps[det][hit->GetSegment()];

            if(side == "P" && det != 3 && det != 4 && strip > 0 && strip < 31) frontvec.push_back({energy, time, det}); //Vector of front events

            if(side == "N" && det != 3 && det != 4 && strip > 0 && strip < 31) backvec.push_back({energy, time, det}); //Vector of back events
        }

        bool allInB = all_of(frontvec.begin(), frontvec.end(), [&](const HitInfo& x) { //Condition on same det and energy for front/back among the back elements
                return any_of(backvec.begin(), backvec.end(), [&](const HitInfo& y) {
                        return x.det == y.det && abs(x.energy - y.energy) < 150.;
                        });
                });

        if(allInB) 
        {
            if(frontvec.size() == 1 && backvec.size() == 1) //Condition on 1 front 1 back
            {
                {
                    double timeDiff = frontvec[0].time - backvec[0].time;

                    fH1[slot].at("TimeDiff_Mult2RCMP")->Fill(timeDiff);

                    if(timeDiff > -300. && timeDiff <= 300.)
                    {
                        fH2[slot].at("EbVSEf_Mult2RCMP")->Fill(frontvec[0].energy, backvec[0].energy);
                    }

                    if(timeDiff > 600. && timeDiff <= 1200.)
                    {
                        fH2[slot].at("EbVSEfBgd_Mult2RCMP")->Fill(frontvec[0].energy, frontvec[1].energy);
                    }
                }
            }
        }
    }

    // MULT 4 ROUTINE

    /*if(mult == 4)
    {
        for(int i = 0; i < mult; i++)
        {
            TRcmpHit* hit = rcmp.GetRcmpHit(i);

            int det = hit->GetDetector();
            double energy = hit->GetEnergy();
            double time = hit->GetTimeStampNs();
            string side = hit->GetChannel()->GetMnemonic()->CollectedChargeString();
            int strip;

            if(side == "P") strip = frontMaps[det][hit->GetSegment()];
            if(side == "N") strip = backMaps[det][hit->GetSegment()];

            if(side == "P" && det != 3 && det != 4 && strip > 0 && strip < 31) frontvec.push_back({energy, time, det}); //Vector of front events

            if(side == "N" && det != 3 && det != 4 && strip > 0 && strip < 31) backvec.push_back({energy, time, det}); //Vector of back events
        }

        bool allInB = all_of(frontvec.begin(), frontvec.end(), [&](const HitInfo& x) { //Condition on same det and energy for front/back among the back elements
                return any_of(backvec.begin(), backvec.end(), [&](const HitInfo& y) {
                        return x.det == y.det && abs(x.energy - y.energy) < 150.;
                        });
                });

        if(allInB) 
        {
            if(frontvec.size() == 2 && backvec.size() == 2 && frontvec[0].det != frontvec[1].det) //Condition on 2 front 2 back with 2 different detectors
            {
                {
                    double timeDiff = frontvec[0].time - frontvec[1].time;

                    fH1[slot].at("TimeDiff_Mult4RCMP")->Fill(timeDiff);

                    if(timeDiff > -600. && timeDiff <= 0.)
                    {
                        fH2[slot].at("E1VSE2_Mult4RCMP")->Fill(frontvec[0].energy, frontvec[1].energy);
                        fH2[slot].at("E1VSE2_Mult4RCMP")->Fill(frontvec[1].energy, frontvec[0].energy);

                        fH1[slot].at("Etot_Mult4RCMP")->Fill(frontvec[0].energy + frontvec[1].energy);

                        fH1[slot].at("E1_Mult4RCMP")->Fill(frontvec[0].energy);
                        fH1[slot].at("E2_Mult4RCMP")->Fill(frontvec[1].energy);
                    }

                    if(timeDiff > -1300. && timeDiff <= -700.)
                    {
                        fH2[slot].at("E1VSE2Bgd_Mult4RCMP")->Fill(frontvec[0].energy, frontvec[1].energy);
                        fH2[slot].at("E1VSE2Bgd_Mult4RCMP")->Fill(frontvec[1].energy, frontvec[0].energy);

                        fH1[slot].at("EtotBgd_Mult4RCMP")->Fill(frontvec[0].energy + frontvec[1].energy);

                        fH1[slot].at("E1Bgd_Mult4RCMP")->Fill(frontvec[0].energy);
                        fH1[slot].at("E2Bgd_Mult4RCMP")->Fill(frontvec[1].energy);
                    }
                }
            }
        }
    }*/

    frontvec.clear();
    backvec.clear();

    // MULT 6 ROUTINE

    /*if(mult == 6)
    {
        //cout << "NEXT MULT 6 EVENT: " << endl;

        for(int i = 0; i < mult; i++)
        {
            TRcmpHit* hit = rcmp.GetRcmpHit(i);

            int det = hit->GetDetector();
            double energy = hit->GetEnergy();
            double time = hit->GetTimeStampNs();
            string side = hit->GetChannel()->GetMnemonic()->CollectedChargeString();
            int strip;

            if(side == "P") strip = frontMaps[det][hit->GetSegment()];
            if(side == "N") strip = backMaps[det][hit->GetSegment()];

            if(side == "P" && det != 3 && det != 4 && strip > 0 && strip < 31) frontvec.push_back({energy, time, det}); //Vector of front events

            if(side == "N" && det != 3 && det != 4 && strip > 0 && strip < 31) backvec.push_back({energy, time, det}); //Vector of back events

            //cout << fixed << setprecision(10) << det << " " << energy << " " << time << " " << side << " " << strip << endl;
        }

        bool allInB = all_of(frontvec.begin(), frontvec.end(), [&](const HitInfo& x) { //Condition on same det and energy for front/back among the back elements
                return any_of(backvec.begin(), backvec.end(), [&](const HitInfo& y) {
                        return x.det == y.det && abs(x.energy - y.energy) < 150.;
                        });
                });

        if(allInB && frontvec.size() == 3 && backvec.size() == 3 &&
                frontvec[0].det != frontvec[1].det && frontvec[0].det != frontvec[2].det &&
                frontvec[1].det != frontvec[2].det)
        {
            const double W = 500.;

            // same selection for prompt (w = 1) and off-time (w = 1/nShifts)
            auto fillTriplet = [&](std::vector<HitInfo> f, const string& suffix, double w) {
                auto it = min_element(f.begin(), f.end(),
                        [](const auto& a, const auto& b) { return a.energy < b.energy; });
                double minE = it->energy;
                f.erase(it);

                fH2[slot].at("E1VSE2_Mult6RCMP" + suffix)->Fill(f[0].energy, f[1].energy, w);
                fH2[slot].at("E1VSE2_Mult6RCMP" + suffix)->Fill(f[1].energy, f[0].energy, w);
                fH1[slot].at("Etot_Mult6RCMP" + suffix)->Fill(f[0].energy + f[1].energy, w);
                fH1[slot].at("E1_Mult6RCMP" + suffix)->Fill(f[0].energy, w);
                fH1[slot].at("E2_Mult6RCMP" + suffix)->Fill(f[1].energy, w);
                fH1[slot].at("Erejected_Mult6RCMP" + suffix)->Fill(minE, w);

                std::sort(f.begin(), f.end(),
                        [](const auto& a, const auto& b){ return a.energy > b.energy; });
                // f[0] = highest (alpha/proton), f[1] = middle, f[2] = lowest (candidate recoil)

                fH2[slot].at("E1vsElow" + suffix)->Fill(f[0].energy, f[2].energy, w);
                fH2[slot].at("E1vsEmid" + suffix)->Fill(f[0].energy, f[1].energy, w);   // for comparison
                fH2[slot].at("Det1vsDetlow" + suffix)->Fill(f[0].det, f[2].det, w);
                fH2[slot].at("Det1vsDetmid" + suffix)->Fill(f[0].det, f[1].det, w);   // for comparison

                //cout << "HEY" << endl;
            };

            // ---- prompt: all three within W
            double tmin = min({frontvec[0].time, frontvec[1].time, frontvec[2].time});
            double tmax = max({frontvec[0].time, frontvec[1].time, frontvec[2].time});
            if(tmax - tmin < W)
            {
                // your existing TimeDiff histograms here, then:
                fillTriplet(frontvec, "", 1.0);
            }

            // ---- off-time: a tight pair plus one hit displaced by +-1250 ns
            static const double shifts[] = {-1250., +1250.};
            const double nShifts = 2.;

            for(int k = 0; k < 3; k++)                    // k = candidate "third" hit
            {
                const HitInfo& a = frontvec[(k+1)%3];
                const HitInfo& b = frontvec[(k+2)%3];
                double plo = min(a.time, b.time), phi = max(a.time, b.time);
                if(phi - plo >= W) continue;              // the other two must be a prompt pair

                double dt3 = frontvec[k].time - 0.5 * (plo + phi);
                fH1[slot].at("T3minusPair")->Fill(dt3);     // once per candidate, full range                                   

                for(double s : shifts)
                {
                    double t3 = frontvec[k].time - s;     // shift back into the prompt region
                    if(t3 > phi - W && t3 < plo + W)      // same acceptance width as prompt
                    {
                        fillTriplet(frontvec, "Bgd", 1. / nShifts);
                    }
                }
            }
        }
    }*/

    /*if(mult == 2) 
    {
        if(rcmp.GetRcmpHit(0)->GetChannel()->GetMnemonic()->CollectedChargeString() == "P")
        {
            hit1 = rcmp.GetRcmpHit(0);
            hit2 = rcmp.GetRcmpHit(1);
        }

        if(rcmp.GetRcmpHit(0)->GetChannel()->GetMnemonic()->CollectedChargeString() == "N")
        {
            hit1 = rcmp.GetRcmpHit(1);
            hit2 = rcmp.GetRcmpHit(0);
        }

        int det1 = hit1->GetDetector();
        int det2 = hit2->GetDetector();

        int strip1 = hit1->GetSegment();
        int strip2 = hit2->GetSegment();

        int mappedstrip1 = frontMaps[det1][hit1->GetSegment()];
        int mappedstrip2 = backMaps[det2][hit2->GetSegment()];

        int mappedstrip1bis = frontMapsBis[det1][hit1->GetSegment()];
        int mappedstrip2bis = backMapsBis[det2][hit2->GetSegment()];

        double charge1 = hit1->GetCharge();
        double charge2 = hit2->GetCharge();

        double energy1 = hit1->GetEnergy();
        double energy2 = hit2->GetEnergy();

        double timediff = hit2->GetTimeStampNs() - hit1->GetTimeStampNs();

        string side1 = hit1->GetChannel()->GetMnemonic()->CollectedChargeString();
        string side2 = hit2->GetChannel()->GetMnemonic()->CollectedChargeString();

        int pixel = mappedstrip1 + 32 * mappedstrip2;

        if((det1 == det2) && (side1 != side2)) 
        {
            fH1[slot].at("EnergyAll_MultTwo")->Fill(hit1->GetEnergy());
            fH1[slot].at("TimeAll_MultTwo")->Fill(hit1->GetTimeStampNs()%60000000000LL);
        }

        if((det1 == det2) && (side1 != side2) && mappedstrip1 > 0 && mappedstrip1 < 31 && mappedstrip2 > 0 && mappedstrip2 < 31)
        {
            fH2[slot].at(Form("EnergyVSFrontStrip_MultTwo%d", det1))->Fill(mappedstrip1, energy1);
            fH2[slot].at(Form("EnergyVSBackStrip_MultTwo%d", det1))->Fill(mappedstrip2, energy2);

            fH2[slot].at(Form("ChargeVSFrontStrip_MultTwo%d", det1))->Fill(strip1, charge1); //Careful to not use mapping for calibration code to work correctly!
            fH2[slot].at(Form("ChargeVSBackStrip_MultTwo%d", det1))->Fill(strip2, charge2);

            fH2[slot].at(Form("HitMapNonCorrected_MultTwo%d", det1))->Fill(strip1, strip2);
            fH2[slot].at(Form("HitMapCorrectedWeird_MultTwo%d", det1))->Fill(mappedstrip1bis, mappedstrip2bis); //This is for files calibrated with ODB previous to RUN28254

            fH2[slot].at(Form("ChargeVSPixelFront_MultTwo%d", det1))->Fill(pixel, charge1);
            fH2[slot].at(Form("ChargeVSPixelBack_MultTwo%d", det1))->Fill(pixel, charge2);

            if(det1 == 1) fH2[slot].at(Form("HitMapCorrectedGood_MultTwo%d", det1))->Fill(mappedstrip1, mappedstrip2); 
            if(det1 == 2) fH2[slot].at(Form("HitMapCorrectedGood_MultTwo%d", det1))->Fill(mappedstrip2, mappedstrip1);

            if(det1 == 3) fH2[slot].at(Form("HitMapCorrectedGood_MultTwo%d", det1))->Fill(mappedstrip1, mappedstrip2);
            if(det1 == 4) fH2[slot].at(Form("HitMapCorrectedGood_MultTwo%d", det1))->Fill(mappedstrip2, mappedstrip1);

            if(det1 == 5) fH2[slot].at(Form("HitMapCorrectedGood_MultTwo%d", det1))->Fill(mappedstrip1, mappedstrip2);
            if(det1 == 6) fH2[slot].at(Form("HitMapCorrectedGood_MultTwo%d", det1))->Fill(mappedstrip2, mappedstrip1);

            fH1[slot].at(Form("TimeDiffBackFront_MultTwo%d", det1))->Fill(timediff);
            fH2[slot].at(Form("EnergyBackVSEnergyFront_MultTwo%d", det1))->Fill(energy1, energy2);
        }

        if((det1 == det2) && (side1 == side2) && (side1 == "P"))
        {
            fH2[slot].at("FrontHitCorrelation_MultTwo")->Fill(mappedstrip1, mappedstrip2);
        }

        if((det1 == det2) && (side1 == side2) && (side1 == "N"))
        {
            fH2[slot].at("BackHitCorrelation_MultTwo")->Fill(mappedstrip1, mappedstrip2);
        }

        fH2[slot].at("DetRepartition_MultTwo")->Fill(det1, det2);
    }*/

    //cout << "MULT IS: " << mult << endl;

    /*for(int i = 0; i < mult; i++)
    {
        TRcmpHit* hit = rcmp.GetRcmpHit(i);

        int det = hit->GetDetector();
        
        double energy = hit->GetEnergy();
        double time = hit->GetTimeStampNs()%60000000000LL;

        string side = hit->GetChannel()->GetMnemonic()->CollectedChargeString();

        fH2[slot].at("DetectorVSMultiplicity_Singles")->Fill(mult, det, 1./((double)mult)); // Careful, weighted histogram here

        if(side == "P")
        {
            fH2[slot].at(Form("EnergyVSFrontStrip_Singles%d", det))->Fill(frontMaps[det][hit->GetSegment()], energy);
            fH2[slot].at(Form("EnergyFrontVSMult_Singles%d", det))->Fill(mult, energy);

            if(det != 3 && det != 4) fH2[slot].at("EnergyFrontVSTimeFront_Singles")->Fill(time, energy);
        }

        if(side == "N") 
        {
            fH2[slot].at(Form("EnergyVSBackStrip_Singles%d", det))->Fill(backMaps[det][hit->GetSegment()], energy);
        }

        for(int j = 0; j < multGriffin; j++)
        {
            TGriffinHit* hitgrif = griffin.GetGriffinHit(j);

            double energygrif = hitgrif->GetEnergy();
            double timegrif = hitgrif->GetTimeStampNs()%60000000000LL;

            double tdiffgrif = (hit->GetTimeStampNs() - hitgrif->GetTimeStampNs());

            if(side == "P" && frontMaps[det][hit->GetSegment()] != 0 && frontMaps[det][hit->GetSegment()] != 31) //Cutting edge strips
            {
                fH2[slot].at(Form("EnergyVSTimeDiffFrontGriffin_CondGRIF%d", det))->Fill(tdiffgrif, energy);        

                if(tdiffgrif >=-400 && tdiffgrif <= 400) 
                {
                    fH2[slot].at(Form("EnergyFrontVSEnergyGriffin_CondRCMP%d", det))->Fill(energygrif, energy);

                    if(det != 3 && det != 4) //Deal with these detectors later
                    {
                        fH2[slot].at("EnergyFrontVSTimeFront_CondGRIF")->Fill(time, energy);
                        fH2[slot].at("EnergyGriffinVSTimeGriffin_CondRCMP")->Fill(timegrif, energygrif);
                    }
                }
            }

            if(side == "N" && backMaps[det][hit->GetSegment()] != 0 && backMaps[det][hit->GetSegment()] != 31) //Cutting edge strips
            {
                fH2[slot].at(Form("EnergyVSTimeDiffBackGriffin_CondGRIF%d", det))->Fill(tdiffgrif, energy);            
            }
        }*/

        /*for(int j = i+1; j < mult; j++)
        {
            TRcmpHit* hitbis = rcmp.GetRcmpHit(j);

            int detbis = hitbis->GetDetector();
            
            double energybis = hitbis->GetEnergy();

            string sidebis = hitbis->GetChannel()->GetMnemonic()->CollectedChargeString();

            if((mult <= 10) && (side == sidebis) && (side == "P") && (5 <= det <= 6) && (5 <= detbis <= 6)) 
            {
                double tdiff = (hitbis->GetTimeStampNs() - hit->GetTimeStampNs());

                fH2[slot].at("EnergyFront1VSTimeDiffFrontFront_Det5Or6")->Fill(tdiff, energy);            

                if((-60. <= tdiff) && (tdiff <= 60.)) 
                {
                    fH2[slot].at(Form("EnergyFront1VSEnergyFront2Mult%d_Det5Or6", mult))->Fill(energybis, energy);   
                }

                if((720. <= tdiff) && (tdiff <= 780.))
                {
                    fH2[slot].at(Form("EnergyFront1VSEnergyFront2BgdMult%d_Det5Or6", mult))->Fill(energybis, energy);
                }
            }

            //cout << det << " " << detbis << " " << side << " " << sidebis << " " << energy << " " << energybis << endl;
        }*/

        /*for(int j = 0; j < mult; j++)
        {
            TRcmpHit* hitbis = rcmp.GetRcmpHit(j);

            int detbis = hitbis->GetDetector();

            double energybis = hitbis->GetEnergy();

            string sidebis = hitbis->GetChannel()->GetMnemonic()->CollectedChargeString();

            double tdiff = (hitbis->GetTimeStampNs() - hit->GetTimeStampNs());

            if((side != sidebis) && (det == detbis) && TMath::Abs(tdiff) < 300.) //-160 to 160 Sydney gate
            {
                fH1[slot].at(Form("TimeDiffBackFront_Gated%d", det))->Fill(tdiff);
                
                if(side == "P") fH2[slot].at(Form("EnergyBackVSEnergyFront_Gated%d", det))->Fill(energy, energybis);
            }
        }
    }

    for(int i = 0; i < multGriffin; i++)
    {
        TGriffinHit* hit = griffin.GetGriffinHit(i);
        double timegrif = hit->GetTimeStampNs()%60000000000LL;
        double timegrifabs = hit->GetTimeStampNs();
        double energygrif = hit->GetEnergy();

        fH1[slot].at("EnergyGriffin_Singles")->Fill(energygrif);
        fH1[slot].at("TimeGriffin_Singles")->Fill(timegrif);
        fH2[slot].at("EnergyGriffinVSTimeGriffin_Singles")->Fill(timegrif, energygrif);
        fH1[slot].at("AbsTimeGriffin_Singles")->Fill(timegrifabs);
    }*/
}

void RCMPHelper::EndOfSort(std::shared_ptr<std::map<std::string, TList>>& list)
{

}
