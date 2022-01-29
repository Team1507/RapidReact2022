#include "commands/AutoJustShootLimelight.h" 

#include <frc/smartdashboard/SmartDashboard.h>
#include <frc2/command/WaitCommand.h>

#include "commands/CmdDriveClearAll.h"
#include "commands/CmdPrintAutoText.h"
#include "commands/CmdHoodSetAngle.h"
#include "commands/CmdShooterSetPower.h"
#include "commands/CmdTurretSetAngle.h"
#include "commands/CmdShooterStop.h"
#include "commands/CmdTurretSetHome.h"
#include "commands/CmdFeederSetPower.h"
#include "commands/CmdFeederStop.h"
#include "commands/CmdCalculateAll.h"

AutoJustShootLimelight::AutoJustShootLimelight(Shooter *shooter, Drivetrain *drivetrain) 
{
  AddCommands
  (
    CmdDriveClearAll(drivetrain),
    CmdPrintAutoText("Just Shoot with limelight"),

    //SetShooter to Idle speed
    CmdShooterSetPower(shooter,frc::SmartDashboard::GetNumber("Idle Power", 0.0)),
    

    frc2::WaitCommand(2.0_s),
    
    //Aim & Set Shooting Speed
    CmdCalculateAll(shooter),

    //Wait to get to up to speed
    frc2::WaitCommand(2.0_s),


    //Shoot 
    CmdFeederSetPower(shooter,CmdFeederSetPower::Level::Top,frc::SmartDashboard::GetNumber("Top Feeder Shooting Power", 0.0)),
    CmdFeederSetPower(shooter,CmdFeederSetPower::Level::Bottom,frc::SmartDashboard::GetNumber("Bot Feeder Shooting Power", 0.0)),

    frc2::WaitCommand(2.0_s),


    //Stop Everything
    CmdShooterStop(shooter),
    CmdTurretSetHome(shooter),
    CmdFeederStop(shooter, CmdFeederStop::Top),
    CmdFeederStop(shooter, CmdFeederStop::Bottom),

    //Done
    CmdPrintAutoText("Just Shoot Done")
  );
}
