#include "main.h"

pros::Motor m_topleft(M_TOPLEFT_PORT, pros::E_MOTOR_GEARSET_18, 0, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor m_topright(M_TOPRIGHT_PORT, pros::E_MOTOR_GEARSET_18, 1 , pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor m_bottomleft(M_BOTTOMLEFT_PORT, pros::E_MOTOR_GEARSET_18, 0, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor m_bottomright(M_BOTTOMRIGHT_PORT, pros::E_MOTOR_GEARSET_18, 1, pros::E_MOTOR_ENCODER_DEGREES);
