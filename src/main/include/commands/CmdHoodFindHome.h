
#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include "subsystems/Shooter.h"


class CmdHoodFindHome
    : public frc2::CommandHelper<frc2::CommandBase, CmdHoodFindHome> {
 public:
  CmdHoodFindHome(Shooter *shooter);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

  private:
  Shooter *m_shooter;
};
