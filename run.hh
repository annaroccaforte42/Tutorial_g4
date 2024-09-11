#ifndef RUN_HH
#define RUN_HH
#INCLUDE "G4UserRunAction.hh"

class MyRunAction : public G4UserRunAction
{
public:
  MyRunAction();
  ~MyRunAction();

  virtual void BeginOfRunAction(const G4Run*);
  virtual void EndofRunAction(const G4Run*);
};
#endif
