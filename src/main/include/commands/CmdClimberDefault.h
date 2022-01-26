#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include "subsystems/Climber.h"
#include <frc/XboxController.h>
#include "GamepadMap.h"


class CmdClimberDefault
    : public frc2::CommandHelper<frc2::CommandBase, CmdClimberDefault> {
 public:
  CmdClimberDefault(Climber *climber, frc::XboxController *topDriver, frc::XboxController *bottomDriver);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

  private:

  Climber *m_climber;
  frc::XboxController *m_topDriver;
  frc::XboxController *m_bottomDriver;

};
