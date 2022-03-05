#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include "subsystems/IntakeFront.h"
#include <frc/XboxController.h>
#include "subsystems/Shooter.h"
#include "subsystems/Feeder.h"

class CmdIntakeFrontDefault
    : public frc2::CommandHelper<frc2::CommandBase, CmdIntakeFrontDefault> {
 public:
  CmdIntakeFrontDefault(IntakeFront *intake, frc::XboxController *topDriver, frc::XboxController *botDriver, Shooter *shooter, Feeder *feeder);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

  private:
  IntakeFront         *m_intake;
  frc::XboxController *m_topDriver;
  frc::XboxController *m_botDriver;
  Shooter *m_shooter;
  Feeder *m_feeder;
  bool m_isFrontActive;
  bool m_isRearActive;
};
