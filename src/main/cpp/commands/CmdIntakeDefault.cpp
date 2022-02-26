#include "commands/CmdIntakeDefault.h"
#include <iostream>
#include "frc/smartdashboard/SmartDashboard.h"

CmdIntakeDefault::CmdIntakeDefault(Intake *intake, frc::XboxController *topDriver, frc::XboxController *botDriver, Shooter *shooter, Feeder *feeder) 
{
	m_intake = intake;
	m_topDriver = topDriver;
	m_shooter = shooter;
<<<<<<< HEAD
	m_isFrontActive = false;
	m_isRearActive = false;
=======
	m_botDriver = botDriver;
>>>>>>> 8df50a7e1c81eaf9a2ab4b2da99e5e220380dfbc
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
<<<<<<< HEAD
		m_isFrontActive = false;
=======

		if(m_topDriver->GetBackButton() && m_botDriver->GetLeftBumper()) //if we go to climb, front intake needs to be deployed in order for a 10 point climb to happen
		{
			m_intake->Deploy();
		}
		else
		{
			m_intake->Retract();
		}
>>>>>>> 8df50a7e1c81eaf9a2ab4b2da99e5e220380dfbc
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
<<<<<<< HEAD

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
=======
//****************************************************************

>>>>>>> 8df50a7e1c81eaf9a2ab4b2da99e5e220380dfbc
}


void CmdIntakeDefault::End(bool interrupted) 
{

}


bool CmdIntakeDefault::IsFinished() {
  return false;
}
