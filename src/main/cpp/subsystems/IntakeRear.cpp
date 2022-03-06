#include "subsystems/IntakeRear.h"
#include "frc/smartdashboard/SmartDashboard.h"

IntakeRear::IntakeRear()
{

}

void IntakeRear::IntakeInit(void)
{
    frc::SmartDashboard::PutNumber("FRONT_INTAKE_POWER", 0.6);
}

void IntakeRear::Deploy(void)
{
    m_doubleSolinoid.Set(frc::DoubleSolenoid::kForward);
    m_isIntaking = true;
}
void IntakeRear::Retract(void)
{
    m_doubleSolinoid.Set(frc::DoubleSolenoid::kReverse);
    m_isIntaking = false;
}

void IntakeRear::SetPower(double power)
{
    m_intakeSpark.Set(power);
}

double IntakeRear::GetPower(void)
{
    return m_intakeSpark.Get();
}

bool IntakeRear::GetIsIntaking(void)
{
    return m_isIntaking;
}

void IntakeRear::Periodic() 
{

}
