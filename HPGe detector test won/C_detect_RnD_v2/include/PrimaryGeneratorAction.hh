//#ifndef PRIMARYGENERATORACTION_h
//#define PRIMARYGENERATORACTION_h

//#ifndef PRIMARYGENERATORACTION_HH
//#define PRIMARYGENERATORACTION_HH

#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4ParticleGun.hh"
#include "G4SystemOfUnits.hh"

#include "G4ParticleTable.hh"
#include "G4Gamma.hh"
#include "G4Alpha.hh"
#include "G4Electron.hh"
#include "G4Positron.hh"

#include "G4RandomTools.hh"

#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4ThreeVector.hh"
#include "G4Event.hh"
#include "G4ParticleGun.hh"
#include "G4ParticleDefinition.hh"
#include <vector>



#include "G4GeneralParticleSource.hh"
#include "G4Event.hh"
#include "globals.hh"

/*
class G4ParticleGun;

class PrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction
{
public:
  PrimaryGeneratorAction();
  ~PrimaryGeneratorAction() override;

  virtual void GeneratePrimaries(G4Event *) override;

  // method to access particle gun
  const G4ParticleGun* GetParticleGun() const { return fParticleGun; }

private:
    G4ParticleGun *fParticleGun;
    G4int fCurrentEnergyIndex;
};
*/








#ifndef PrimaryGeneratorAction_h
#define PrimaryGeneratorAction_h 1

#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4ParticleGun.hh"
#include "globals.hh"

class G4Event;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

class PrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction
{
  public:
    PrimaryGeneratorAction();    
   ~PrimaryGeneratorAction();

  public:
    virtual void GeneratePrimaries(G4Event*);
    G4ParticleGun* GetParticleGun() { return fParticleGun;} ;
            
  private:
    G4ParticleGun*  fParticleGun;
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif















/*
class PrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction
{
  public:
    PrimaryGeneratorAction();    
    virtual ~PrimaryGeneratorAction();
 
    // method from the base class
    virtual void GeneratePrimaries(G4Event*);         
 
  private:
    G4GeneralParticleSource* fParticleGun;
    

};

#endif
*/