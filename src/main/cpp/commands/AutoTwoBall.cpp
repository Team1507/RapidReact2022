#include "commands/AutoTwoBall.h"
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
#include "commands/CmdFeederSetStatus.h"
//**********SHOOTER***********
#include "commands/CmdCalculateAll.h"
#include "commands/CmdShooterSetPower.h"
#include "commands/CmdTurretSetHome.h"
#include "commands/CmdHoodFindHome.h"
#include "commands/CmdHoodSetAngle.h"
#include "commands/CmdTurretSetAngle.h"
#include "commands/CmdShooterSetRPM.h"

AutoTwoBall::AutoTwoBall(Shooter *shooter, Drivetrain *drivetrain,IntakeRear *rearintake, Feeder *feeder ) //
{
    AddCommands
    (
        //Pre-Shoot for Ball 1
        CmdPrintAutoText("Auto2Ball Start"),

        CmdDriveClearAll(drivetrain),
        frc2::WaitCommand(0.5_s),
        //CmdShooterSetPower(shooter, 0.25),                               
        CmdShooterSetRPM(shooter, 1440),//Inital Shooter Idle RPM
        //frc2::WaitCommand(2.0_s),

        // //Shoot Ball 1 (Up Close)
        // CmdShooterSetPower(shooter, SHOOTER_CLOSE_VELOCITY),
        // frc2::WaitCommand(1.5_s),
        // CmdFeederSetPower(feeder, Feeder::Level::Top, TOP_FEEDER_SHOOTING_POWER),
        // CmdFeederSetPower(feeder, Feeder::Level::Bottom, BOTTOM_FEEDER_SHOOTING_POWER),
        // frc2::WaitCommand(2.0_s),

        // //Reset
        // CmdShooterSetPower(shooter, SHOOTER_IDLE_VELOCITY),
        // CmdFeederStop(feeder, Feeder::Level::Bottom),
        // CmdFeederStop(feeder, Feeder::Level::Top),

        //Backup for Ball 2
        CmdIntakeDeploy(rearintake),
        CmdIntakeSetPower(rearintake, REAR_INTAKE_POWER),
        CmdFeederSetStatus(feeder,true),
        // CmdFeederSetPower(feeder, Feeder::Level::Bottom, BOTTOM_FEEDER_INTAKE_POWER),
        CmdDriveRevGyroV2(drivetrain, 0.3, 0.0, 28.44, true, false, 0.0),    //Measurements brought to you by Yours Truly, Jack Skerrett
        CmdDriveRevGyroV2(drivetrain, 0.1, 0.0, 12, false, true, 3.0),    //Measurements brought to you by Yours Truly, Jack Skerrett
        frc2::WaitCommand(1.0_s),

        //Bring Everything back in
        CmdIntakeSetPower(rearintake, 0.0),
        CmdIntakeRetract(rearintake),
        CmdShooterSetRPM(shooter, 2100),
        CmdHoodSetAngle(shooter,   7000),
        //Pre-Shoot for Ball 2
        CmdDriveFwdGyroV2(drivetrain, 0.3, 0, 8, true, true, 0.0),
        // CmdCalculateAllV2(shooter, 0.0),//Sets ShooterRPM, Hood, and Turret. Thanks Limelight :)


        //Shoot Ball 2
        //CmdShooterSetPower(shooter,0.425),
  //Set Hood Angle
        CmdCalculateAll(shooter),              //Turret               
        //CmdTurretSetAngle(shooter,10),
        frc2::WaitCommand(2.5_s),
        CmdFeederSetStatus(feeder, false),
        CmdFeederSetPower(feeder, Feeder::Level::Top, TOP_FEEDER_SHOOTING_POWER),
        CmdFeederSetPower(feeder, Feeder::Level::Bottom, BOTTOM_FEEDER_SHOOTING_POWER),
        frc2::WaitCommand(3.5_s),

        //Post-Shoot
        CmdFeederStop(feeder, Feeder::Level::Bottom),
        CmdFeederStop(feeder, Feeder::Level::Top),
        CmdIntakeSetPower(rearintake, 0.0),
        CmdIntakeRetract(rearintake),
        CmdTurretSetAngle(shooter,0),
        CmdHoodSetAngle(shooter,   0),                               //Set Hood Angle
        // CmdShooterSetPower(shooter, 0.25),
        CmdShooterSetRPM(shooter, 1440),
        CmdDriveRevGyroV2(drivetrain, .3, 0, 18.0, false, true, 0.0),


        CmdPrintAutoText("Auto2Ball Finish")
    
    );
}
