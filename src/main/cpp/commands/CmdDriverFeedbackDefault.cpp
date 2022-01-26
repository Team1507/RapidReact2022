#include "commands/CmdDriverFeedbackDefault.h"

CmdDriverFeedbackDefault::CmdDriverFeedbackDefault(DriverFeedback *driverfeedback, frc::XboxController *topDriver) 
{
    m_topDriver = topDriver;
	m_driverFeedback = driverfeedback;
	AddRequirements(m_driverFeedback);
}


void CmdDriverFeedbackDefault::Initialize() 
{

}


void CmdDriverFeedbackDefault::Execute() 
{
	
}


void CmdDriverFeedbackDefault::End(bool interrupted) 
{
	
}


bool CmdDriverFeedbackDefault::IsFinished() 
{
  return false;
}
