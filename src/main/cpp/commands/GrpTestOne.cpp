#include "commands/GrpTestOne.h"


GrpTestOne::GrpTestOne(Climber *climber, DriverFeedback *driverfeedback, Drivetrain *drivetrain, IntakeFront *frontIntake, IntakeRear *rearIntake,  Shooter *shooter, XboxController *topdriver, XboxController *botdriver, Feeder *feeder) // 
{
  AddCommands
  (
    CmdPrintAutoText("Group Test One")
  );
}
