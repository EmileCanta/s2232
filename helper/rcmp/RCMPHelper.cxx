/******************* Taken from GRSI collaboration and adapted by Emile Cantacuzene, 2026 *******************/

#include "RCMPHelper.hh"

void RCMPHelper::CreateHistograms(unsigned int slot)
{
    fH1[slot]["EFront1"]  = new TH1F("EFront1", "EFront1", 10000, 0, 10000);
}

void RCMPHelper::Exec(unsigned int slot, TRcmp& rcmp)
{
    for (int i = 0; i < rcmp.GetFrontMultiplicity(); ++i)
    {
        TRcmpHit* hit = rcmp.GetRcmpFrontHit(i);

        int det = hit->GetDetector();

        if (det == 1) fH1[slot].at("EFront1")->Fill(hit->GetEnergy());
    }
}

void RCMPHelper::EndOfSort(std::shared_ptr<std::map<std::string, TList>>& list)
{

}
