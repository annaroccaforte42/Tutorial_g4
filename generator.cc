#include "generator.hh"

MyPrimaryGenerator::MyPrimaryGenerator()
{
    fParticleGun = new G4ParticleGun(1);

}
MyPrimaryGenerator::~MyPrimaryGenerator()
{
    delete fParticleGun;
}

void MyPrimaryGenerator::GeneratePrimaries(G4Event *anEvent)
{
	G4cout << "MyPrimaryGenerator::GeneratePrimaries" << G4endl;
	G4ParticleTable *particleTable=G4ParticleTable::GetParticleTable();
	G4String particleName = "proton";
	G4ParticleDefinition *particle=particleTable->FindParticle("proton");
	

    G4ThreeVector pos(0.03*m,0.03*m,0.);//change beam position
	
    G4ThreeVector mom(0.,0.,1.);

    fParticleGun->SetParticlePosition(pos);
    fParticleGun->SetParticleMomentumDirection(mom);
    fParticleGun->SetParticleMomentum(100.*GeV);
    fParticleGun->SetParticleDefinition(particle);
    fParticleGun->GeneratePrimaryVertex(anEvent);
    G4cout << "MyPrimaryGenerator::GeneratePrimaries:fine" << G4endl;
}
