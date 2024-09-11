#ifndef DETECTOR.HH
#define DETECTOR.HH
#include "G4VSensitiveDetector.hh"
#include "g4root.hh"

class MySensitiveDetector : public G4VSensitiveDetector
{
public:
  MySensitiveDetector(G4String);
  ~MySensitiveDetector();
private:
  virtual G4bool ProcessHits(G4Step *, G4TouchableHistory *);
};
#endif
