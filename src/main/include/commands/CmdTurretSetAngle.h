#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/InstantCommand.h>
#include "subsystems/Shooter.h"

class CmdTurretSetAngle
    : public frc2::CommandHelper<frc2::InstantCommand,
                                 CmdTurretSetAngle> {
 public:
  CmdTurretSetAngle( Shooter *shooter, double angle);

  void Initialize() override;
  private:
  Shooter *m_shooter;
  double m_angle;
};
