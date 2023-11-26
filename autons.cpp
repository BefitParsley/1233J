#include "vex.h"

void default_constants(){
  chassis.set_drive_constants(10, 1.5, 0, 10, 0);
  chassis.set_heading_constants(6, .4, 0, 1, 0);
  chassis.set_turn_constants(12, .4, .03, 3, 15);
  chassis.set_swing_constants(12, .3, .001, 2, 15);
  chassis.set_drive_exit_conditions(1.5, 300, 5000);
  chassis.set_turn_exit_conditions(1, 300, 3000);
  chassis.set_swing_exit_conditions(1, 300, 3000);
}

void odom_constants(){
  default_constants();
  chassis.drive_max_voltage = 8;
  chassis.drive_settle_error = 3;
}

void matchload_side(){

}

void defense_side(){
  
}

void turn_test(){
  Wings.set(true);
  chassis.drive_distance(-15);
  Wings.set(false);
  chassis.turn_to_angle(70);
  chassis.drive_distance(-50);
  chassis.turn_to_angle(-60);
  Intake.setVelocity(100,percent);
  Intake.spin(reverse);
  wait(.65, seconds);
  Intake.stop();
  chassis.drive_distance(-10);
  chassis.turn_to_angle(97);
  chassis.drive_distance(-5);
  chassis.turn_to_angle(175);
  chassis.drive_distance(-30);
  intakePistons.set(true);
}

void swing_test(){
  Intake.setVelocity(100,percent);
  Wings.set(true);
  chassis.drive_distance(-20);
  Wings.set(false);
  chassis.turn_to_angle(-30);
  chassis.drive_distance(-15);
  chassis.drive_distance(10);
  chassis.turn_to_angle(-110);
  intakePistons.set(true);
  Intake.spin(forward);
  chassis.drive_distance(-45);
  chassis.drive_distance(5);
  chassis.turn_to_angle(-40);
  chassis.drive_distance(-20);
  chassis.turn_to_angle(50);
  Intake.stop();
  chassis.drive_distance(8);
  intakePistons.set(false);
  Intake.spin(reverse);
  wait(0.2,seconds);
  Wings.set(true);
  chassis.drive_distance(-25);
  chassis.drive_distance(10);

}

void full_test(){
  Cata.setVelocity(100,percent);
  intakePistons.set(true);
  wait(0.5, seconds);
  Cata.spin(forward);
  wait(0, seconds);
  Cata.stop();
  chassis.drive_distance(10);
  chassis.turn_to_angle(145);
  chassis.drive_distance(-54);
  chassis.turn_to_angle(220);
  chassis.drive_distance(8);
  chassis.drive_distance(-53);
  intakePistons.set(false);
  Wings.set(true);
  wait(0.45,seconds);
  chassis.drive_distance(-30);
  chassis.drive_distance(20);
  chassis.drive_distance(-20);
  chassis.drive_distance(20);
  chassis.drive_distance(-20);
  chassis.drive_distance(20);
}

void odom_test(){
  chassis.set_coordinates(0, 0, 0);
  while(1){
    Brain.Screen.clearScreen();
    Brain.Screen.printAt(0,50, "X: %f", chassis.get_X_position());
    Brain.Screen.printAt(0,70, "Y: %f", chassis.get_Y_position());
    Brain.Screen.printAt(0,90, "Heading: %f", chassis.get_absolute_heading());
    Brain.Screen.printAt(0,110, "ForwardTracker: %f", chassis.get_ForwardTracker_position());
    Brain.Screen.printAt(0,130, "SidewaysTracker: %f", chassis.get_SidewaysTracker_position());
    task::sleep(20);
  }
}

void tank_odom_test(){
  odom_constants();
  chassis.set_coordinates(0, 0, 0);
  chassis.turn_to_point(24, 24);
  chassis.drive_to_point(24,24);
  chassis.drive_to_point(0,0);
  chassis.turn_to_angle(0);
}

void holonomic_odom_test(){
  odom_constants();
  chassis.set_coordinates(0, 0, 0);
  chassis.holonomic_drive_to_point(0, 18, 90);
  chassis.holonomic_drive_to_point(18, 0, 180);
  chassis.holonomic_drive_to_point(0, 18, 270);
  chassis.holonomic_drive_to_point(0, 0, 0);
}