#include "run.hh"

MyRunAction::MyRunAction()
{
}

MyRunAction::~MyRunAction()
{}

void MyRunAction::BeginOfRunAction(const G4Run*)
{
  G4AnalysisManager *man = G4AnalysisManager::Instance();

  man->OpenFile("output.root");

  man->CreateNtuple("Hits", "Hits");
  man->CreateNtupleIColumn("fEvent"); // event number
  man->CreateNtupleDColumn("fX"); // x coordinate of the detector
  man->CreateNtupleDColumn("fY"); // y
  man->CreateNtupleDColumn("fZ"); // z
  man->FinishNtuple(0);
}

void MyRunAction::EndOfRunAction(const G4Run*)
{
  G4AnalysisManager *man = G4AnalysisManager::Instance();

  man->Write();
  man->CloseFile();
}
