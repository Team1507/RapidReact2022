#include "commands/CmdIntakeDeploy.h"

CmdIntakeDeploy::CmdIntakeDeploy(IntakeRear *intake) 
{ 
  m_intake = intake;
}


void CmdIntakeDeploy::Initialize() 
{
  m_intake->Deploy();
}

void CmdIntakeDeploy::Execute() {}

void CmdIntakeDeploy::End(bool interrupted) {}

bool CmdIntakeDeploy::IsFinished() {
  return false;
}
