/*
Compile: make surface
Run: ./surface
make surface && ./surface
*/

#include "base.h"
# define M_PI           3.14159265358979323846  /* pi */

typedef enum Tag { 
	TCylinder, 
	TSphere, 
	TCuboid 
} Tag;

struct Cylinder {
    double r, h; // A = 2 pi r^2 + 2 pi r h
};

struct Sphere {
    double r; // A = 4 pi r^2
};

struct Cuboid {
    double a, b, c; // A = 2ab + 2ac + 2bc
};


typedef struct Cylinder Cylinder;
typedef struct Sphere Sphere;
typedef struct Cuboid Cuboid;
typedef struct GeomObject GeomObject;

struct GeomObject {
    // todo: implement
    enum Tag tag;
    union {
        Cylinder cylinder;
        Sphere sphere;
        Cuboid cuboid;
    };
};


GeomObject make_cylinder(double r, double h) {
    // todo: implement
    GeomObject o = {};
    o.tag = TCylinder;
    o.cylinder.r = r;
    o.cylinder.h = h;
    
    return o;
}

GeomObject make_sphere(double r) {
    // todo: implement
    GeomObject o = {};
    o.tag = TSphere;
    o.sphere.r = r;
    return o;
}

GeomObject make_cuboid(double a, double b, double c) {
    // todo: implement
    GeomObject o = {};
    o.tag = TCuboid;
    o.cuboid.a = a;
    o.cuboid.b = b;
    o.cuboid.c = c;
    return o;
}

double surface_area(GeomObject o);

void surface_area_test(void) {
    test_within_d(surface_area(make_sphere(2)), 4 * M_PI * 2 * 2, 1e-6);
    test_within_d(surface_area(make_cuboid(2, 3, 4)), 2 * 2 * 3 + 2 * 2 * 4 + 2 * 3 * 4, 1e-6);
    test_within_d(surface_area(make_cylinder(3, 4)), 2 * M_PI * 3 * 3 + 2 * M_PI * 3 * 4, 1e-6);
}
    
// GeomObject -> double
// Computes the surface area of the given object.
double surface_area(GeomObject o) {
    // todo: implement
    double surface_area = 0;
    switch (o.tag)
    {
    case TCuboid:
        surface_area = 2 * o.cuboid.a * o.cuboid.b + 2 * o.cuboid.a * o.cuboid.c + 2 * o.cuboid.b * o.cuboid.c;
        break;
    case TSphere:
        surface_area = 4 * M_PI * o.sphere.r * o.sphere.r;
        break;
    case TCylinder:
        surface_area = 2 * M_PI * o.cylinder.r * o.cylinder.r + 2 * M_PI * o.cylinder.r * o.cylinder.h;
        break;
    }
	return surface_area;
}

int main(void) {
    surface_area_test();
    return 0;
}
