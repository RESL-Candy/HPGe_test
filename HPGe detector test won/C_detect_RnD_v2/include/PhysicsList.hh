#ifndef PHYSICS_h
#define PHYSICS_h

#include "G4VModularPhysicsList.hh"
#include "G4EmStandardPhysics.hh"
#include "G4OpticalPhysics.hh"
#include "G4EmstandardPhysics.hh"
#include "G4EmExtraPhysics.hh"
#include "G4HadronElasticPhysicsXS.hh"
#include "G4StoppingPhysics.hh"
#include "G4IonBinaryCascadePhysics.hh"
#include "G4HadronInelasticQBBC.hh"
#include "G4NeutronTrackingCut.hh"
#include "FTFP_BERT.hh"
#include "G4EmStandardPhysics_option4.hh"
#include "G4DecayPhysics.hh"
#include "G4VUserPhysicsList.hh"
#include "globals.hh"
class MyPhysicsList : public G4VModularPhysicsList
{
public:
  MyPhysicsList();
  ~MyPhysicsList() override;
//protected:
  //Construct particle and physics
  //virtual void ConstructParticle();
  //virtual void ConstructProcess(); 
  //virtual void SetCuts(); 

};

#endif
