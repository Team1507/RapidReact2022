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
    m_container.m_rearIntake.Retract();
    m_container.m_frontIntake.Retract();
    m_container.m_frontIntake.SetPower(0);
    m_container.m_rearIntake.SetPower(0);
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
  frc::SmartDashboard::PutBoolean("Top Hood Limit Switch", m_container.m_shooter.GetTopHoodLimitSW());
  frc::SmartDashboard::PutBoolean("Bottom Hood Limit Switch", m_container.m_shooter.GetBotHoodLimitSW());
  frc::SmartDashboard::PutBoolean("Left Turret Limit Switch", m_container.m_shooter.GetLeftTurretLimitSW());
  frc::SmartDashboard::PutBoolean("Right Turret Limit Switch", m_container.m_shooter.GetRightTurretLimitSW());
  frc::SmartDashboard::PutBoolean("Turret Home Limit Switch", m_container.m_shooter.GetTurretHomeSW());
  frc::SmartDashboard::PutBoolean("Mid Climber Hall Effect", m_container.m_climber.GetMidHallEffect());
  frc::SmartDashboard::PutBoolean("High Climb Hall Effect", m_container.m_climber.GetHighHallEffect());
  frc::SmartDashboard::PutBoolean("Top Feeder PhotoEye", m_container.m_feeder.GetTopFeederPhotoeye());
  frc::SmartDashboard::PutBoolean("Bottom Feeder PhotoEye", m_container.m_feeder.GetBotFeederPhotoeye());

  frc::SmartDashboard::PutNumber("Left Shooter Temp", m_container.m_shooter.GetTempatureLeftShooter());
  frc::SmartDashboard::PutNumber("Right Shooter Temp", m_container.m_shooter.GetTempatureRightShooter());
  frc::SmartDashboard::PutNumber("Hood Motor Temp", m_container.m_shooter.GetTempatureHoodMotor());
  frc::SmartDashboard::PutNumber("Turret Temp", m_container.m_shooter.GetTempatureTurretMotor());
  frc::SmartDashboard::PutNumber("Drivetrain Left Encoder", m_container.m_drivetrain.GetLeftEncoder3());
  frc::SmartDashboard::PutNumber("DriveTrain Right Encoder", m_container.m_drivetrain.GetRightEncoder3());
  frc::SmartDashboard::GetNumber("Shooter Encoder", m_container.m_shooter.E)
  m_container.m_drivetrain.WriteFalconTemps();
  
}

void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>();
}
#endif

