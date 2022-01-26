#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include <subsystems/Shooter.h>
#include <frc/XboxController.h>
#include <frc/Timer.h>


class CmdCalculateAll
    : public frc2::CommandHelper<frc2::CommandBase, CmdCalculateAll> {
 public:
  CmdCalculateAll(Shooter *shooter, frc::XboxController *topDriver);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;
  
  private:
  Shooter *m_shooter;
  double hAngle;
  double vAngle;
  frc::XboxController *m_topDriver;
  frc::Timer m_timer;
};
