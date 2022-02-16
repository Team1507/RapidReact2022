#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/SequentialCommandGroup.h>
//************SUBSYSTEMS**************
#include "subsystems/Shooter.h"
#include "subsystems/Intake.h"
#include "subsystems/Drivetrain.h"
#include "subsystems/Feeder.h"

class AutoFiveBallBlitz
    : public frc2::CommandHelper<frc2::SequentialCommandGroup,
                                 AutoFiveBallBlitz> {
 public:
  AutoFiveBallBlitz(Drivetrain *drivetrain, Intake *rearintake, Shooter *shooter, Feeder *feeder);
};
