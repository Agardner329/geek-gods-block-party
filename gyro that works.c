//due to the developent ot IT'S ALIVE.c this file has BEEN RENDERED USELESS

#pragma config(Sensor, S2,     gyro,           sensorLightInactive)
#pragma config(Sensor, S3,     compass,        sensorSONAR)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "drivers/hitechnic-gyro.h"
//float oldframe = 0;
float frame = 0;
float framemotion = 0;
float frameerrer = 0;
float comp = 0;
float compinit = SensorValue(compass);

task main()
{
				frameerrer = SensorValue(gyro);
        while(true)
        {
        	framemotion = SensorValue(gyro);
        	comp = SensorValue(compass);
        	frame += (framemotion - frameerrer);

        	//Resetting if above 360
        	/*if(comp >= 360){
						comp = 1;
					}
					if(comp <= 0){
						comp = 359;
					}*/
					comp = (compinit - comp);
					nxtDisplayCenteredTextLine(3, "Gyro: %f", frame);
          nxtDisplayCenteredTextLine(4, "Comp: %f", comp);
          //wait10Msec(50);


        }
}
