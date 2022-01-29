#include "commands/CmdTurretSetAngle.h"

CmdTurretSetAngle::CmdTurretSetAngle( Shooter *shooter, double angle) 
{
  m_shooter = shooter;
  m_angle = angle;
}

// Called when the command is initially scheduled.
void CmdTurretSetAngle::Initialize() 
{
  m_shooter->SetTurretYaw(m_angle);
}
