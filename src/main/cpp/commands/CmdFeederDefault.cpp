#include "commands/CmdFeederDefault.h"
#include <iostream>
#include "frc/smartdashboard/SmartDashboard.h"
CmdFeederDefault::CmdFeederDefault(Feeder *feeder, frc::XboxController *topDriver) 
{
  m_feeder = feeder;
  m_topDriver = topDriver;
  m_isManualOn = false;
  AddRequirements({m_feeder});
}

// Called when the command is initially scheduled.
void CmdFeederDefault::Initialize() {}

void CmdFeederDefault::Execute() 
{
  bool TopFeederActivate = m_topDriver->GetYButton();
  bool BottomFeederActivate = m_topDriver->GetAButton();
  bool ShootPressed = m_topDriver->GetRawAxis(GAMEPADMAP_AXIS_R_TRIG);
//*******************************************************
  //rt = shoot
  if(ShootPressed == 1) // pressed
  {
    double topFeederPower = frc::SmartDashboard::GetNumber("FEEDER_TOP_SHOOT_POWER", 0);
    double bottomFeederPower = frc::SmartDashboard::GetNumber("FEEDER_BOTTOM_SHOOT_POWER", 0);
    m_feeder->SetTopFeederPower(topFeederPower);
    m_feeder->SetBottomFeederPower(bottomFeederPower);
    m_feeder->SetFeederOn(false); 
    m_isManualOn = true;
    //This is here to allow shooting and intake, ignore intake if shooter is on

}
  else if ((ShootPressed == 0) && (m_isManualOn == false)) // released 
  {
    m_feeder->SetTopFeederPower(0);
    m_feeder->SetBottomFeederPower(0);
    //std::cout<<"Feeder Stopped after shot"<<std::endl;
  }
//*******************************************************
  //Y + LJ = Top Feeder Manual
  if(TopFeederActivate) 
  {
    m_topFeederPower = -m_topDriver->GetRawAxis(GAMEPADMAP_AXIS_L_Y);
    std::cout<<m_topFeederPower<<std::endl;
    m_feeder->SetTopFeederPower(m_topFeederPower);
    m_isManualOn = true;
    std::cout<<"Top Feeder Manual"<<std::endl;
  }
  else 
  
  //*******************************************************
  //A + LJ = Bottom Feeder Manual
  if(BottomFeederActivate) 
  {
    m_bottomFeederPower = m_topDriver->GetRawAxis(GAMEPADMAP_AXIS_L_Y);
    m_feeder->SetBottomFeederPower(m_bottomFeederPower);
    m_isManualOn = true;
  }
  else
  //*************************************************
  //Feeder State Machine
  if(m_feeder->GetFeederOn() && !m_feeder->GetTopFeederPhotoeye())
  {
    double topFeederIntakePower = frc::SmartDashboard::GetNumber("TOP_FEEDER_INTAKE_POWER", 0);
    m_feeder->SetTopFeederPower(topFeederIntakePower);   
  }
  else if(m_feeder->GetFeederOn() && m_feeder->GetTopFeederPhotoeye())
  {
    m_feeder->SetTopFeederPower(0);
  }
  if(m_feeder->GetFeederOn() && !m_feeder->GetBotFeederPhotoeye())
  {
    double bottomFeederIntakePower = frc::SmartDashboard::GetNumber("BOTTOM_FEEDER_INTAKE_POWER", 0);
    m_feeder->SetBottomFeederPower(bottomFeederIntakePower);
  }
  else if(m_feeder->GetFeederOn() && m_feeder->GetBotFeederPhotoeye() && !m_feeder->GetTopFeederPhotoeye())
  {
    double bottomFeederIntakePower = frc::SmartDashboard::GetNumber("BOTTOM_FEEDER_INTAKE_POWER", 0);
    m_feeder->SetBottomFeederPower(bottomFeederIntakePower);
  }
  else if(m_feeder->GetFeederOn() && m_feeder->GetBotFeederPhotoeye() && m_feeder->GetTopFeederPhotoeye())
  {
    m_feeder->SetBottomFeederPower(0);
    m_feeder->SetTopFeederPower(0); //fail safe just in case
    m_feeder->SetFeederOn(false);
  }

  if(m_topDriver->GetStartButton()) //a way to turn the feeder off cause rn we dont have a way unless we shoot or recieve 2 balls
  {
    m_feeder->SetBottomFeederPower(0.0);
    m_feeder->SetTopFeederPower(0.0);
    m_feeder->SetFeederOn(false);
  }
}
void CmdFeederDefault::End(bool interrupted) 
{
  //std::cout << "POOP!!!" << std::endl;
}


bool CmdFeederDefault::IsFinished() {
  return false;
}
