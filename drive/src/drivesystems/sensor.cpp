#include "main.h"

pros::Imu inertial_sensor(16);

std::vector<double> rotation_list;
std::vector<pros::c::imu_accel_s_t> acceleration_list;
std::vector<uint64_t> timestamp_list;
std::vector<double> vx_list;
std::vector<double> vy_list;
std::vector<double> px_list;
std::vector<double> py_list;