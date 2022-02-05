#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include "subsystems/Shooter.h"

class CmdTurretFindHome
    : public frc2::CommandHelper<frc2::CommandBase, CmdTurretFindHome> {
 public:
  CmdTurretFindHome(Shooter *shooter);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

  private:
  Shooter *m_shooter;
  bool HitLeftLSW = false;
  bool HitRightLSW = false;
};
