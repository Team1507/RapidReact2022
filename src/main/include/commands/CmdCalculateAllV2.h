#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include "subsystems/Shooter.h"
#include <frc/Timer.h>

class CmdCalculateAllV2
    : public frc2::CommandHelper<frc2::CommandBase, CmdCalculateAllV2> {
 public:
  CmdCalculateAllV2(Shooter *shooter, double timeout);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

  private:
  Shooter *m_shooter;
  frc::Timer m_timer;

  double m_timeout;
  double m_limeLightAngle;
  double m_limeLightDistance;
  const double SHOOTER_ANGLE_TOLERANCE = 1; //Change later
  const double SHOOTER_POWER_TOLERANCE = 1; //Change later
  const double SHOOTER_HOOD_TOLERANCE  = 1; //Change later

  const double SHOOTER_POWER_RATIO     = 0; //Change later
  const double SHOOTER_HOOD_RATIO      = 0; //Change later


};
