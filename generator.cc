#include "generator.hh"

MyPrimaryGenerator::MyPrimaryGenerator()
{
	// he wants 1 primary vertex per event
	fParticleGun = new G4ParticleGun(1);
}

MyPrimaryGenerator::~MyPrimaryGenerator()
{
	delete fParticleGun;
}

void MyPrimaryGenerator::GeneratePrimaries(G4Event *anEvent)
{
	// what kind of particles we want to create?
	// the properties of the particle we want is store in the following table
	G4ParticleTable *particleTable = G4ParticleTable::GetParticleTable();
	
	// for instance we want a proton
	G4String particleName = "proton";
	G4ParticleDefinition *particle = particleTable->FindParticle(particleName);
	
	// where the particle should be created
	G4ThreeVector pos(0.,0.,0.);
	
	// same for momentum, that is not momentum itself but rather direction
	G4ThreeVector mom(0.,0.,1.);
	
	fParticleGun->SetParticlePosition(pos);
	fParticleGun->SetParticleMomentumDirection(mom);
	fParticleGun->SetParticleMomentum(100.*GeV);
	fParticleGun->SetParticleDefinition(particle);
	
	// tell Geant4 to generate primary vertex and hand over the variable anEvent
	fParticleGun->GeneratePrimaryVertex(anEvent);
}
