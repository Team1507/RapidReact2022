#include "commands/CmdShooterDefault.h"
#include "commands/CmdCalculateAllV2.h"
#include "commands/CmdCalculateAll.h"
#include <math.h>
#include <iostream>

#define SHOOTER_kF_CONSTANT 0.0470          
#define SHOOTER_kP_CONSTANT 0.00035

#define TURRET_DEADBAND_CONSTANT    0.5    // purposfully high
#define HOOD_DEADBAND_CONSTANT      0.5    // purposfully high

#define HOOD_kP_CONSTANT   0.00058
#define TURRET_kP_CONSTANT 0.03

CmdShooterDefault::CmdShooterDefault(Shooter *shooter, frc::XboxController *topDriver) 
{
  m_shooter = shooter;
  m_topDriver = topDriver;
  AddRequirements({m_shooter});

}

void CmdShooterDefault::Initialize() 
{
    std::cout << "    CmdShootDefault Started!" << std::endl;
}

void CmdShooterDefault::Execute() 
{
  bool TurretHomePressed   = m_topDriver->GetXButton();
  bool CalculateAllPressed = ( m_topDriver->GetLeftTriggerAxis() > 0.9);
  bool ShootPressed        = ( m_topDriver->GetRawAxis(GAMEPADMAP_AXIS_R_TRIG) > 0.9);
  double RJYAxis           = m_topDriver->GetRawAxis(GAMEPADMAP_AXIS_R_Y);
  double RJXAxis           = m_topDriver->GetRawAxis(GAMEPADMAP_AXIS_R_X);
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
    double limelightHOffset = frc::SmartDashboard::GetNumber("Limelight H Offset", 0.0);
    m_shooter->SetTurretAngle(m_shooter->GetCurrentTurretAngle() + m_shooter->GetLimelightHAngle() + limelightHOffset);
  }


  //Check for Turret/Hood Limit Switch
  if(m_shooter->GetLeftTurretLimitSW() )
  {
    m_shooter->SetTurretEncoderAtLeft();
  }
  if(m_shooter->GetRightTurretLimitSW() )
  {
    m_shooter->SetTurretEncoderAtRight();
  }
  if(m_shooter->GetBotHoodLimitSW() )
  {
    m_shooter->ResetHoodEncoder();
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
      case 0: //Fender Shot
        //m_shooter->SetShooterRPM(0);
        m_shooter->SetHoodAngle(0);
        m_shooter->SetTurretAngle(0);
        m_shooter->SetShooterPower(frc::SmartDashboard::GetNumber("Shooter Fender Power",0.0));        
        std::cout << "DPAD: Fender Shot" << std::endl;
        isDpadCenter = false;
        break;
      case 90: // Idle 
        //m_shooter->SetShooterRPM(0);
        m_shooter->SetHoodAngle(0);
        m_shooter->SetTurretAngle(0);
        m_shooter->SetShooterPower(frc::SmartDashboard::GetNumber("Shooter Idle Power",0.0));   
        std::cout << "DPAD: Idle" << std::endl;
        isDpadCenter = false;
        break;
      case 180: //Launch Pad Shot
        //m_shooter->SetShooterRPM(0);
        m_shooter->SetHoodAngle(16000);
        m_shooter->SetTurretAngle(35.0);
        m_shooter->SetShooterPower(frc::SmartDashboard::GetNumber("Shooter Launch Pad Power",0.0));   
        std::cout << "DPAD: Launch Pad" << std::endl;
        isDpadCenter = false;
        break;
      case 270: //Tarmac Line Shot
        //m_shooter->SetShooterRPM(0);
        m_shooter->SetHoodAngle(12000);
        //m_shooter->SetTurretAngle(0);
        m_shooter->SetShooterPower(frc::SmartDashboard::GetNumber("Shooter Tarmac Line Power",0.0));   
        std::cout << "DPAD: Tarmac" << std::endl;
        isDpadCenter = false;
        break;
    }
  }
  


  
#ifndef SHOOTER_PID

  //Calcualate
/*
//***************************SHOOTER ERROR****************************
  if(m_shooter->GetCurrentShooterRPM() > 0.0)
  {
    const int MAX_POS_ERROR = 1500;
    const int MAX_NEG_ERROR = -100;
  
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
*/
#endif 

  //*******************************************************
  //*********************TURRET CONTROL********************

  //RJX = Manual Turret Control 
  if(RJXAxis > TURRET_DEADBAND_CONSTANT)
  {
    m_shooter->SetTurretPower(TURRET_SLOW_POWER);
     m_shooter->SetTurretAngle(m_shooter->GetCurrentTurretAngle());
  } 
  else if(RJXAxis < -TURRET_DEADBAND_CONSTANT)
  {
    m_shooter->SetTurretPower(-TURRET_SLOW_POWER);
     m_shooter->SetTurretAngle(m_shooter->GetCurrentTurretAngle());
  }
  else
  {
    const double TURRET_TOLERANCE = 1.0;
    const double TURRET_MIN_POWER = 0.07;
    
    const double MAX_POS_TURRET_POWER = 0.3;
    const double MAX_NEG_TURRET_POWER = -0.3;

    double turretangle = m_shooter->GetCurrentTurretAngle();
    double wantedTurretAngle = m_shooter->GetWantedTurretAngle();
    
    double turret_error = wantedTurretAngle - turretangle;
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
  }


  


  //******************************************************
  //*********************HOOD Control ***********************


  //******************************************************
  //RJY = Manual Hood Control
  if(RJYAxis > HOOD_DEADBAND_CONSTANT)
  {
    m_shooter->SetHoodPower(HOOD_SLOW_POWER);
    m_shooter->SetHoodAngle(m_shooter->GetCurrentHoodAngle());
  }
  else if(RJYAxis < -HOOD_DEADBAND_CONSTANT)
  {
    m_shooter->SetHoodPower(-HOOD_SLOW_POWER);
    m_shooter->SetHoodAngle(m_shooter->GetCurrentHoodAngle());
  }
  else
  {
    //Values in encoder ticks
    const double HOOD_TOLERANCE = 200;
    const double HOOD_MIN_POWER = 0.07;
    
    const double MAX_POS_HOOD_POWER = 0.5;
    const double MAX_NEG_HOOD_POWER = -0.5;

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



//END of Execute()
}

void CmdShooterDefault::End(bool interrupted) 
{
  std::cout << "    CmdShootDefault Exited!" << std::endl;
}

bool CmdShooterDefault::IsFinished() {
  return false;
}
