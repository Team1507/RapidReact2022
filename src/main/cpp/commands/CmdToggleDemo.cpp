#include "commands/CmdToggleDemo.h"

CmdToggleDemo::CmdToggleDemo(Drivetrain *drivetrain) 
{
  m_drivetrain = drivetrain;
}

// Called when the command is initially scheduled.
void CmdToggleDemo::Initialize() 
{
  if(m_drivetrain->IsDemo())
  {
    m_drivetrain->SetDemo(false);
  }
  else
  {
    m_drivetrain->SetDemo(true);
  }
}
