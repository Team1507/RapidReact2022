#include "commands/CmdCalculateAllV2.h"
#include <iostream>

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
    m_shooter->SetTurretAngle(m_shooter->GetTurretAngle() + m_shooter->GetLimelightHAngle());
    m_shooter->SetShooterRPM(m_shooter->GetLimelightDistance() * SHOOTER_POWER_RATIO);
    m_shooter->SetHoodAngle(m_shooter->GetLimelightDistance() * SHOOTER_HOOD_RATIO);
  }
  else 
  {
    std::cout<<"Target not found"<<std::endl;
  }
}

void CmdCalculateAllV2::End(bool interrupted) {}

bool CmdCalculateAllV2::IsFinished() 
{
  double wantedShooterPower = m_limeLightDistance * SHOOTER_POWER_RATIO;
  double wantedHoodAngle = m_limeLightDistance * SHOOTER_HOOD_RATIO;
  double shooterPower = m_shooter->GetShooterPower();
  double hoodEncoder = m_shooter->GetHoodAngle();

  if ((units::time::second_t) m_timeout > m_timer.Get()) 
  {
    return true;
  }
  else if (
    (m_limeLightAngle > -SHOOTER_ANGLE_TOLERANCE)                     && (m_limeLightAngle < SHOOTER_ANGLE_TOLERANCE) && 
    (shooterPower     > (wantedShooterPower - SHOOTER_ANGLE_TOLERANCE)) && (shooterPower     < (wantedShooterPower + SHOOTER_ANGLE_TOLERANCE))&&
    (hoodEncoder      > (wantedHoodAngle    - SHOOTER_ANGLE_TOLERANCE)) && (hoodEncoder      < (wantedHoodAngle    + SHOOTER_ANGLE_TOLERANCE))) 
  {
    return true;
  }
  return false;
}