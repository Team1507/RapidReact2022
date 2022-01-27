#include "commands/CmdClearAll.h"

CmdClearAll::CmdClearAll(Drivetrain *drivetrain) 
{
  m_drivetrain = drivetrain;
  AddRequirements(m_drivetrain);
}

void CmdClearAll::Initialize() 
{
  m_drivetrain->ResetEncoders();
  m_drivetrain->ResetOdometry();
  m_drivetrain->ZeroGyro();
}
