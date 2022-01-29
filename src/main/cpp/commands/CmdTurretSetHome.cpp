#include "commands/CmdTurretSetHome.h"


CmdTurretSetHome::CmdTurretSetHome(Shooter *shooter) 
{
  m_shooter = shooter;
}

// Called when the command is initially scheduled.
void CmdTurretSetHome::Initialize() 
{
  m_shooter->SetTurretYaw(0);
}
