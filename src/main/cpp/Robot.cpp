#include "Robot.h"
#include <iostream>
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc2/command/CommandScheduler.h>

void Robot::RobotInit() 
{
  //*************************** INIT ******************************
    std::cout<<"RobotInit"<<std::endl;
    std::cout<<"FRC2022: Rapid React"<<std::endl;
    std::cout<<"          ~~~ Deus ~~~"<<std::endl;
    std::cout<<"Version: " << __DATE__ <<"  "<<__TIME__<<std::endl<<std::endl; 

    m_container.m_drivetrain.FalconsInit();
    m_container.m_drivetrain.Stop();
    m_container.m_drivetrain.HardResetEncoders();
    m_container.m_drivetrain.ZeroGyro(); 
    m_container.m_drivetrain.ResetOdometry();

    m_container.m_shooter.FalconsInit();
    m_container.m_shooter.ShooterInit();
    
    m_container.m_climber.TalonsInit();
    m_container.m_climber.ClimberInit();

    // m_container.m_rearIntake.IntakeInit();
    // m_container.m_rearIntake.Retract();
    // m_container.m_rearIntake.SetPower(0);

    m_container.m_frontIntake.IntakeInit();
    m_container.m_frontIntake.Retract();    
    m_container.m_frontIntake.SetPower(0);
    
    m_container.m_feeder.FeederInit();
    m_container.m_feeder.SetTopFeederPower(0);
    m_container.m_feeder.SetBottomFeederPower(0);
    
  
}


void Robot::RobotPeriodic() 
{
  frc2::CommandScheduler::GetInstance().Run();
  WriteToSmartDashboard();
}


void Robot::DisabledInit() 
{
    std::cout<<"Disabled Init"<<std::endl;
}

void Robot::DisabledPeriodic() 
{
    
}


void Robot::AutonomousInit() {
  std::cout<<"Auto Init"<<std::endl;
  m_autonomousCommand = m_container.GetAutonomousCommand();

  if (m_autonomousCommand != nullptr) {
    m_autonomousCommand->Schedule();
  }
}

void Robot::AutonomousPeriodic() {}

void Robot::TeleopInit() {
  
  std::cout<<"Teleop Init"<<std::endl;
  if (m_autonomousCommand != nullptr) {
    m_autonomousCommand->Cancel();
    m_autonomousCommand = nullptr;
  }
}


void Robot::TeleopPeriodic() {}

void Robot::WriteToSmartDashboard(void)
{
  //Shooter
  frc::SmartDashboard::PutNumber("Left Shooter Temp", m_container.m_shooter.GetTempatureLeftShooter());
  frc::SmartDashboard::PutNumber("Right Shooter Temp", m_container.m_shooter.GetTempatureRightShooter());

  //Hood
  frc::SmartDashboard::PutBoolean("Top Hood Limit Switch", m_container.m_shooter.GetTopHoodLimitSW());
  frc::SmartDashboard::PutBoolean("Bottom Hood Limit Switch", m_container.m_shooter.GetBotHoodLimitSW());
  frc::SmartDashboard::PutNumber("Hood Motor Temp", m_container.m_shooter.GetTempatureHoodMotor());
  frc::SmartDashboard::PutNumber("Hood Angle", m_container.m_shooter.GetCurrentHoodAngle());
  frc::SmartDashboard::PutNumber("Hood Power",m_container.m_shooter.GetHoodPower());
  //Turret
  frc::SmartDashboard::PutBoolean("Left Turret Limit Switch", m_container.m_shooter.GetLeftTurretLimitSW());
  frc::SmartDashboard::PutBoolean("Right Turret Limit Switch", m_container.m_shooter.GetRightTurretLimitSW());
  frc::SmartDashboard::PutBoolean("Turret Home Limit Switch", m_container.m_shooter.GetTurretHomeSW());
  frc::SmartDashboard::PutNumber("Turret Temp", m_container.m_shooter.GetTempatureTurretMotor());
  frc::SmartDashboard::PutNumber("Turret Encoder", m_container.m_shooter.GetTurretEncoder());
  frc::SmartDashboard::PutNumber("Hood Encoder", m_container.m_shooter.GetHoodEncoder());
  frc::SmartDashboard::PutNumber("Turret Angle", m_container.m_shooter.GetCurrentTurretAngle());
  frc::SmartDashboard::PutNumber("Turret Power", m_container.m_shooter.GetTurretPower()  );
  
  //Climber
  frc::SmartDashboard::PutBoolean("Mid Climber Hall Effect", m_container.m_climber.GetMidHallEffect());
  //frc::SmartDashboard::PutBoolean("High Climb Hall Effect", m_container.m_climber.GetHighHallEffect());
  
  //Feeder
  frc::SmartDashboard::PutBoolean("Top Feeder PhotoEye", m_container.m_feeder.GetTopFeederPhotoeye());
  frc::SmartDashboard::PutBoolean("Bottom Feeder PhotoEye", m_container.m_feeder.GetBotFeederPhotoeye());

  //DriveTrain
  frc::SmartDashboard::PutNumber("Drivetrain Left Encoder", m_container.m_drivetrain.GetLeftEncoder3());
  frc::SmartDashboard::PutNumber("DriveTrain Right Encoder", m_container.m_drivetrain.GetRightEncoder3());
  
  //LimeLight
  frc::SmartDashboard::PutNumber("LimeLight Distance", m_container.m_shooter.GetLimelightDistance());
  frc::SmartDashboard::PutNumber("LimeLight Distance", m_container.m_shooter.GetLimelightVAngle());
  frc::SmartDashboard::PutNumber("LimeLight Distance", m_container.m_shooter.GetLimelightHAngle());
  frc::SmartDashboard::PutBoolean("LimeLight Target Valid", m_container.m_shooter.GetLimelightTargetValid());
  
  
  
  m_container.m_drivetrain.WriteFalconTemps();
  
}

void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>();
}
#endif

