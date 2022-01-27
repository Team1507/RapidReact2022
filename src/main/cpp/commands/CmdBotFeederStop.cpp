#include "commands/CmdBotFeederStop.h"

CmdBotFeederStop::CmdBotFeederStop(Shooter *shooter) 
{
  m_shooter = shooter;
  AddRequirements(m_shooter);
}

void CmdBotFeederStop::Initialize() 
{
  //stop top feeder
}
