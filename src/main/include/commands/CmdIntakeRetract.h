#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include "subsystems/IntakeRear.h"


class CmdIntakeRetract
    : public frc2::CommandHelper<frc2::CommandBase, CmdIntakeRetract> {
 public:
  CmdIntakeRetract(IntakeRear *intake);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;
  private:
    IntakeRear *m_intake;
};
