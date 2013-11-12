#pragma config(Hubs,  S2, HTMotor,  HTMotor,  none,     none)
#pragma config(Sensor, S4,     HTGYRO,              sensorAnalogInactive)
#pragma config(Motor,  mtr_S2_C1_1,     RightFront,    tmotorNormal, openLoop)
#pragma config(Motor,  mtr_S2_C1_2,     RightBack,     tmotorNormal, openLoop)
#pragma config(Motor,  mtr_S2_C2_1,     LeftFront,     tmotorNormal, openLoop)
#pragma config(Motor,  mtr_S2_C2_2,     LeftBack,      tmotorNormal, openLoop)
#include "JoystickDriver.c"
void initializeRobot(){
  return;
}

/*----------------------------------------End Gyro Position Compensation------------------------------*/

task drive(){
	while(true){
	  motor(LeftFront) = X+Y+joystick.joy1_x2;
	  motor(LeftBack) = Y-X+joystick.joy1_x2;
	  motor(RightFront) = X-Y+joystick.joy1_x2;
	  motor(RightBack) = joystick.joy1_x2-X-Y;
	  abortTimeslice();
	 }
}
task main(){
  StartTask(drive);
	while(true){
	}

}
