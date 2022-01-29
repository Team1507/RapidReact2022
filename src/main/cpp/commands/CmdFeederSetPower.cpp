#include "commands/CmdFeederSetPower.h"

CmdFeederSetPower::CmdFeederSetPower(Shooter *shooter ,Level level, double power) 
{
  m_shooter = shooter;
  m_power = power;
  m_level = level;
}

void CmdFeederSetPower::Initialize() 
{
  if(m_level == CmdFeederSetPower::Level::Top)
  {
    m_shooter->SetTopFeederPower(m_power);
  }
  else if(m_level == CmdFeederSetPower::Level::Bottom)
  {
    m_shooter->SetBottomFeederPower(m_power);
  }
}
