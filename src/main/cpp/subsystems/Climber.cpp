#include "subsystems/Climber.h"

Climber::Climber()
{
    m_isClimbActivated = false;
    // m_highBarControl = new frc::DoubleSolenoid(PCM_CAN_ID, frc::PneumaticsModuleType::REVPH, HI_CLIMB_DEPLOY_PCM, HI_CLIMB_RETURN_PCM);
    // m_climbBrake = new frc::DoubleSolenoid(PCM_CAN_ID, frc::PneumaticsModuleType::REVPH, CLIMB_BRAKE_ENGAGE_PCM, CLIMB_BRAKE_DISENGAGE_PCM);
}

void Climber::SetMidBarPower(double power)
{
    m_lowClimbLeftMotor.Set(power);
    m_lowClimbRightMotor.Set(power);
}
void Climber::SetHighBarPower(double power)
{
    m_highClimbLeftMotor.Set(power);
    m_highClimbRightMotor.Set(power);
}

void Climber::HighBarExtend()
{
    m_highBarControl.Set(frc::DoubleSolenoid::kForward);
}

void Climber::HighBarRetract()
{
    m_highBarControl.Set(frc::DoubleSolenoid::kReverse);
}

void Climber::ClimbBrakeExtend()
{
    m_climbBrake.Set(frc::DoubleSolenoid::kForward);
}
void Climber::ClimbBrakeRetract()
{
    m_climbBrake.Set(frc::DoubleSolenoid::kReverse);
}

bool Climber::GetHighHallEffect(void)
{
    return m_highBarHallEffectSensor.Get();
}

bool Climber::GetMidHallEffect(void)
{
    return m_midBarHallEffectSensor.Get();
}

bool Climber::IsClimbActivated(void)
{
    return m_isClimbActivated;
}

void Climber::InitTalons(void)
{
    m_lowClimbLeftMotor.ConfigFactoryDefault();
    m_lowClimbRightMotor.ConfigFactoryDefault();
    m_highClimbLeftMotor.ConfigFactoryDefault();
    m_highClimbLeftMotor.ConfigFactoryDefault();

    //Setting left to follow right motor
    m_lowClimbLeftMotor.Follow(m_lowClimbRightMotor);
    m_highClimbLeftMotor.Follow(m_highClimbRightMotor);

    //Set Inverted
    m_lowClimbLeftMotor.SetInverted(false);
    m_lowClimbRightMotor.SetInverted(false);
    m_highClimbLeftMotor.SetInverted(false);
    m_highClimbRightMotor.SetInverted(false);

    //Set Coast Mode
    m_lowClimbLeftMotor.SetNeutralMode(NeutralMode::Brake);
    m_lowClimbRightMotor.SetNeutralMode(NeutralMode::Brake);
    m_highClimbLeftMotor.SetNeutralMode(NeutralMode::Brake);
    m_highClimbRightMotor.SetNeutralMode(NeutralMode::Brake);

    //Setup Encoders
    m_lowClimbLeftMotor.ConfigSelectedFeedbackSensor(FeedbackDevice::IntegratedSensor);
    m_lowClimbRightMotor.ConfigSelectedFeedbackSensor(FeedbackDevice::IntegratedSensor);
    m_highClimbLeftMotor.ConfigSelectedFeedbackSensor(FeedbackDevice::IntegratedSensor,0);
    m_highClimbRightMotor.ConfigSelectedFeedbackSensor(FeedbackDevice::IntegratedSensor,0);
}


void Climber::Periodic() 
{

}

