#include "construction.hh"
MyDetectorConstruction :: MyDetectorConstruction()
{}
MyDetectorConstruction :: ~MyDetectorConstruction()
{}
G4VPhysicalVolume *MyDetectorConstruction::Construct(){
	G4NistManager *nist=G4NistManager::Instance();
    	
	G4Material *SiO2 = new G4Material("Si=O2",2.201*g/cm3,2);
	SiO2->AddElement(nist->FindOrBuildElement("Si"),1);
	SiO2->AddElement(nist->FindOrBuildElement("O"),2);

    	G4Material *worldMat =nist->FindOrBuildMaterial("G4_AIR");

    	G4Box *solidWorld =new  G4Box("solidWorld",0.5*m,0.5*m,0.5*m);

    	G4LogicalVolume *logicWorld = new G4LogicalVolume(solidWorld, worldMat, "logicWorld");
    	G4VPhysicalVolume *physWorld=new G4PVPlacement(0,G4ThreeVector(0.,0.,0.),logicWorld,
	 "physWorld",0,false,0,true);
    
	return physWorld;
}
