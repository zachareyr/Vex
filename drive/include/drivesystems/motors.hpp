#include "main.h"

// 36 - red, 100rpm
// 18 - green, 200rpm
// 06 - blue, 600rpm

#define INTAKE_GEARSET pros::E_MOTOR_GEARSET_36
extern pros::Motor m_intake;

#define PUSH_GEARSET pros::E_MOTOR_GEARSET_06
extern pros::Motor m_push;

#define DRIVE_GEARSET pros::E_MOTOR_GEARSET_18
extern pros::Motor m_topleft;
extern pros::Motor m_topright;
extern pros::Motor m_bottomleft;
extern pros::Motor m_bottomright;

#define FLY_GEARSET pros::E_MOTOR_GEARSET_06
extern pros::Motor m_fly1;
extern pros::Motor m_fly2;

