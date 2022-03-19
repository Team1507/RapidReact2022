#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include "subsystems/Shooter.h"

class CmdShooterSetRPM
    : public frc2::CommandHelper<frc2::CommandBase, CmdShooterSetRPM> {
 public:
  CmdShooterSetRPM(Shooter *shooter, double rpm);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

  private:

  Shooter *m_shooter;
  double m_rpm;
};
