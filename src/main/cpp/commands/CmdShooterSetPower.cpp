#include "commands/CmdShooterSetPower.h"


CmdShooterSetPower::CmdShooterSetPower(Shooter *shooter, double power) 
{
  m_shooter = shooter;
  m_power = power;
  AddRequirements(m_shooter);
}

void CmdShooterSetPower::Initialize() 
{
  m_shooter->SetShooterPower(m_power);
}
