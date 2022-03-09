#include "commands/AutoOneBall.h"
#include "frc2/command/WaitCommand.h"
#include "commands/CmdPrintAutoText.h"
//**********DRIVETRAIN********
#include "commands/CmdDriveClearAll.h"
#include "commands/CmdDriveRevGyroV2.h"
#include "commands/CmdDriveFwdGyroV2.h"
//**********INTAKE************
#include "commands/CmdIntakeDeploy.h"
#include "commands/CmdIntakeRetract.h"
#include "commands/CmdIntakeSetPower.h"
//**********FEEDER************
#include "commands/CmdFeederSetPower.h"
#include "commands/CmdFeederStop.h"
//**********SHOOTER***********
#include "commands/CmdCalculateAllV2.h"
#include "commands/CmdShooterSetPower.h"
#include "commands/CmdTurretSetHome.h"
#include "commands/CmdHoodSetAngle.h"
#include "commands/CmdHoodFindHome.h"


AutoOneBall::AutoOneBall(Shooter *shooter, Drivetrain *drivetrain,IntakeRear *rearintake, Feeder *feeder ) //
{
    AddCommands
    (
        //Pre-Shoot for Ball 1
        CmdPrintAutoText("AutoOneBall Start"),

        CmdDriveClearAll(drivetrain),
        
        frc2::WaitCommand(0.5_s),
        CmdShooterSetPower(shooter, 0.25),                               //Inital Shooter Idle Power
        //CmdHoodSetAngle(shooter,   5000),                               //Set Hood Angle

        frc2::WaitCommand(2.0_s),

        //Shoot Ball 1 (Up Close)
        CmdShooterSetPower(shooter, 0.365),                               //First Ball shot power
        frc2::WaitCommand(1.5_s),
        CmdFeederSetPower(feeder, Feeder::Level::Top, TOP_FEEDER_SHOOTING_POWER),
        CmdFeederSetPower(feeder, Feeder::Level::Bottom, BOTTOM_FEEDER_SHOOTING_POWER),
        frc2::WaitCommand(5.0_s),


        //Backup Out of Terminal
        CmdDriveRevGyroV2(drivetrain, 0.3, 0.0, 95.0, true, true, 0.0),  
        frc2::WaitCommand(1.0_s),



        //Post-Shoot
        CmdShooterSetPower(shooter, 0.25),                               //Shooter Idle Power
        CmdFeederStop(feeder, Feeder::Level::Bottom),
        CmdFeederStop(feeder, Feeder::Level::Top),

        //CmdHoodFindHome(shooter), 




        CmdPrintAutoText("AutoOneBall Finish")

    
    );
}
