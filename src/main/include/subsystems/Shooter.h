#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/motorcontrol/Spark.h>
#include <frc/motorcontrol/MotorControllerGroup.h>
#include <frc/DigitalInput.h>

#include <ctre/phoenix.h>

#include <Constants.h>

#define RPM2Velocity(rpm)      ((rpm * 2048)/(60 * 10))
#define Velocity2RPM(velocity) ((600 * velocity) / (2048))

class Shooter : public frc2::SubsystemBase {
 public:
  Shooter();
  void ShooterInit(void);
  bool ShooterInterpolation(float distance);
  void Periodic() override;

//*********************SHOOTER********************
  void   SetShooterPower(double power);
  void   SetShooterRPM(double rpm);
  void   SetIdle(bool idle);

  double GetShooterPower(void);
  double GetLeftShooterPower(void);
  double GetRightShooterPower(void);
  double GetShooterVelocity(void);
  double GetWantedShooterRPM(void);
  double GetCurrentShooterRPM(void);
  bool   IsIdle();

  double GetTempatureLeftShooter(void);
  double GetTempatureRightShooter(void);

  void   FalconsInit(void);

  const double SHOOTER_RPM_TOLERANCE = 50; //CHANGE LATER

//**********************HOOD**********************
  void   SetHoodAngle(double angle);
  void   SetHoodPower(double power);

  double GetHoodPower(void);
  double GetWantedHoodAngle(void);
  double GetCurrentHoodAngle(void);

  bool   GetTopHoodLimitSW(void);
  bool   GetBotHoodLimitSW(void);

  void   ResetHoodEncoder(void);

  int    GetHoodEncoder(void);

  const double HOOD_TOLERANCE = 500; //CHANGE LATER

//**********************TURRET**********************
  void   SetTurretAngle(double angle);
  void   SetTurretPower(double power);
  void   SetTurretPosition(double position);
  double GetTurretPower(void);
  double GetWantedTurretAngle(void);
  double GetCurrentTurretAngle(void);

  bool   GetLeftTurretLimitSW(void); 
  bool   GetRightTurretLimitSW(void);
  bool   GetTurretHomeSW(void);

  void   ResetTurretEncoder(void);
  void   SetTurretEncoderAtLeft(void);
  void   SetTurretEncoderAtRight(void);

  int    GetTurretEncoder(void);

  const double TURRET_TOLERANCE = 1; //CHANGE LATER

//*********************LIMELIGHT*********************
  double GetLimelightHAngle(void);
  double GetLimelightVAngle(void);
  double GetLimelightDistance(void);
  bool   GetLimelightTargetValid(void);
  
  //void   LimeLight3xMode(bool is3XMode);

  

  const double LIMELIGHT_ANGLE_TOLERANCE = 1; //CHANGE LATER

 private:
    // frc::DigitalInput m_topHoodLimitSwitch    {HOOD_TOP_LIMIT_SWITCH};
    // frc::DigitalInput m_botHoodLimtSwitch     {HOOD_BOTTOM_LIMIT_SWITCH};
    frc::DigitalInput m_turretHomeHallEffect  {TURRET_HOME_HALL_EFFECT};

    TalonFX  m_leftShooter                    {LEFT_SHOOTER_CAN};
    TalonFX  m_rightShooter                   {RIGHT_SHOOTER_CAN};
    TalonSRX m_hoodMotor                      {HOOD_TALON_CAN};
    TalonSRX m_turretMotor                    {TURRET_TALON_CAN};

    double m_shooterRPM;
    double m_hoodAngle;
    double m_turretAngle;

    double m_turretPower;
    double m_hoodPower;

    double m_wantedHoodAngle;
    double m_wantedTurretAngle;
    double m_wantedShooterRPM;
    bool m_isIdle;
};
