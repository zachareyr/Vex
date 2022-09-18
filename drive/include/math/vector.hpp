#include "main.h"

class Angle {
    public:
        double degrees;

        Angle();
        Angle(double _degrees);

        double to_radians();
        double to_double();
        static double to_degrees(double radians);
};

/* 
 * Define the Vector & VectorEq classes so the compiler knows they both exist
 */
class Vector;
class VectorEq;

class Vector {
    public:
        double m;
        Angle direction;
        uint8_t quadrant;
        /*
         * Constructors
         */
        Vector();
        Vector(double _m, Angle _direction);
        Vector(VectorEq v);
        Vector(double i, double j);

        /*
         * Converts a vector to equation (aka unit vector) form
         */
        VectorEq to_eq();

        /* 
         * Vector Math
         */
        uint8_t get_quadrant();
        Vector add(Vector other);
        Vector add(VectorEq other);
        Vector subtract(Vector other);
        Vector subtract(VectorEq other);
        Vector multiply(double by);
        Vector get_copy();
        void copy(Vector other);
        void copy(VectorEq other);
};

class VectorEq {
    public:
        double i;
        double j;
        uint8_t quadrant;
        /*
         * Constructors
         */
        VectorEq();
        VectorEq(double _i, double _j);
        VectorEq(Vector v);
        VectorEq(double m, Angle direction);

        /* 
         * Conversions & Copying
         */
        uint8_t get_quadrant();
        Vector to_vector();
        VectorEq get_copy();
        void copy(VectorEq other);
        void copy(Vector other);

        /* 
         * Math
         */
        VectorEq add(VectorEq other);
        VectorEq add(Vector other);
        VectorEq subtract(VectorEq other);
        VectorEq subtract(Vector other);
        VectorEq multiply(double by);
        
};