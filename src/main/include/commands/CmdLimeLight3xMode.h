#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/InstantCommand.h>
#include "subsystems/Shooter.h"

class CmdLimeLight3xMode
    : public frc2::CommandHelper<frc2::InstantCommand,
                                 CmdLimeLight3xMode> {
 public:
  CmdLimeLight3xMode(Shooter *shooter, bool is3xMode);

  void Initialize() override;

  private:

  bool m_is3xOn;
  Shooter *m_shooter;
};
