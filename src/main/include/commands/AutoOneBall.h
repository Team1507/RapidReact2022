#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/SequentialCommandGroup.h>
#include "subsystems/Shooter.h"
#include "subsystems/Drivetrain.h"
#include "subsystems/IntakeRear.h"
#include "subsystems/Feeder.h"


class AutoOneBall
    : public frc2::CommandHelper<frc2::SequentialCommandGroup,
                                 AutoOneBall> {
 public:
  AutoOneBall(Shooter *shooter, Drivetrain *drivetrain, IntakeRear *rearintake, Feeder *feeder );
};
