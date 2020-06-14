#ifndef HITTABLE_H
#define HITTABLE_H

#include "ray.h"

struct hit_record {
    Vec3 p;
    Vec3 normal;
    double t;
    bool front_face;

    inline void set_face_normal(const Ray& r, const Vec3& outward_normal) {
        front_face = dot(r.direction(), outward_normal) < 0;
        if(front_face)
            normal = outward_normal;
        else
            normal = -outward_normal;
    }
};

class Hittable {
    public :
        //pure virtual function hence the "= 0"
        virtual bool hit(const Ray &r, double t_min, double t_max, hit_record& rec) const = 0;
};

#endif
