#include "detector.hh"

MySensitiveDetector::MySensitiveDetector(G4String name) : G4VSensitiveDetector(name)
{
  G4cout << "MySensitiveDetector::MySensitiveDetector" << G4endl;
}
MySensitiveDetector::~MySensitiveDetector()
{}

G4bool MySensitiveDetector::ProcessHits(G4Step *aStep, G4TouchableHistory *ROhist)
{
  G4cout<<"MySensitiveDetector::ProcessHits"<<G4endl;
  G4Track *track = aStep->GetTrack();
if (!track)
  G4cout << "no track" << G4endl;
else
{
  track->SetTrackStatus(fStopAndKill);

  G4StepPoint *preStepPoint = aStep->GetPreStepPoint();
  G4StepPoint *postStepPoint = aStep->GetPostStepPoint();

  G4ThreeVector posPhoton = preStepPoint->GetPosition();

  //G4cout << "Photon position: "<<posPhoton << G4endl;

  const G4VTouchable *touchable = aStep->GetPreStepPoint()->GetTouchable();
  if (!touchable)
    G4cout << "no touchable" << G4endl;
  else
  {
  G4int copyNo = touchable->GetCopyNumber();

  //G4cout<<"Copy number " << copyNo <<G4endl;

  G4VPhysicalVolume *physVol = touchable->GetVolume();
    if (!physVol)
      G4cout << "no phys vol" << G4endl;
    else
    {
  G4ThreeVector posDetector = physVol->GetTranslation();

  G4cout<<"Detector position: "<<posDetector<<G4endl;

  G4int evt = G4RunManager::GetRunManager()->GetCurrentEvent()->GetEventID();

  G4AnalysisManager *man = G4AnalysisManager::Instance();
  man->FillNtupleIColumn(0,evt);
  man->FillNtupleDColumn(1,posDetector[0]);
  man->FillNtupleDColumn(2,posDetector[1]);
  man->FillNtupleDColumn(3,posDetector[2]);
  man->AddNtupleRow(0);
    }
  }
}
  G4cout<<"MySensitiveDetector::ProcessHits::end"<<G4endl;
}
