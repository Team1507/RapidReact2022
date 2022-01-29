#include "commands/CmdHoodSetAngle.h"

CmdHoodSetAngle::CmdHoodSetAngle(Shooter *shooter, int angle)
{
  m_shooter = shooter;
  m_angle = angle;
}

void CmdHoodSetAngle::Initialize() 
{
  m_shooter->SetHoodAngle(m_angle);
}
