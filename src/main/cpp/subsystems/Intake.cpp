#include "subsystems/Intake.h"

Intake::Intake(Intake::Type type)
{
    m_type = type;
 
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

bool GetLimitSwitch(void)
{
    return false;
}

double Intake::GetPower(void)
{
    return 0;
}
bool Intake::GetIsIntaking(void)
{
    return isIntaking;
}

void Intake::Periodic() 
{

}
Intake::Type Intake::GetType(void)
{
    return m_type;
}