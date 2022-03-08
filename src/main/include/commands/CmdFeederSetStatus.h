#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/InstantCommand.h>
#include "subsystems/Feeder.h"

class CmdFeederSetStatus
    : public frc2::CommandHelper<frc2::InstantCommand,
                                 CmdFeederSetStatus> {
 public:
  CmdFeederSetStatus(Feeder *feeder, bool status);

  void Initialize() override;
  private:
  Feeder *m_feeder;
  bool m_status;
};
