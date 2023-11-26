#include "vex.h"
#include <iostream>
void runCata();
void Driver_Auto_Cata();
void Double_Inertial(){
  Inertial1.calibrate();
  Inertial2.calibrate();
  double prevReading1 = Inertial1.heading(); 
  double prevReading2 = Inertial2.heading();
  double currentReading1, currentReading2;
  while (true) { // Continuous loop, replace with your loop condition
  currentReading1 = (Inertial1.calibrate(), Inertial1.heading());
  currentReading2 = (Inertial2.calibrate(), Inertial2.heading());
  double roc1 = (prevReading1, currentReading1);
  double roc2 = (prevReading2, currentReading2);
  if (roc1 > roc2) {
   std::cout << "Using data from sensor 2: " << currentReading2 << std::endl;
  } else {
  // Use data from sensor 1
    std::cout << "Using data from sensor 1: " << currentReading1 << std::endl;
  }
  // Update previous readings
  prevReading1 = currentReading1;
  prevReading2 = currentReading2;
  }
}