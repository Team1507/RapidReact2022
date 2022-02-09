#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/InstantCommand.h>
#include "subsystems/Shooter.h"
#include "subsystems/Feeder.h"

class CmdFeederSetPower

    : public frc2::CommandHelper<frc2::InstantCommand,
                                 CmdFeederSetPower> {
 public:
  CmdFeederSetPower(Feeder *feeder ,Feeder::Level level, double power);

  void Initialize() override;
  private:
  Feeder *m_feeder;
  Feeder::Level m_level;
  double m_power;
};
