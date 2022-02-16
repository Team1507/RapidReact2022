#include "commands/CmdFeederDefault.h"
#include <iostream>
CmdFeederDefault::CmdFeederDefault(Feeder *feeder, frc::XboxController *topDriver) 
{

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
    m_feeder->SetTopFeederPower(TOP_FEEDER_SHOOTING_POWER);
    m_feeder->SetBottomFeederPower(BOTTOM_FEEDER_SHOOTING_POWER);
    m_feeder->SetFeederOn(false);    //This is here to allow shooting and intake, ignore intake if shooter is on

}
  else if (ShootPressed == 0) // released 
  {
    m_feeder->SetTopFeederPower(0);
    m_feeder->SetBottomFeederPower(0);
  }
//*******************************************************
  //Y + LJ = Top Feeder Manual
  if(TopFeederActivate) 
  {
    m_topFeederPower = m_topDriver->GetRawAxis(GAMEPADMAP_AXIS_L_Y);
    m_feeder->SetTopFeederPower(m_topFeederPower);
  }
  else 
  
  //*******************************************************
  //A + LJ = Bottom Feeder Manual
  if(BottomFeederActivate) 
  {
    m_bottomFeederPower = m_topDriver->GetRawAxis(GAMEPADMAP_AXIS_L_Y);
    m_feeder->SetBottomFeederPower(m_bottomFeederPower);
  }
  else
  //*************************************************
  //Feeder State Machine
  if(m_feeder->GetFeederOn() && !m_feeder->GetTopFeederPhotoeye())
  {
    m_feeder->SetTopFeederPower(TOP_FEEDER_INTAKE_POWER);   
  }
  else if(m_feeder->GetFeederOn() && m_feeder->GetTopFeederPhotoeye())
  {
    m_feeder->SetTopFeederPower(0);
  }
  if(m_feeder->GetFeederOn() && !m_feeder->GetBotFeederPhotoeye())
  {
    m_feeder->SetBottomFeederPower(BOTTOM_FEEDER_INTAKE_POWER);
  }
  else if(m_feeder->GetFeederOn() && m_feeder->GetBotFeederPhotoeye() && m_feeder->GetTopFeederPhotoeye())
  {
    m_feeder->SetBottomFeederPower(0);
    m_feeder->SetTopFeederPower(0); //fail safe just in case
    m_feeder->SetFeederOn(false);
  }
}
void CmdFeederDefault::End(bool interrupted) 
{
    std::cout << "POOP!!!" << std::endl;
}


bool CmdFeederDefault::IsFinished() {
  return false;
}
