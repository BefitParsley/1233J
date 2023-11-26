#include "vex.h"
    double kP = 0.1;
    double kD = 0;
    
/*void catapultPI(){
double kP = 0.1;
double kI = 0;
double kD = 0;
double prevError = 0.0;
double targetPosition = 50;

double currentPosition = Rotation3.angle();
double error = targetPosition - currentPosition;
double integral = error;
prevError = error;
}*/

 void runCata() { 
while (Rotation3.angle() > 0 && Rotation3.angle() < 50.5) 
{
  
  Cata.spin(forward);

}
  Cata.stop();
  if (Controller1.ButtonL1.pressing()){
    Cata.spinFor(forward, 0.6, turns);
    while (Rotation3.angle() > 0 && Rotation3.angle() < 50.5) {
      Cata.spin(forward);
    }
    Cata.stop();
  }
}

void Driver_Auto_Cata(){
  if (Controller1.ButtonL1.pressing()){
    runCata();
  }
}