#include "commands/CmdIntakeDefault.h"
#include <iostream>
#include "frc/smartdashboard/SmartDashboard.h"

CmdIntakeDefault::CmdIntakeDefault(Intake *intake, frc::XboxController *topDriver, frc::XboxController *botDriver, Shooter *shooter, Feeder *feeder) 
{
	m_intake = intake;
	m_topDriver = topDriver;
	m_shooter = shooter;
	m_botDriver = botDriver;
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
			double frontIntakePower = frc::SmartDashboard::GetNumber("FRONT_INTAKE_POWER", 0);
			m_intake->Deploy();
			m_intake->SetPower(frontIntakePower);
			m_feeder->SetFeederOn(true);

		}
		else
		{	
			m_intake->SetPower(0);
			m_intake->Retract();
		}

		if(m_topDriver->GetBackButton() && m_botDriver->GetLeftBumper()) //if we go to climb, front intake needs to be deployed in order for a 10 point climb to happen
		{
			m_intake->Deploy();
		}
		else
		{
			m_intake->Retract();
		}
	}
	
//****************************************************************
	if( m_intake->GetType() == Intake::Type::REAR)
	{
		if(m_topDriver->GetLeftBumper())
		{
			double rearIntakePower = frc::SmartDashboard::GetNumber("REAR_INTAKE_POWER", 0);
			m_intake->Deploy();
			m_intake->SetPower(rearIntakePower);
			m_feeder->SetFeederOn(true);
		}
		else
		{	
			m_intake->SetPower(0);
			m_intake->Retract();
		}
	}
//****************************************************************

}


void CmdIntakeDefault::End(bool interrupted) 
{

}


bool CmdIntakeDefault::IsFinished() {
  return false;
}
