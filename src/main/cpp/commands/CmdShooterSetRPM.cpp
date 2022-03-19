
#include "commands/CmdShooterSetRPM.h"

CmdShooterSetRPM::CmdShooterSetRPM(Shooter *shooter, double rpm) 
{
    m_shooter = shooter;
    m_rpm =  rpm;
}

void CmdShooterSetRPM::Initialize() 
{
    m_shooter->SetShooterRPM(m_rpm);
}

void CmdShooterSetRPM::Execute() {}

void CmdShooterSetRPM::End(bool interrupted) {}

bool CmdShooterSetRPM::IsFinished() {
  return true;
}
