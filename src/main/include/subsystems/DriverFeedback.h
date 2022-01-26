#pragma once

#include <frc2/command/SubsystemBase.h>

class DriverFeedback : public frc2::SubsystemBase {
 public:
  DriverFeedback();



  void RumbleOn(void);
  void RumbleOff(void);



  void Periodic() override;

 private:

};
