#include "RobotContainer.h"
#include "commands/CmdDriveWithGamepad.h"
#include "frc/smartdashboard/SmartDashboard.h"
#include "commands/CmdIntakeFrontDefault.h"
#include "commands/CmdIntakeRearDefault.h"
#include "commands/CmdClimberDefault.h"
#include "commands/CmdShooterDefault.h"
#include "commands/CmdCalculateAll.h"
#include "commands/CmdDriverFeedbackDefault.h"
#include "commands/CmdFeederDefault.h"
#include "commands/GrpTestOne.h"
#include "commands/GrpTestTwo.h"
#include "commands/CmdIntakeSetPower.h"
#include "commands/CmdDriveClearAll.h"

RobotContainer::RobotContainer() : m_autonomousCommand(&m_subsystem) 
{
  // *********************************Defaults*********************************************

  m_drivetrain.SetDefaultCommand(CmdDriveWithGamepad( &m_drivetrain, &m_bot_driver ));
  m_rearIntake.SetDefaultCommand(CmdIntakeRearDefault(   &m_rearIntake,  &m_top_driver, &m_bot_driver, &m_shooter, &m_feeder));
  m_frontIntake.SetDefaultCommand(CmdIntakeFrontDefault( &m_frontIntake, &m_top_driver, &m_bot_driver, &m_shooter, &m_feeder));
  m_climber.SetDefaultCommand(CmdClimberDefault( &m_climber, &m_top_driver, &m_bot_driver));
  m_shooter.SetDefaultCommand(CmdShooterDefault( &m_shooter, &m_top_driver));
  m_driverFeedback.SetDefaultCommand(CmdDriverFeedbackDefault( &m_driverFeedback, &m_top_driver, &m_shooter, &m_climber));
  m_feeder.SetDefaultCommand(CmdFeederDefault(&m_feeder, &m_top_driver));

  //*************************************Auto**********************************************

  m_chooser.SetDefaultOption("Auto Do Nothing", &m_autoDoNothing);
  //m_chooser.AddOption("Auto Just Shoot With Limelight", &m_autoJustShootLimelight);
 // m_chooser.AddOption("Auto Just Shoot Without Limelight", &m_autoJustShootNoLimelight);
  //m_chooser.AddOption("Auto Shoot ONE Ball", &m_autoOneBall);
  m_chooser.AddOption("Auto Shoot Two Ball", &m_autoTwoBall);
  //m_chooser.AddOption("Auto Two Ball Left", &m_autoTwoBallLeft);
  m_chooser.AddOption("Auto Four Ball", &m_autoFourBall);
  m_chooser.AddOption("Auto Four Ball Interpolation", &m_autoFourBallInterpolation);
  frc::SmartDashboard::PutData(&m_chooser);

  //********************************Smart Dashboard Buttons**************************************
   frc::SmartDashboard::PutData("CmdDriveClearAll", new CmdDriveClearAll(&m_drivetrain)  );

  frc::SmartDashboard::PutData( "JustShootNoLimelight", new AutoJustShootNoLimelight(&m_shooter,&m_drivetrain,&m_feeder));
  frc::SmartDashboard::PutData( "JustShootWithLimelight", new AutoJustShootLimelight(&m_shooter,&m_drivetrain,&m_feeder));
  
  frc::SmartDashboard::PutData( "GrpTestOne", new GrpTestOne(&m_climber, &m_driverFeedback, &m_drivetrain, &m_frontIntake, &m_rearIntake,  &m_shooter, &m_top_driver, &m_bot_driver, &m_feeder));//
  frc::SmartDashboard::PutData( "GrpTestTwo", new GrpTestTwo(&m_climber, &m_driverFeedback, &m_drivetrain, &m_frontIntake, &m_rearIntake, &m_shooter, &m_top_driver, &m_bot_driver, &m_feeder));//

  frc::SmartDashboard::PutData("Toggle Demo", new CmdToggleDemo(&m_drivetrain));

  ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings() 
{
  //m_btn_driver_A.WhenPressed(new CmdLimeLight3xMode(&m_shooter, true)).WhenReleased(new CmdLimeLight3xMode(&m_shooter, false));
  //m_top_driver_LB.WhenPressed(new CmdIntakeSetPower(&m_frontIntake, 0.5)).WhenReleased(new CmdIntakeSetPower(&m_frontIntake, 0.0));
}

frc2::Command* RobotContainer::GetAutonomousCommand() 
{
  return m_chooser.GetSelected();
}
