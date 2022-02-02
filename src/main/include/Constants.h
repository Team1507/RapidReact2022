#pragma once

//********** DRIVETRAIN CONSTANTS **********
#define LEFTDRIVE_FRONT_CAN_ID       1
#define LEFTDRIVE_BACK_CAN_ID        2
#define RIGHTDRIVE_FRONT_CAN_ID      3
#define RIGHTDRIVE_BACK_CAN_ID       4 

//*********FEEDER CONSTANTS**********
#define TOP_FEEDER_PWM_ID            0
#define BOTTOM_FEEDER_PWM_ID         1
#define TOP_FEEDER_SHOOTING_POWER    0.7
#define BOTTOM_FEEDER_SHOOTING_POWER 0.7
#define TOP_FEEDER_INTAKE_POWER      0.35
#define BOTTOM_FEEDER_INTAKE_POWER   0.35

//**********INTAKE CONSTANTS**********
#define FRONT_INTAKE_PWM              2
#define REAR_INTAKE_PWM               3
#define FRONT_INTAKE_POWER            0.6
#define REAR_INTAKE_POWER             0.6

//**********CONTROL CONSTANTS**********
// #define CP_SPINNER_CAN_ID       13
// #define CP_DEPLOY_CAN_ID        14


//**********SHOOTER CONSTANTS**********
#define LEFT_SHOOTER_FALCON_ID  5
#define RIGHT_SHOOTER_FALCON_ID 6
#define HOOD_SLOW_POWER         0.3
#define HOOD_BOTTOM_LIMIT_SWITCH 7
#define HOOD_TOP_LIMIT_SWITCH    8

// #define SHOOTER_HOOD_PORT       0

//**********PCM CONSTANTS********** 
 #define PCM_CAN_ID              13
// #define PCM_RAMP_ID             0

//**********CLIMBER CONSTANTS**********
// #define LEFT_WINCH_CAN_ID       10
// #define RIGHT_WINCH_CAN_ID      11
// #define LIGHTSABER_CAN_ID       12  //lightsaber is the climber lift thing to raise the hook up
