#include "physics.hh"
#include "G4EmStandardPhysics.hh"
#include "G4OpticalPhysics.hh"

MyPhysicsList::MyPhysicsList()
{
	// the aim here is to produce Cerenkov effect
	// so we need two interactions
	// he advises to use only the physics that is required for your application
	// the more physics you implement the longer it takes for calculations
	RegisterPhysics (new G4EmStandardPhysics());
	RegisterPhysics (new G4OpticalPhysics());
}

MyPhysicsList::~MyPhysicsList()
{}
