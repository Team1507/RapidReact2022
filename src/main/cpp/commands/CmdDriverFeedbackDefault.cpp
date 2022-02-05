#include "commands/CmdDriverFeedbackDefault.h"

CmdDriverFeedbackDefault::CmdDriverFeedbackDefault(DriverFeedback *driverfeedback, frc::XboxController *topDriver, Shooter *shooter) 
{
  m_topDriver = topDriver;
	m_driverFeedback = driverfeedback;
  m_shooter = shooter;
	AddRequirements(m_driverFeedback);
}


void CmdDriverFeedbackDefault::Initialize() 
{

}


void CmdDriverFeedbackDefault::Execute() 
{
  double HoodAngle         = m_shooter->GetHoodAngle();
  double TurretAngle       = m_shooter->GetTurretAngle();
  double WantedHoodAngle   = m_shooter->GetWantedHoodAngle();
  double WantedTurretAngle = m_shooter->GetWantedTurretAngle();
  double WantedShooterRPM  = m_shooter->GetWantedShooterRPM();
  double ShooterRPM        = m_shooter->GetShooterRPM();
  double LimeLightAngle    = m_shooter->GetLimelightHAngle();

  if((HoodAngle      < (WantedHoodAngle   + m_shooter->HOOD_TOLERANCE))        && (HoodAngle      > (WantedHoodAngle   - m_shooter->HOOD_TOLERANCE)) && 
     (TurretAngle    < (WantedTurretAngle + m_shooter->TURRET_TOLERANCE))      && (TurretAngle    > (WantedTurretAngle - m_shooter->HOOD_TOLERANCE)) &&
     (ShooterRPM     < (WantedShooterRPM  + m_shooter->SHOOTER_RPM_TOLERANCE)) && (ShooterRPM     > (WantedShooterRPM  - m_shooter->SHOOTER_RPM_TOLERANCE)) &&
     (LimeLightAngle <  m_shooter->LIMELIGHT_ANGLE_TOLERANCE)                  && (LimeLightAngle > -m_shooter->LIMELIGHT_ANGLE_TOLERANCE) && m_shooter->GetLimelightTargetValid())
  {
    m_driverFeedback->RumbleOn();
    m_driverFeedback->UpdateLEDs(0,255,0);
  }
  else
  {
    m_driverFeedback->RumbleOff();
  }
  
}

void CmdDriverFeedbackDefault::End(bool interrupted) 
{
	
}


bool CmdDriverFeedbackDefault::IsFinished() 
{
  return false;
}
