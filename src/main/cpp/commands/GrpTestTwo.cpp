#include "commands/GrpTestTwo.h"


GrpTestTwo::GrpTestTwo(Climber *climber, DriverFeedback *driverfeedback, Drivetrain *drivetrain, Intake *frontIntake, Intake *backIntake, Shooter *shooter, XboxController *topdriver, XboxController *botdriver) 
{
 AddCommands
  (
    CmdPrintAutoText("Group Test One")
  );
}
