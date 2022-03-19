#include "subsystems/Shooter.h"
#include <networktables/NetworkTable.h>
#include <networktables/NetworkTableInstance.h>
#include <iostream>
#include "frc/smartdashboard/SmartDashboard.h"
#define SHOOTER_PID

#define PI 3.1415

#ifdef SHOOTER_PID
#define SHOOTER_PID_SLOT 0
#define SHOOTER_kF_CONSTANT 0.0501          //Slightly highter than calculated 0.0467    
#define SHOOTER_kP_CONSTANT 0.300            //started 0.5
#define SHOOTER_RAMP_TIME 0.25              // started at 0.5
#endif


//Turret contants
//Calibrated 3/6/22
#define TURRET_MAX_LEFT_ANGLE               -37.0
#define TURRET_MAX_RIGHT_ANGLE               40.0
#define TURRET_ENCODER_AT_LEFT              -3930
#define TURRET_ENCODER_AT_RIGHT              4260
#define TURRET_ENCODER_TICKS_PER_ANGLE       106.36
//Max hood 16000


typedef struct 
{
    float distance;
    float rpm;
    float hoodAngle;
} shooterInterpolation_t;


shooterInterpolation_t shooterInfo[] = {{87,  2100, 13000}, //Distance, RPM, Hood Angle
                                        {92,  2120, 13000},
                                        {97,  2120, 13000},
                                        {102, 2150, 13000},
                                        {107, 2200, 13000},
                                        {112, 2.0, 2.0},
                                        {117, 3.0, 3.0},
                                        {122, 1.0, 1.0},
                                        {127, 2.0, 2.0},
                                        {132, 3.0, 3.0},
                                        {137, 3.0, 3.0},
                                        {145, 2350, 16000}};


#define SHOOTER_LIST_LENGTH  (sizeof(shooterInfo) / sizeof(shooterInterpolation_t))




Shooter::Shooter()
{
    //double m_shooterRPM        = 0;
    //double m_topFeederPower    = 0;
    //double m_bottomFeederPower = 0;
    // double m_hoodEncoder       = 0;
    // double m_turretYaw         = 0;   
    // double m_wantedTurretAngle = 0;
    // double m_wantedHoodAngle   = 0;
    // double m_wantedShooterRPM  = 0;
}

void Shooter::ShooterInit(void)
{
    SetShooterPower(0);
    SetHoodPower(0);
    SetTurretPower(0);
    SetIdle(false);

    ResetTurretEncoder();
    ResetHoodEncoder();
    frc::SmartDashboard::PutNumber("Shooter Idle Power",0.25); //1440RPM
    frc::SmartDashboard::PutNumber("Shooter Launch Pad Power",0.355);
    frc::SmartDashboard::PutNumber("Shooter Low Goal Power",0.25);
    frc::SmartDashboard::PutNumber("Shooter Tarmac Line Power",0.42); // 2470RPM

    frc::SmartDashboard::PutNumber("Shooter Idle RPM",1440); //1440RPM
    frc::SmartDashboard::PutNumber("Shooter Launch Pad RPM",2400);
    frc::SmartDashboard::PutNumber("Shooter Low Goal RPM",1000);
    frc::SmartDashboard::PutNumber("Shooter Tarmac Line RPM",2100); // 2470RPM

    frc::SmartDashboard::PutNumber("Shooter test RPM",0.0);
    frc::SmartDashboard::PutNumber("Limelight H Offset", -1.5);
}

void Shooter::Periodic() 
{
    
}

bool Shooter::ShooterInterpolation(float distance)
{
    if((distance > shooterInfo[SHOOTER_LIST_LENGTH-1].distance) || (distance < shooterInfo[0].distance))
    {
        return false;
    }
    else
    {
        for(unsigned int i = 0; i < SHOOTER_LIST_LENGTH; i++)
        { 
            if((distance > shooterInfo[i].distance) && (distance < shooterInfo[i+1].distance))
            {
                double x2 = shooterInfo[i+1].distance;
                double x1 = shooterInfo[i].distance;
                double y2 = shooterInfo[i+1].rpm;
                double y1 = shooterInfo[i].rpm;

                double RPM = y1 + (distance - x1)*((y2 - y1) / (x2 - x1));
                std::cout<<"Interpolation RPM ="<< RPM<<std::endl;
                m_shooterRPM = RPM;


                y2 = shooterInfo[i+1].hoodAngle;
                y1 = shooterInfo[i].hoodAngle;

                double HOOD = y1 + (distance - x1)*((y2 - y1) / (x2 - x1));
                std::cout<<"Interpolation Hood Angle ="<< HOOD<<std::endl;
                m_hoodAngle = HOOD;

                return true;
            }
           
        }
    }
    return false;
}





void Shooter::FalconsInit()
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
    m_rightShooter.SetInverted(true);
    m_turretMotor.SetInverted(true);
    m_hoodMotor.SetInverted(false);

    //Set PID 
    #ifdef SHOOTER_PID
    m_rightShooter.ConfigClosedloopRamp(SHOOTER_RAMP_TIME,10);
    m_rightShooter.ConfigNeutralDeadband(0.001);
    m_rightShooter.Config_kF(SHOOTER_PID_SLOT,SHOOTER_kF_CONSTANT,10);
    m_rightShooter.Config_kP(SHOOTER_PID_SLOT,SHOOTER_kP_CONSTANT,10);
    #endif

    //Set Coast Mode
    m_leftShooter.SetNeutralMode(NeutralMode::Coast);
    m_rightShooter.SetNeutralMode(NeutralMode::Coast);
    m_turretMotor.SetNeutralMode(NeutralMode::Brake);
    m_hoodMotor.SetNeutralMode(NeutralMode::Brake);

    //Setup Encoders
    m_leftShooter.ConfigSelectedFeedbackSensor(FeedbackDevice::IntegratedSensor);
    m_rightShooter.ConfigSelectedFeedbackSensor(FeedbackDevice::IntegratedSensor);
    m_hoodMotor.ConfigSelectedFeedbackSensor(FeedbackDevice::QuadEncoder,0);
    m_turretMotor.ConfigSelectedFeedbackSensor(FeedbackDevice::QuadEncoder,0);

    // //Power Limits
    //  PeakOutput is not a limiter, its a multiplier
    //    So, motor output is set power * PeakOutputSetting
    //    It also seems to have memory that ConfigFactoryDefault() does not clear.
    m_rightShooter.ConfigPeakOutputForward(1.0,10);
    m_leftShooter.ConfigPeakOutputForward(1.0,10);
    m_rightShooter.ConfigPeakOutputReverse(-0.0,10);
    m_leftShooter.ConfigPeakOutputReverse(0.0,10);

    m_isIdle = true;
}




//*********************SHOOTER********************


void Shooter::SetShooterPower(double power)
{
    m_rightShooter.Set(ControlMode::PercentOutput, power);
}
void Shooter::SetShooterRPM(double rpm)
{
    #ifdef SHOOTER_PID
    m_rightShooter.Set(ControlMode::Velocity, RPM2Velocity(rpm));
    #endif
    m_wantedShooterRPM = rpm;
}
void Shooter::SetIdle(bool idle)
{
    m_isIdle = idle;
}
double Shooter::GetShooterPower(void)
{
    return m_rightShooter.GetMotorOutputPercent();
}

double Shooter::GetRightShooterPower(void)
{
    return m_rightShooter.GetMotorOutputPercent();
}
double Shooter::GetLeftShooterPower(void)
{
    return m_leftShooter.GetMotorOutputPercent();
}
bool Shooter::IsIdle()
{
    return m_isIdle;
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




//**********************HOOD**********************

void Shooter::SetHoodAngle(double angle)
{
    m_wantedHoodAngle = angle;
}
void Shooter::SetHoodPower(double power)
{
    m_hoodMotor.Set(ControlMode::PercentOutput, power);
}
double Shooter::GetHoodPower(void)
{
    return m_hoodMotor.GetMotorOutputPercent();
}
double Shooter::GetWantedHoodAngle()
{
    return m_wantedHoodAngle;
}
double Shooter::GetCurrentHoodAngle()
{
    return m_hoodMotor.GetSelectedSensorPosition();
}
bool Shooter::GetTopHoodLimitSW(void)
{
    return m_hoodMotor.GetSensorCollection().IsRevLimitSwitchClosed(); 
}
bool Shooter::GetBotHoodLimitSW(void)
{
    return m_hoodMotor.GetSensorCollection().IsFwdLimitSwitchClosed();
}
void Shooter::ResetHoodEncoder(void)
{
    //Jack Waz Here
    m_hoodMotor.SetSelectedSensorPosition(0,0,0);
    //m_wantedHoodAngle = 0;
}
int Shooter::GetHoodEncoder(void) 
{
    return m_hoodMotor.GetSelectedSensorPosition(0);
    //return m_hoodMotor.GetSensorCollection().GetQuadraturePosition();
}

//**********************TURRET**********************

void Shooter::SetTurretAngle(double angle)
{
    m_wantedTurretAngle = angle;
}
void Shooter::SetTurretPower(double power)
{
    m_turretMotor.Set(ControlMode::PercentOutput, power);
}
double Shooter::GetTurretPower(void)
{
    return m_turretMotor.GetMotorOutputPercent();
}
double Shooter::GetWantedTurretAngle()
{
    return m_wantedTurretAngle;
}
double Shooter::GetCurrentTurretAngle()
{
    return GetTurretEncoder() / TURRET_ENCODER_TICKS_PER_ANGLE;
}
bool Shooter::GetLeftTurretLimitSW(void)
{
    return m_turretMotor.GetSensorCollection().IsRevLimitSwitchClosed();
}
bool Shooter::GetRightTurretLimitSW(void)
{
    return m_turretMotor.GetSensorCollection().IsFwdLimitSwitchClosed();
}
bool Shooter::GetTurretHomeSW(void)
{
    return !m_turretHomeHallEffect.Get();
}
void Shooter::ResetTurretEncoder(void)
{
    m_turretMotor.SetSelectedSensorPosition(0,0,0);
    m_wantedTurretAngle = 0;
}

void Shooter::SetTurretEncoderAtLeft(void)
{
    m_turretMotor.SetSelectedSensorPosition(-TURRET_ENCODER_AT_LEFT,0,0);
    m_wantedTurretAngle = TURRET_MAX_LEFT_ANGLE;
}
void Shooter::SetTurretEncoderAtRight(void)
{
    m_turretMotor.SetSelectedSensorPosition(-TURRET_ENCODER_AT_RIGHT,0,0);
    m_wantedTurretAngle = TURRET_MAX_RIGHT_ANGLE;
}



int Shooter::GetTurretEncoder(void) 
{
    return -m_turretMotor.GetSelectedSensorPosition(0);
    //return m_turretMotor.GetSensorCollection().GetQuadraturePosition();
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
    const double a1 = 32;//angle of limelight 32 off of vertical
    const double h1 = 35.5;//height of limelight from ground
    const double h2 = 103.50;//height of target

    double a2 = nt::NetworkTableInstance::GetDefault().GetTable("limelight")->GetNumber("ty", 0);
    
    return (h2-h1)/tan((a1+a2)*(PI/180));
}
bool Shooter::GetLimelightTargetValid(void)
{
    return (bool)nt::NetworkTableInstance::GetDefault().GetTable("limelight")->GetNumber("tv", 0);
}


// void Shooter::LimeLight3xMode(bool is3xMode)
// {
//     if(is3xMode)
//     {
//         nt::NetworkTableInstance::GetDefault().GetTable("limelight")->PutNumber("pipeline", 1);
//     }
//     else
//     {
//         nt::NetworkTableInstance::GetDefault().GetTable("limelight")->PutNumber("pipeline", 0);
//     }
// }

