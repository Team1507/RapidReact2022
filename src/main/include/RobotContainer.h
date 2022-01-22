#pragma once

#include <frc2/command/Command.h>
#include "commands/ExampleCommand.h"
#include "subsystems/ExampleSubsystem.h"
#include "subsystems/Drivetrain.h"
#include <frc/XboxController.h>

 
class RobotContainer 
{
 public:
  RobotContainer();

  Drivetrain m_drivetrain;
  frc::XboxController m_bot_driver{0};
  frc::XboxController m_top_driver{1};
  frc2::Command* GetAutonomousCommand();

 private:
  ExampleSubsystem m_subsystem;
  ExampleCommand m_autonomousCommand;

  void ConfigureButtonBindings();
};
