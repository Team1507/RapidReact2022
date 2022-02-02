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
  void SetHoodAngle(double angle);
  void SetHoodPower(double power);
  void SetTurretAngle(double angle);
  void SetTurretPower(double power);
  void SetFeederOn(bool status);

  double GetLimelightHAngle(void);
  double GetLimelightVAngle(void);
  double GetLimelightDistance(void);
  bool GetLimelightTargetValid(void);
  double GetShooterPower(void);
  double GetShooterRPM(void);
  double GetShooterVelocity(void);
  double GetTopFeederPower(void);
  double GetBottomFeederPower(void);
  double GetHoodAngle(void);
  double GetHoodPower(void);
  double GetTurretAngle(void);
  double GetTurretPower(void);
  bool GetLeftTurretLimitSW(void);
  bool GetRightTurretLimitSW(void);
  bool GetTurretHomeSW(void);
  bool GetTopFeederPhotoeye(void);
  bool GetBotFeederPhotoeye(void);
  bool GetFeederOn(void);
  bool GetTopHoodLimitSW(void);
  bool GetBotHoodLimitSW(void);

  void ResetHoodEncoder(void);
  void ResetTurretEncoder(void);
  


  void Periodic() override;

 private:
    frc::DigitalInput *topFeederDetect;
    frc::DigitalInput *botFeederDetect;
    double m_shooterRPM;
    double m_hoodAngle;
    double m_turretAngle;
    frc::Spark m_topFeeder{TOP_FEEDER_PWM_ID};
    frc::Spark m_botFeeder{BOTTOM_FEEDER_PWM_ID};
    double m_topFeederPower;
    double m_bottomFeederPower;
    bool m_feederStatus;
    double m_turretPower;
    double m_hoodPower;
    frc::DigitalInput *m_topHoodLimitSwitch;
    frc::DigitalInput *m_botHoodLimtSwitch;
    
};
