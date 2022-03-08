#pragma once

#define PEAK_FALCON_POWER            0.9

//********** DRIVETRAIN CONSTANTS **********
#define LEFTDRIVE_FRONT_CAN_ID       1
#define LEFTDRIVE_BACK_CAN_ID        2
#define RIGHTDRIVE_FRONT_CAN_ID      3
#define RIGHTDRIVE_BACK_CAN_ID       4

#define LEFT_DRIVE_ENCODER_A         0
#define RIGHT_DRIVE_ENCODER_A        2
#define LEFT_DRIVE_ENCODER_B         1       
#define RIGHT_DRIVE_ENCODER_B        3

//*********FEEDER CONSTANTS**********
#define TOP_FEEDER_PWM_ID            0
#define BOTTOM_FEEDER_PWM_ID         1

#define TOP_FEEDER_SHOOTING_POWER    0.9
#define BOTTOM_FEEDER_SHOOTING_POWER 0.7
#define TOP_FEEDER_INTAKE_POWER      0.35
#define BOTTOM_FEEDER_INTAKE_POWER   0.35

#define UPPER_FEEDER_PHOTOEYE        4
#define LOWER_FEEDER_PHOTOEYE        5

//**********INTAKE CONSTANTS**********
#define FRONT_INTAKE_PWM              2
#define REAR_INTAKE_PWM               3
#define FRONT_INTAKE_DEPLOY_PCM       0
#define REAR_INTAKE_DEPLOY_PCM        2
#define FRONT_INTAKE_RETRACT_PCM      1
#define REAR_INTAKE_RETRACT_PCM       3
#define FRONT_INTAKE_POWER            0.6
#define REAR_INTAKE_POWER             0.6

//**********CLIMBER CONSTANTS**********
#define LO_CLIMB_LEFT_FALCON_CAN    6
#define LO_CLIMB_RIGHT_FALCON_CAN   7
// #define HI_CLIMB_LEFT_FALCON_CAN    8
// #define HI_CLIMB_RIGHT_FALCON_CAN   9
// #define HI_CLIMB_DEPLOY_PCM         4
// #define HI_CLIMB_RETURN_PCM         5
#define CLIMB_BRAKE_ENGAGE_PCM      6
#define CLIMB_BRAKE_DISENGAGE_PCM   7

//**********SHOOTER CONSTANTS**********
#define TURRET_TALON_CAN           5
#define TURRET_HOME_HALL_EFFECT    6
#define TURRET_SLOW_POWER          0.4
#define LEFT_SHOOTER_CAN           10
#define RIGHT_SHOOTER_CAN          11
#define HOOD_TALON_CAN             12
#define HOOD_SLOW_POWER            0.3

#define SHOOTER_IDLE_VELOCITY      11
#define SHOOTER_CLOSE_VELOCITY     16 //TBD



//**********PCM CONSTANTS********** 
 #define PCM_CAN_ID                13       //PCH


