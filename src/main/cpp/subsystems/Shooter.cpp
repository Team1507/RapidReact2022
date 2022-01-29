#include "subsystems/Shooter.h"

Shooter::Shooter()
{
    double m_shooterRPM  = 0;
    double m_topFeederPower = 0;
    double m_bottomFeederPower = 0;
    double m_hoodEncoder = 0;
    double m_turretYaw   = 0;
    topFeederDetect = new frc::DigitalInput(0);
    botFeederDetect = new frc::DigitalInput(1);
    

}


void Shooter::SetShooterPower(double power)
{
    //set motor
}
void Shooter::SetShooterRPM(double rpm)
{
    m_shooterRPM = rpm;
}
void Shooter::SetTopFeederPower(double power)
{
    m_topFeederPower = power;
}
void Shooter::SetBottomFeederPower(double power)
{
    m_bottomFeederPower = power;
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
void Shooter::SetFeederOn(bool status)
{
    m_feederStatus = status;
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
double Shooter::GetShooterVelocity(void)
{
    return 0; // m_shooterMotos.GetSelectedSensorVelocity(SHOOTER_PID_SLOT)
}
double Shooter::GetTopFeederPower(void)
{
    return m_topFeederPower;
}
double Shooter::GetBottomFeederPower(void)
{
    return m_bottomFeederPower;
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
bool Shooter::GetTopPhotoeye(void)
{
    return topFeederDetect;
}
bool Shooter::GetBotPhotoeye(void)
{
    return botFeederDetect;
}
bool Shooter::GetFeederOn(void)
{
    return m_feederStatus;
}
void Shooter::Periodic() 
{
    
}
