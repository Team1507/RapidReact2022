#include "commands/CmdFeederSetPower.h"

#include <iostream>

CmdFeederSetPower::CmdFeederSetPower(Feeder *feeder ,Feeder::Level level, double power) 
{
  m_feeder = feeder;
  m_power = power;
  m_level = level;
}

void CmdFeederSetPower::Initialize() 
{

  std::cout << "CmdFeederSetPower = " << m_level << " " << m_power << std::endl;


  if(m_level == Feeder::Level::Top)
  {
    m_feeder->SetTopFeederPower(m_power);
  }
  else if(m_level == Feeder::Level::Bottom)
  {
    m_feeder->SetBottomFeederPower(m_power);
  }
}
