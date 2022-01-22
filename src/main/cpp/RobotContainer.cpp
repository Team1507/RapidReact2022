#include "RobotContainer.h"
#include "commands/CmdDriveWithGamepad.h"

RobotContainer::RobotContainer() : m_autonomousCommand(&m_subsystem) 
{
  m_drivetrain.SetDefaultCommand(CmdDriveWithGamepad( &m_drivetrain, &m_bot_driver ));
  
  ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings() 
{
  
}

frc2::Command* RobotContainer::GetAutonomousCommand() 
{
 
  return &m_autonomousCommand;
}
