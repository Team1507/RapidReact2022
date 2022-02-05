#include "subsystems/Intake.h"

Intake::Intake(Intake::Type type)
{
    m_type = type;
    if(type == Type::FRONT)
    {
        m_intakeSpark = new frc::Spark(FRONT_INTAKE_PWM);
        m_pnumatic = new frc::DoubleSolenoid(PCM_CAN_ID, frc::PneumaticsModuleType::REVPH, 0, 1);
    }
    if(type == Type::REAR)
    {
        m_intakeSpark = new frc::Spark(REAR_INTAKE_PWM);
        m_pnumatic = new frc::DoubleSolenoid(PCM_CAN_ID, frc::PneumaticsModuleType::REVPH, 2, 3);
    }
}

void Intake::Deploy(void)
{
    
}

void Intake::Retract(void)
{
    
}

void Intake::SetPower(double power)
{

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