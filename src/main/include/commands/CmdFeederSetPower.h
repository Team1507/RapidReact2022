#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/InstantCommand.h>
#include "subsystems/Shooter.h"

class CmdFeederSetPower

    : public frc2::CommandHelper<frc2::InstantCommand,
                                 CmdFeederSetPower> {
 public:
  enum Level{Top,Bottom};//put in shooter
  CmdFeederSetPower(Shooter *shooter ,Level level, double power);

  void Initialize() override;
  private:
  Shooter *m_shooter;
  Level m_level;
  double m_power;
};
