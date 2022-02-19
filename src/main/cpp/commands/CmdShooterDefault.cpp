#include "commands/CmdShooterDefault.h"
#include <math.h>

#define SHOOTER_kF_CONSTANT 0.0470          
#define SHOOTER_kP_CONSTANT 0.00035

#define TURRET_DEADBAND_CONSTANT 0.05

#define HOOD_kP_CONSTANT   0.058
#define TURRET_kP_CONSTANT 0.067

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
  bool ShootPressed = m_topDriver->GetRawAxis(GAMEPADMAP_AXIS_R_TRIG);
  bool TopFeederActivate = m_topDriver->GetYButton();
  bool BottomFeederActivate = m_topDriver->GetAButton();
  bool HoodControlActivate = m_topDriver->GetBButton();
  double LJYAxis = m_topDriver->GetRawAxis(GAMEPADMAP_AXIS_L_Y);
  double RJXAxis = m_topDriver->GetRawAxis(GAMEPADMAP_AXIS_R_X);
  //*******************************************************
  //x = return to home
  if(TurretHomePressed)
  {
    m_shooter->SetTurretAngle(0);
  }

  //*******************************************************
  //Lt = caculate all
  if(CalculateAllPressed)
  {
    
  }
  //*******************************************************
  //RJX = Manual Turret Control 
  if((RJXAxis > TURRET_DEADBAND_CONSTANT) || (RJXAxis < -TURRET_DEADBAND_CONSTANT))
  {
    double power = RJXAxis;
    m_shooter->SetTurretPower(power);
  }

  //*******************************************************
  //rt = shoot
  if(ShootPressed == 1) // pressed
  {
    //m_shooter->SetTopFeederPower(TOP_FEEDER_SHOOTING_POWER);
    //m_shooter->SetBottomFeederPower(BOTTOM_FEEDER_SHOOTING_POWER);
    //m_shooter->SetFeederOn(false);    //This is here to allow shooting and intake, ignore intake if shooter is on

  }
 else if (ShootPressed == 0) // released 
 {
 //   m_shooter->SetTopFeederPower(0);
 //   m_shooter->SetBottomFeederPower(0);
 }
  
  //*******************************************************
  //Y + LJ = Top Feeder Manual
  // if(TopFeederActivate) 
  // {
  //   m_topFeederPower = m_topDriver->GetRawAxis(GAMEPADMAP_AXIS_L_Y);
  //   m_shooter->SetTopFeederPower(m_topFeederPower);
  // }
  // else 
  
  // //*******************************************************
  // //A + LJ = Bottom Feeder Manual
  // if(BottomFeederActivate) 
  // {
  //   m_bottomFeederPower = m_topDriver->GetRawAxis(GAMEPADMAP_AXIS_L_Y);
  //   m_shooter->SetBottomFeederPower(m_bottomFeederPower);
  // }
  // else
  // //*************************************************
  // //Feeder State Machine
  // if(m_shooter->GetFeederOn() && !m_shooter->GetTopFeederPhotoeye())
  // {
  //   m_shooter->SetTopFeederPower(TOP_FEEDER_INTAKE_POWER);   
  // }
  // else if(m_shooter->GetFeederOn() && m_shooter->GetTopFeederPhotoeye())
  // {
  //   m_shooter->SetTopFeederPower(0);
  // }
  // if(m_shooter->GetFeederOn() && !m_shooter->GetBotFeederPhotoeye())
  // {
  //   m_shooter->SetBottomFeederPower(BOTTOM_FEEDER_INTAKE_POWER);
  // }
  // else if(m_shooter->GetFeederOn() && m_shooter->GetBotFeederPhotoeye() && m_shooter->GetTopFeederPhotoeye())
  // {
  //   m_shooter->SetBottomFeederPower(0);
  //   m_shooter->SetTopFeederPower(0); //fail safe just in case
  //   m_shooter->SetFeederOn(false);
  // }
  //*************************************************
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
        m_shooter->SetHoodAngle(0);//make a state
        m_shooter->SetTurretAngle(0);//make a state
        break;
      case 90:
        m_shooter->SetShooterRPM(0);//make a state
        m_shooter->SetHoodAngle(0);//make a state
        m_shooter->SetTurretAngle(0);//make a state
        break;
      case 180:
        m_shooter->SetShooterRPM(0);//make a state
        m_shooter->SetHoodAngle(0);//make a state
        m_shooter->SetTurretAngle(0);//make a state
        break;
      case 270:
        m_shooter->SetShooterRPM(0);//make a state
        m_shooter->SetHoodAngle(0);//make a state
        m_shooter->SetTurretAngle(0);//make a state
        break;
    }
  }
  


  
#ifndef SHOOTER_PID

  //Calcualate

//***************************SHOOTER ERROR****************************
  if(m_shooter->GetCurrentShooterRPM() > 0.0)
  {
    const int MAX_POS_ERROR = 1500;
    const int MAX_NEG_ERROR = -100;
    
    const double HOOD_TOLERANCE = 2;
    const double SHOOTER_RPM = 3;

    double curr_velocity = m_shooter->GetShooterVelocity();
    double curr_power = m_shooter->GetShooterPower();

    double v_error = RPM2Velocity(m_shooter->GetCurrentShooterRPM()) - curr_velocity;
    frc::SmartDashboard::PutNumber("v error", v_error);
    if( v_error > MAX_POS_ERROR)    v_error = MAX_POS_ERROR;
    if( v_error < MAX_NEG_ERROR)    v_error = MAX_NEG_ERROR;

    double shoot_power = (m_shooter->GetCurrentShooterRPM() * SHOOTER_kF_CONSTANT) + (v_error * SHOOTER_kP_CONSTANT); // kP/kF made for Dot, will have to recalc once build team gives us the bot
    frc::SmartDashboard::PutNumber("shoot_power", shoot_power);

    if( shoot_power < curr_power ) shoot_power-= 0.01;    //Ramp down slowly to prevent belt slip
        
    if( shoot_power > 1.0 ) shoot_power = 1.0;
    if( shoot_power < 0.0 ) shoot_power = 0.0;

    //m_shooter->(shoot_power); ************wtf???????
    m_shooter->SetShooterPower(shoot_power);

    frc::SmartDashboard::PutNumber("Curr Power", curr_power);
    frc::SmartDashboard::PutNumber("Curr Velocity", curr_velocity);

  }
#endif 

  //*****************************************************
  //*********************TURRET ERROR********************
  const double TURRET_TOLERANCE = 1;
  const double TURRET_MIN_POWER = 0.07;
    
  const int MAX_POS_TURRET_POWER = 0.7;
  const int MAX_NEG_TURRET_POWER = -0.7;

  double turretangle = m_shooter->GetCurrentTurretAngle();
  double wantedTurretAngle = m_shooter->GetWantedTurretAngle();
    
  double turret_error = turretangle - wantedTurretAngle;
  double turret_power = (turret_error * TURRET_kP_CONSTANT);

        
  if( turret_power > MAX_POS_TURRET_POWER ) turret_power = MAX_POS_TURRET_POWER;
  if( turret_power < MAX_NEG_TURRET_POWER ) turret_power = MAX_NEG_TURRET_POWER;
  if( abs(turret_error) > TURRET_TOLERANCE)
  {
    if(turret_power < 0)
    {
      m_shooter->SetTurretPower(turret_power -TURRET_MIN_POWER); 
    }
    else if(turret_power > 0)
    {
      m_shooter->SetTurretPower(turret_power +TURRET_MIN_POWER); 
    }
  }
  else
  {
    m_shooter->SetTurretPower(0.0);
  }


  //******************************************************
  //*********************HOOD ERROR***********************
  const double HOOD_TOLERANCE = 1;
  const double HOOD_MIN_POWER = 0.07;
    
  const int MAX_POS_HOOD_POWER = 0.7;
  const int MAX_NEG_HOOD_POWER = -0.7;

  double hoodangle = m_shooter->GetCurrentHoodAngle();
  double wantedHoodAngle = m_shooter->GetWantedHoodAngle();
    
  double hood_error = hoodangle - wantedHoodAngle;
  double hood_power = (hood_error * HOOD_kP_CONSTANT);

        
  if( hood_power > MAX_POS_HOOD_POWER ) hood_power = MAX_POS_HOOD_POWER;
  if( hood_power < MAX_NEG_HOOD_POWER ) hood_power = MAX_NEG_HOOD_POWER;
  if( abs(hood_error) > HOOD_TOLERANCE)
  {
    if(hood_power < 0)
    {
      m_shooter->SetHoodPower(hood_power -HOOD_MIN_POWER); 
    }
    else if(hood_power > 0)
    {
      m_shooter->SetHoodPower(hood_power +HOOD_MIN_POWER); 
    }
  }
  else
  {
    m_shooter->SetHoodPower(0.0);
  }
  
}

void CmdShooterDefault::End(bool interrupted) {}

bool CmdShooterDefault::IsFinished() {
  return false;
}
