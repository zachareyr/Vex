#include "main.h"

extern pros::Controller master;

#define FLYWHEEL_BUTTON pros::E_CONTROLLER_DIGITAL_X
#define FLYWHEEL_STICK pros::E_CONTROLLER_ANALOG_RIGHT_Y

// 0 button
// 1 stick
#define FLYWHEEL_CONTROL_SCHEME 0

#define INTAKE_FWD_BUTTON pros::E_CONTROLLER_DIGITAL_UP
#define INTAKE_REV_BUTTON pros::E_CONTROLLER_DIGITAL_DOWN
#define INTAKE_STICK pros::E_CONTROLLER_ANALOG_RIGHT_Y

// 0 - fwd & reverse button
// 1 - stick
#define INTAKE_CONTROL_SCHEME 1

#define DRIVE_FWD pros::E_CONTROLLER_ANALOG_LEFT_Y
#define DRIVE_TRN pros::E_CONTROLLER_ANALOG_LEFT_X
#define DRIVE_TRN_ALT pros::E_CONTROLLER_ANALOG_RIGHT_X

// 0 - left stick only
// 1 - forward on left stick, turn on right stick
#define DRIVE_CONTROL_SCHEME 1

#define PUSH_BUTTON pros::E_CONTROLLER_DIGITAL_LEFT

#define WIRELESS_RECIEVER_PORT 10