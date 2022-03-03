#include "commands/GrpTestOne.h"


GrpTestOne::GrpTestOne(Climber *climber, DriverFeedback *driverfeedback, Drivetrain *drivetrain, Intake *frontIntake, Intake *backIntake,  Shooter *shooter, XboxController *topdriver, XboxController *botdriver, Feeder *feeder) // 
{
  AddCommands
  (
    CmdPrintAutoText("Group Test One")
  );
}
