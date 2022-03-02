#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include <frc/XboxController.h>
#include "subsystems/DriverFeedback.h"
#include "subsystems/Shooter.h"
#include "subsystems/Intake.h"
#include "subsystems/Climber.h"


class CmdDriverFeedbackDefault
    : public frc2::CommandHelper<frc2::CommandBase, CmdDriverFeedbackDefault> {
 public:
  CmdDriverFeedbackDefault(DriverFeedback *driverfeedback, frc::XboxController *topDriver, Shooter *shooter, Climber *climber);//Intake *intake

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

  private:

  frc::XboxController *m_topDriver;
  DriverFeedback *m_driverFeedback;
  Shooter *m_shooter;
  Intake *m_intake;
  Climber *m_climber;
};
