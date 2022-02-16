#include "commands/CmdHoodFindHome.h"
#include <iostream>
CmdHoodFindHome::CmdHoodFindHome(Shooter *shooter) 
{
  m_shooter = shooter;
  AddRequirements(m_shooter);
}


void CmdHoodFindHome::Initialize() 
{
  m_shooter->SetHoodPower(HOOD_SLOW_POWER);
}


void CmdHoodFindHome::Execute() {}


void CmdHoodFindHome::End(bool interrupted) 
{
  std::cout<<"Hood Has Found Home"<<std::endl;
  m_shooter->ResetHoodEncoder();
  m_shooter->SetHoodPower(0.0);
}


bool CmdHoodFindHome::IsFinished() {
  return m_shooter->GetBotHoodLimitSW();
}
