#include "subsystems/DriverFeedback.h"
#include <frc/XboxController.h>

DriverFeedback::DriverFeedback(frc::XboxController *topDriver) 
{
    m_topDriver = topDriver;
}

void DriverFeedback::UpdateLEDs(int R, int G, int B)
{
    // m_LED.SetLEDOutput(R, CANifier::LEDChannelA);
    // m_LED.SetLEDOutput(G, CANifier::LEDChannelB);
    // m_LED.SetLEDOutput(B, CANifier::LEDChannelC);
}

void DriverFeedback::RumbleOn(void)
{
    m_topDriver->SetRumble(frc::GenericHID::kLeftRumble, 1);
    m_topDriver->SetRumble(frc::GenericHID::kRightRumble, 1);
}
void DriverFeedback::RumbleOff(void)
{
    m_topDriver->SetRumble(frc::GenericHID::kLeftRumble, 0);
    m_topDriver->SetRumble(frc::GenericHID::kRightRumble, 0);
}
  

void DriverFeedback::Periodic() 
{

}

