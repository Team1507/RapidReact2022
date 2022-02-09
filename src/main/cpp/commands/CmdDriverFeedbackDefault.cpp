#include "commands/CmdDriverFeedbackDefault.h"
#include <frc2/command/WaitCommand.h>
CmdDriverFeedbackDefault::CmdDriverFeedbackDefault(DriverFeedback *driverfeedback, frc::XboxController *topDriver, Shooter *shooter, Intake *intake) 
{
  m_topDriver = topDriver;
	m_driverFeedback = driverfeedback;
  m_shooter = shooter;
  m_intake = intake;
	AddRequirements(m_driverFeedback);
}


void CmdDriverFeedbackDefault::Initialize() 
{

}


void CmdDriverFeedbackDefault::Execute() 
{
  double HoodAngle         = m_shooter->GetCurrentHoodAngle();
  double TurretAngle       = m_shooter->GetCurrentTurretAngle();
  double WantedHoodAngle   = m_shooter->GetWantedHoodAngle();
  double WantedTurretAngle = m_shooter->GetWantedTurretAngle();
  double WantedShooterRPM  = m_shooter->GetWantedShooterRPM();
  double ShooterRPM        = m_shooter->GetCurrentShooterRPM();
  double LimeLightAngle    = m_shooter->GetLimelightHAngle();

  if(m_intake->GetIsIntaking())
  {
      m_driverFeedback->UpdateLEDs(255,0,0);
      frc2::WaitCommand(0.3_s);
      m_driverFeedback->UpdateLEDs(0,0,0);
      frc2::WaitCommand(0.3_s);
  }
  else if(m_topDriver->GetRightTriggerAxis() > 0.7)  
  {
    m_driverFeedback->RumbleOff();
    m_driverFeedback->UpdateLEDs(0,0,0);
  }

  else if((HoodAngle      < (WantedHoodAngle   + m_shooter->HOOD_TOLERANCE))        && (HoodAngle      > (WantedHoodAngle   - m_shooter->HOOD_TOLERANCE)) && 
     (TurretAngle    < (WantedTurretAngle + m_shooter->TURRET_TOLERANCE))      && (TurretAngle    > (WantedTurretAngle - m_shooter->HOOD_TOLERANCE)) &&
     (ShooterRPM     < (WantedShooterRPM  + m_shooter->SHOOTER_RPM_TOLERANCE)) && (ShooterRPM     > (WantedShooterRPM  - m_shooter->SHOOTER_RPM_TOLERANCE)) &&
     (LimeLightAngle <  m_shooter->LIMELIGHT_ANGLE_TOLERANCE)                  && (LimeLightAngle > -m_shooter->LIMELIGHT_ANGLE_TOLERANCE) && m_shooter->GetLimelightTargetValid())
  {
    m_driverFeedback->RumbleOn();
    m_driverFeedback->UpdateLEDs(0,255,0);
  }

  else if(ShooterRPM < (WantedShooterRPM  + m_shooter->SHOOTER_RPM_TOLERANCE) && (ShooterRPM > (WantedShooterRPM - m_shooter->SHOOTER_RPM_TOLERANCE))) // if we need to shoot from up close and are not using the limelight
  {
    m_driverFeedback->UpdateLEDs(0,0,255);
  }

  else if(m_shooter->GetLimelightTargetValid())
  {
      m_driverFeedback->UpdateLEDs(255,165,0); // orange
  }
  else
  {
      m_driverFeedback->UpdateLEDs(0,0,0);
  }
}

void CmdDriverFeedbackDefault::End(bool interrupted) 
{
	
}


bool CmdDriverFeedbackDefault::IsFinished() 
{
  return false;
}
