#include "commands/CmdDriveWithGamepad.h"
#include "GamepadMap.h"
#include <iostream>

//Drive limiter
const double MAX_DRIVE_POWER = 1.0;
const double MAX_TURN_POWER  = 0.9;

CmdDriveWithGamepad::CmdDriveWithGamepad(Drivetrain *drivetrain, frc::XboxController *driver_xbox )
{
  
  m_ptrDrivetrain = drivetrain;
  m_ptrDriverXbox = driver_xbox;

  //SetName("Drivetrain");
  AddRequirements({m_ptrDrivetrain});
}


void CmdDriveWithGamepad::Initialize() 
{
  std::cout<<"Starting CmdDriveWithGamepad"<<std::endl;
}

void CmdDriveWithGamepad::Execute() 
{

    const double DEADBAND  = 0.05;

    double yL = m_ptrDriverXbox->GetRawAxis(GAMEPADMAP_AXIS_L_Y);
    double xL = m_ptrDriverXbox->GetRawAxis(GAMEPADMAP_AXIS_L_X);
    double yR = m_ptrDriverXbox->GetRawAxis(GAMEPADMAP_AXIS_R_Y);
    double xR = m_ptrDriverXbox->GetRawAxis(GAMEPADMAP_AXIS_R_X); 

    //double tL = m_driver_xbox->GetRawAxis(GAMEPADMAP_AXIS_L_TRIG);
    //double tR = m_driver_xbox->GetRawAxis(GAMEPADMAP_AXIS_R_TRIG);

    //Control DeadBand
    if (fabs(yL)<= DEADBAND) yL = 0;
    if (fabs(xL)<= DEADBAND) xL = 0;
    if (fabs(yR)<= DEADBAND) yR = 0;
    if (fabs(xR)<= DEADBAND) xR = 0;

    //Subtract off deadband
    if (fabs(yL)>= DEADBAND) yL +=  (yL>0)? -DEADBAND : +DEADBAND;
    if (fabs(xL)>= DEADBAND) xL +=  (xL>0)? -DEADBAND : +DEADBAND;
    if (fabs(yR)>= DEADBAND) yR +=  (yR>0)? -DEADBAND : +DEADBAND;
    if (fabs(xR)>= DEADBAND) xR +=  (xR>0)? -DEADBAND : +DEADBAND;



    //Arcade Drive

    static const double LEFT_TRIGGER_DEADBAND = 0.9;
    //Creep Mode
    if(m_ptrDriverXbox->GetLeftTriggerAxis() >= LEFT_TRIGGER_DEADBAND)
    {
        m_ptrDrivetrain->ArcadeDrive( ((-yL * MAX_DRIVE_POWER)/2)    , ((xR * MAX_TURN_POWER)/2) );
    }
    else
    {
      m_ptrDrivetrain->ArcadeDrive( -yL * MAX_DRIVE_POWER    , xR * MAX_TURN_POWER );
    }

    //Tank Drive
    //m_ptrDrivetrain->Drive( -yL* MAX_DRIVE_POWER , -yR * MAX_DRIVE_POWER );

}

void CmdDriveWithGamepad::End(bool interrupted) 
{
  std::cout<<"End CmdDriveWithGamepad " << interrupted <<std::endl;
}

bool CmdDriveWithGamepad::IsFinished()
{
  return false;
}
