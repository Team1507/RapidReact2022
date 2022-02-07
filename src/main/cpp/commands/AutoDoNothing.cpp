#include "commands/AutoDoNothing.h"

#include "commands/CmdPrintAutoText.h"
#include "commands/CmdDriveClearAll.h"

AutoDoNothing::AutoDoNothing(Drivetrain *drivetrain)
{
  AddCommands(

    //Auto Setup 
    CmdPrintAutoText("****** AutoDoNothing ******"),
    CmdDriveClearAll(drivetrain),

    //Auto Commands here




    //Clean up
    CmdPrintAutoText("AutoDoNothing Complete")

  );

}
