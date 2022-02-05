#include "commands/CmdClimberDefault.h"


#define LYAXIS_DEADBAND  .1
#define LXAXIS_DEADBAND	 .1

//LB ENABLE WINCH ON BOTTOM DRIVE
//RIGHT AND LEFT ON LEFT STICK TOP DRIVER IS HIGH BAR
//UP AND DOWN ON LEFT STICK TOP DRIVER MID BAR
//BACK BUTTON TOP DRIVER ALSO ENBALES WINCH
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
	double topLYAxis = m_topDriver->GetRawAxis(GAMEPADMAP_AXIS_L_Y);
	double topLXAxis = m_topDriver->GetRawAxis(GAMEPADMAP_AXIS_L_X);

	if(m_topDriver->GetBackButton() && m_bottomDriver->GetLeftBumper())
	{
		if(topLYAxis>LYAXIS_DEADBAND || topLYAxis<-LYAXIS_DEADBAND)
		{
			m_climber->SetMidBarPower(topLYAxis); //Raise/Lower Winch for Mid Bar
		}
		else
		{
			m_climber->SetMidBarPower(0);
		}
		if(topLXAxis<-LXAXIS_DEADBAND)
		{
			m_climber->HighBarExtend(); //Raise/Lower Winch for High
		}
		if(topLXAxis>LXAXIS_DEADBAND)
		{
			m_climber->SetHighBarPower(-topLXAxis);
		}
		else
		{
			m_climber->SetHighBarPower(0);
		}
	}
	else
	{
		m_climber->SetHighBarPower(0);
		m_climber->SetMidBarPower(0);
	}
}


void CmdClimberDefault::End(bool interrupted) 
{

}


bool CmdClimberDefault::IsFinished() 
{
  return false;
}


