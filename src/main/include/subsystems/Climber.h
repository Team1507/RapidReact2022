#pragma once

#include <frc2/command/SubsystemBase.h>

class Climber : public frc2::SubsystemBase {
 public:
  	Climber();
	void ExtendFirstStage(double power);
	void RetractFirstStage(double power);
	void ExtendSecondStage(double power);
	void RetractSecondStage(double power);
	void SetRightWinchMotor(double power);
	void SetLeftWinchMotor(double power);

	double GetRightWinchMotor(void);
	double GetLeftWinchMotor(void);


  	void Periodic() override;

 private:

};
