#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/motorcontrol/Spark.h>
#include <Constants.h>
#include <frc/DigitalInput.h>

class Feeder : public frc2::SubsystemBase {
 public:
  enum Level{Top,Bottom};
  Feeder();
  void FeederInit(void);
  void SetTopFeederPower(double power);
  void SetBottomFeederPower(double power);

  void SetFeederOn(bool status);
  double GetTopFeederPower(void);
  double GetBottomFeederPower(void);

  bool GetTopFeederPhotoeye(void);
  bool GetBotFeederPhotoeye(void);
  bool GetFeederOn(void);

  void Periodic() override;

 private: 

    frc::DigitalInput m_topFeederDetect{UPPER_FEEDER_PHOTOEYE};
    frc::DigitalInput m_botFeederDetect{LOWER_FEEDER_PHOTOEYE};

    frc::Spark m_topFeeder{TOP_FEEDER_PWM_ID};
    frc::Spark m_botFeeder{BOTTOM_FEEDER_PWM_ID};

    bool   m_feederStatus;

    double m_topFeederPower;
    double m_bottomFeederPower;


};
