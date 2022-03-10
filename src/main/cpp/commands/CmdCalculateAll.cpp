#include "commands/CmdCalculateAll.h"
#include <frc/smartdashboard/SmartDashboard.h>
#include <iostream>

CmdCalculateAll::CmdCalculateAll(Shooter *shooter) 
{
  m_shooter = shooter;
}

void CmdCalculateAll::Initialize() 
{
  

  const double SHOOTER_POWER_RATIO = 0; //Change later
  const double SHOOTER_HOOD_RATIO = 0; //Change later
  
  //getting limelight and aim and speed
  
  if(m_shooter->GetLimelightTargetValid() == true) 
  {
    std::cout<<"Aiming towards target with limelight"<<std::endl;
    double limelightHOffset = frc::SmartDashboard::GetNumber("Limelight H Offset", 0.0);
    m_shooter->SetTurretAngle(m_shooter->GetCurrentTurretAngle() + m_shooter->GetLimelightHAngle() + limelightHOffset);
    // m_shooter->SetShooterRPM(m_shooter->GetLimelightDistance() * SHOOTER_POWER_RATIO);
    // m_shooter->SetHoodAngle(m_shooter->GetLimelightDistance() * SHOOTER_HOOD_RATIO);
  }
  else 
  {
    std::cout<<"Target not found"<<std::endl;
  }
  
}