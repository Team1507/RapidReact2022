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
//***********FEEDER****************
#include "commands/CmdFeederSetPower.h"
#include "commands/CmdFeederStop.h"
//***********INTAKE****************
#include "commands/CmdIntakeDeploy.h"
#include "commands/CmdIntakeRetract.h"
#include "commands/CmdIntakeSetPower.h"

AutoFourBall::AutoFourBall(Drivetrain *drivetrain,  Shooter *shooter, IntakeRear *rearintake, Feeder *feeder) //
{
    AddCommands
    (
        CmdPrintAutoText("AutoFourBall Start"),
        //Iniital Setup
        CmdDriveClearAll(drivetrain),
        CmdShooterSetPower(shooter, SHOOTER_IDLE_VELOCITY),
        frc2::WaitCommand(2.0_s),

        //Shoot Ball 1
        // CmdShooterSetPower(shooter, SHOOTER_CLOSE_VELOCITY),
        // frc2::WaitCommand(1.5_s),
        // CmdFeederSetPower(feeder, Feeder::Level::Top, TOP_FEEDER_SHOOTING_POWER),
        // CmdFeederSetPower(feeder, Feeder::Level::Bottom, BOTTOM_FEEDER_SHOOTING_POWER),
        // frc2::WaitCommand(1.5_s),

		//Post Shoot Ball 1
		// CmdShooterSetPower(shooter, SHOOTER_IDLE_VELOCITY),
		// CmdFeederStop(feeder, Feeder::Level::Bottom),
		// CmdFeederStop(feeder, Feeder::Level::Top),

		//Move to Ball 2
		CmdIntakeDeploy(rearintake),
		CmdIntakeSetPower(rearintake, 0.6),
		CmdDriveRevGyroV2(drivetrain, 0.7, 0, 40.44, true, true, 0.0),
		//frc2::WaitCommand(1.0_s),
		CmdIntakeSetPower(rearintake, 0.0), // Save some power for the shooter
		CmdIntakeRetract(rearintake),

		//Shoot Ball 2
		CmdCalculateAllV2(shooter, 0.0),
		CmdFeederSetPower(feeder, Feeder::Level::Top, TOP_FEEDER_SHOOTING_POWER),
        CmdFeederSetPower(feeder, Feeder::Level::Bottom, BOTTOM_FEEDER_SHOOTING_POWER),
		frc2::WaitCommand(1.5_s),

		//Post Shoot Ball 2 
		CmdShooterSetPower(shooter, SHOOTER_IDLE_VELOCITY),
		CmdFeederStop(feeder, Feeder::Level::Bottom),
		CmdFeederStop(feeder, Feeder::Level::Top),

		//Back Up to Balls 3/4	
		
		CmdDriveRevGyroV2(drivetrain, 0.7, 0, 134.56, true, true, 0.0),
		CmdIntakeDeploy(rearintake),
		CmdIntakeSetPower(rearintake, 0.6),
		CmdDriveRevGyroV2(drivetrain, 0.3, 0, 12.00, true, true, 2.0), // 146.56 total 
		frc2::WaitCommand(2.5_s),

		//Pre Shoot for Balls 3/4
		CmdIntakeSetPower(rearintake, 0.0),
		CmdIntakeRetract(rearintake),
		CmdDriveFwdGyroV2(drivetrain, 0.7, 0.0, 146.56, true, true, 0.0),
		
		//Shoot Balls 3/4
		CmdCalculateAllV2(shooter, 0.0),
		CmdFeederSetPower(feeder, Feeder::Level::Top, TOP_FEEDER_SHOOTING_POWER),
        CmdFeederSetPower(feeder, Feeder::Level::Bottom, BOTTOM_FEEDER_SHOOTING_POWER),
		frc2::WaitCommand(1.5_s),


		//Post Shoot Balls 3/4
		CmdShooterSetPower(shooter, SHOOTER_IDLE_VELOCITY),
		CmdFeederStop(feeder, Feeder::Level::Bottom),
		CmdFeederStop(feeder, Feeder::Level::Top),
		





        CmdPrintAutoText("AutoFourBall Finish")
    );
}
