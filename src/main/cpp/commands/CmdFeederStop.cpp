#include "commands/CmdFeederStop.h"

CmdFeederStop::CmdFeederStop(Feeder *feeder, Feeder::Level level) 
{
  m_level = level;
  m_feeder = feeder;
}

void CmdFeederStop::Initialize() 
{
  if(m_level == Feeder::Level::Top)
  {
    m_feeder->SetTopFeederPower(0.0);
  }
  else if(m_level == Feeder::Level::Bottom) 
  {
    m_feeder->SetBottomFeederPower(0.0);
  }
}
