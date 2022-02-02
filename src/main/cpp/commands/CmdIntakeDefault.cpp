#include "commands/CmdIntakeDefault.h"
#include <iostream>

CmdIntakeDefault::CmdIntakeDefault(Intake *intake, frc::XboxController *topDriver, Shooter *shooter) 
{
	m_intake = intake;
	m_topDriver = topDriver;
	m_shooter = shooter;
	AddRequirements(m_intake);
}

void CmdIntakeDefault::Initialize() 
{

}


void CmdIntakeDefault::Execute() 
{
	if( m_intake->GetType() == Intake::Type::FRONT)
	{
		if(m_topDriver->GetRightBumper())
		{
			m_intake->Deploy();
			m_intake->SetPower(FRONT_INTAKE_POWER);
			m_shooter->SetFeederOn(true);

		}
		else
		{	
			m_intake->SetPower(0);
			m_intake->Retract();
		}
	}
	
//****************************************************************
	if( m_intake->GetType() == Intake::Type::REAR)
	{
		if(m_topDriver->GetLeftBumper())
		{
			m_intake->Deploy();
			m_intake->SetPower(REAR_INTAKE_POWER);
			m_shooter->SetFeederOn(true);
		}
		else
		{	
			m_intake->SetPower(0);
			m_intake->Retract();
		}
	}
}


void CmdIntakeDefault::End(bool interrupted) 
{

}


bool CmdIntakeDefault::IsFinished() {
  return false;
}
