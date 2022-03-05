#include "commands/CmdIntakeSetPower.h"

CmdIntakeSetPower::CmdIntakeSetPower(IntakeRear *intake, double power) 
{
  m_intake = intake;
  m_power = power;
}


void CmdIntakeSetPower::Initialize() 
{
  m_intake->SetPower(m_power);
}


void CmdIntakeSetPower::Execute() {}


void CmdIntakeSetPower::End(bool interrupted) {}

// Returns true when the command should end.
bool CmdIntakeSetPower::IsFinished() {
  return true;
}
