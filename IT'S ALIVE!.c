#pragma config(Sensor, S4,     HTGYRO,              sensorAnalogInactive)

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
