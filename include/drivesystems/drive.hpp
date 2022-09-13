#include "main.h"

extern pros::Motor m_topleft;
extern pros::Motor m_topright;
extern pros::Motor m_bottomleft;
extern pros::Motor m_bottomright;

#define M_TOPLEFT_PORT 12
#define M_TOPRIGHT_PORT 11
#define M_BOTTOMLEFT_PORT 2
#define M_BOTTOMRIGHT_PORT 1

// TODO measure this shit

// Where the robot starts on the field (left side)
#define STARTING_POSITION_1

// Where the robot starts on the field (right side)
#define STARTING_POSITION_2 

// The starting position used
#define STARTING_POSITION_X 1
#define STARTING_POSITION_Y 1

// Wheel attributes
// MEASUREMENTS IN INCHES

#define WHEEL_CIRCUMFERENCE 4 * PI 
#define WHEEL_RADIUS 2
#define WHEEL_DIAMETER 4
#define WHEEL_WIDTH 1

// Distance between the axles
#define WHEEL_BASE

// Width of the robot  
#define TRACK_WIDTH
