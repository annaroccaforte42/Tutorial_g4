#ifndef GENERATOR_HH
#define GENERATOR_HH

#include "G4SystemOfUnits.hh"
#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4ParticleGun.hh"
#include "G4ParticleTable.hh"

class MyPrimaryGenerator : public G4VUserPrimaryGeneratorAction
{
	public:
    	MyPrimaryGenerator();
    	~MyPrimaryGenerator();

    	virtual void GeneratorPrimaries(G4Event*);
private:
	G4ParticleGun *fParticleGun;

};
#endif
