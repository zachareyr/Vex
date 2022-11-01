#include "main.h"

extern pros::Controller master;

#define FLYWHEEL_BUTTON pros::E_CONTROLLER_DIGITAL_L2
#define FLYWHEEL_STICK pros::E_CONTROLLER_ANALOG_RIGHT_Y

// 0 button
// 1 stick
#define FLYWHEEL_CONTROL_SCHEME 0

#define INTAKE_FWD_BUTTON pros::E_CONTROLLER_DIGITAL_L1
#define INTAKE_REV_BUTTON pros::E_CONTROLLER_DIGITAL_R1
#define INTAKE_STICK pros::E_CONTROLLER_ANALOG_RIGHT_Y

// 0 - fwd & reverse button
// 1 - stick
#define INTAKE_CONTROL_SCHEME 0

#define DRIVE_FWD pros::E_CONTROLLER_ANALOG_LEFT_Y
#define DRIVE_TRN pros::E_CONTROLLER_ANALOG_LEFT_X
#define DRIVE_TRN_FINE pros::E_CONTROLLER_ANALOG_RIGHT_X
#define DRIVE_FWD_FINE pros::E_CONTROLLER_ANALOG_RIGHT_Y

// 0 - left stick only
// 1 - forward on left stick, turn on right stick
#define DRIVE_CONTROL_SCHEME 1

#define PUSH_BUTTON pros::E_CONTROLLER_DIGITAL_R2
#define RESET_PUSH_BUTTON pros::E_CONTROLLER_DIGITAL_DOWN
#define RESET_TIME = 1

#define REVERSE_DRIVE_BTN pros::E_CONTROLLER_DIGITAL_X 
#define REVERSE_PUSH_BTN pros::E_CONTROLLER_DIGITAL_B
#define WIRELESS_RECIEVER_PORT 10

extern bool push_reverse_held;
extern bool drive_reverse_held;
extern bool push_is_active;
extern bool driving_mode;
extern bool push_is_forward;