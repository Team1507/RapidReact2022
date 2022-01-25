#pragma once

#include <frc2/command/SubsystemBase.h>
#include "Constants.h"
#include <frc/DoubleSolenoid.h>
#include <frc/PneumaticsModuleType.h>

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




    void Periodic() override;

 private:

};
