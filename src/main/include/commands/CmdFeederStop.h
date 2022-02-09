#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/InstantCommand.h>
#include "subsystems/Shooter.h"
#include "subsystems/Feeder.h"
class CmdFeederStop
    : public frc2::CommandHelper<frc2::InstantCommand,
                                 CmdFeederStop> {
 public:
  CmdFeederStop(Feeder *feeder, Feeder::Level level);

  void Initialize() override;
  private:
  Feeder *m_feeder;
  Feeder::Level m_level;
};
