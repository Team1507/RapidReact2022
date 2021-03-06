#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/SequentialCommandGroup.h>

#include "subsystems/Climber.h"
#include "subsystems/DriverFeedback.h"
#include "subsystems/Drivetrain.h"
#include "subsystems/IntakeFront.h"
#include "subsystems/IntakeRear.h"
#include "subsystems/Shooter.h"
#include <frc/XboxController.h>
#include "subsystems/Feeder.h"

#include "commands/CmdPrintAutoText.h"


class GrpTestTwo
    : public frc2::CommandHelper<frc2::SequentialCommandGroup,
                                 GrpTestTwo> {
 public:
  GrpTestTwo(Climber *climber, DriverFeedback *driverfeedback, Drivetrain *drivetrain, IntakeFront *frontIntake, IntakeRear *rearIntake, Shooter *shooter, XboxController *topdriver, XboxController *botdriver, Feeder *feeder);//
};
