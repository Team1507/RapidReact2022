#include "subsystems/Intake.h"

Intake::Intake(Intake::Type type)
{
    m_type = type;
    if(type == Type::FRONT)
    {
        m_intakeSpark = new frc::Spark(FRONT_INTAKE_PWM);
        m_doubleSolinoid = new frc::DoubleSolenoid(PCM_CAN_ID, frc::PneumaticsModuleType::REVPH, FRONT_INTAKE_DEPLOY_PCM, FRONT_INTAKE_RETRACT_PCM);
    }
    if(type == Type::REAR)
    {
        m_intakeSpark = new frc::Spark(REAR_INTAKE_PWM);
        m_doubleSolinoid = new frc::DoubleSolenoid(PCM_CAN_ID, frc::PneumaticsModuleType::REVPH, REAR_INTAKE_DEPLOY_PCM, REAR_INTAKE_RETRACT_PCM);
    }
    m_doubleSolinoid->Set(frc::DoubleSolenoid::kReverse);
    m_intakeSpark->Set(0);
}

void Intake::Deploy(void)
{
    m_doubleSolinoid->Set(frc::DoubleSolenoid::kForward);
    m_isIntaking = true;
}
void Intake::Retract(void)
{
    m_doubleSolinoid->Set(frc::DoubleSolenoid::kReverse);
    m_isIntaking = false;
}

void Intake::SetPower(double power)
{
    m_intakeSpark->Set(power);
}

double Intake::GetPower(void)
{
    return m_intakeSpark->Get();
}

bool Intake::GetIsIntaking(void)
{
    return m_isIntaking;
}

void Intake::Periodic() 
{

}
Intake::Type Intake::GetType(void)
{
    return m_type;
}