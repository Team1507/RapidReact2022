#include "commands/CmdBotFeederSetPower.h"

CmdBotFeederSetPower::CmdBotFeederSetPower(Shooter *shooter, double power) 
{
  m_shooter = shooter;
  m_power = power;
  AddRequirements(m_shooter);
}

void CmdBotFeederSetPower::Initialize() 
{
  //set bot feeder
}
