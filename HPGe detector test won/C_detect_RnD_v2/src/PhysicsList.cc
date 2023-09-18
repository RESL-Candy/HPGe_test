#include "PhysicsList.hh"
#include "G4EmStandardPhysics.hh"
#include "G4SystemOfUnits.hh"


#include "G4UnitsTable.hh"
#include "G4ParticleTypes.hh"
#include "G4IonConstructor.hh"
#include "G4PhysicsListHelper.hh"
#include "G4Radioactivation.hh"
#include "G4NuclideTable.hh"
#include "G4LossTableManager.hh"
#include "G4UAtomicDeexcitation.hh"
#include "G4NuclearLevelData.hh"
#include "G4DeexPrecoParameters.hh"
#include "G4NuclideTable.hh"

  /*
MyPhysicsList::MyPhysicsList()
{
  new FTFP_BERT;
  ReplacePhysics(new G4EmStandardPhysics_option4());
  //RegisterPhysics (new G4EmStandardPhysics());
  RegisterPhysics (new G4OpticalPhysics());
}

MyPhysicsList::~MyPhysicsList()
{
}
*/




MyPhysicsList::MyPhysicsList() : G4VModularPhysicsList() {
    SetDefaultCutValue(0.001 * m); // Set default cut value for production of secondary particles

    // Electromagnetic physics
    RegisterPhysics(new G4EmStandardPhysics());

    new FTFP_BERT;
    ReplacePhysics(new G4EmStandardPhysics_option4());
    //RegisterPhysics (new G4EmStandardPhysics());
    RegisterPhysics (new G4OpticalPhysics());



    // EM Physics
    RegisterPhysics( new G4EmStandardPhysics() );

    // Synchroton Radiation & GN Physics
    RegisterPhysics( new G4EmExtraPhysics() );
    // Decays
    RegisterPhysics( new G4DecayPhysics() );

    // Hadron physics
    RegisterPhysics( new G4HadronElasticPhysicsXS() );
    RegisterPhysics( new G4StoppingPhysics() );
    RegisterPhysics( new G4IonBinaryCascadePhysics() );
    RegisterPhysics( new G4HadronInelasticQBBC());

    // Neutron tracking cut
    RegisterPhysics( new G4NeutronTrackingCut() );

}

MyPhysicsList::~MyPhysicsList()
{
}




/*
MyPhysicsList::MyPhysicsList()
: G4VUserPhysicsList()
{
  // mandatory for G4NuclideTable
  //
  G4NuclideTable::GetInstance()->SetThresholdOfHalfLife(0.1*picosecond);
  G4NuclideTable::GetInstance()->SetLevelTolerance(1.0*eV);

  //read new PhotonEvaporation data set 
  //
  G4DeexPrecoParameters* deex = 
    G4NuclearLevelData::GetInstance()->GetParameters();
  deex->SetCorrelatedGamma(false);
  deex->SetStoreAllLevels(true);
  deex->SetIsomerProduction(true);  
  deex->SetMaxLifeTime(G4NuclideTable::GetInstance()->GetThresholdOfHalfLife()
                /std::log(2.));
}


MyPhysicsList::~MyPhysicsList()
{
}

void MyPhysicsList::ConstructParticle()
{
  // pseudo-particles
  G4Geantino::GeantinoDefinition();
  
  // gamma
  G4Gamma::GammaDefinition();

  // leptons
  G4Electron::ElectronDefinition();
  G4Positron::PositronDefinition();

  G4NeutrinoE::NeutrinoEDefinition();
  G4AntiNeutrinoE::AntiNeutrinoEDefinition();
  
  // baryons
  G4Proton::ProtonDefinition();
  G4Neutron::NeutronDefinition();  

  // ions
  G4IonConstructor iConstructor;
  iConstructor.ConstructParticle();  
}


void MyPhysicsList::ConstructProcess()
{
  AddTransportation();

  G4Radioactivation* radioactiveDecay = new G4Radioactivation();

  G4bool ARMflag = false;
  radioactiveDecay->SetARM(ARMflag);        //Atomic Rearangement

  // need to initialize atomic deexcitation
  //
  G4LossTableManager* man = G4LossTableManager::Instance();
  G4VAtomDeexcitation* deex = man->AtomDeexcitation();
  if (!deex) {
     ///G4EmParameters::Instance()->SetFluo(true);
     G4EmParameters::Instance()->SetAugerCascade(ARMflag);
     G4EmParameters::Instance()->SetDeexcitationIgnoreCut(ARMflag);    
     deex = new G4UAtomicDeexcitation();
     deex->InitialiseAtomicDeexcitation();
     man->SetAtomDeexcitation(deex);
  }

  // register radioactiveDecay
  //
  G4PhysicsListHelper* ph = G4PhysicsListHelper::GetPhysicsListHelper();
  ph->RegisterProcess(radioactiveDecay, G4GenericIon::GenericIon());

  //printout
  //
  G4cout << "\n  Set atomic relaxation mode " << ARMflag << G4endl;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void MyPhysicsList::SetCuts()
{
  SetCutsWithDefault();
}

*/