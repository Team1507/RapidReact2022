#include "commands/CmdIntakeDefault.h"

CmdIntakeDefault::CmdIntakeDefault(Intake *intake, frc::XboxController *topDriver) 
{
	m_intake = intake;
	m_topDriver = topDriver;
	AddRequirements(m_intake);
}

void CmdIntakeDefault::Initialize() 
{

}


void CmdIntakeDefault::Execute() 
{

	if(m_topDriver->GetRightBumper())
	{
		m_intake->Deploy();
		m_intake->SetPower(0);
	}
	else
	{
		m_intake->Retract();
		m_intake->SetPower(0);
	}
//****************************************************************
	if(m_topDriver->GetLeftBumper())
	{
		m_intake->Deploy();
		m_intake->SetPower(0);
	}
	else
	{
		m_intake->Retract();
		m_intake->SetPower(0);
	}

}


void CmdIntakeDefault::End(bool interrupted) 
{

}


bool CmdIntakeDefault::IsFinished() {
  return false;
}
