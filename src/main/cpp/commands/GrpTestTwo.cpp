#include "commands/GrpTestTwo.h"


GrpTestTwo::GrpTestTwo(Climber *climber, DriverFeedback *driverfeedback, Drivetrain *drivetrain, Intake *frontIntake,  Shooter *shooter, XboxController *topdriver, XboxController *botdriver, Feeder *feeder) //Intake *backIntake,
{
 AddCommands
  (
    CmdPrintAutoText("Group Test One")
  );
}
