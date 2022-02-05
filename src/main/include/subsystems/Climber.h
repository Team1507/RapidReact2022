#pragma once

#include <frc2/command/SubsystemBase.h>
#include "ctre/Phoenix.h"
#include "AHRS.h"
#include "Constants.h"
#include <frc/DoubleSolenoid.h>
#include <frc/PneumaticsModuleType.h>
#include <frc/Digitalinput.h>

class Climber : public frc2::SubsystemBase {
 public:
  	Climber();
	void SetMidBarPower(double power);
	void SetHighBarPower(double power);

	void HighBarExtend(void);
	void HighBarRetract(void);
	void ClimbBrakeExtend(void);
	void ClimbBrakeRetract(void);

	bool IsClimbActivated(void);


  	void Periodic() override;

 private:
	WPI_TalonFX m_lowClimbLeftMotor     {LO_CLIMB_LEFT_FALCON_CAN};
	WPI_TalonFX m_lowClimbRightMotor    {LO_CLIMB_RIGHT_FALCON_CAN};
	WPI_TalonFX m_highClimbLeftMotor	{HI_CLIMB_LEFT_FALCON_CAN};
	WPI_TalonFX m_highClimbRightMotor	{HI_CLIMB_RIGHT_FALCON_CAN};
	bool m_isClimbActivated;
	frc::DoubleSolenoid m_highBarControl {PCM_CAN_ID, frc::PneumaticsModuleType::REVPH, HI_CLIMB_DEPLOY_PCM, HI_CLIMB_RETURN_PCM};
    frc::DoubleSolenoid m_climbBrake {PCM_CAN_ID, frc::PneumaticsModuleType::REVPH, CLIMB_BRAKE_ENGAGE_PCM, CLIMB_BRAKE_DISENGAGE_PCM};
	//frc::DoubleSolenoid *m_highBarControl;
	//frc::DoubleSolenoid *m_climbBrake;
	//frc::DigitalInput m_hallEffectSensor{DIO_ID_HALLEFFECT};
};
