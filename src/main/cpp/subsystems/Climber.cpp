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

bool Climber::IsClimbActivated(void)
{
    return m_isClimbActivated;
}


void Climber::Periodic() 
{

}

