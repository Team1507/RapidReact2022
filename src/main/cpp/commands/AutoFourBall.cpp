#include "commands/AutoFourBall.h"
#include "commands/CmdPrintAutoText.h"
#include "frc2/command/WaitCommand.h"
//***********DRIVETRAIN************
#include "commands/CmdDriveFwdGyroV2.h"
#include "commands/CmdDriveRevGyroV2.h"
#include "commands/CmdDriveClearAll.h"
//***********SHOOTER***************
#include "commands/CmdShooterSetPower.h"
#include "commands/CmdCalculateAllV2.h"
#include "commands/CmdShooterStop.h"
#include "commands/CmdHoodSetAngle.h"
#include "commands/CmdTurretSetAngle.h"
//***********FEEDER****************
#include "commands/CmdFeederSetPower.h"
#include "commands/CmdFeederStop.h"
#include "commands/CmdFeederSetStatus.h"
//***********INTAKE****************
#include "commands/CmdIntakeDeploy.h"
#include "commands/CmdIntakeRetract.h"
#include "commands/CmdIntakeSetPower.h"

AutoFourBall::AutoFourBall(Drivetrain *drivetrain,  Shooter *shooter, IntakeRear *rearintake, Feeder *feeder) //
{
    AddCommands
    (
         CmdPrintAutoText("Auto4Ball Start"),

        CmdDriveClearAll(drivetrain),
        //frc2::WaitCommand(0.5_s),
        CmdShooterSetPower(shooter, 0.25),                               //Inital Shooter Idle Power
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
        CmdDriveRevGyroV2(drivetrain, 0.35, 0.0, 32.44, true, false, 0.0), 
		CmdShooterSetPower(shooter,0.41),
        CmdHoodSetAngle(shooter,   8000),                               //Set Hood Angle
        CmdTurretSetAngle(shooter, -35),   
        CmdDriveRevGyroV2(drivetrain, 0.35, 0.0, 20, false, true, 3.0),    //Measurements brought to you by Yours Truly, Jack Skerrett
        frc2::WaitCommand(1.5_s),

        //Bring Everything back in
        CmdIntakeSetPower(rearintake, 0.0),
        CmdIntakeRetract(rearintake),

        //Pre-Shoot for Ball 2
       // CmdDriveFwdGyroV2(drivetrain, 0.3, 0, 20.0, true, true, 0.0),
        // CmdCalculateAllV2(shooter, 0.0),//Sets ShooterRPM, Hood, and Turret. Thanks Limelight :)


        //Shoot Ball 2

        CmdFeederSetStatus(feeder, false),
        CmdFeederSetPower(feeder, Feeder::Level::Top, TOP_FEEDER_SHOOTING_POWER),
        CmdFeederSetPower(feeder, Feeder::Level::Bottom, .6),
        frc2::WaitCommand(2.0_s),

        //Post-Shoot
        CmdFeederStop(feeder, Feeder::Level::Bottom),
        CmdFeederStop(feeder, Feeder::Level::Top),
        CmdIntakeSetPower(rearintake, 0.0),
        CmdIntakeRetract(rearintake),
        CmdTurretSetAngle(shooter,0),
        CmdHoodSetAngle(shooter,   0),                               //Set Hood Angle
        CmdShooterSetPower(shooter, 0.25),



        CmdDriveRevGyroV2(drivetrain, .55, 0, 129.0, false, false, 0.0),
		CmdIntakeDeploy(rearintake),
		CmdIntakeSetPower(rearintake, .6),
		CmdFeederSetStatus(feeder, true),
		CmdDriveRevGyroV2(drivetrain, 0.1, 0, 24, false, true, 3.0),
		frc2::WaitCommand(1.5_s),
		CmdIntakeRetract(rearintake),
		CmdIntakeSetPower(rearintake, 0.0),
		CmdShooterSetPower(shooter, .4),
		CmdHoodSetAngle(shooter, 8000),
		CmdTurretSetAngle(shooter, -30),
		CmdDriveFwdGyroV2(drivetrain, 0.6, 0, 144.0, true, true, 0.0),
		frc2::WaitCommand(1.0_s),
		CmdFeederSetStatus(feeder, false),
        CmdFeederSetPower(feeder, Feeder::Level::Top, TOP_FEEDER_SHOOTING_POWER),
        CmdFeederSetPower(feeder, Feeder::Level::Bottom, BOTTOM_FEEDER_SHOOTING_POWER),
        frc2::WaitCommand(4.0_s),





		





        CmdPrintAutoText("Auto4Ball Finish")
    );
}
