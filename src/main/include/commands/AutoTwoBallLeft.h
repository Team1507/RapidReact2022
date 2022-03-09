#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/SequentialCommandGroup.h>
#include "subsystems/Shooter.h"
#include "subsystems/Drivetrain.h"
#include "subsystems/IntakeRear.h"
#include "subsystems/Feeder.h"


class AutoTwoBallLeft
    : public frc2::CommandHelper<frc2::SequentialCommandGroup,
                                 AutoTwoBallLeft> {
 public:
  AutoTwoBallLeft(Shooter *shooter, Drivetrain *drivetrain, IntakeRear *rearintake, Feeder *feeder);
};
