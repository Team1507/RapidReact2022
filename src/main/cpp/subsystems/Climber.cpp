#include "subsystems/Climber.h"

Climber::Climber()
{
    m_isClimbActivated = false;
    m_isClimbBrakeActivated = false;
    // m_highBarControl = new frc::DoubleSolenoid(PCM_CAN_ID, frc::PneumaticsModuleType::REVPH, HI_CLIMB_DEPLOY_PCM, HI_CLIMB_RETURN_PCM);
    //m_climbBrake = new frc::DoubleSolenoid(PCM_CAN_ID, frc::PneumaticsModuleType::REVPH, CLIMB_BRAKE_ENGAGE_PCM, CLIMB_BRAKE_DISENGAGE_PCM);
}

void Climber::ClimberInit()
{
    SetMidBarPower(0); 
    m_climbBrake.Set(frc::DoubleSolenoid::kReverse);
}

void Climber::SetMidBarPower(double power)
{
    m_lowClimbRightMotor.Set(power);
}


void Climber::ClimbBrakeExtend()
{
    m_climbBrake.Set(frc::DoubleSolenoid::kForward);
    m_isClimbBrakeActivated = true;
}
void Climber::ClimbBrakeRetract()
{
    m_climbBrake.Set(frc::DoubleSolenoid::kReverse);
    m_isClimbBrakeActivated = false;
}

bool Climber::GetHighHallEffect(void)
{
    return m_lowClimbRightMotor.GetSensorCollection().IsFwdLimitSwitchClosed();
}

bool Climber::GetLowHallEffect(void)
{
    return m_lowClimbRightMotor.GetSensorCollection().IsRevLimitSwitchClosed();
}

bool Climber::IsClimbActivated(void)
{
    return m_isClimbActivated;
}

bool Climber::IsClimbBrakeActivated(void)
{
    return m_isClimbBrakeActivated;
}
void Climber::TalonsInit(void)
{
    m_lowClimbLeftMotor.ConfigFactoryDefault();
    m_lowClimbRightMotor.ConfigFactoryDefault();

    //Setting left to follow right motor
    m_lowClimbLeftMotor.Follow(m_lowClimbRightMotor);

    //Set Inverted
    m_lowClimbLeftMotor.SetInverted(false);
    m_lowClimbRightMotor.SetInverted(true);

    //Set Coast Mode
    m_lowClimbLeftMotor.SetNeutralMode(NeutralMode::Brake);
    m_lowClimbRightMotor.SetNeutralMode(NeutralMode::Brake);

}


void Climber::Periodic() 
{

}

