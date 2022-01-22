#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/DoubleSolenoid.h>
#include "Constants.h"
#include <frc/PneumaticsModuleType.h>

class Intake : public frc2::SubsystemBase {
 public:
 
    Intake(int intakeType);
    void Deploy(void);
    void Retract(void);
    void SetPower(double power);
    double GetPower(void);



    void Periodic() override;

 private:

};
