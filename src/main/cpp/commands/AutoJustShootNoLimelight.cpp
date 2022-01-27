#include "commands/AutoJustShootNoLimelight.h"
#include <frc/smartdashboard/SmartDashboard.h>

#include <frc2/command/WaitCommand.h>

#include "commands/CmdClearAll.h"
#include "commands/CmdPrintAutoText.h"
#include "commands/CmdHoodSetAngle.h"
#include "commands/CmdShooterSetPower.h"
#include "commands/CmdTurretSetAngle.h"
#include "commands/CmdTopFeederSetPower.h"
#include "commands/CmdBotFeederSetPower.h"
#include "commands/CmdShooterStop.h"
#include "commands/CmdBotFeederStop.h"
#include "commands/CmdTurretSetHome.h"
#include "commands/CmdTopFeederStop.h"

AutoJustShootNoLimelight::AutoJustShootNoLimelight(Shooter *shooter, Drivetrain *drivetrain) 
{


  AddCommands(
    
    
    CmdClearAll(drivetrain),
    CmdPrintAutoText("Just Shoot No limelight"),

    //SetShooter to Idle speed and aim
    CmdHoodSetAngle(shooter,frc::SmartDashboard::GetNumber("Hood Angle", 0.0)),
    CmdShooterSetPower(shooter,frc::SmartDashboard::GetNumber("Idle Power", 0.0)),
    CmdTurretSetAngle(shooter,frc::SmartDashboard::GetNumber("Turret Angle", 0.0)),

    frc2::WaitCommand(2.0_s),
    
    //Set to shooting speed
    CmdShooterSetPower(shooter,frc::SmartDashboard::GetNumber("Shooting Power", 0.0)),
    //Wait to get to up to speed
    frc2::WaitCommand(2.0_s),


    //Shoot 
    CmdTopFeederSetPower(shooter,frc::SmartDashboard::GetNumber("Top Feeder Shooting Power", 0.0)),
    CmdBotFeederSetPower(shooter,frc::SmartDashboard::GetNumber("Bot Feeder Shooting Power", 0.0)),

    frc2::WaitCommand(2.0_s),


    //Stop Everything
    CmdShooterStop(shooter),
    CmdTurretSetHome(shooter),
    CmdTopFeederStop(shooter),
    CmdBotFeederStop(shooter),

    //Done
    CmdPrintAutoText("Just Shot Done")

    
  );

  // Add your commands here, e.g.
  // AddCommands(FooCommand(), BarCommand());
}
