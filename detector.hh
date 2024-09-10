#inndef DETECTOR.HH
#define DETECTOR.HH

class MySensitiveDetector : public G4VSensitiveDetector
{
public:
  MySensitiveDetector(G4String);
  ~MySensitiveDetector();
private:
  virtual G4bool ProcessHits(G4Step *, G4TouchableHistory *);
}
#endif
