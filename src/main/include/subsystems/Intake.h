#pragma once

#include <frc2/command/SubsystemBase.h>
#include "Constants.h"
#include <frc/DoubleSolenoid.h>
#include <frc/PneumaticsModuleType.h>
#include "Shooter.h"
#include <frc/motorcontrol/Spark.h>
class Intake : public frc2::SubsystemBase 
{
 public:
   enum Type {FRONT, REAR};
    Intake(Type type);
    void Deploy(void);
    void Retract(void);
    void SetPower(double power);
    bool GetLimitSwitch(void);
    double GetPower(void);
    Type GetType(void);
    double Test(void);

    void Periodic() override;

 private:
  Type m_type;
  frc::Spark *m_intakeSpark;
  frc::DoubleSolenoid *m_doubleSolinoid;
  
 

};
