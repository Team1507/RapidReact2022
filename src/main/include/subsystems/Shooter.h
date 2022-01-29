#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/motorcontrol/Spark.h>
#include <Constants.h>
#include <frc/DigitalInput.h>

class Shooter : public frc2::SubsystemBase {
 public:
  Shooter();

  void SetShooterPower(double power);
  void SetShooterRPM(double rpm);
  void SetTopFeederPower(double power);
  void SetBottomFeederPower(double power);
  void SetHoodEncoder(double angle);
  void SetTurretYaw(double angle);
  void SetTurretHome();
  void SetFeederOn(bool status);

  double GetLimelightAngle(void);
  double GetLimelightDistance(void);
  double GetShooterPower(void);
  double GetShooterRPM(void);
  double GetShooterVelocity(void);
  double GetTopFeederPower(void);
  double GetBottomFeederPower(void);
  double GetHoodEncoder(void);
  bool GetLeftLimitSW(void);
  bool GetRightLimitSW(void);
  bool GetHomeSW(void);
  bool GetTopPhotoeye(void);
  bool GetBotPhotoeye(void);
  bool GetFeederOn(void);
  

  void Periodic() override;

 private:
    frc::DigitalInput *topFeederDetect;
    frc::DigitalInput *botFeederDetect;
    double m_shooterRPM;
    double m_hoodEncoder;
    double m_turretYaw;
    frc::Spark m_topFeeder{TOP_FEEDER_PWM_ID};
    frc::Spark m_botFeeder{BOTTOM_FEEDER_PWM_ID};
    double m_topFeederPower;
    double m_bottomFeederPower;
    bool m_feederStatus;
    
};
