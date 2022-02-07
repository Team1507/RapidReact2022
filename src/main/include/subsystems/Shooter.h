#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/motorcontrol/Spark.h>
#include <Constants.h>
#include <frc/DigitalInput.h>
#include <ctre/phoenix.h>

class Shooter : public frc2::SubsystemBase {
 public:
  Shooter();

  void SetShooterPower(double power);
  void SetShooterRPM(double rpm);
  //void SetTopFeederPower(double power);
  //void SetBottomFeederPower(double power);
  void SetHoodAngle(double angle);
  void SetHoodPower(double power);
  void SetTurretAngle(double angle);
  void SetTurretPower(double power);
  //void SetFeederOn(bool status);

  double GetLimelightHAngle(void);
  double GetLimelightVAngle(void);
  double GetLimelightDistance(void);
  bool GetLimelightTargetValid(void);
  double GetShooterPower(void);
  double GetShooterRPM(void);
  double GetShooterVelocity(void);
  //double GetTopFeederPower(void);
  //double GetBottomFeederPower(void);
  double GetHoodAngle(void);
  double GetHoodPower(void);
  double GetTurretAngle(void);
  double GetTurretPower(void);
  bool GetLeftTurretLimitSW(void);
  bool GetRightTurretLimitSW(void);
  bool GetTurretHomeSW(void);
  //bool GetTopFeederPhotoeye(void);
  //bool GetBotFeederPhotoeye(void);
  //bool GetFeederOn(void);
  bool GetTopHoodLimitSW(void);
  bool GetBotHoodLimitSW(void);

  double GetWantedHoodAngle(void);
  double GetCurrentHoodAngle(void);
  double GetWantedTurretAngle(void);
  double GetCurrentTurretAngle(void);
  double GetWantedShooterRPM(void);
  double GetCurrentShooterRPM(void);
  
  double GetTempatureLeftShooter(void);
  double GetTempatureRightShooter(void);
  double GetTempatureHoodMotor(void);
  double GetTempatureTurretMotor(void);

  void ResetHoodEncoder(void);
  void ResetTurretEncoder(void);

  void LimeLight3xMode(bool is3XMode);

  const double TURRET_TOLERANCE = 0; //Change Later
  const double HOOD_TOLERANCE = 0; //CHANGE LATER
  const double SHOOTER_RPM_TOLERANCE = 0; //CHANGE LATER
  const double LIMELIGHT_ANGLE_TOLERANCE = 0; //CHANGE LATER


  void Periodic() override;

 private:
    //frc::DigitalInput m_topFeederDetect{TOP_FEEDER_PWM_ID};
    //frc::DigitalInput m_botFeederDetect{BOTTOM_FEEDER_PWM_ID};
    frc::DigitalInput m_topHoodLimitSwitch{HOOD_TOP_LIMIT_SWITCH};
    frc::DigitalInput m_botHoodLimtSwitch{HOOD_BOTTOM_LIMIT_SWITCH};

    frc::DigitalInput m_rightTurretLimitSwitch{TURRET_RIGHT_LIMIT_SWITCH};
    frc::DigitalInput m_leftTurretLimitSwitch{TURRET_LEFT_LIMIT_SWITCH};

    frc::DigitalInput m_turretHomeHallEffect{TURRET_HOME_HALL_EFFECT};
    

    //frc::Spark m_topFeeder{TOP_FEEDER_PWM_ID};
    //frc::Spark m_botFeeder{BOTTOM_FEEDER_PWM_ID};

    TalonFX m_leftShooter{LEFT_SHOOTER_CAN};
    TalonFX m_rightShooter{RIGHT_SHOOTER_CAN};
    TalonSRX m_hoodMotor{HOOD_TALON_CAN};
    TalonSRX m_turretMotor{TURRET_TALON_CAN};

    double m_shooterRPM;
    double m_hoodAngle;
    double m_turretAngle;

    //double m_topFeederPower;
    //double m_bottomFeederPower;
    double m_turretPower;
    double m_hoodPower;
    
    //bool   m_feederStatus;

    double m_wantedHoodAngle;
    double m_wantedTurrentAngle;
    double m_wantedShooterRPM;

    
};
