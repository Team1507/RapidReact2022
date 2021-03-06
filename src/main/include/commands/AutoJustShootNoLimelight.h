#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/SequentialCommandGroup.h>

#include "subsystems/Shooter.h"
#include "subsystems/Drivetrain.h"
#include "subsystems/Feeder.h"

class AutoJustShootNoLimelight
    : public frc2::CommandHelper<frc2::SequentialCommandGroup,
                                 AutoJustShootNoLimelight> {
 public:
  AutoJustShootNoLimelight(Shooter *shooter, Drivetrain *drivetrain, Feeder *feeder);

};
