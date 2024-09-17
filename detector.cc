#include "detector.hh"

MySensitiveDetector::MySensitiveDetector(G4String name) : G4VSensitiveDetector(name)
{}

MySensitiveDetector::~MySensitiveDetector()
{}

G4bool MySensitiveDetector::ProcessHits(G4Step *aStep, G4TouchableHistory *ROhist)
{
  // we want information about the position of our photons

  // first we get the track from the step
  G4Track* track = aStep->GetTrack();

  track->SetTrackStatus(fStopAndKill);

  // we define 2 step points
  // there are only 2 steps for photons in the SD because they are not charged so they do not deposit energy
  // when the photon is entering the SD
  G4StepPoint *preStepPoint = aStep->GetPreStepPoint();
  // when the photon is leaving the SD
  G4StepPoint *postStepPoint = aStep->GetPostStepPoint();

  G4ThreeVector posPhoton = preStepPoint->GetPosition();

  // G4cout << "photon position: " << posPhoton << G4endl;
  // we do not have access to the real photon position in a real experiment
  // we only have access to the detector copy number

  const G4VTouchable *touchable = aStep->GetPreStepPoint()->GetTouchable();

  G4int copyNo = touchable->GetCopyNumber();

  G4cout << "copy number: " << copyNo << G4endl;

  // you can also have the position of the detector
  G4VPhysicalVolume *physVol = touchable->GetVolume();
  G4ThreeVector posDetector = physVol->GetTranslation();

  G4cout << "Detector position: " << posDetector << G4endl;

  // get the event number
  G4int evt = G4RunManager::GetRunManager()->GetCurrentEvent()->GetEventID();

  // store the information of the photon
  G4AnalysisManager *man = G4AnalysisManager::Instance();
  man->FillNtupleIColumn(0, evt);
  man->FillNtupleDColumn(1, posDetector[0]);
  man->FillNtupleDColumn(2, posDetector[1]);
  man->FillNtupleDColumn(3, posDetector[2]);
  man->AddNtupleRow(0);

  return true;
}
