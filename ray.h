#ifndef RAY_H
#define RAY_H

#include "vec3.h"

class Ray
{
    public:

    Ray() {}
    Ray(const Vec3& origin, const Vec3& direction) : 
       ori(origin), dir(direction) {}

    Vec3 origin() const{ return ori; }
    Vec3 direction() const{ return dir; }

    Vec3 pos(double t)const
    {
        return ori + t*dir;
    }

    private :
    
    Vec3 ori;
    Vec3 dir;
};

#endif
