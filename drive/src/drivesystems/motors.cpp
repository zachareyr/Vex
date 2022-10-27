#include "main.h"

pros::Motor m_fly1(M_FLY1_PORT, FLY_GEARSET, false, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor m_fly2(M_FLY2_PORT, FLY_GEARSET, true, pros::E_MOTOR_ENCODER_DEGREES);

pros::Motor m_push(M_PUSH_PORT, PUSH_GEARSET, false, pros::E_MOTOR_ENCODER_DEGREES);

pros::Motor m_intake(M_INTAKE_PORT, INTAKE_GEARSET, true, pros::E_MOTOR_ENCODER_ROTATIONS);

pros::Motor m_topleft    (M_TOPLEFT_PORT,     DRIVE_GEARSET, false, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor m_topright   (M_TOPRIGHT_PORT,    DRIVE_GEARSET, true , pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor m_bottomleft (M_BOTTOMLEFT_PORT,  DRIVE_GEARSET, false, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor m_bottomright(M_BOTTOMRIGHT_PORT, DRIVE_GEARSET, true , pros::E_MOTOR_ENCODER_DEGREES);
