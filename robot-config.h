using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor UpL;
extern motor UpR;
extern motor BackL;
extern motor FrontL;
extern motor FrontR;
extern motor BackR;
extern rotation Rotation3;
extern motor Cata;
extern motor Intake;
extern controller Controller1;
extern digital_out intakePistons;
extern digital_out Wings;
extern inertial Inertial1;
extern digital_out Endgame;
extern inertial Inertial2;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );