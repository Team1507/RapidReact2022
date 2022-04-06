#pragma once

#include <frc2/command/Command.h>
#include "commands/ExampleCommand.h"
#include "subsystems/ExampleSubsystem.h"
#include "frc/smartdashboard/SendableChooser.h"
#include <frc2/command/button/JoystickButton.h>
#include "GamepadMap.h"
#include <frc2/command/button/JoystickButton.h>
#include "commands/CmdLimeLight3xMode.h"

//*****************Subsystems*******************
#include "subsystems/Drivetrain.h"
#include "subsystems/IntakeFront.h"
#include "subsystems/IntakeRear.h"
#include "subsystems/Shooter.h"
#include "subsystems/Climber.h"
#include "subsystems/DriverFeedback.h"
#include <frc/XboxController.h>

//*********************AUTO**********************

#include "commands/AutoDoNothing.h"
#include "commands/AutoJustShootLimelight.h"
#include "commands/AutoJustShootNoLimelight.h"
#include "commands/AutoOneBall.h"
#include "commands/AutoTwoBall.h"
#include "commands/AutoFourBall.h"
#include "commands/AutoFiveBallBlitz.h"
#include "commands/AutoTwoBallLeft.h"
#include "commands/AutoFourBallInterpolation.h"


class RobotContainer 
{
 public:
  RobotContainer();

  //****************Subsystems*******************
  Drivetrain          m_drivetrain;
  IntakeFront         m_frontIntake;
  IntakeRear          m_rearIntake;
  Shooter             m_shooter;
  Climber             m_climber;
  frc::XboxController m_bot_driver{0};
  frc::XboxController m_top_driver{1};
  DriverFeedback      m_driverFeedback{&m_top_driver};
  Feeder              m_feeder;

  //******************AUTO*************************
  AutoDoNothing m_autoDoNothing {&m_drivetrain};
  AutoJustShootLimelight m_autoJustShootLimelight {&m_shooter,&m_drivetrain,&m_feeder};
  AutoJustShootNoLimelight m_autoJustShootNoLimelight {&m_shooter,&m_drivetrain,&m_feeder};
  AutoOneBall m_autoOneBall {&m_shooter, &m_drivetrain, &m_rearIntake, &m_feeder};//
  AutoTwoBall m_autoTwoBall {&m_shooter, &m_drivetrain, &m_rearIntake, &m_feeder};//
  AutoTwoBallLeft m_autoTwoBallLeft {&m_shooter, &m_drivetrain, &m_rearIntake, &m_feeder};
  AutoFourBall m_autoFourBall {&m_drivetrain, &m_shooter,&m_rearIntake, &m_feeder};// 
  AutoFiveBallBlitz m_autoFiveBall {&m_drivetrain, &m_shooter,&m_rearIntake, &m_feeder};
  AutoFourBallInterpolation m_autoFourBallInterpolation {&m_drivetrain, &m_shooter,&m_rearIntake, &m_feeder};
  frc2::Command* GetAutonomousCommand();
  
 private:
  frc::SendableChooser<frc2::Command*> m_chooser;
  ExampleSubsystem m_subsystem;
  ExampleCommand m_autonomousCommand;

  void ConfigureButtonBindings();
  frc2::JoystickButton m_btn_driver_A{&m_bot_driver, GAMEPADMAP_BUTTON_A};
  frc2::JoystickButton m_btn_driver_LB{&m_bot_driver, GAMEPADMAP_BUTTON_LBUMP};

  frc2::JoystickButton m_top_driver_A{&m_top_driver, GAMEPADMAP_BUTTON_A};
  frc2::JoystickButton m_top_driver_B{&m_top_driver, GAMEPADMAP_BUTTON_B};
  frc2::JoystickButton m_top_driver_X{&m_top_driver, GAMEPADMAP_BUTTON_X};
  frc2::JoystickButton m_top_driver_Y{&m_top_driver, GAMEPADMAP_BUTTON_Y};
  frc2::JoystickButton m_top_driver_RB{&m_top_driver, GAMEPADMAP_BUTTON_RBUMP};
  frc2::JoystickButton m_top_driver_LB{&m_top_driver, GAMEPADMAP_BUTTON_LBUMP};
  frc2::JoystickButton m_top_driver_START{&m_top_driver, GAMEPADMAP_BUTTON_START};
  frc2::JoystickButton m_top_driver_BACK{&m_top_driver, GAMEPADMAP_BUTTON_BACK};
};
