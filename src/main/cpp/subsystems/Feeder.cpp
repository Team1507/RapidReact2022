#include "subsystems/Feeder.h"
#include "frc/smartdashboard/SmartDashboard.h"
Feeder::Feeder() = default;

void Feeder::FeederInit(void)
{
  frc::SmartDashboard::PutNumber("TOP_FEEDER_SHOOT_POWER", .9);
  frc::SmartDashboard::PutNumber("BOTTOM_FEEDER_SHOOT_POWER", .45);
  frc::SmartDashboard::PutNumber("TOP_FEEDER_INTAKE_POWER", .6);
  frc::SmartDashboard::PutNumber("BOTTOM_FEEDER_INTAKE_POWER", .6);
  m_topFeeder.SetInverted(true);
}


void Feeder::SetTopFeederPower(double power)
{
  m_topFeederPower = power;
  m_topFeeder.Set(m_topFeederPower);
}
void Feeder::SetBottomFeederPower(double power)
{
  m_bottomFeederPower = power;
  m_botFeeder.Set(m_bottomFeederPower);
}
//Zach wuz here B)
void Feeder::SetFeederOn(bool status)
{
  m_feederStatus = status;
}
double Feeder::GetTopFeederPower(void)
{
  return m_topFeederPower;
}
double Feeder::GetBottomFeederPower(void)
{
  return m_bottomFeederPower;
}

bool Feeder::GetTopFeederPhotoeye(void)
{
  return m_topFeederDetect.Get();
}
bool Feeder::GetBotFeederPhotoeye(void)
{
  return m_botFeederDetect.Get();
}
bool Feeder::GetFeederOn(void)
{
  return m_feederStatus;
}

void Feeder::Periodic() {}
