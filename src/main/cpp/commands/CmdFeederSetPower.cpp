#include "commands/CmdFeederSetPower.h"

CmdFeederSetPower::CmdFeederSetPower(Feeder *feeder ,Feeder::Level level, double power) 
{
  m_feeder = feeder;
  m_power = power;
  m_level = level;
}

void CmdFeederSetPower::Initialize() 
{
  if(m_level == Feeder::Level::Top)
  {
    m_feeder->SetTopFeederPower(m_power);
  }
  else if(m_level == Feeder::Level::Bottom)
  {
    m_feeder->SetBottomFeederPower(m_power);
  }
}
