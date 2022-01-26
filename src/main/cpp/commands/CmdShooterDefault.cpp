#include "commands/CmdShooterDefault.h"

CmdShooterDefault::CmdShooterDefault(Shooter *shooter, frc::XboxController *topDriver) 
{
  m_shooter = shooter;
  m_topDriver = topDriver;
  AddRequirements(m_shooter);
}

void CmdShooterDefault::Initialize() {}

void CmdShooterDefault::Execute() 
{
  //*******************************************************
  //x = return to home
  if(m_topDriver->GetXButton())
  {
    m_shooter->SetTurretHome();
  }

  //*******************************************************
  //Lt = caculate all
  if(m_topDriver->GetLeftTriggerAxis())
  {
    //cmd caculate all
  }

  //*******************************************************
  //rt = shoot
  if(m_topDriver->GetRightTriggerAxis())
  {
    m_shooter->SetFeederPower(1.0);
  }
  else
  {
    m_shooter->SetFeederPower(0.5);//idle1
  }

  //*******************************************************
  //Dpad = set shooting velocities
  int DpadState = m_topDriver->GetPOV(0);
  static bool isDpadCenter = false;
  if(DpadState == -1)
  {
    isDpadCenter = true;
  }
  
  if(isDpadCenter)
  {
    switch(DpadState)
    {
      case 0:
        m_shooter->SetShooterRPM(0);//make a state
        m_shooter->SetHoodEncoder(0);//make a state
        m_shooter->SetTurretYaw(0);//make a state
        break;
      case 90:
        m_shooter->SetShooterRPM(0);//make a state
        m_shooter->SetHoodEncoder(0);//make a state
        m_shooter->SetTurretYaw(0);//make a state
        break;
      case 180:
        m_shooter->SetShooterRPM(0);//make a state
        m_shooter->SetHoodEncoder(0);//make a state
        m_shooter->SetTurretYaw(0);//make a state
        break;
      case 270:
        m_shooter->SetShooterRPM(0);//make a state
        m_shooter->SetHoodEncoder(0);//make a state
        m_shooter->SetTurretYaw(0);//make a state
        break;
    }
  }
  
}

void CmdShooterDefault::End(bool interrupted) {}

bool CmdShooterDefault::IsFinished() {
  return false;
}
