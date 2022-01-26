#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include <frc/XboxController.h>
#include "subsystems/DriverFeedback.h"


class CmdDriverFeedbackDefault
    : public frc2::CommandHelper<frc2::CommandBase, CmdDriverFeedbackDefault> {
 public:
  CmdDriverFeedbackDefault(DriverFeedback *driverfeedback, frc::XboxController *topDriver);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

  private:

  frc::XboxController *m_topDriver;
  DriverFeedback *m_driverFeedback;
};
