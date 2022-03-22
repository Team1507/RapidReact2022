#include "commands/CmdDriverFeedbackDefault.h"
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc2/command/WaitCommand.h>
#include <iostream>
CmdDriverFeedbackDefault::CmdDriverFeedbackDefault(DriverFeedback *driverfeedback, frc::XboxController *topDriver, Shooter *shooter, Climber *climber) // 
{
  m_topDriver = topDriver;
	m_driverFeedback = driverfeedback;
  m_shooter = shooter;
  m_climber = climber;
	AddRequirements({m_driverFeedback});
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
  double LimeLightAngle    = m_shooter->GetLimelightHAngle()+frc::SmartDashboard::GetNumber("Limelight H Offset", -1.5);

  //BALLS!!!!!!
  
  if (1 == 2)
  {
    std::cout<<"ahhhhh"<<std::endl;
  }
  else if(m_climber->IsClimbBrakeActivated())
  {
    m_driverFeedback->UpdateLEDs(0,255,64);// purple
  }
  else if(m_topDriver->GetRightTriggerAxis() > 0.7)  
  {
    m_driverFeedback->RumbleOff();
    m_driverFeedback->UpdateLEDs(0,0,0);
  }
  else if((HoodAngle < (WantedHoodAngle   + m_shooter->HOOD_TOLERANCE))        && (HoodAngle      > (WantedHoodAngle   - m_shooter->HOOD_TOLERANCE)) && 
     (TurretAngle    < (WantedTurretAngle + m_shooter->TURRET_TOLERANCE))      && (TurretAngle    > (WantedTurretAngle - m_shooter->HOOD_TOLERANCE)) &&
     (ShooterRPM     < (WantedShooterRPM  + m_shooter->SHOOTER_RPM_TOLERANCE)) && (ShooterRPM     > (WantedShooterRPM  - m_shooter->SHOOTER_RPM_TOLERANCE)) &&
     (LimeLightAngle <  m_shooter->LIMELIGHT_ANGLE_TOLERANCE)                  && (LimeLightAngle > -m_shooter->LIMELIGHT_ANGLE_TOLERANCE && !m_shooter->IsIdle())) //&& m_shooter->GetLimelightTargetValid()) //&& !m_shooter->IsIdle())
  {
    m_driverFeedback->RumbleOn();
    m_driverFeedback->UpdateLEDs(255,0,0);//green
  }
  else if(m_shooter->GetLimelightTargetValid())
  {
    m_driverFeedback->UpdateLEDs(0,255,0); // red ben wuz here
    
  }


  else if(ShooterRPM < (WantedShooterRPM  + m_shooter->SHOOTER_RPM_TOLERANCE) && (ShooterRPM > (WantedShooterRPM - m_shooter->SHOOTER_RPM_TOLERANCE)) && (ShooterRPM > 100)) // if we need to shoot from up close and are not using the limelight
  {
    m_driverFeedback->UpdateLEDs(0,0,255); //blue
  }

  else
  {
    m_driverFeedback->RumbleOff();
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
