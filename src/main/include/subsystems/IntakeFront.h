#pragma once

#include <frc2/command/SubsystemBase.h>
#include "Constants.h"
#include <frc/DoubleSolenoid.h>
#include <frc/PneumaticsModuleType.h>
#include "Shooter.h"
#include <frc/motorcontrol/Spark.h>
class IntakeFront : public frc2::SubsystemBase 
{
 public:

    IntakeFront();
    void IntakeInit(void);
    void Deploy(void);
    void Retract(void);
    void SetPower(double power);
    bool GetLimitSwitch(void);
    double GetPower(void);
    double Test(void);
    bool GetIsIntaking(void);
    void Periodic() override;

    

 private:
  frc::Spark           m_intakeSpark {FRONT_INTAKE_PWM};
  frc::DoubleSolenoid  m_doubleSolinoid{PCM_CAN_ID, frc::PneumaticsModuleType::REVPH, FRONT_INTAKE_DEPLOY_PCM, FRONT_INTAKE_RETRACT_PCM};
  bool m_isIntaking;
  
 

};
