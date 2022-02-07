#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/InstantCommand.h>
#include "subsystems/Shooter.h"
#include "subsystems/Feeder.h"
class CmdFeederStop
    : public frc2::CommandHelper<frc2::InstantCommand,
                                 CmdFeederStop> {
 public:
 enum Level{Top,Bottom};//put in shooter
  CmdFeederStop(Feeder *feeder, Level level);

  void Initialize() override;
  private:
  Feeder *m_feeder;
  Level m_level;
};
