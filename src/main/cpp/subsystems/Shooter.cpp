#include "subsystems/Shooter.h"
#define PI 3.1415

Shooter::Shooter()
{
    double m_shooterRPM  = 0;
    double m_topFeederPower = 0;
    double m_bottomFeederPower = 0;
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
    if(m_isLimeLight3xMode)
    {
        //Three Times Mode
        //Change Limelight name
        //return nt::NetworkTableInstance::GetDefault().GetTable("limelight")->GetNumber("tx", 0);
    }
    else
    {
        //This is normal mode
        //Change Limelight name
        //return nt::NetworkTableInstance::GetDefault().GetTable("limelight")->GetNumber("tx", 0);
    }
    
    return 0;
}
double Shooter::GetLimelightVAngle(void)
{
    if(m_isLimeLight3xMode)
    {
        //Three Times Mode
        //Change Limelight name
        //return nt::NetworkTableInstance::GetDefault().GetTable("limelight")->GetNumber("ty", 0);
    }
    else
    {
        //This is normal mode
        //Change Limelight name
        //return nt::NetworkTableInstance::GetDefault().GetTable("limelight")->GetNumber("ty", 0);
    }
    
    return 0;
}
double Shooter::GetLimelightDistance(void)
{
    const double a1 = 19.3;//68.4;
    const double h1 = 24;
    const double h2 = 103.50;
    double a2;
    
    if(m_isLimeLight3xMode)
    {
        //Three Times Mode
        //Change Limelight name
        //a2 = nt::NetworkTableInstance::GetDefault().GetTable("limelight")->GetNumber("ty", 0);
    }
    else
    {
        //This is normal mode
        //Change Limelight name
        //a2 = nt::NetworkTableInstance::GetDefault().GetTable("limelight")->GetNumber("ty", 0);
    }
    return 0;
    //return (h2-h1)/tan((a1+a2)*(PI/180));
}
bool Shooter::GetLimelightTargetValid(void)
{
    if(m_isLimeLight3xMode)
    {
        //Three Times Mode
        //Change Limelight name
        //return (bool)nt::NetworkTableInstance::GetDefault().GetTable("limelight")->GetNumber("tv", 0);
    }
    else
    {
        //This is normal mode
        //Change Limelight name
        //return (bool)nt::NetworkTableInstance::GetDefault().GetTable("limelight")->GetNumber("tv", 0);
    }
    
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
    return m_leftTurretLimitSwitch.Get();
}
bool Shooter::GetRightTurretLimitSW(void)
{
    return m_rightTurretLimitSwitch.Get();
}
bool Shooter::GetTurretHomeSW(void)
{
    return m_turretHomeHallEffect.Get();
}
bool Shooter::GetTopFeederPhotoeye(void)
{
    return m_topFeederDetect.Get();
}
bool Shooter::GetBotFeederPhotoeye(void)
{
    return m_botFeederDetect.Get();
}
bool Shooter::GetFeederOn(void)
{
    return m_feederStatus;
}
bool Shooter::GetTopHoodLimitSW(void)
{
    return m_topHoodLimitSwitch.Get(); // return limit switch objects here once i create it 
}
bool Shooter::GetBotHoodLimitSW(void)
{
    return m_botHoodLimtSwitch.Get();
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
 return m_wantedHoodAngle;
}
double Shooter::GetCurrentHoodAngle()
{
 return 0;
}
double Shooter::GetWantedTurretAngle()
{
 return m_wantedTurrentAngle;
}
double Shooter::GetCurrentTurretAngle()
{
    return 0;
}
double Shooter::GetWantedShooterRPM()
{
 return m_wantedShooterRPM;
}
double Shooter::GetCurrentShooterRPM()
{
    return 0;
}
double Shooter::GetTempatureLeftShooter()
{
    return m_leftShooter.GetTemperature();
}
double Shooter::GetTempatureRightShooter()
{
    return m_rightShooter.GetTemperature();
}
double Shooter::GetTempatureHoodMotor()
{
    return m_hoodMotor.GetTemperature();
}
double Shooter::GetTempatureTurretMotor()
{
    return m_turretMotor.GetTemperature();
}
void Shooter::Periodic() 
{
    
}
void Shooter::LimeLight3xMode(bool is3xMode)
{
    m_isLimeLight3xMode = is3xMode;
}