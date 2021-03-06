#include "commands/CmdCalculateAllV2.h"
#include <iostream>
#include <frc/smartdashboard/SmartDashboard.h>
CmdCalculateAllV2::CmdCalculateAllV2(Shooter *shooter, double timeout) 
{
  m_timeout = timeout;
  m_shooter = shooter;
}

void CmdCalculateAllV2::Initialize() 
{
  m_timer.Reset();
  m_timer.Start();
  std::cout<<"Starting CmdCalculateAll"<<std::endl;
  
}

void CmdCalculateAllV2::Execute() 
{
  m_limeLightAngle = m_shooter->GetLimelightHAngle();
  m_limeLightDistance = m_shooter->GetLimelightDistance();

  //getting limelight and aim and speed
  
  if(m_shooter->GetLimelightTargetValid() == true) 
  {
    m_shooter->SetTurretAngle(m_shooter->GetCurrentTurretAngle() + m_shooter->GetLimelightHAngle() + frc::SmartDashboard::GetNumber("Limelight H Offset", 0.0));
    m_shooterInterpolationCalculation = m_shooter->ShooterInterpolation(m_limeLightDistance);
    //m_shooter->SetShooterRPM(m_shooter->GetLimelightDistance() * SHOOTER_POWER_RATIO);
    //m_shooter->SetHoodAngle(m_shooter->GetLimelightDistance() * SHOOTER_HOOD_RATIO);
  }
  else 
  {
    std::cout<<"Target not found"<<std::endl;
  }
}

void CmdCalculateAllV2::End(bool interrupted) {}

bool CmdCalculateAllV2::IsFinished() 
{
  double wantedShooterPower = m_shooter->GetWantedShooterRPM();
  double wantedHoodAngle = m_shooter->GetWantedHoodAngle();
  double shooterRPM = m_shooter->GetCurrentShooterRPM();
  double hoodEncoder = m_shooter->GetCurrentHoodAngle();

  if ((units::time::second_t) m_timeout > m_timer.Get()) 
  {
    return true;
  }
  else if (
    (m_limeLightAngle > -SHOOTER_ANGLE_TOLERANCE)                       && (m_limeLightAngle < SHOOTER_ANGLE_TOLERANCE) && 
    (shooterRPM     > (wantedShooterPower - SHOOTER_ANGLE_TOLERANCE)) && (shooterRPM     < (wantedShooterPower + SHOOTER_ANGLE_TOLERANCE))&&
    (hoodEncoder      > (wantedHoodAngle    - SHOOTER_ANGLE_TOLERANCE)) && (hoodEncoder      < (wantedHoodAngle    + SHOOTER_ANGLE_TOLERANCE))&& 
     m_shooterInterpolationCalculation) 
  {
    return true;
  }
  return false;
}