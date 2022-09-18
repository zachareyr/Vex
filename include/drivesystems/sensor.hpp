#include "main.h"
#include <vector>

extern pros::Imu inertial_sensor;
extern std::vector<double> rotation_list;
extern std::vector<pros::c::imu_accel_s_t> acceleration_list;
extern std::vector<uint64_t> timestamp_list;
extern std::vector<double> vx_list;
extern std::vector<double> vy_list;
extern std::vector<double> px_list;
extern std::vector<double> py_list;

#define UNKNOWN -1
#define O_SENSOR_PORT

// Distance to the bottom right corner of the robot in inches 
#define SENSOR_X 0.5
#define SENSOR_Y 1.25