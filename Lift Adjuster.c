#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  HTMotor)
#pragma config(Motor,  mtr_S1_C3_1,     lift,          tmotorTetrix, openLoop)
//Lift Adjuster.c
task main(){
	nxtDisplayCenteredTextLine(1, "Lift Adjuster");
	while(true){
		if (nNxtButtonPressed == 2){
			motor[lift] = -5;
			nxtDisplayCenteredBigTextLine(4, "Lowering");
			PlayTone(450,1);
			}else if(nNxtButtonPressed == 1){
			motor[lift] = 5;
			nxtDisplayCenteredBigTextLine(4, "Raising");
			PlayTone(550,1);
			}else{
			motor[lift] = 0;
			nxtDisplayCenteredBigTextLine(4, "Still");
			PlayTone(500,1);
		}
		wait10Msec(1);
	}
}
