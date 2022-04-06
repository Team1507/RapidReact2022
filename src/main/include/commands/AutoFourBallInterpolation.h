#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/SequentialCommandGroup.h>

//************SUBSYSTEMS**************
#include "subsystems/Shooter.h"
#include "subsystems/IntakeRear.h"
#include "subsystems/Drivetrain.h"
#include "subsystems/Feeder.h"

class AutoFourBallInterpolation
    : public frc2::CommandHelper<frc2::SequentialCommandGroup,
                                 AutoFourBallInterpolation> {
 public:
  AutoFourBallInterpolation(Drivetrain *drivetrain,  Shooter *shooter,IntakeRear *rearintake, Feeder *feeder);
};
