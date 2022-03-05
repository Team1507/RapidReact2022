#include "subsystems/IntakeFront.h"
#include "frc/smartdashboard/SmartDashboard.h"

IntakeFront::IntakeFront()
{

}

void IntakeFront::IntakeInit(void)
{
    frc::SmartDashboard::PutNumber("FRONT_INTAKE_POWER", 0.6);
}

void IntakeFront::Deploy(void)
{
    m_doubleSolinoid.Set(frc::DoubleSolenoid::kForward);
    m_isIntaking = true;
}
void IntakeFront::Retract(void)
{
    m_doubleSolinoid.Set(frc::DoubleSolenoid::kReverse);
    m_isIntaking = false;
}

void IntakeFront::SetPower(double power)
{
    m_intakeSpark.Set(power);
}

double IntakeFront::GetPower(void)
{
    return m_intakeSpark.Get();
}

bool IntakeFront::GetIsIntaking(void)
{
    return m_isIntaking;
}

void IntakeFront::Periodic() 
{

}
