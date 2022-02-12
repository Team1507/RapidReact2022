#include "commands/AutoJustShootNoLimelight.h"
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
#include "commands/CmdFeederDefault.h"


AutoJustShootNoLimelight::AutoJustShootNoLimelight(Shooter *shooter, Drivetrain *drivetrain, Feeder *feeder) 
{


  AddCommands(
    
    
    CmdDriveClearAll(drivetrain),
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
    CmdFeederSetPower(feeder,Feeder::Level::Top,frc::SmartDashboard::GetNumber("Top Feeder Shooting Power", 0.0)),
    CmdFeederSetPower(feeder,Feeder::Level::Bottom,frc::SmartDashboard::GetNumber("Bot Feeder Shooting Power", 0.0)),

    frc2::WaitCommand(2.0_s),


    //Stop Everything
    CmdShooterStop(shooter),
    CmdTurretSetHome(shooter),
    CmdFeederStop(feeder, Feeder::Top),
    CmdFeederStop(feeder, Feeder::Bottom),

    //Done
    CmdPrintAutoText("Just Shot Done")

    
  );

  // Add your commands here, e.g.
  // AddCommands(FooCommand(), BarCommand());
}
