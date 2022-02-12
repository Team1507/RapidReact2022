#include "subsystems/Shooter.h"
#include <networktables/NetworkTable.h>
#include <networktables/NetworkTableInstance.h>
#include <iostream>

#define PI 3.1415
#define HOOD_TICK2ANGLE 1 //change later
#define TURRET_TICK2ANGLE 1 //change later

Shooter::Shooter()
{
    double m_shooterRPM        = 0;
    double m_topFeederPower    = 0;
    double m_bottomFeederPower = 0;
    double m_hoodEncoder       = 0;
    double m_turretYaw         = 0;
}

void Shooter::Periodic() 
{
    
}

//*********************SHOOTER********************

void Shooter::SetShooterPower(double power)
{
    m_leftShooter.Set(ControlMode::PercentOutput, power);
}
void Shooter::SetShooterRPM(double rpm)
{
    m_wantedShooterRPM = rpm;
}
double Shooter::GetShooterPower(void)
{
    return m_rightShooter.GetMotorOutputPercent();
}
double Shooter::GetShooterVelocity(void)
{
    return m_rightShooter.GetSelectedSensorVelocity();
}
double Shooter::GetWantedShooterRPM()
{
    return m_wantedShooterRPM;
}
double Shooter::GetCurrentShooterRPM()
{
    return Velocity2RPM(m_rightShooter.GetSelectedSensorVelocity());
}
double Shooter::GetTempatureLeftShooter()
{
    return m_leftShooter.GetTemperature();
}
double Shooter::GetTempatureRightShooter()
{
    return m_rightShooter.GetTemperature();
}
void Shooter::InitFalcons()
{
    std::cout<<"Shooter: Falcon Init"<<std::endl;

    //reset
    m_leftShooter.ConfigFactoryDefault();
    m_rightShooter.ConfigFactoryDefault();
    m_turretMotor.ConfigFactoryDefault();
    m_hoodMotor.ConfigFactoryDefault();

    //Setting left to follow right motor
    m_leftShooter.Follow(m_rightShooter);

    //Set Inverted
    m_leftShooter.SetInverted(false);
    m_rightShooter.SetInverted(false);
    m_turretMotor.SetInverted(false);
    m_hoodMotor.SetInverted(false);

    //Set Coast Mode
    m_leftShooter.SetNeutralMode(NeutralMode::Coast);
    m_rightShooter.SetNeutralMode(NeutralMode::Coast);
    m_turretMotor.SetNeutralMode(NeutralMode::Brake);
    m_hoodMotor.SetNeutralMode(NeutralMode::Brake);

    //Setup Encoders
    m_leftShooter.ConfigSelectedFeedbackSensor(FeedbackDevice::IntegratedSensor);
    m_rightShooter.ConfigSelectedFeedbackSensor(FeedbackDevice::IntegratedSensor);
    m_hoodMotor.ConfigSelectedFeedbackSensor(FeedbackDevice::IntegratedSensor,0);
    m_turretMotor.ConfigSelectedFeedbackSensor(FeedbackDevice::IntegratedSensor,0);
}

//**********************HOOD**********************

void Shooter::SetHoodAngle(double angle)
{
    m_wantedHoodAngle = angle;
}
void Shooter::SetHoodPower(double power)
{
    m_hoodPower = power;
}
double Shooter::GetHoodPower(void)
{
    return m_hoodPower;
}
double Shooter::GetWantedHoodAngle()
{
    return m_wantedHoodAngle;
}
double Shooter::GetCurrentHoodAngle()
{
    return m_hoodMotor.GetSelectedSensorPosition() * HOOD_TICK2ANGLE;
}
double Shooter::GetTempatureHoodMotor()
{
    return m_hoodMotor.GetTemperature();
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
    m_hoodMotor.SetSelectedSensorPosition(0);
    m_wantedHoodAngle = 0;
}

//**********************TURRET**********************

void Shooter::SetTurretAngle(double angle)
{
    m_wantedTurretAngle = angle;
}
void Shooter::SetTurretPower(double power)
{
    m_turretPower = power;
}
double Shooter::GetTurretPower(void)
{
    return m_turretPower;
}
double Shooter::GetWantedTurretAngle()
{
    return m_wantedTurretAngle;
}
double Shooter::GetCurrentTurretAngle()
{
    return m_turretMotor.GetSelectedSensorPosition()*TURRET_TICK2ANGLE;
}
double Shooter::GetTempatureTurretMotor()
{
    return m_turretMotor.GetTemperature();
}
bool Shooter::GetLeftTurretLimitSW(void)
{
    return m_turretMotor.GetSensorCollection().IsFwdLimitSwitchClosed();
}
bool Shooter::GetRightTurretLimitSW(void)
{
    return m_turretMotor.GetSensorCollection().IsRevLimitSwitchClosed();
}
bool Shooter::GetTurretHomeSW(void)
{
    return m_turretHomeHallEffect.Get();
}
void Shooter::ResetTurretEncoder(void)
{
    m_turretMotor.SetSelectedSensorPosition(0);
    m_wantedTurretAngle = 0;
}

//*********************LIMELIGHT*********************

double Shooter::GetLimelightHAngle(void)
{
    return nt::NetworkTableInstance::GetDefault().GetTable("limelight")->GetNumber("tx", 0);
}
double Shooter::GetLimelightVAngle(void)
{

    return nt::NetworkTableInstance::GetDefault().GetTable("limelight")->GetNumber("ty", 0);    
}
double Shooter::GetLimelightDistance(void)
{
    const double a1 = 19.3;//angle of limelight
    const double h1 = 24;//height of limelight from ground
    const double h2 = 103.50;//height of target

    double a2 = nt::NetworkTableInstance::GetDefault().GetTable("limelight")->GetNumber("ty", 0);
    
    return (h2-h1)/tan((a1+a2)*(PI/180));
}
bool Shooter::GetLimelightTargetValid(void)
{
    return (bool)nt::NetworkTableInstance::GetDefault().GetTable("limelight")->GetNumber("tv", 0);
}
void Shooter::LimeLight3xMode(bool is3xMode)
{
    if(is3xMode)
    {
        nt::NetworkTableInstance::GetDefault().GetTable("limelight")->PutNumber("pipeline", 1);
    }
    else
    {
        nt::NetworkTableInstance::GetDefault().GetTable("limelight")->PutNumber("pipeline", 0);
    }
}

