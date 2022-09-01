#include "main.h"

pros::Imu inertial_sensor(16);

std::vector<pros::c::imu_accel_s_t> accelerations;
std::vector<pros::c::imu_gyro_s_t> rotations;
std::vector<double> timestamps;