#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include "subsystems/IntakeRear.h"
#include <frc/XboxController.h>
#include "subsystems/Shooter.h"
#include "subsystems/Feeder.h"

class CmdIntakeRearDefault
    : public frc2::CommandHelper<frc2::CommandBase, CmdIntakeRearDefault> {
 public:
  CmdIntakeRearDefault(IntakeRear *intake, frc::XboxController *topDriver, frc::XboxController *botDriver, Shooter *shooter, Feeder *feeder);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

  private:
  IntakeRear          *m_intake;
  frc::XboxController *m_topDriver;
  frc::XboxController *m_botDriver;
  Shooter *m_shooter;
  Feeder *m_feeder;
  bool m_isFrontActive;
  bool m_isRearActive;
  int  m_offDelayCount;
};
