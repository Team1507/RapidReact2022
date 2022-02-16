#include "RobotContainer.h"
#include "commands/CmdDriveWithGamepad.h"
#include "frc/smartdashboard/SmartDashboard.h"
#include "commands/CmdIntakeDefault.h"
#include "commands/CmdClimberDefault.h"
#include "commands/CmdShooterDefault.h"
#include "commands/CmdCalculateAll.h"
#include "commands/CmdDriverFeedbackDefault.h"
#include "commands/CmdFeederDefault.h"
#include "commands/GrpTestOne.h"
#include "commands/GrpTestTwo.h"

RobotContainer::RobotContainer() : m_autonomousCommand(&m_subsystem) 
{
  // *********************************Defaults*********************************************

  m_drivetrain.SetDefaultCommand(CmdDriveWithGamepad( &m_drivetrain, &m_bot_driver ));
  m_rearIntake.SetDefaultCommand(CmdIntakeDefault( &m_rearIntake, &m_top_driver, &m_shooter, &m_feeder));
  m_frontIntake.SetDefaultCommand(CmdIntakeDefault( &m_frontIntake, &m_top_driver, &m_shooter, &m_feeder));
  m_climber.SetDefaultCommand(CmdClimberDefault( &m_climber, &m_top_driver, &m_bot_driver));
  m_shooter.SetDefaultCommand(CmdShooterDefault( &m_shooter, &m_top_driver));
  m_driverFeedback.SetDefaultCommand(CmdDriverFeedbackDefault( &m_driverFeedback, &m_top_driver, &m_shooter, &m_rearIntake));
  m_feeder.SetDefaultCommand(CmdFeederDefault(&m_feeder, &m_top_driver));

  //*************************************Auto**********************************************

  m_chooser.SetDefaultOption("Auto Do Nothing", &m_autoDoNothing);
  m_chooser.AddOption("Auto Just Shoot With Limelight", &m_autoJustShootLimelight);
  m_chooser.AddOption("Auto Just Shoot Without Limelight", &m_autoJustShootNoLimelight);
  m_chooser.AddOption("Auto Shoot Two Ball", &m_autoTwoBall);
  m_chooser.AddOption("Auto Shoot Four Ball", &m_autoFourBall);
  frc::SmartDashboard::PutData(&m_chooser);

  //********************************Smart Dashboard Buttons**************************************
   
  frc::SmartDashboard::PutData( new AutoJustShootNoLimelight(&m_shooter,&m_drivetrain,&m_feeder));
  frc::SmartDashboard::PutData( new AutoJustShootLimelight(&m_shooter,&m_drivetrain,&m_feeder));
  
  frc::SmartDashboard::PutData( new GrpTestOne(&m_climber, &m_driverFeedback, &m_drivetrain, &m_frontIntake, &m_rearIntake, &m_shooter, &m_top_driver, &m_bot_driver, &m_feeder));
  frc::SmartDashboard::PutData( new GrpTestTwo(&m_climber, &m_driverFeedback, &m_drivetrain, &m_frontIntake, &m_rearIntake, &m_shooter, &m_top_driver, &m_bot_driver, &m_feeder));

  ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings() 
{
  m_btn_driver_A.WhenPressed(new CmdLimeLight3xMode(&m_shooter, true)).WhenReleased(new CmdLimeLight3xMode(&m_shooter, false));
}

frc2::Command* RobotContainer::GetAutonomousCommand() 
{
  return m_chooser.GetSelected();
}
