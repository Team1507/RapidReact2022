#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/InstantCommand.h>
#include "subsystems/Shooter.h"

class CmdBotFeederStop
    : public frc2::CommandHelper<frc2::InstantCommand,
                                 CmdBotFeederStop> {
 public:
  CmdBotFeederStop(Shooter *shooter);

  void Initialize() override;
  private:
  Shooter *m_shooter;
};
