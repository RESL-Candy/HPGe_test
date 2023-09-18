#include "PrimaryGeneratorAction.hh"

#include "G4Event.hh"
#include "G4IonTable.hh"
#include "G4Geantino.hh"
#include "G4LogicalVolumeStore.hh"
#include "G4LogicalVolume.hh"
#include "G4Box.hh"
#include "G4RunManager.hh"
#include "G4GeneralParticleSource.hh"
#include "G4ParticleTable.hh"
#include "G4ParticleDefinition.hh"
#include "G4SystemOfUnits.hh"
#include "Randomize.hh"

/*
PrimaryGeneratorAction::PrimaryGeneratorAction()
    : G4VUserPrimaryGeneratorAction(), fCurrentEnergyIndex(0)
{
  G4int nofParticles = 1;
  fParticleGun = new G4ParticleGun(nofParticles);

  // default particle kinematic

  G4String particle_name = "gamma";
  G4ParticleDefinition* particleDefinition
    = G4ParticleTable::GetParticleTable()->FindParticle(particle_name);
  fParticleGun->SetParticleDefinition(particleDefinition);

// Initialize the current energy index to 0
    fCurrentEnergyIndex = 0;
}

PrimaryGeneratorAction::~PrimaryGeneratorAction()
{
    delete fParticleGun;
}

void PrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent)
{
  // Array of gamma ray energies: 1.17 MeV and 1.33 MeV
  G4double gammaEnergies[] = {1.17 * MeV, 1.33 * MeV};

  // Select the energy based on the current index
  G4double currentEnergy = gammaEnergies[fCurrentEnergyIndex];
    

  fParticleGun->SetParticleEnergy(currentEnergy);
  fParticleGun->SetParticlePosition(G4ThreeVector(0.,1.0*m,0.));
  fParticleGun->SetParticleMomentumDirection(G4ThreeVector(0., -1.0, 0.));
  fParticleGun->GeneratePrimaryVertex(anEvent);
  
  // Update the energy index for the next event
  fCurrentEnergyIndex = (fCurrentEnergyIndex + 1) % 2;
}

*/




PrimaryGeneratorAction::PrimaryGeneratorAction()
 : G4VUserPrimaryGeneratorAction(),
   fParticleGun(0)
{
  G4int n_particle = 1;
  fParticleGun  = new G4ParticleGun(n_particle);

  fParticleGun->SetParticleEnergy(0*eV);
  fParticleGun->SetParticlePosition(G4ThreeVector(0.,0.,500.));
  fParticleGun->SetParticleMomentumDirection(G4ThreeVector(1.,0.,0.));          
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

PrimaryGeneratorAction::~PrimaryGeneratorAction()
{
  delete fParticleGun;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void PrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent)
{
  if (fParticleGun->GetParticleDefinition() == G4Geantino::Geantino()) {  
    G4int Z = 10, A = 24;
    G4double ionCharge   = 0.*eplus;
    G4double excitEnergy = 0.*keV;
    
    G4ParticleDefinition* ion
       = G4IonTable::GetIonTable()->GetIon(Z,A,excitEnergy);
    fParticleGun->SetParticleDefinition(ion);
    fParticleGun->SetParticleCharge(ionCharge);
  }    
  //create vertex
  //   
  fParticleGun->GeneratePrimaryVertex(anEvent);
}
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......











/*
PrimaryGeneratorAction::PrimaryGeneratorAction()
: G4VUserPrimaryGeneratorAction()
{
  fParticleGun = new G4GeneralParticleSource();
}

PrimaryGeneratorAction::~PrimaryGeneratorAction()
{
  delete fParticleGun;
}

void PrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent)
{
  //this function is called at the begining of each event

  fParticleGun -> GeneratePrimaryVertex(anEvent);
}

*/