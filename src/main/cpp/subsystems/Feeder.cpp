#include "subsystems/Feeder.h"

Feeder::Feeder() = default;

  void Feeder::SetTopFeederPower(double power)
  {
    m_topFeederPower = power;
  }
  void Feeder::SetBottomFeederPower(double power)
  {
      m_bottomFeederPower = power;
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
