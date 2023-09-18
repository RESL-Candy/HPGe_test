#include "Construction.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

MyDetectorConstruction::MyDetectorConstruction()
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

MyDetectorConstruction::~MyDetectorConstruction()
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
G4VPhysicalVolume* MyDetectorConstruction::Construct()
{
  //////////////////   materials   //////////////////////////
  //
  //
  /////complete material////
  //
  G4NistManager *nist = G4NistManager::Instance();
  G4Material* Mat_Air = nist->FindOrBuildMaterial("G4_AIR");
  G4Material* Mat_Teflon = nist->FindOrBuildMaterial("G4_TEFLON"); 
  G4Material* Mat_AL = nist->FindOrBuildMaterial("G4_Al");
  G4Material* Mat_germanium = nist->FindOrBuildMaterial("G4_Ge");
  //
  //G4bool checkovelaps = true;

  
  G4Random::setTheSeed(42);


  /*
  /////Compound material (need to compound)///
  //
  // Define the elements that make up LAB
  G4Element* El_C = nist->FindOrBuildElement("C");
  G4Element* El_H = nist->FindOrBuildElement("H");

  ////Define the chemical formula for LAB and densities of its constituents///
  //
  fMat_LAB = new G4Material("LAB", 0.853*g/cm3, 2);
  fMat_LAB->AddElement(El_C, 18);
  fMat_LAB->AddElement(El_H, 30);
  //
  ///////////////Define LAB's scintillation properties/////////// 
  //
  std::vector<G4double> lab_Energy = { 2.67 * eV, 2.92 * eV, 3.26 * eV };
  std::vector<G4double> lab_SCINT = { 0.25, 0.5 , 1.0 };//emission rate
  std::vector<G4double> lab_RIND  = { 1.52, 1.53, 1.55 };
  std::vector<G4double> lab_ABSL  = { 1000. * cm, 1000. * cm, 1000. * cm };
  fmat_Prop_table_LAB = new G4MaterialPropertiesTable();
  fmat_Prop_table_LAB->AddProperty("SCINTILLATIONCOMPONENT1", lab_Energy, lab_SCINT);//emission rate 
  // fmat_Prop_table_LAB->AddProperty("SCINTILLATIONCOMPONENT2", lab_Energy, lab_SCINT);
  fmat_Prop_table_LAB->AddProperty("RINDEX", lab_Energy, lab_RIND);
  fmat_Prop_table_LAB->AddProperty("ABSLENGTH", lab_Energy, lab_ABSL);
  fmat_Prop_table_LAB->AddConstProperty("SCINTILLATIONYIELD", 12000. / MeV);
  fmat_Prop_table_LAB->AddConstProperty("RESOLUTIONSCALE", 1.0);
  fmat_Prop_table_LAB->AddConstProperty("SCINTILLATIONTIMECONSTANT1", 20. * ns);

  fMat_LAB->SetMaterialPropertiesTable(fmat_Prop_table_LAB);

  fMat_LAB->GetIonisation()->SetBirksConstant(0.151 * mm / MeV);
*/
  ////////////////////////////////////////////////////////////////
  ////////////////////////////////////////////////////////////////
  //////////////////  Detector Define   //////////////////////////
  //
  //

  // Option to switch on/off checking of volumes overlaps
  //
  G4bool checkOverlaps = true;

  
  ///////////// World /////////////////
  //
  //
  G4double world_Size = 4. * m;
  
  G4Box* solide_World = new G4Box("Worldsol",                            //its name
			       world_Size,                        //its size
			       world_Size,
			       world_Size);
  
  G4LogicalVolume* logical_World = new G4LogicalVolume(solide_World,  //its solid
						       Mat_Air,       //its material
						       "Worldlog");      //its name
  
  G4VPhysicalVolume* Phys_World = new G4PVPlacement(0,                //no rotation
						    G4ThreeVector(),  //at (0,0,0)
						    logical_World,    //its logical volume
						    "Worldphy",       //its name
  						    0,                //its mother  volume
						    false,            //no boolean operation
						    0,                //copy number
						    checkOverlaps);   //overlaps checking


  
///////////////////////////////////////////////////////////////////////////////////////////
///////////////HPGe detector caps///////
/////////////////////////////////////

  // Material surrounding the crystal

G4double zero = 0*m;
G4double CapRadius = 0.06 *m;
G4double Capheight = 0.3 *m;

G4Tubs* CapSol = new G4Tubs("CapSol",
                            zero,
                            CapRadius,
                            .5 * Capheight,
                            0.,
                            2. *M_PI);

G4LogicalVolume* CapLog = new G4LogicalVolume(CapSol,
                            Mat_AL,
                            "Caplog");

G4VPhysicalVolume* CapPhys = new G4PVPlacement(0,
                                                     G4ThreeVector(0,0,0),
                                                     CapLog,
                                                     "CapPhys",
                                                     logical_World,
                                                     false,
                                                     0,
                                                     checkOverlaps);

  /////////////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////////////
  //
  ////// HPGe detector Germanium Crystal/////
  G4double Radius = 0.05 * m;
  G4double innerRadius = 0.02 * m;
  G4double upheight = 0.05 * m;
  G4double downheight = 0.15 * m;
  
  /*
  G4Tubs* GeCrystalupSol = new G4Tubs("GeCrystalupsol",
				 zero,
				 Radius,
				 .5 * upheight,
				 0.,         //tub 에서 시작 각도 
				 2. * M_PI); //끝 각도

  G4Tubs* GeCrystaldownSol = new G4Tubs("GeCrystaldownsol",
          innerRadius,
          Radius,
          .5 * downheight,
          0.,
          2. *M_PI);

  G4UnionSolid* GeCrystalSol = new G4UnionSolid("UnionGeCrystalSol",
               GeCrystalupSol,
               GeCrystaldownSol,
               0,
               G4ThreeVector(0,0,-0.1*m));
  
  */

  G4Tubs* GeCrystalSol = new G4Tubs("GeCrystalSol",
                                      0,
                                      Radius,
                                      0.5*(upheight+downheight),
                                      0.,
                                      2. * M_PI);

  fGeCrystalLog = new G4LogicalVolume(GeCrystalSol,
                Mat_germanium,
                "GeCrystallog");

 new G4PVPlacement(0,
                G4ThreeVector(0,0,0.0*m),
                fGeCrystalLog,
                "GeCrystalPhys",
                CapLog,
                false,
                0,
                checkOverlaps);


  /////////////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////////////
  ////////////////////////////Detector Color define//////////////////////////////////

  //Ge Crystal
  G4Colour transgreen (0.0,0.75, 0.0, 0.3); 
  G4VisAttributes* Vis_1 = new G4VisAttributes(transgreen);
  Vis_1->SetVisibility(true);
  Vis_1->SetForceSolid(true);

  //Cap
  G4Colour transGrey (0.5, 0.5, 0.5, 0.3);
  G4VisAttributes* Vis_2 = new G4VisAttributes(transGrey);
  Vis_2->SetVisibility(true);
  Vis_2->SetForceSolid(true);

  fGeCrystalLog ->SetVisAttributes(Vis_1);
  CapLog -> SetVisAttributes(Vis_2);


  /////////////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////////////
  ///////////////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////Surface define////////////////////////////////////
  //
  //
  //
  //
  //
  //////Define Teflon surface/////////////
  //

  /*   //Geant4 Application manual의 Listing 73에 dielectric_dielectric의 경우가 적혀있음
  //또한 teflon의 material property 또한 지정해줘야함.
  //그래서 LUT모델을 씀.
  std::vector<G4double> ephoton = { 2.67 * eV, 2.92 * eV, 3.26 * eV }; //입사에너지
  std::vector<G4double> reflectivity = { 1.0, 1.0, 1.0 }; //반사비율
  std::vector<G4double> efficiency = { 0.0, 0.0, 0.0 }; //투과율
  G4MaterialPropertiesTable* Teflon_Surface = new G4MaterialPropertiesTable();
  Teflon_Surface->AddProperty("REFLECTIVITY", ephoton, reflectivity);
  Teflon_Surface->AddProperty("EFFICIENCY", ephoton, efficiency);
  */




  /*
  G4OpticalSurface* Tef_roughSurf = new G4OpticalSurface("tef_roughSurf");
  Tef_roughSurf->SetType(dielectric_LUTDAVIS); //이거 하면 LUT를 사용하여 데이터를 갖고와서 씀. 
  Tef_roughSurf->SetModel(DAVIS);// LUT DAVIS 모델은 DAVIS 고정
  Tef_roughSurf->SetFinish(RoughTeflon_LUT);//이거 다른 세팅이면 반사가 안됨. --> 해결!  

  new G4LogicalBorderSurface("tef_roughSurf",
			     Union_LS_Phys, teflonPhy,
			     Tef_roughSurf);

*/







  
  logical_World->SetVisAttributes(G4VisAttributes::GetInvisible());//world 안보이게 함 
  
  return Phys_World;
  
}

