#include "main.h"

std::vector<float> get_motor_efficiencies(std::vector<pros::Motor> motors);
std::vector<float> get_motor_faults(std::vector<pros::Motor> motors);
std::vector<float> get_motor_positions(std::vector<pros::Motor> motors);
std::vector<float> get_motor_temperatures(std::vector<pros::Motor> motors);

void power_motors(std::vector<pros::Motor> *motors, int voltage);
void update_inertial();
int bool_to_multiplier(bool x);
int capint(int val, int min, int max);
double cap(double val, double min, double max);

VectorEq get_pos();

typedef struct p2 position2D;
typedef struct p3 position3D;
