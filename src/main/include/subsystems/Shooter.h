#pragma once

#include <frc2/command/SubsystemBase.h>

class Shooter : public frc2::SubsystemBase {
 public:
  Shooter();

  void SetShooterPower(double power);
  void SetShooterRPM(double rpm);
  void SetFeederPower(double power);
  void SetHoodEncoder(double angle);
  void SetTurretYaw(double angle);
  void SetTurretHome();

  double GetLimelightAngle(void);
  double GetLimelightDistance(void);
  double GetShooterPower(void);
  double GetShooterRPM(void);
  double GetFeederPower(void);
  double GetHoodEncoder(void);
  bool GetLeftLimitSW(void);
  bool GetRightLimitSW(void);
  bool GetHomeSW(void);



  void Periodic() override;

 private:
    double m_shooterRPM;
    double m_feederPower;
    double m_hoodEncoder;
    double m_turretYaw;
};
