#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  HTMotor)
#pragma config(Hubs,  S3, HTServo,  none,     none,     none)
#pragma config(Sensor, S2,     INF,            sensorHiTechnicIRSeeker1200)
#pragma config(Sensor, S4,     RGB,            sensorCOLORFULL)
#pragma config(Motor,  mtr_S1_C1_1,     yellow,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     red,           tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     blue,          tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     green,         tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_1,     arm,           tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     whisk,         tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_1,     lift,          tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_2,     flag,          tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S3_C1_1,    autoflipper,          tServoStandard)
#pragma config(Servo,  srvo_S3_C1_2,    wrist,                tServoStandard)
#pragma config(Servo,  srvo_S3_C1_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S3_C1_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S3_C1_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S3_C1_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "JoystickDriver.c"


void driveToInf(){

        int a = 5;
        int ex = 0;
        nMotorEncoder[yellow] = 0;
        while(SensorValue[INF] != a && nMotorEncoder[yellow] < 6500){
                motor(red) = -80;
                motor(yellow) = 60;
                motor(green) = -80;
                motor(blue) = 60;
                if(nMotorEncoder[yellow] < 1000){
                        a = 5;
                        ex = 350;
                        }else if(nMotorEncoder[yellow] < 2000){
                        a = 5;
                        ex = 350;
                        }else{
                        a = 5;
                        ex = 50;
                }
        }

        motor(red) = -60;
        motor(yellow) = 60;
        motor(green) = -60;
        motor(blue) = 60;
        wait1Msec(ex);
        motor(blue) = 0;
        motor(green) = 0;
        motor(yellow) = 0;
        motor(red) = 0;
        servo[autoflipper] = 65;
        wait1Msec(2500);
        servo[autoflipper] = 240;
        PlayTone(300,15);
}

void returnto(){
        time1[T1] = 0;
        while(nMotorEncoder[yellow] > 700 && time1[T1] < 6500){
                motor(red) = 60;
                motor(yellow) = -60;
                motor(green) = 60;
                motor(blue) = -60;
        }
        motor[red] = 0;
        motor[yellow] = 0;
        motor[green] = 0;
        motor[blue] = 0;
}


task main (){
        SensorType[RGB] = sensorCOLORFULL;
        int waitstart = 0;
        while(waitstart  == 0){
                nxtDisplayCenteredTextLine(3, "<- Test Tournament ->");
                if(nNxtButtonPressed == 2){
                        //test
                        wait1Msec(10);
                };
                
                if(nNxtButtonPressed == 2){
                        //tournament
                        SensorType[RGB] = sensorCOLORFULL;
                        waitForStart();
                };
        };
        SensorType[RGB] = sensorCOLORBLUE;



        servo[wrist] = 0;
        servo[autoflipper] = 240;
        waitForStart();
        driveToInf();
        returnto();


}