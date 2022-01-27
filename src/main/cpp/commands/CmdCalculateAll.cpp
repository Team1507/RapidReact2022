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

  m_shooter->SetTurretYaw(0);

  vAngle = m_shooter->GetLimelightDistance();
  
  m_shooter->SetHoodEncoder(0);
  m_shooter->SetShooterRPM(0);
}

void CmdCalculateAll::End(bool interrupted) {}

bool CmdCalculateAll::IsFinished() {
  return true;
  //If GetLimeLightAngle is 0 then return true
}
