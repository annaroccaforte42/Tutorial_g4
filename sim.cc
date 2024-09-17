// c++ inclusions
#include <iostream>

// Geant4 inclusions
#include "G4RunManager.hh"
#include "G4UIExecutive.hh"
#include "G4UImanager.hh"
#include "G4VisManager.hh"
#include "G4VisExecutive.hh"

// my inclusions
#include "construction.hh"
#include "physics.hh"
#include "action.hh"
#include "generator.hh"

int main(int argc, char** argv)
{
	// the hearth of Geant is the G4RunManager, it takes care of everything
	G4RunManager *runManager = new G4RunManager();

	// everything that we want to add later we have to add to this runmanager
	runManager->SetUserInitialization(new MyDetectorConstruction());
	runManager->SetUserInitialization(new MyPhysicsList());
	runManager->SetUserInitialization(new MyActionInitialization());

	runManager->Initialize();
	// but you need detector, physics, track and step information

	// we need for user interface
	G4UIExecutive *ui = new G4UIExecutive(argc, argv);

	// we need visualization manager
	G4VisManager *visManager = new G4VisExecutive();

	// initialize the visualization manager
	visManager->Initialize();

	G4UImanager *UImanager = G4UImanager::GetUIpointer();

	// tell Geant4 to show the scene
	UImanager->ApplyCommand("/vis/open OGL");

	// decide the initial position of the detector
	UImanager->ApplyCommand("/vis/viewer/set/viewpointVector 1 1 1");

	// tell Geant4 to draw the volumes
	UImanager->ApplyCommand("/vis/drawVolume");

	// tell Geant4 to update every time it creates an event
	UImanager->ApplyCommand("/vis/viewer/set/autorefresh true");

	// tell Geant4 to draw the trajectories of the particles
	UImanager->ApplyCommand("/vis/scene/add/trajectories smooth");

	// tell Geant4 to draw all the events without deleting the previous ones
	UImanager->ApplyCommand("/vis/scene/endOfEventAction accumulate");

	// start the session from G4UIExecutive
	ui->SessionStart();

	return 0;
}
