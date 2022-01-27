#include "commands/CmdHoodSetAngle.h"

CmdHoodSetAngle::CmdHoodSetAngle(Shooter *shooter, int angle)
{
  m_shooter = shooter;
  m_angle = angle;
  AddRequirements(m_shooter);
}

void CmdHoodSetAngle::Initialize() 
{
  m_shooter->SetHoodEncoder(m_angle);
}
