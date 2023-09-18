#include "SteppingAction.hh"


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

SteppingAction::SteppingAction(EventAction* eventAction)
: fEventAction(eventAction)
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

SteppingAction::~SteppingAction()
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
// collect energy deposited in this step
//G4double edepStep = step->GetTotalEnergyDeposit();
//aStep->GetTrack()->GetParentID() == 1 /양전자 조건
//aStep->GetTrack()->GetParentID() != 1 /양전자 아닌 조건


void SteppingAction::UserSteppingAction(const G4Step* aStep)
{  
  if (!fGeDeVolume) {
    const MyDetectorConstruction* detConstruction
      = static_cast<const MyDetectorConstruction*>
      (G4RunManager::GetRunManager()->GetUserDetectorConstruction());

    fGeDeVolume = detConstruction->GetGeDeVolume();
  }
  //G4cout<<aStep->GetPreStepPoint()->GetTouchableHandle()->GetVolume()->GetLogicalVolume() << G4endl;
  // get analysis manager
  //G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();
  //G4double totalEnergyDeposited = 0.0;
  G4LogicalVolume* volume = aStep->GetPreStepPoint()->GetTouchableHandle()->GetVolume()->GetLogicalVolume();
  //copyNoGe = aStep->GetPreStepPoint()->GetTouchableHandle()->GetVolume()->GetLogicalVolume()->GetCopyNo();
  if (volume != fGeDeVolume){
    return;
  }
  fEventAction->AddCount_TDE(aStep->GetTotalEnergyDeposit());
  //G4cout <<"원성준 바보 똥꾸멍" << aStep->GetTotalEnergyDeposit() << G4endl;

    //  analysisManager->FillNtupleDColumn(1, totalEnergyDeposited)
    //fEventAction->AddCount_depositenergy(fEventAction->fDepositenergys,fDepositenergyfin);
    //if(aStep->GetPreStepPoint()->GetTouchableHandle()->GetVolume()->GetLogicalVolume()==fGeDeVolume && aStep->GetPostStepPoint()->GetTouchableHandle()->GetVolume()->GetLogicalVolume()!=fGeDeVolume){
      //aStep->GetTrack()->SetTrackStatus(fStopAndKill)
    
  

  //    fEventAction->AddCount_TDE(5);
  
 // G4cout <<"원성준 바보 똥꾸멍" << aStep->GetTotalEnergyDeposit() << G4endl;
     
/*

// Declare a variable to accumulate energy deposition
G4double totalEnergyDeposited = 0.0;

const G4StepVector* stepVector = track->GetStepVector();

// Loop over all steps of the current track
for (size_t iStep = 0; iStep < stepVector->size(); ++iStep) {
    G4Step* step = (*stepVector)[iStep];
    G4LogicalVolume* currentVolume = step->GetPreStepPoint()->GetTouchableHandle()->GetVolume()->GetLogicalVolume();

    if (currentVolume == fGeDeVolume) {
        totalEnergyDeposited += step->GetTotalEnergyDeposit();
    }
}

// After looping through all steps, if any energy was deposited, store it in the ntuple
if (totalEnergyDeposited > 0.0) {
    analysisManager->FillNtupleDColumn(1, totalEnergyDeposited);
}

*/

  
  


/*
      analysisManager->FillNtupleDColumn(2,  aStep->GetPreStepPoint()->GetPosition().x()/cm);
      analysisManager->FillNtupleDColumn(3,  aStep->GetPreStepPoint()->GetPosition().y()/cm);
      analysisManager->FillNtupleDColumn(4,  aStep->GetPreStepPoint()->GetPosition().z()/cm);

      analysisManager->FillNtupleDColumn(5, aStep->GetPreStepPoint()->GetMomentumDirection().x());
      analysisManager->FillNtupleDColumn(6, aStep->GetPreStepPoint()->GetMomentumDirection().y());
      analysisManager->FillNtupleDColumn(7, aStep->GetPreStepPoint()->GetMomentumDirection().z());
*/
/*
  if (aStep->GetTrack()->GetParticleDefinition()->GetParticleName() == "gamma"){
    if(aStep->GetTrack()->GetCurrentStepNumber() == 1){
      fEventAction->AddCount_Whole(1);
      if(aStep->GetTrack()->GetParentID() == 1){
        fEventAction->AddCount_gamma(1);
      }
      else {
        fEventAction->AddCount_notgamma(1);
      }
    }
  }
  */
  // get volume of the current step

  // check if we are in scoring volume
  //if (volume != fGeDeVolume ){
  //  return;
  //  } 




  //G4int copyNo = 0;

  ///////////////////////////////////////////////////////////////////////////////////////////
  ///////////////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////SiPM scoring/////////////////////////////////////////
  //
  /*
  if (aStep->GetTrack()->GetParticleDefinition()->GetParticleName() == "opticalphoton"){
    if (volume == fSiPMScoringVolume){
      //if(aStep->GetTrack()->GetParentID() == 1){
        copyNo = aStep->GetPreStepPoint()->GetTouchableHandle()
        ->GetVolume()->GetCopyNo();  
        // fill ntuple
        fEventAction->AddCount_SiPM(fEventAction->f_SiPM_Count, copyNo);
        fEventAction->AddCount_Whole_SiPM(1);
        //analysisManager->FillNtupleDColumn(copyNo+12,  1);
        aStep->GetTrack()->SetTrackStatus(fStopAndKill);        
      //}
    }
    else if (volume == fOpticalVolume){
        //copyNo = aStep->GetPreStepPoint()->GetTouchableHandle()
        //->GetVolume()->GetCopyNo();  
        //fEventAction->AddCount_SiPM(fEventAction->f_SiPM_Count, copyNo);
        //aStep->GetTrack()->SetTrackStatus(fStopAndKill);        
      //}
    }
  ///////////////////////////////////////////////////////////////////////////////////////////
  ///////////////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////PMT scoring//////////////////////////////////////////
  //
    else if (volume == fPMTScoringVolume){
      copyNo = aStep->GetPreStepPoint()->GetTouchableHandle()
      ->GetVolume()->GetCopyNo();  
      fEventAction->AddCount_PMT(fEventAction->f_PMT_Count, copyNo);
      // fill ntuple
      //analysisManager->FillNtupleDColumn(copyNo+10,  1);
      aStep->GetTrack()->SetTrackStatus(fStopAndKill);
    }
  
  
  
  }
  */
}
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
