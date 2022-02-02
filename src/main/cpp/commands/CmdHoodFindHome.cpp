#include "commands/CmdHoodFindHome.h"
#include <iostream>
CmdHoodFindHome::CmdHoodFindHome(Shooter *shooter) 
{
  m_shooter = shooter;
}


void CmdHoodFindHome::Initialize() 
{

}


void CmdHoodFindHome::Execute() 
{
  if(!m_shooter->GetBotHoodLimitSW())
  {
    m_shooter->SetHoodPower(HOOD_SLOW_POWER);
  }
  else if (m_shooter->GetBotHoodLimitSW())
  {
    m_shooter->SetHoodPower(0);
  }
}


void CmdHoodFindHome::End(bool interrupted) 
{
  std::cout<<"Hood Has Found Home"<<std::endl;
}


bool CmdHoodFindHome::IsFinished() {
  return false;
}
