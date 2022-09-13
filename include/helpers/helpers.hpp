#include "main.h"

std::vector<float> get_motor_efficiencies(std::vector<pros::Motor> motors);
std::vector<float> get_motor_faults(std::vector<pros::Motor> motors);
std::vector<float> get_motor_positions(std::vector<pros::Motor> motors);
std::vector<float> get_motor_temperatures(std::vector<pros::Motor> motors);

void power_motors(std::vector<pros::Motor> *motors, int voltage);
void update_inertial();
