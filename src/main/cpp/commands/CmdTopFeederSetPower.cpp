#include "commands/CmdTopFeederSetPower.h"

CmdTopFeederSetPower::CmdTopFeederSetPower(Shooter *shooter, double power) 
{
  m_shooter = shooter;
  m_power = power;
  AddRequirements(m_shooter);
}

void CmdTopFeederSetPower::Initialize() 
{
  //set top feeder
}
