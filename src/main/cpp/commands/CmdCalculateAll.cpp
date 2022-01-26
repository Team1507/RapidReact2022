#include "commands/CmdCalculateAll.h"


CmdCalculateAll::CmdCalculateAll(Shooter *shooter, frc::XboxController *topDriver)

{
  m_shooter = shooter;
  m_topDriver = topDriver;
  AddRequirements(m_shooter);
}

void CmdCalculateAll::Initialize() {}

void CmdCalculateAll::Execute() 
{
  hAngle = m_shooter->GetLimelightAngle();
  //Calculate Limelight math here
  m_shooter->SetTurretYaw(0);
  vAngle = m_shooter->GetLimelightDistance();
  //Find hood angle & shooter speed
  m_shooter->SetHoodEncoder(0);
  m_shooter->SetShooterRPM(0);
}

void CmdCalculateAll::End(bool interrupted) 
{
//   m_topDriver->SetRumble(frc::XboxController::kLeftRumble,1);
//   m_topDriver->SetRumble(frc::XboxController::kRightRumble,1);
//   m_timer.Reset();
//   m_timer.Start();
//   if(m_timer.Get() >= (units::second_t)1.0)
//   {
// 	m_topDriver->SetRumble(frc::XboxController::kLeftRumble,0);
//   	m_topDriver->SetRumble(frc::XboxController::kRightRumble,0);
//   }

}

bool CmdCalculateAll::IsFinished() {
  return true;
  //If GetLimeLightAngle is 0 then return true
}
