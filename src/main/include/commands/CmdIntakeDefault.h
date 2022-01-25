
#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include "subsystems/Intake.h"
#include <frc/XboxController.h>


class CmdIntakeDefault
    : public frc2::CommandHelper<frc2::CommandBase, CmdIntakeDefault> {
 public:
  CmdIntakeDefault(Intake *intake, frc::XboxController *topDriver);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

  private:
  Intake *m_intake;
  frc::XboxController *m_topDriver;
};