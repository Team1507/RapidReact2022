#include "commands/CmdIntakeRetract.h"

CmdIntakeRetract::CmdIntakeRetract(IntakeRear *intake) 
{
  m_intake = intake;
  AddRequirements({m_intake});
}


void CmdIntakeRetract::Initialize() 
{
  m_intake->Retract();
}


void CmdIntakeRetract::Execute() {}


void CmdIntakeRetract::End(bool interrupted) {}


bool CmdIntakeRetract::IsFinished() {
  return true;
}
