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
	
	G4Material *SiO2 = new G4Material("H2O",1.*g/cm3,2);
	H2O->AddElement(nist->FindOrBuildElement("H"),2);
	H2O->AddElement(nist->FindOrBuildElement("O"),1);

	G4Element *C = nist->FindOrBuildElement("C");

	G4Material *Aerogel = new G4Material("Aerogel", 0.200*g/cm3,3);
	Aerogel->AddMaterial(SiO2, 62.5%*perCent);
	Aerogel->AddMaterial(H2O, 37.4%*perCent);
	Aerogel->AddElement(C, 0.1%*perCent);

    	G4Material *worldMat =nist->FindOrBuildMaterial("G4_AIR");

    	G4Box *solidWorld =new  G4Box("solidWorld",0.5*m,0.5*m,0.5*m);

    	G4LogicalVolume *logicWorld = new G4LogicalVolume(solidWorld, worldMat, "logicWorld");
    	G4VPhysicalVolume *physWorld=new G4PVPlacement(0,G4ThreeVector(0.,0.,0.),logicWorld,
	 "physWorld",0,false,0,true);
    
	return physWorld;
}
