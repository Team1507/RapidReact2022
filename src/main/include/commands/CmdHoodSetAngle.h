#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/InstantCommand.h>
#include "subsystems/Shooter.h"

class CmdHoodSetAngle
    : public frc2::CommandHelper<frc2::InstantCommand,
                                 CmdHoodSetAngle> {
 public:
  CmdHoodSetAngle(Shooter *shooter, int angle);

  void Initialize() override;
  
  private:
  Shooter *m_shooter;
  int m_angle;
};
