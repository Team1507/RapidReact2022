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
//**********SHOOTER***********
#include "commands/CmdCalculateAllV2.h"
#include "commands/CmdShooterSetPower.h"
#include "commands/CmdTurretSetHome.h"
#include "commands/CmdHoodFindHome.h"

AutoTwoBall::AutoTwoBall(Shooter *shooter, Drivetrain *drivetrain, Feeder *feeder ) //Intake *rearintake
{
    AddCommands
    (
        //Pre-Shoot for Ball 1
        CmdPrintAutoText("Auto2Ball Start"),

        CmdDriveClearAll(drivetrain),
        CmdShooterSetPower(shooter, SHOOTER_IDLE_VELOCITY),
        frc2::WaitCommand(2.0_s),

        //Shoot Ball 1 (Up Close)
        CmdShooterSetPower(shooter, SHOOTER_CLOSE_VELOCITY),
        frc2::WaitCommand(1.5_s),
        CmdFeederSetPower(feeder, Feeder::Level::Top, TOP_FEEDER_SHOOTING_POWER),
        CmdFeederSetPower(feeder, Feeder::Level::Bottom, BOTTOM_FEEDER_SHOOTING_POWER),
        frc2::WaitCommand(2.0_s),

        //Reset
        CmdShooterSetPower(shooter, SHOOTER_IDLE_VELOCITY),
        CmdFeederStop(feeder, Feeder::Level::Bottom),
        CmdFeederStop(feeder, Feeder::Level::Top),

        //Backup for Ball 2
        //CmdIntakeDeploy(rearintake),
        //CmdIntakeSetPower(rearintake, REAR_INTAKE_POWER),
        CmdFeederSetPower(feeder, Feeder::Level::Bottom, BOTTOM_FEEDER_INTAKE_POWER),
        CmdDriveRevGyroV2(drivetrain, 0.7, 0.0, 40.44, true, true, 0.0),    //Measurements brought to you by Yours Truly, Jack Skerrett
        frc2::WaitCommand(1.0_s),

        //Bring Everything back in
        //CmdIntakeSetPower(rearintake, 0.0),
        //CmdIntakeRetract(rearintake),

        //Pre-Shoot for Ball 2
        CmdDriveFwdGyroV2(drivetrain, 0.7, 0, 32.5, true, true, 0.0),
        CmdCalculateAllV2(shooter, 0.0),//Sets ShooterRPM, Hood, and Turret. Thanks Limelight :)


        //Shoot Ball 2
        CmdFeederSetPower(feeder, Feeder::Level::Top, TOP_FEEDER_SHOOTING_POWER),
        CmdFeederSetPower(feeder, Feeder::Level::Bottom, BOTTOM_FEEDER_SHOOTING_POWER),
        frc2::WaitCommand(2.0_s),

        //Post-Shoot
        CmdFeederStop(feeder, Feeder::Level::Bottom),
        CmdFeederStop(feeder, Feeder::Level::Top),
        //CmdIntakeSetPower(rearintake, 0.0),
        //CmdIntakeRetract(rearintake),
        CmdTurretSetHome(shooter),
        CmdHoodFindHome(shooter),
        CmdShooterSetPower(shooter, SHOOTER_IDLE_VELOCITY),



        CmdPrintAutoText("Auto2Ball Finish")



        



    
    
    );
}
