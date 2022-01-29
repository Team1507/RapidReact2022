#include "commands/CmdShooterStop.h"

CmdShooterStop::CmdShooterStop(Shooter *shooter) 
{
  m_shooter = shooter;
}

void CmdShooterStop::Initialize() 
{
  m_shooter->SetShooterPower(0);
}
