#include "main.h"


Angle::Angle(double _degrees) {
    this->degrees = _degrees;
};

Angle::Angle() {
    this->degrees = 0;
}

double Angle::to_radians() {
    return (this->degrees * DEGREES_TO_RADIANS);
}

double Angle::to_degrees(double radians) {
    return radians * RADIANS_TO_DEGREES;
}


/* 
 * VECTOR
 */

/* 
 * Constructors
 */
Vector::Vector() {
    this->m = 0;
    this->direction = Angle();
    this->quadrant = this->get_quadrant();
}

Vector::Vector(double _m, Angle _direction) {
    this->m = _m;
    this->direction = _direction;
};

Vector::Vector(VectorEq v) {
    this->copy(v);
}

Vector::Vector(double i, double j) {
    this->copy(VectorEq(i, j));
}

uint8_t Vector::get_quadrant() {
    if (this->direction.to_double() >   0 && this->direction.to_double() <  90)
        return 1;
    if (this->direction.to_double() >  90 && this->direction.to_double() < 180) 
        return 2;
    if (this->direction.to_double() > 180 && this->direction.to_double() < 270) 
        return 3;
    if (this->direction.to_double() > 270 && this->direction.to_double() < 360) 
        return 4; 
    return 0;
}

/*
 * Copying
 */
Vector Vector::get_copy() {
    return Vector(this->m, this->direction);
}

void Vector::copy(Vector other) {
    this->m = other.m;
    this->direction = other.direction;
}

void Vector::copy(VectorEq other) {
    Vector tmp = other.to_vector();
    this->copy(other);
}

/*
 * Math
 */
Vector Vector::add(Vector other) {
    VectorEq eq1 = this->to_eq();
    VectorEq eq2 = other.to_eq();
    return eq1.add(eq2).to_vector();
}

Vector Vector::add(VectorEq other) {
    VectorEq eq1 = this->to_eq();
    return eq1.add(other).to_vector();
}

Vector Vector::subtract(Vector other) {
    VectorEq eq1 = this->to_eq();
    VectorEq eq2 = other.to_eq();
    return eq1.subtract(eq2);
}

Vector Vector::subtract(VectorEq other) {
    VectorEq eq1 = this->to_eq();
    return eq1.subtract(other);
}

Vector Vector::multiply(double by) {
    return Vector(this->m * by, this->direction);
}


/*
 * VECTOR EQUATION
 */

/*
 * Constructors
 */
VectorEq::VectorEq() {
    this->i = 0;
    this->j = 0;
}

VectorEq::VectorEq(double _i, double _j) {
    this->i = _i;
    this->j = _j;
}

VectorEq::VectorEq(Vector v) {
    this->copy(v);
}

VectorEq::VectorEq(double m, Angle direction) {
    this->copy(Vector(m, direction));
}


uint8_t VectorEq::get_quadrant() {
    if (this->i > 0) {
        if (this->j > 0)
            return 1;
        else if (this->j < 0)
            return 4;
    } else if (this->i < 0) {
        if (this->j > 0)
            return 2;
        else if (this->j < 0)
            return 3;
    }
    return 0;
}

/*
 * Copying
 */
VectorEq VectorEq::get_copy() {
    return VectorEq(this->i, this->j);
}

void VectorEq::copy(VectorEq other) {
    this->i = other.i;
    this->j = other.j;
}

void VectorEq::copy(Vector other) {
    VectorEq tmp = other.to_eq();
    this->i = tmp.i;
    this->j = tmp.j;
}


/*
 * Math
 */
VectorEq VectorEq::add(VectorEq other) {
    return Vector(this->i + other.i, this->j + other.j);
}

VectorEq VectorEq::add(Vector other) {
    VectorEq tmp = other.to_eq();
    return VectorEq(this->i + tmp.i, this->j + tmp.j);
}

VectorEq VectorEq::subtract(VectorEq other) {
    return VectorEq(this->i - other.i, this->j - other.j);
}

VectorEq VectorEq::subtract(Vector other) {
    VectorEq tmp = other.to_eq();
    return VectorEq(this->i - tmp.i, this->j - tmp.j);
}

VectorEq VectorEq::multiply(double by) {
    return VectorEq(this->i * by, this->j * by);
}



/*
 * Conversions
 */
Vector VectorEq::to_vector() {
    double m = sqrt((this->i * this->i) + (this->j * this->j));
    
    if (this->i == 0) {
        if (this->j == 0) {
            return VectorEq(0, 0);
        }
        else if (this->j > 0)
            return Vector(m, Angle(90));
        else if (this->j < 0) 
            return Vector(m, Angle(270));
    } else if (this->j == 0) {
        if (this->i > 0)
            return Vector(m, Angle(0));
        else if (this->i < 0)
            return Vector(m, Angle(180));
    } else {
        double raw = atan(j/i) * RADIANS_TO_DEGREES;
        if (this->quadrant == 2 || this->quadrant == 3) 
            raw += 180;
        else if (this->quadrant == 4) 
            raw += 360;
        return Vector(m, Angle(raw));
    }
    return Vector(0, 0);
}

VectorEq Vector::to_eq() {
    double i = this->m * cos(this->direction.to_double() * DEGREES_TO_RADIANS);
    double j = this->m * sin(this->direction.to_double() * DEGREES_TO_RADIANS);
    return VectorEq(i, j);
}

