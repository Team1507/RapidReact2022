#include "commands/CmdIntakeRearDefault.h"
#include <iostream>
#include "frc/smartdashboard/SmartDashboard.h"

CmdIntakeRearDefault::CmdIntakeRearDefault(IntakeRear *intake, frc::XboxController *topDriver, frc::XboxController *botDriver, Shooter *shooter, Feeder *feeder) 
{
	m_intake = intake;
	m_topDriver = topDriver;
	m_shooter = shooter;
	m_isFrontActive = false;
	m_isRearActive = false;
	m_feeder = feeder;
	AddRequirements({m_intake});
}

void CmdIntakeRearDefault::Initialize() 
{

}


void CmdIntakeRearDefault::Execute() 
{
	if(m_topDriver->GetRightBumper() && !m_isFrontActive)// one intake down at a time   && !m_isRearActive
	{

		double rearIntakePower = frc::SmartDashboard::GetNumber("REAR_INTAKE_POWER", 0);

		m_intake->Deploy();
		m_intake->SetPower(rearIntakePower);
		m_feeder->SetFeederOn(true);

		m_isRearActive = true;
	}
	else
	{

		m_intake->SetPower(0);
		m_intake->Retract();

		m_isRearActive = false;
	}

	//************************************


	if(m_topDriver->GetLeftBumper()&& !m_isRearActive) // one intake down at a time    && !m_isFrontActive
	{
		m_isFrontActive = true;
	}
	else
	{
		m_isFrontActive = false;
	}

	
}


void CmdIntakeRearDefault::End(bool interrupted) 
{

}


bool CmdIntakeRearDefault::IsFinished() {
  return false;
}
