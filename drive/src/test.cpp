#include "main.h"

std::vector<pros::c::imu_accel_s_t> al{0};
std::vector<double> rl{};
std::vector<double> vxl{};
std::vector<double> vyl{};
std::vector<double> pxl{};
std::vector<double> pyl{};

void intest(double yaw, pros::c::imu_accel_s_t a, uint64_t micros) {
    int n = acceleration_list.size() - 1;
    
    // Previous velocity is required for calculations
    if (vx_list.size() > 0) {
        double a0x = al[n - 1].x;
        double a0y = al[n - 1].y;
        double afx = al[n].x;
        double afy = al[n].y;
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
        // Assume the object begins stationary
        vx_list.push_back(0);
        vy_list.push_back(0);
        px_list.push_back(STARTING_POSITION_X);
        py_list.push_back(STARTING_POSITION_Y);
    }
}