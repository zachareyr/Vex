#include "main.h"

std::vector<float> get_motor_temperatures(std::vector<pros::Motor> motors) {
    std::vector<float> temps;

    for (std::vector<pros::Motor>::iterator ptr = motors.begin(); ptr < motors.end(); ptr++) {
        temps.push_back((*ptr).get_temperature());
    }
    return temps;
}

void power_motors(std::vector<pros::Motor> *motors, int voltage) {
    for (std::vector<pros::Motor>::iterator ptr = motors->begin(); ptr < motors->end(); ptr++) {
        ptr->move(voltage);
    }
}

void update_inertial() {
	double ry = inertial_sensor.get_yaw();
	rotation_list.push_back(ry);

	pros::c::imu_accel_s_t a = inertial_sensor.get_accel();
	acceleration_list.push_back(a);

	uint64_t micros = pros::micros();
	timestamp_list.push_back(micros);

    int length = vx_list.size();
    // double a_avg = (acceleration_list[length] - acceleration_list[length - 1]) / (timestamp_list[length] - timestamp_list[length - 1]);
    // double vx = vx_list[length - 1] + (acceleration_list[length].x - acceleration_list[length - 1].x);
    double vy = vy_list[length - 1];
}

double calculate_position() {
    double px = STARTING_POSITION_X;
    double py = STARTING_POSITION_Y;
    double vx = 0;
    double vy = 0;
    for (uint64_t i = 0; i < timestamp_list.size(); i++) {
        vx += acceleration_list[i].x * (timestamp_list[i] * 1000);
        vy += acceleration_list[i].y * (timestamp_list[i] * 1000);
    }  
    
    // TODO finish this
    return -1;
}
// Ms. Heine