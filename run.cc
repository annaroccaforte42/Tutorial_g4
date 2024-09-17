#include "run.hh"

MyRunAction::MyRunAction()
{
  // u can create a single output file here for all the runs
}

MyRunAction::~MyRunAction()
{}

void MyRunAction::BeginOfRunAction(const G4Run*)
{
  // u can create a new output file here for every run
  G4AnalysisManager *man = G4AnalysisManager::Instance();

  man->OpenFile("output.root");

  // create tuples
  man->CreateNtuple("Hits", "Hits");
  man->CreateNtupleIColumn("fEvent"); // event number
  man->CreateNtupleDColumn("fX"); // x coordinate of the detector
  man->CreateNtupleDColumn("fY"); // y
  man->CreateNtupleDColumn("fZ"); // z
  man->FinishNtuple(0);
  // in root I can see the circle on xy plane with
  // Hits->Draw("fX:fY", "", "colz")
}

void MyRunAction::EndOfRunAction(const G4Run*)
{
  G4AnalysisManager *man = G4AnalysisManager::Instance();

  man->Write();
  // it is very important to always write before closing otherwise the root file could take heavy damage
  man->CloseFile();
}
