#include "commands/CmdTopFeederStop.h"

CmdTopFeederStop::CmdTopFeederStop(Shooter *shooter) 
{
  m_shooter = shooter;
  AddRequirements(m_shooter);
}

void CmdTopFeederStop::Initialize() 
{
  //stop top feeder
}
