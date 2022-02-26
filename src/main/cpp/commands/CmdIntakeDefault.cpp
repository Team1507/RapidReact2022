#include "commands/CmdIntakeDefault.h"
#include <iostream>
#include "frc/smartdashboard/SmartDashboard.h"

CmdIntakeDefault::CmdIntakeDefault(Intake *intake, frc::XboxController *topDriver, Shooter *shooter, Feeder *feeder) 
{
	m_intake = intake;
	m_topDriver = topDriver;
	m_shooter = shooter;
	m_isFrontActive = false;
	m_isRearActive = false;
	AddRequirements(m_intake);
}

void CmdIntakeDefault::Initialize() 
{

}


void CmdIntakeDefault::Execute() 
{
	if(m_topDriver->GetRightBumper() && !m_isRearActive)// one intake down at a time
	{
		if( m_intake->GetType() == Intake::Type::FRONT)
		{
			double frontIntakePower = frc::SmartDashboard::GetNumber("FRONT_INTAKE_POWER", 0);
			m_intake->Deploy();
			m_intake->SetPower(frontIntakePower);
			m_feeder->SetFeederOn(true);
		}
		m_isFrontActive = true;
	}
	else
	{
		if( m_intake->GetType() == Intake::Type::FRONT)
		{
			m_intake->SetPower(0);
			m_intake->Retract();
		}
		m_isFrontActive = false;
	}

	// if( m_intake->GetType() == Intake::Type::FRONT)
	// {
	// 	if(m_topDriver->GetRightBumper() && !m_isRearActive) // one intake down at a time
	// 	{
	// 		double frontIntakePower = frc::SmartDashboard::GetNumber("FRONT_INTAKE_POWER", 0);
	// 		m_intake->Deploy();
	// 		m_intake->SetPower(frontIntakePower);
	// 		m_feeder->SetFeederOn(true);
	// 		m_isFrontActive = true;

	// 	}
	// 	else
	// 	{	
	// 		m_intake->SetPower(0);
	// 		m_intake->Retract();
	// 		m_isFrontActive = false;
	// 	}
	// }
	
//****************************************************************

	if(m_topDriver->GetLeftBumper() && !m_isFrontActive) // one intake down at a time
	{
		if(m_intake->GetType() == Intake::Type::REAR)
		{
			double rearIntakePower = frc::SmartDashboard::GetNumber("REAR_INTAKE_POWER", 0);
			m_intake->Deploy();
			m_intake->SetPower(rearIntakePower);
			m_feeder->SetFeederOn(true);
		}
		m_isRearActive = true;
	}
	else
	{
		if(m_intake->GetType() == Intake::Type::REAR)
		{
			m_intake->SetPower(0);
			m_intake->Retract();
		}
		m_isRearActive = false;
	}

	// if( m_intake->GetType() == Intake::Type::REAR)
	// {
	// 	if(m_topDriver->GetLeftBumper() && !m_isFrontActive) // one intake down at a time
	// 	{
	// 		double rearIntakePower = frc::SmartDashboard::GetNumber("REAR_INTAKE_POWER", 0);
	// 		m_intake->Deploy();
	// 		m_intake->SetPower(rearIntakePower);
	// 		m_feeder->SetFeederOn(true);
	// 		m_isRearActive = true;
	// 	}
	// 	else
	// 	{	
	// 		m_intake->SetPower(0);
	// 		m_intake->Retract();
	// 		m_isRearActive = false;
	// 	}
	// }
}


void CmdIntakeDefault::End(bool interrupted) 
{

}


bool CmdIntakeDefault::IsFinished() {
  return false;
}
