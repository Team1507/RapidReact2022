#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/InstantCommand.h>
#include "subsystems/Shooter.h"

class CmdShooterSetPower
    : public frc2::CommandHelper<frc2::InstantCommand,
                                 CmdShooterSetPower> {
 public:
  CmdShooterSetPower(Shooter *shooter, double power);

  void Initialize() override;
  private:
  Shooter *m_shooter;
  double m_power;
};
