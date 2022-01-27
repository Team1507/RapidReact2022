#include "commands/CmdShooterDefault.h"

#define SHOOTER_kF_CONSTANT 0.0470          
#define SHOOTER_kP_CONSTANT 0.00035

CmdShooterDefault::CmdShooterDefault(Shooter *shooter, frc::XboxController *topDriver) 
{
  m_shooter = shooter;
  m_topDriver = topDriver;
  AddRequirements(m_shooter);
}

void CmdShooterDefault::Initialize() {}

void CmdShooterDefault::Execute() 
{
  bool TurretHomePressed = m_topDriver->GetXButton();
  bool CalculateAllPressed = m_topDriver->GetLeftTriggerAxis();
  bool ShootPressed = m_topDriver->GetRightTriggerAxis();
  bool TopFeederActivate = m_topDriver->GetYButton();
  bool BottomFeederActivate = m_topDriver->GetAButton();
  bool HoodControlActivate = m_topDriver->GetBButton();
  double LJYAxis = m_topDriver->GetRawAxis(GAMEPADMAP_AXIS_L_Y);
  double RJYAxis = m_topDriver->GetRawAxis(GAMEPADMAP_AXIS_R_Y);
  //*******************************************************
  //x = return to home
  if(TurretHomePressed)
  {
    m_shooter->SetTurretHome();
  }

  //*******************************************************
  //Lt = caculate all
  if(CalculateAllPressed)
  {
    
  }

  //*******************************************************
  //rt = shoot
  if(ShootPressed)
  {
    m_shooter->SetTopFeederPower(TOP_FEEDER_SHOOTING_SPEED);
    m_shooter->SetBottomFeederPower(BOTTOM_FEEDER_SHOOTING_SPEED);
  }
  else
  
  //*******************************************************
  //Y + LJ = Top Feeder Manual
  if(TopFeederActivate) 
  {
    m_topFeederPower = m_topDriver->GetRawAxis(GAMEPADMAP_AXIS_L_Y);
    m_shooter->SetTopFeederPower(m_topFeederPower);
  }
  else 
  
  //*******************************************************
  //A + LJ = Bottom Feeder Manual
  if(BottomFeederActivate) 
  {
    m_bottomFeederPower = m_topDriver->GetRawAxis(GAMEPADMAP_AXIS_L_Y);
    m_shooter->SetBottomFeederPower(m_bottomFeederPower);
  }
  else
  {
    m_shooter->SetTopFeederPower(0);
    m_shooter->SetBottomFeederPower(0);
  }
  //*******************************************************
  //Dpad = set shooting velocities
  int DpadState = m_topDriver->GetPOV(0);
  static bool isDpadCenter = false;
  if(DpadState == -1)
  {
    isDpadCenter = true;
  }
  
  if(isDpadCenter)
  {
    switch(DpadState)
    {
      case 0:
        m_shooter->SetShooterRPM(0);//make a state
        m_shooter->SetHoodEncoder(0);//make a state
        m_shooter->SetTurretYaw(0);//make a state
        break;
      case 90:
        m_shooter->SetShooterRPM(0);//make a state
        m_shooter->SetHoodEncoder(0);//make a state
        m_shooter->SetTurretYaw(0);//make a state
        break;
      case 180:
        m_shooter->SetShooterRPM(0);//make a state
        m_shooter->SetHoodEncoder(0);//make a state
        m_shooter->SetTurretYaw(0);//make a state
        break;
      case 270:
        m_shooter->SetShooterRPM(0);//make a state
        m_shooter->SetHoodEncoder(0);//make a state
        m_shooter->SetTurretYaw(0);//make a state
        break;
    }
  }
  


  




  //Calcualate


//***************************SHOOTER ERROR****************************
  if(m_shooter->GetShooterRPM() == 0)
  {
    m_shooter->SetShooterPower(0);
  }
  else
  {
    
    const int MAX_POS_ERROR = 1500;
    const int MAX_NEG_ERROR = -100;

    double curr_velocity = m_shooter->GetShooterVelocity();
    double curr_power = m_shooter->GetShooterPower();

    double v_error = m_shooter->GetShooterRPM()*1000 - curr_velocity;
    frc::SmartDashboard::PutNumber("v error", v_error);
    if( v_error > MAX_POS_ERROR)    v_error = MAX_POS_ERROR;
    if( v_error < MAX_NEG_ERROR)    v_error = MAX_NEG_ERROR;

    double shoot_power = (m_shooter->GetShooterRPM() * SHOOTER_kF_CONSTANT) + (v_error * SHOOTER_kP_CONSTANT);
    frc::SmartDashboard::PutNumber("shoot_power", shoot_power);

    if( shoot_power < curr_power ) shoot_power-= 0.01;    //Ramp down slowly to prevent belt slip
        
    if( shoot_power > 1.0 ) shoot_power = 1.0;
    if( shoot_power < 0.0 ) shoot_power = 0.0;

    //m_shooter->(shoot_power); ************wtf???????

    frc::SmartDashboard::PutNumber("Curr Power", curr_power);
    frc::SmartDashboard::PutNumber("Curr Velocity", curr_velocity);

  }

  //*****************************************************
  //*********************TURRET ERROR********************

  


}

void CmdShooterDefault::End(bool interrupted) {}

bool CmdShooterDefault::IsFinished() {
  return false;
}
