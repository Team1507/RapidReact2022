#include "commands/AutoFiveBallBlitz.h"
#include "commands/CmdPrintAutoText.h"
#include "frc2/command/WaitCommand.h"
//***********DRIVETRAIN************
#include "commands/CmdDriveFwdGyroV2.h"
#include "commands/CmdDriveRevGyroV2.h"
#include "commands/CmdDriveClearAll.h"
#include "commands/CmdDriveTurn2Angle.h"
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


AutoFiveBallBlitz::AutoFiveBallBlitz(Drivetrain *drivetrain, Intake *rearintake, Shooter *shooter, Feeder *feeder) 
{
    AddCommands
    (
		CmdPrintAutoText("Auto Five Ball Blitz Start"),
        //Initial Setup
        CmdDriveClearAll(drivetrain),
        CmdShooterSetPower(shooter, SHOOTER_IDLE_VELOCITY),
        frc2::WaitCommand(2.0_s),

        //Shoot Ball 1
        CmdShooterSetPower(shooter, SHOOTER_CLOSE_VELOCITY),
        frc2::WaitCommand(1.5_s),
        CmdFeederSetPower(feeder, Feeder::Level::Top, TOP_FEEDER_SHOOTING_POWER),
        CmdFeederSetPower(feeder, Feeder::Level::Bottom, BOTTOM_FEEDER_SHOOTING_POWER),
        frc2::WaitCommand(1.5_s),

		//Post Shoot for Ball 1
		CmdShooterSetPower(shooter, SHOOTER_IDLE_VELOCITY),
		CmdFeederStop(feeder, Feeder::Level::Bottom),
		CmdFeederStop(feeder, Feeder::Level::Top),

		//Move to Ball 2
		CmdIntakeDeploy(rearintake),
		CmdIntakeSetPower(rearintake, REAR_INTAKE_POWER),
		CmdDriveRevGyroV2(drivetrain, 0.7, 0, 28.44, true, true, 0.0),
		CmdDriveRevGyroV2(drivetrain, 0.3, 0, 12.00, true, true, 2.0), // 40.44
		frc2::WaitCommand(1.0_s),

		//Turn/Move to Ball 3
		CmdDriveTurn2Angle(drivetrain, 0.4, 126.5), 
		CmdDriveRevGyroV2(drivetrain, 0.7, 126.5, 117.23, true, true, 0.0),
		CmdDriveTurn2Angle(drivetrain, 0.4, -99.88),

		//Pre-Shoot for Balls 2/3
		CmdCalculateAllV2(shooter, 0.0),
		CmdIntakeRetract(rearintake),
		CmdIntakeSetPower(rearintake, 0.0),

		//Shoot Balls 2/3
		CmdFeederSetPower(feeder, Feeder::Level::Bottom, BOTTOM_FEEDER_SHOOTING_POWER),
		CmdFeederSetPower(feeder, Feeder::Level::Top, TOP_FEEDER_SHOOTING_POWER),
		frc2::WaitCommand(1.5_s),

		//Post Shoot Ball 2/3		
		CmdShooterSetPower(shooter, SHOOTER_IDLE_VELOCITY),
		CmdFeederStop(feeder, Feeder::Level::Bottom),
		CmdFeederStop(feeder, Feeder::Level::Top),

		//Backup to Balls 4/5
		CmdIntakeDeploy(rearintake),
		CmdIntakeSetPower(rearintake, REAR_INTAKE_POWER),
		CmdDriveRevGyroV2(drivetrain, 0.7, 26.62, 134.56, true, true, 0.0), 
		CmdDriveRevGyroV2(drivetrain, 0.3, 26.62, 12.00, true, true, 2.0),  // 146.56 total
		frc2::WaitCommand(2.5_s),

		//Back to Shooting Location for Balls 4/5
		CmdIntakeRetract(rearintake),
		CmdIntakeSetPower(rearintake, 0),
		CmdDriveFwdGyroV2(drivetrain, 0.7, 26.62, 146.56, true, true, 0.0),
		CmdCalculateAllV2(shooter, 0.0),

		//Shoot Balls
		CmdFeederSetPower(feeder, Feeder::Level::Bottom, BOTTOM_FEEDER_SHOOTING_POWER),
		CmdFeederSetPower(feeder, Feeder::Level::Top, TOP_FEEDER_SHOOTING_POWER),
		frc2::WaitCommand(1.5_s),

		//Post Shoot Balls 4/5
		CmdShooterSetPower(shooter, SHOOTER_IDLE_VELOCITY),
		CmdFeederStop(feeder, Feeder::Level::Bottom),
		CmdFeederStop(feeder, Feeder::Level::Top),
		


		CmdPrintAutoText("Auto Five Ball Blitz Finish")
    );
}
