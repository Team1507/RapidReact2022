#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include "subsystems/Drivetrain.h"

class CmdDriveClearAll
    : public frc2::CommandHelper<frc2::CommandBase, CmdDriveClearAll> {
 public:
  CmdDriveClearAll(Drivetrain *drivetrain);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

  private:
  Drivetrain *m_ptrDrivetrain; 
};
