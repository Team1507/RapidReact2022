#include "RobotContainer.h"
#include "commands/CmdDriveWithGamepad.h"
#include "frc/smartdashboard/SmartDashboard.h"


RobotContainer::RobotContainer() : m_autonomousCommand(&m_subsystem) 
{
  //Defaults
  m_drivetrain.SetDefaultCommand(CmdDriveWithGamepad( &m_drivetrain, &m_bot_driver ));

  //Auto
  m_chooser.SetDefaultOption("Auto Do Nothing", &m_autoDoNothing);
  frc::SmartDashboard::PutData(&m_chooser);

  ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings() 
{
  
}

frc2::Command* RobotContainer::GetAutonomousCommand() 
{
 
  return m_chooser.GetSelected();
}
