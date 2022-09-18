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
	double yaw = inertial_sensor.get_yaw();
	rotation_list.push_back(yaw);

	pros::c::imu_accel_s_t a = inertial_sensor.get_accel();
	acceleration_list.push_back(a);

	uint64_t micros = pros::micros();
	timestamp_list.push_back(micros);
    
    int n = acceleration_list.size() - 1;
    
    // If any of the lists failed to update, continue recursing n back until a valid # is found
    for (; n > acceleration_list.size() - 1 || n > timestamp_list.size() - 1 || n > rotation_list.size() - 1; n--)

    // Previous velocity is required for calculations, so don't continue without it
    if (vx_list.size() > 0) {
        // fucky wucky math to get velocity and position
        double a0x = acceleration_list[n - 1].x;
        double a0y = acceleration_list[n - 1].y;
        double afx = acceleration_list[n].x;
        double afy = acceleration_list[n].y;
        double vx0 = vx_list[n - 1];
        double vy0 = vy_list[n - 1];
        double dt = timestamp_list[n] - timestamp_list[n - 1];

        double ax_avg = (a0x + afx) / 2;
        double ay_avg = (a0y + afy) / 2; 
        double vxf = vx0 + (ax_avg * dt);
        double vyf = vy0 + (ay_avg * dt);   

        vx_list.push_back(vxf);
        vy_list.push_back(vyf);

        double vx_avg = (vx0 + vxf) / 2;
        double vy_avg = (vy0 + vyf) / 2;
        double px = px_list[n] + (vx_avg * dt);
        double py = py_list[n] + (vy_avg * dt);

        px_list.push_back(px);
        py_list.push_back(py);
    } else {
        // Assume the object begins stationary at the starting coordinates defined in [include/drive.hpp]
        vx_list.push_back(0);
        vy_list.push_back(0);
        px_list.push_back(STARTING_POSITION_X);
        py_list.push_back(STARTING_POSITION_Y);
    }
}

VectorEq get_pos() {
    return VectorEq(px_list[px_list.size() - 1], py_list[py_list.size() - 1]); 
}
