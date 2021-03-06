#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  HTMotor)
#pragma config(Hubs,  S3, HTServo,  none,     none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     INF,            sensorHiTechnicIRSeeker1200)
#pragma config(Sensor, S3,     ,               sensorI2CMuxController)
#pragma config(Sensor, S4,     HTGYRO,              sensorAnalogInactive)
#pragma config(Motor,  mtr_S1_C1_1,     yellow,        tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C1_2,     red,           tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     blue,          tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     green,         tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_1,     arm,           tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C3_2,     whisk,         tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_1,     lift,          tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_2,     flag,          tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S3_C1_1,    autoflipper,          tServoStandard)
#pragma config(Servo,  srvo_S3_C1_2,    wrist,                tServoStandard)
#pragma config(Servo,  srvo_S3_C1_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S3_C1_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S3_C1_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S3_C1_6,    servo6,               tServoNone)

//color and gyro are switched

#include "drivers/hitechnic-gyro.h"

task main ()
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

    // Read rotation speed
    rotSpeed = HTGYROreadRot(HTGYRO);

    /* Calculate the new heading by adding the amount of degrees
     we've turned in the last 20ms
     If our current rate of rotation is 100 degrees/second,
     then we will have turned 100 * (20/1000) = 2 degrees since
     the last time we measured.*/

     //varience compinsator for integration with multiple tasks
    nxtDisplayCenteredTextLine(2, "Timer: %2.3f", (time1[T1]));
    heading += rotSpeed * (time1[T1]);

    // Reset timer
    time1[T1]=0;

    // Display degrees from start position
  
    nxtDisplayCenteredTextLine(3, "Gyro: %2.3f", heading);
  }
}
/*----------------------------------------End Gyro Position Compensation------------------------------*/