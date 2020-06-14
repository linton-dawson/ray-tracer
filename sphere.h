#ifndef SPHERE_H
#define SPHERE_H

#include "hittable.h"
#include "vec3.h"

class Sphere : public Hittable {
    public : 
        Sphere() {}
        Sphere(Vec3 c, double r) : center(c), radius(r) {}

        virtual bool hit(const Ray& r, double t_min, double t_max, hit_record& rec) const;

        public :
            double radius;
            Vec3 center;
};

bool Sphere:: hit(const Ray &r, double t_min, double t_max, hit_record& rec) const {

    // sphere eqn t2b.b + 2tb.(A - C) + (A-C).(A-C) = r2 = 0 for ray sphere intersection
    // A is the origin of the ray and C is the center of the sphere, b is ray direction
    // taking its discriminant and taking 2 common from num and denom, we get below eqn
    Vec3 oc = r.origin() - center;
    auto a = r.direction().length_sq();
    auto half_b = dot(oc, r.direction());
    auto c = oc.length_sq() - radius*radius;
    auto discriminant = half_b*half_b - a*c;
    if (discriminant > 0) {
        auto root = sqrt(discriminant);
        auto tmp = (-half_b - root)/a;
        if(tmp < t_max && tmp > t_min) {
            rec.t = tmp;
            rec.p = r.pos(rec.t);
            Vec3 outward_normal = (rec.p - center)/ radius;
            rec.set_face_normal(r, outward_normal);
            return true;
        }
        tmp = (-half_b + root) / a;
        if(tmp < t_max && tmp > t_min) {
            rec.t = tmp;
            rec.p = r.pos(rec.t);
            Vec3 outward_normal = (rec.p - center) / radius;
            rec.set_face_normal(r, outward_normal);
            return true;
        }
    }
    return false;
}

#endif
