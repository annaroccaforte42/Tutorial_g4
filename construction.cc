#include "construction.hh"

MyDetectorConstruction::MyDetectorConstruction()
{
	fMessenger = new G4GenericMessenger(this,"/detector/","Detector Construction");

	fMessenger->DeclareProperty("nCols",nCols,"Number of columns");
	fMessenger->DeclareProperty("nRows",nRows,"Number of rows");
	nCols=100;
	nRows=100;

}

MyDetectorConstruction::~MyDetectorConstruction()
{}

G4VPhysicalVolume* MyDetectorConstruction::Construct()
{
	G4NistManager *nist = G4NistManager::Instance();

	G4Material *SiO2 = new G4Material("SiO2", 2.201*g/cm3, 2);
	SiO2->AddElement(nist->FindOrBuildElement("Si"), 1);
	SiO2->AddElement(nist->FindOrBuildElement("O"), 2);

	G4Material *H2O = new G4Material("H2O", 1.000*g/cm3, 2);
	H2O->AddElement(nist->FindOrBuildElement("H"), 2);
	H2O->AddElement(nist->FindOrBuildElement("O"), 1);

	G4Element *C = nist->FindOrBuildElement("C");

	G4Material *Aerogel = new G4Material("Aerogel", 0.200*g/cm3, 3);
	Aerogel->AddMaterial(SiO2, 62.5*perCent);
	Aerogel->AddMaterial(H2O, 27.4*perCent);
	Aerogel->AddElement(C, 0.1*perCent);

	G4double energy[2] = {1.2398*eV*um/0.2/um, 1.2398*eV*um/0.9/um};
	G4double rindexAerogel[2] = {1.1, 1.1};
	G4double rindexWorld[2] = {1.0, 1.0};

	G4MaterialPropertiesTable *mptAerogel = new G4MaterialPropertiesTable();
	mptAerogel->AddProperty("RINDEX", energy, rindexAerogel, 2);

	Aerogel->SetMaterialPropertiesTable(mptAerogel);

	G4Material *worldMat = nist->FindOrBuildMaterial("G4_AIR");

	G4MaterialPropertiesTable *mptWorld = new G4MaterialPropertiesTable();
	mptWorld->AddProperty("RINDEX", energy, rindexWorld, 2);

	worldMat->SetMaterialPropertiesTable(mptWorld);

	G4double xWorld = 0.5*m;
	G4double yWorld = 0.5*m;
	G4double zWorld = 0.5*m;

	solidWorld = new G4Box("solidWorld", xWorld,yWorld,zWorld);

	logicWorld = new G4LogicalVolume(solidWorld, worldMat, "logicWorld");

	physWorld = new G4PVPlacement(0, G4ThreeVector(0., 0., 0.), logicWorld, "PhysWorld", 0, false, 0, true);

	solidRadiator = new G4Box("solidRadiator", .4*m, .4*m, .01*m);

	logicRadiator = new G4LogicalVolume(solidRadiator, Aerogel, "logicRadiator");

	physRadiator = new G4PVPlacement(0, G4ThreeVector(.0, .0, .25*m), logicRadiator, "physRadiator", logicWorld, false, 0, true);

	solidDetector = new G4Box("solidDetector", xWorld/nCols, yWorld/nRows, 0.01*m);

	logicDetector = new G4LogicalVolume(solidDetector, worldMat, "logicDetector");

	for(G4int i = 0; i < nRows; i++)
	{
		for(G4int j = 0; j < nCols; j++)
		{
			physDetector = new G4PVPlacement(0, 
			G4ThreeVector(-0.5*m + (i + 0.5)*m/nCols, -0.5*m + (j + 0.5)*m/nRows, 0.5*m - 0.01*m), 
			logicDetector, "physDetector", logicWorld, false, j + i*100, true);
		}
	}

	return physWorld;
}

void MyDetectorConstruction::ConstructSDandField()
{
	MySensitiveDetector *sensDet = new MySensitiveDetector("SensitiveDetector");

	logicDetector->SetSensitiveDetector(sensDet);
}
