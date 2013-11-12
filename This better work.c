#pragma config(Hubs,  S2, HTMotor,  HTMotor,  none,     none)
#pragma config(Sensor, S4,     HTGYRO,              sensorAnalogInactive)
#pragma config(Motor,  mtr_S2_C1_1,     RightFront,    tmotorNormal, openLoop)
#pragma config(Motor,  mtr_S2_C1_2,     RightBack,     tmotorNormal, openLoop)
#pragma config(Motor,  mtr_S2_C2_1,     LeftFront,     tmotorNormal, openLoop)
#pragma config(Motor,  mtr_S2_C2_2,     LeftBack,      tmotorNormal, openLoop)
#include "drivers/hitechnic-gyro.h"
#include "JoystickDriver.c"
float rotSpeed = 0;
float heading = 0;
float time = 0;
void initializeRobot(){
  return;
}
task gyrocal ()
{
 /*-----------------------------------Start Gyro Position Compensation-------------------------------*/
	float rotSpeed = 0;
  float heading = 0;

  // Calibrating
  HTGYROstartCal(HTGYRO);

  // Reset the timer.
  time1[T1] = 0;

  while (true)
  {
    // timeout 20ms
    while (time1[T1] < 20)
      wait1Msec(1);

    // Reset timer
    time1[T1]=0;

    // Read rotation speed
    rotSpeed = HTGYROreadRot(HTGYRO);

    /* Calculate the new heading by adding the amount of degrees
     we've turned in the last 20ms
     If our current rate of rotation is 100 degrees/second,
     then we will have turned 100 * (20/1000) = 2 degrees since
     the last time we measured.*/
    heading += rotSpeed * 0.02;

    // Display degrees from start position
    nxtDisplayCenteredTextLine(3, "Gyro: %2.3f", heading);
  }
}
/*----------------------------------------End Gyro Position Compensation------------------------------*/

task drive(){
	while(true){
		getJoystickSettings(joystick);
		long X = (joystick.joy1_x1*cos((heading*PI)/180)) + (joystick.joy1_y1*sin((heading*PI)/180));
	  long Y = (joystick.joy1_y1*cos((heading*PI)/180)) - (joystick.joy1_x1*sin((heading*PI)/180));

	  motor(LeftFront) = X+Y+joystick.joy1_x2;
	  motor(LeftBack) = Y-X+joystick.joy1_x2;
	  motor(RightFront) = X-Y+joystick.joy1_x2;
	  motor(RightBack) = joystick.joy1_x2-X-Y;
	  abortTimeslice();
	 }
}
task main(){
	StartTask(gyrocal);
	StartTask(drive);
	while(true){
	}

}
