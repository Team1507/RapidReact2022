#include "commands/CmdFeederSetStatus.h"

CmdFeederSetStatus::CmdFeederSetStatus(Feeder *feeder, bool status) 
{
  m_feeder = feeder;
  m_status = status;
}

void CmdFeederSetStatus::Initialize() 
{
  m_feeder->SetFeederOn(m_status);
}
