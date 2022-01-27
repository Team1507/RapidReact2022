#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/InstantCommand.h>
#include "subsystems/Shooter.h"

class CmdTurretSetHome
    : public frc2::CommandHelper<frc2::InstantCommand,
                                 CmdTurretSetHome> {
 public:
  CmdTurretSetHome( Shooter *shooter);

  void Initialize() override;
  private:
  Shooter *m_shooter;
};
