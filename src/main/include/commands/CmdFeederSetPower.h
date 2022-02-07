#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/InstantCommand.h>
#include "subsystems/Shooter.h"
#include "subsystems/Feeder.h"

class CmdFeederSetPower

    : public frc2::CommandHelper<frc2::InstantCommand,
                                 CmdFeederSetPower> {
 public:
  enum Level{Top,Bottom};//put in shooter
  CmdFeederSetPower(Feeder *feeder ,Level level, double power);

  void Initialize() override;
  private:
  Feeder *m_feeder;
  Level m_level;
  double m_power;
};
