#include "subsystems/Shooter.h"

Shooter::Shooter()
{
    double m_shooterRPM  = 0;
    double m_feederPower = 0;
    double m_hoodEncoder = 0;
    double m_turretYaw   = 0;
}


void Shooter::SetShooterPower(double power)
{
    //set motor
}
void Shooter::SetShooterRPM(double rpm)
{
    m_shooterRPM = rpm;
}
void Shooter::SetFeederPower(double power)
{
    m_feederPower = power;
}
void Shooter::SetHoodEncoder(double angle)
{
    m_hoodEncoder = angle;
}
void Shooter::SetTurretYaw(double angle)
{
    m_turretYaw = angle;
}
void Shooter::SetTurretHome(void)
{
    m_turretYaw = 0;
}

double Shooter::GetLimelightAngle(void)
{
    return 0;
}
double Shooter::GetLimelightDistance(void)
{
    return 0;
}
double Shooter::GetShooterPower(void)
{
    return 0;
}
double Shooter::GetShooterRPM(void)
{
    return m_shooterRPM;
}
double Shooter::GetFeederPower(void)
{
    return m_feederPower;
}
double Shooter::GetHoodEncoder(void)
{
    return m_hoodEncoder;
}
bool Shooter::GetLeftLimitSW(void)
{
    return false;
}
bool Shooter::GetRightLimitSW(void)
{
    return false;
}
bool Shooter::GetHomeSW(void)
{
    return false;
}

void Shooter::Periodic() 
{
    
}
