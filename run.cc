#include "run.hh"

MyRunAction::MyRunAction()
{
  G4AnalysisManager *man = G4AnalysisManager::Instance();
  man->CreateNtuple("Hits", "Hits");
  man->CreateNtupleIColumn("fEvent"); // event number
  man->CreateNtupleDColumn("fX"); // x coordinate of the detector
  man->CreateNtupleDColumn("fY"); // y
  man->CreateNtupleDColumn("fZ"); // z
  man->FinishNtuple(0);
}

MyRunAction::~MyRunAction()
{}

void MyRunAction::BeginOfRunAction(const G4Run*)
{
  G4AnalysisManager *man = G4AnalysisManager::Instance();
  G4int runNumber = run->GetRunID();
  std::stringstream strRunID;
  strRunID<<runID;
  man->OpenFile("output.root"+strRunID.str()+".root");


}

void MyRunAction::EndOfRunAction(const G4Run*)
{
  G4AnalysisManager *man = G4AnalysisManager::Instance();

  man->Write();
  man->CloseFile();
}
