#include "commands/CmdFeederStop.h"

CmdFeederStop::CmdFeederStop(Shooter *shooter, Level level) 
{
  m_level = level;
  m_shooter = shooter;
}

void CmdFeederStop::Initialize() 
{
  if(m_level == Top)
  {
    m_shooter->SetTopFeederPower(0.0);
  }
  else if(m_level == Bottom) 
  {
    m_shooter->SetBottomFeederPower(0.0);
  }
}
