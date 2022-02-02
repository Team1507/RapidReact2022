#include "subsystems/Intake.h"

Intake::Intake(Intake::Type type)
{
    m_type = type;
    if(type == Type::FRONT)
    {
        m_intakeSpark = new frc::Spark(FRONT_INTAKE_PWM);
        m_doubleSolinoid = new frc::DoubleSolenoid(PCM_CAN_ID, frc::PneumaticsModuleType::REVPH, 0, 1);
    }
    if(type == Type::REAR)
    {
        m_intakeSpark = new frc::Spark(REAR_INTAKE_PWM);
        m_doubleSolinoid = new frc::DoubleSolenoid(PCM_CAN_ID, frc::PneumaticsModuleType::REVPH, 2, 3);
    }
    m_doubleSolinoid->Set(frc::DoubleSolenoid::kReverse);
}

void Intake::Deploy(void)
{
    m_doubleSolinoid->Set(frc::DoubleSolenoid::kForward);
}
void Intake::Retract(void)
{
    m_doubleSolinoid->Set(frc::DoubleSolenoid::kReverse);
}

void Intake::SetPower(double power)
{
    m_intakeSpark->Set(power);
}

double Intake::GetPower(void)
{
    return 0;
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