#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/InstantCommand.h>
#include "subsystems/Drivetrain.h"

class CmdToggleDemo
    : public frc2::CommandHelper<frc2::InstantCommand,
                                 CmdToggleDemo> {
 public:
  CmdToggleDemo(Drivetrain *drivetrain);

  void Initialize() override;
  private:
  Drivetrain *m_drivetrain;
};
