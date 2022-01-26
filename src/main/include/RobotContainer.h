#pragma once

#include <frc2/command/Command.h>
#include "commands/ExampleCommand.h"
#include "subsystems/ExampleSubsystem.h"
#include "frc/smartdashboard/SendableChooser.h"
#include <frc2/command/button/JoystickButton.h>
#include "GamepadMap.h"

//*****************Subsystems*******************
#include "subsystems/Drivetrain.h"
#include "subsystems/Intake.h"
#include "subsystems/Shooter.h"
#include "subsystems/Climber.h"
#include <frc/XboxController.h>

//*********************AUTO**********************

#include "commands/AutoDoNothing.h"

class RobotContainer 
{
 public:
  RobotContainer();

  //****************Subsystems*******************
  Drivetrain          m_drivetrain;
  Intake              m_frontIntake{Intake::Type::FRONT};
  Intake              m_rearIntake{Intake::Type::REAR};
  Shooter             m_shooter;
  Climber             m_climber;
  frc::XboxController m_bot_driver{0};
  frc::XboxController m_top_driver{1};

  //******************AUTO*************************
  AutoDoNothing m_autoDoNothing {&m_drivetrain};

  frc2::Command* GetAutonomousCommand();
  
 private:
  frc::SendableChooser<frc2::Command*> m_chooser;
  ExampleSubsystem m_subsystem;
  ExampleCommand m_autonomousCommand;

  void ConfigureButtonBindings();
  frc2::JoystickButton m_top_driver_A{&m_top_driver,GAMEPADMAP_BUTTON_A};
};
