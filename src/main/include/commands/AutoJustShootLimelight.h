
#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/SequentialCommandGroup.h>
#include "subsystems/Shooter.h"
#include "subsystems/Drivetrain.h"

class AutoJustShootLimelight
    : public frc2::CommandHelper<frc2::SequentialCommandGroup,
                                 AutoJustShootLimelight> {
 public:
  AutoJustShootLimelight(Shooter *shooter, Drivetrain *drivetrain);
};
