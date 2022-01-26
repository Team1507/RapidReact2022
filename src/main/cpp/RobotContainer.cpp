#include "RobotContainer.h"
#include "commands/CmdDriveWithGamepad.h"
#include "frc/smartdashboard/SmartDashboard.h"
#include "commands/CmdIntakeDefault.h"
#include "commands/CmdClimberDefault.h"
#include "commands/CmdShooterDefault.h"

RobotContainer::RobotContainer() : m_autonomousCommand(&m_subsystem) 
{
  //Defaults
  m_drivetrain.SetDefaultCommand(CmdDriveWithGamepad( &m_drivetrain, &m_bot_driver ));
  m_rearIntake.SetDefaultCommand(CmdIntakeDefault( &m_rearIntake, &m_top_driver));
  m_frontIntake.SetDefaultCommand(CmdIntakeDefault( &m_frontIntake, &m_top_driver));
  m_climber.SetDefaultCommand(CmdClimberDefault( &m_climber, &m_top_driver, &m_bot_driver));
  m_shooter.SetDefaultCommand(CmdShooterDefault( &m_shooter, &m_top_driver));


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
