#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include "GamepadMap.h"
#include "subsystems/Feeder.h"
#include <frc/XboxController.h>

class CmdFeederDefault
    : public frc2::CommandHelper<frc2::CommandBase, CmdFeederDefault> 
    {
 public:
  CmdFeederDefault(Feeder *feeder, frc::XboxController *topDriver);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

  private:

  Feeder *m_feeder;

  double m_topFeederPower;
  double m_bottomFeederPower;

  bool m_isManualOn;

  frc::XboxController *m_topDriver;
};
