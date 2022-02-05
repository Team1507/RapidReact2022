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
    m_topHoodLimitSwitch = new frc::DigitalInput(HOOD_TOP_LIMIT_SWITCH);
    m_botHoodLimtSwitch = new frc::DigitalInput(HOOD_BOTTOM_LIMIT_SWITCH);
    
    

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
void Shooter::SetHoodAngle(double angle)
{
    m_hoodAngle = angle;
}
void Shooter::SetHoodPower(double power)
{
    m_hoodPower = power;
}
void Shooter::SetTurretAngle(double angle)
{
    m_turretAngle = angle;
}
void Shooter::SetTurretPower(double power)
{
    m_turretPower = power;
}
void Shooter::SetFeederOn(bool status)
{
    m_feederStatus = status;
}



double Shooter::GetLimelightHAngle(void)
{
    return 0;
}
double Shooter::GetLimelightVAngle(void)
{
    return 0;
}
double Shooter::GetLimelightDistance(void)
{
    return 0;
}
bool Shooter::GetLimelightTargetValid(void)
{
    return false;
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
double Shooter::GetHoodAngle(void)
{
    return m_hoodAngle;
}
double Shooter::GetHoodPower(void)
{
    return m_hoodPower;
}
double Shooter::GetTurretAngle(void)
{
    return m_turretAngle;
}
double Shooter::GetTurretPower(void)
{
    return m_turretPower;
}
bool Shooter::GetLeftTurretLimitSW(void)
{
    return false;
}
bool Shooter::GetRightTurretLimitSW(void)
{
    return false;
}
bool Shooter::GetTurretHomeSW(void)
{
    return false;
}
bool Shooter::GetTopFeederPhotoeye(void)
{
    return topFeederDetect;
}
bool Shooter::GetBotFeederPhotoeye(void)
{
    return botFeederDetect;
}
bool Shooter::GetFeederOn(void)
{
    return m_feederStatus;
}
bool Shooter::GetTopHoodLimitSW(void)
{
    return m_topHoodLimitSwitch; // return limit switch objects here once i create it 
}
bool Shooter::GetBotHoodLimitSW(void)
{
    return m_botHoodLimtSwitch;
}
void Shooter::ResetHoodEncoder(void)
{
    //Jack Waz Here
}
void Shooter::ResetTurretEncoder(void)
{

}
double Shooter::GetWantedHoodAngle()
{
 return wantedHoodAngle;
}
double Shooter::GetCurrentHoodAngle()
{
 return 0;
}
double Shooter::GetWantedTurretAngle()
{
 return wantedTurrentAngle;
}
double Shooter::GetCurrentTurretAngle()
{
    return 0;
}
double Shooter::GetWantedShooterRPM()
{
 return wantedShooterRPM;
}
double Shooter::GetCurrentShooterRPM()
{
    return 0;
}

void Shooter::Periodic() 
{
    
}
