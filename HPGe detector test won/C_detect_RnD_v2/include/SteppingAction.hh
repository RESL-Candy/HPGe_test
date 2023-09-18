#ifndef CANDYSteppingAction_h
#define CANDYSteppingAction_h 1


#include "EventAction.hh"
#include "Construction.hh"


#include "G4SystemOfUnits.hh"
#include "G4AnalysisManager.hh"


//#include "G4Track.hh"
#include "G4Step.hh"
#include "G4Event.hh"
#include "G4RunManager.hh"
#include "G4LogicalVolume.hh"
#include "G4UserSteppingAction.hh"



class SteppingAction : public G4UserSteppingAction
{
public:
  SteppingAction(EventAction* eventAction);
  ~SteppingAction() override;
  
  // method from the base class
  void UserSteppingAction(const G4Step*) override;
  
private:
  EventAction* fEventAction = nullptr;
  //EventAction* fDepositenergyfin = nullptr;
  //G4LogicalVolume* fSiPMScoringVolume = nullptr;
  //G4LogicalVolume* fPMTScoringVolume = nullptr;
  //G4LogicalVolume* fOpticalVolume = nullptr;
  G4LogicalVolume* fGeDeVolume = nullptr;
};


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif
