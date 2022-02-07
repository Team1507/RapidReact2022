#include "commands/CmdDriveClearAll.h"

CmdDriveClearAll::CmdDriveClearAll(Drivetrain *drivetrain) 
{
  m_ptrDrivetrain = drivetrain;
}

void CmdDriveClearAll::Initialize() 
{
  m_ptrDrivetrain->ResetEncoders();
  m_ptrDrivetrain->ResetOdometry();
  m_ptrDrivetrain->ZeroGyro();
}

void CmdDriveClearAll::Execute() 
{
  m_ptrDrivetrain->Drive( 0.0, 0.0 ); //Keep MotorSafety checks happy during Gyro Calibration
}

void CmdDriveClearAll::End(bool interrupted) {}

bool CmdDriveClearAll::IsFinished() 
{
  //Don't move until Gyro is finished calibrating
  return !m_ptrDrivetrain->IsGyroBusy();
  //return true;
}
