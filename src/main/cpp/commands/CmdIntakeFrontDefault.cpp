#include "commands/CmdIntakeFrontDefault.h"
#include <iostream>
#include "frc/smartdashboard/SmartDashboard.h"

CmdIntakeFrontDefault::CmdIntakeFrontDefault(IntakeFront *intake, frc::XboxController *topDriver, frc::XboxController *botDriver, Shooter *shooter, Feeder *feeder) 
{
	m_intake = intake;
	m_topDriver = topDriver;
	m_shooter = shooter;
	m_isFrontActive = false;
	m_isRearActive = false;
	m_feeder = feeder;
	m_offDelayCount = 0;
	AddRequirements({m_intake});
}

void CmdIntakeFrontDefault::Initialize() 
{

}


void CmdIntakeFrontDefault::Execute() 
{
	if(m_topDriver->GetLeftBumper() && !m_isRearActive)// one intake down at a time   && !m_isRearActive
	{

		double frontIntakePower = frc::SmartDashboard::GetNumber("FRONT_INTAKE_POWER", 0);

		m_intake->Deploy();
		m_intake->SetPower(frontIntakePower);
		m_feeder->SetFeederOn(true);

		m_isFrontActive = true;
		m_offDelayCount = 25;				//1sec = 50 counts @20ms
	}
	else
	if( !m_topDriver->GetLeftBumper() && m_isFrontActive && (m_offDelayCount >0))// one intake down at a time   && !m_isRearActive
	{
		//Active, but now released  Delay turning off intake roller when arms on the way up
		//Retract but do not turn off feeder

		m_intake->Retract();
		m_offDelayCount--;

	}
	else
	{

		m_intake->SetPower(0);
		m_intake->Retract();

		m_isFrontActive = false;
	}

	//************************************


	if(m_topDriver->GetRightBumper()&& !m_isFrontActive) // one intake down at a time    && !m_isFrontActive
	{
		m_isRearActive = true;
	}
	else
	{
		m_isRearActive = false;
	}

	
}


void CmdIntakeFrontDefault::End(bool interrupted) 
{

}


bool CmdIntakeFrontDefault::IsFinished() {
  return false;
}
