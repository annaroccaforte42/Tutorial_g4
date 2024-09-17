#include "detector.hh"

MySensitiveDetector::MySensitiveDetector(G4String name) : G4VSensitiveDetector(name)
{
  //G4cout << "MySensitiveDetector::MySensitiveDetector" << G4endl;
}
MySensitiveDetector::~MySensitiveDetector()
{}

G4bool MySensitiveDetector::ProcessHits(G4Step *aStep, G4TouchableHistory *ROhist)
{
  //G4cout<<"MySensitiveDetector::ProcessHits"<<G4endl;
  //G4cout<<"MySensitiveDetector::ProcessHits::end"<<G4endl;
}
