#include "mbed.h"
#include "actiondrv.h"
#include "Timer.h"

//--constant--------------------------------------------------------------------
Serial pc(USBTX, USBRX);
actionDrv action1(4);
int motor1Speed = -500;

int acc = 1000000;
int dec = 1000000;
Ticker motorUpdater;

//--function--------------------------------------------------------------------
//Initialization HF motor
void motorInitialization()
{
    //refer to manual for more detail 
    action1.Enable();
    wait(0.1);
    action1.SetOperationalMode();
    wait(0.1); 
    action1.Configvelocity(acc, dec);
    wait(0.1);
    
    //set speed to 0
    action1.stop();
}

//function that will be run repeatedly
//i.e constanly update velocity
void motorUpdate()
{
        action1.SetVelocity(motor1Speed);
        wait(0.005);
}
//mian
int main() {

    //Initialization for hf motor (id :1
    motorInitialization();
    motorUpdater.attach(&motorUpdate, 0.01);

    //looping
    while(1);
}

