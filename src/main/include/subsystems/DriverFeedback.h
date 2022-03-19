#pragma once

#include <frc2/command/SubsystemBase.h>
#include <ctre/Phoenix.h>
#include "Constants.h"
#include <frc/XboxController.h>

class DriverFeedback : public frc2::SubsystemBase {
 public:
  DriverFeedback(frc::XboxController *topDriver);
  void UpdateLEDs(int R, int G, int B);//green,red,blue



  void RumbleOn(void);
  void RumbleOff(void);



  void Periodic() override;

 private:
    const int ID_LEDs = 15;
    CANifier m_LED{ID_LEDs};
    frc::XboxController *m_topDriver;

};
