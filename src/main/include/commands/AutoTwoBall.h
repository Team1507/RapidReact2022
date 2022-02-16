#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/SequentialCommandGroup.h>
#include "subsystems/Shooter.h"
#include "subsystems/Drivetrain.h"
#include "subsystems/Intake.h"
#include "subsystems/Feeder.h"


class AutoTwoBall
    : public frc2::CommandHelper<frc2::SequentialCommandGroup,
                                 AutoTwoBall> {
 public:
  AutoTwoBall(Shooter *shooter, Drivetrain *drivetrain, Feeder *feeder, Intake *rearintake);
};
