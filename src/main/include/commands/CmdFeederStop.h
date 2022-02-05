#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/InstantCommand.h>
#include "subsystems/Shooter.h"

class CmdFeederStop
    : public frc2::CommandHelper<frc2::InstantCommand,
                                 CmdFeederStop> {
 public:
 enum Level{Top,Bottom};//put in shooter
  CmdFeederStop(Shooter *shooter, Level level);

  void Initialize() override;
  private:
  Shooter *m_shooter;
  Level m_level;
};
