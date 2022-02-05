#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/Shooter.h"
#include <frc/XboxController.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include "GamepadMap.h"
#include "subsystems/Intake.h"

//x = return to home
//Lt = caculate all
//rt = shoot
//Dpad = set shooting velocities

class CmdShooterDefault
    : public frc2::CommandHelper<frc2::CommandBase, CmdShooterDefault> {
 public:
  CmdShooterDefault(Shooter *shooter, frc::XboxController *topDriver);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

  private:

  Shooter *m_shooter;
  frc::XboxController *m_topDriver;
  bool isRTriggerPressed;
  double m_topFeederPower;
  double m_bottomFeederPower;
  

};
