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


task drive(){
	while(true){
	  motor(LeftFront) =
	  motor(LeftBack) =
	  motor(RightFront) =
	  motor(RightBack) =
	  abortTimeslice();
	 }
}
task main(){
  StartTask(drive);
	while(true){
	}

}
