#include "commands/CmdClimberDefault.h"

CmdClimberDefault::CmdClimberDefault(Climber *climber, frc::XboxController *topDriver, frc::XboxController *bottomDriver) 
{
	m_climber = climber;
	m_topDriver = topDriver;
	m_bottomDriver = bottomDriver;
	AddRequirements(m_climber);
}

void CmdClimberDefault::Initialize() 
{

}


void CmdClimberDefault::Execute() 
{
	double bottomLYAxis = m_bottomDriver->GetRawAxis(GAMEPADMAP_AXIS_L_Y);
	double bottomLXAxis = m_bottomDriver->GetRawAxis(GAMEPADMAP_AXIS_L_X);

	if(m_topDriver->GetBackButton() && m_bottomDriver->GetLeftBumper())
	{
		m_climber->MidBarPower(bottomLYAxis); //Raise/Lower Winch for Mid Bar
		m_climber->HighBarPower(bottomLXAxis); //Raise/Lower Winch for High
	}

}


void CmdClimberDefault::End(bool interrupted) 
{

}


bool CmdClimberDefault::IsFinished() {
  return false;
}
