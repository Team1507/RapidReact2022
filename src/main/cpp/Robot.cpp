#include "Robot.h"
#include <iostream>
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc2/command/CommandScheduler.h>

void Robot::RobotInit() 
{
  //*************************** INIT ******************************
    std::cout<<"RobotInit"<<std::endl;
    std::cout<<"FRC2022: Rapid React"<<std::endl;
    std::cout<<"          ~~~ Deus ~~~"<<std::endl;
    std::cout<<"Version: " << __DATE__ <<"  "<<__TIME__<<std::endl<<std::endl; 
    //Test Test Test
    //Test on  Second Laptop
    
}


void Robot::RobotPeriodic() 
{
  frc2::CommandScheduler::GetInstance().Run();
}


void Robot::DisabledInit() 
{
    std::cout<<"Disabled Init"<<std::endl;
}

void Robot::DisabledPeriodic() 
{
    
}


void Robot::AutonomousInit() {
  std::cout<<"Auto Init"<<std::endl;
  m_autonomousCommand = m_container.GetAutonomousCommand();

  if (m_autonomousCommand != nullptr) {
    m_autonomousCommand->Schedule();
  }
}

void Robot::AutonomousPeriodic() {}

void Robot::TeleopInit() {
  
  std::cout<<"Teleop Init"<<std::endl;
  if (m_autonomousCommand != nullptr) {
    m_autonomousCommand->Cancel();
    m_autonomousCommand = nullptr;
  }
}


void Robot::TeleopPeriodic() {}

void Robot::WriteToSmartDashboard(void)
{

}

void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>();
}
#endif

