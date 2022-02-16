#include "commands/CmdTurretFindHome.h"

CmdTurretFindHome::CmdTurretFindHome(Shooter *shooter) 
{

m_shooter = shooter;
AddRequirements(m_shooter);
}


void CmdTurretFindHome::Initialize() 
{
  m_shooter->SetTurretPower(0.3);

}

void CmdTurretFindHome::Execute() 
{
  if(m_shooter->GetLeftTurretLimitSW() || m_shooter->GetRightTurretLimitSW())
  {
    m_shooter->SetTurretPower(-0.3); 
  }
}


void CmdTurretFindHome::End(bool interrupted) 
{
 m_shooter->SetTurretPower(0.0);
 m_shooter->ResetTurretEncoder();
}


bool CmdTurretFindHome::IsFinished() 
{
  return m_shooter->GetTurretHomeSW();
  
}
