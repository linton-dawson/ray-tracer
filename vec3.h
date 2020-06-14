#ifndef VEC3_H
#define VEC3_H

#include "headers.h"
#include<iostream>
#include<cmath>

class Vec3 {
    public :
        double ord[3];

    public:

        //constructors
        Vec3() : ord{0,0,0} {};
        Vec3(double x, double y, double z) : ord{x,y,z} {}; 

        //overloading - operator
        Vec3 operator -() const{
            return Vec3(-ord[0],-ord[1], - ord[2]);
        }

        //overloading += operator
        Vec3& operator +=(const Vec3& vec) {
            ord[0] += vec.ord[0];
            ord[1] += vec.ord[1];
            ord[2] += vec.ord[2];
            return *this;
        }
        
        //overloading *= operator
        Vec3 operator *=(const Vec3& vec) {
            ord[0] *= vec.ord[0];
            ord[1] *= vec.ord[1];
            ord[2] *= vec.ord[2];
            return *this;
        }

        //overloading /= operator
        Vec3 operator /=(const Vec3& vec) {
            ord[0] /= vec.ord[0];
            ord[1] /= vec.ord[1];
            ord[2] /= vec.ord[2];
            return *this;
        }

        double x() { return ord[0]; }
        double y() { return ord[1]; }
        double z() { return ord[2]; }

        //magnitude of vector
        constexpr double length() {
            return std::sqrt(length_sq());
        }

        //squared length
        constexpr double length_sq() {
            return (ord[0]*ord[0] + ord[1]*ord[1] + ord[2]*ord[2]);
        }

        //get a vector of random_double
        inline static Vec3 random() {
            return Vec3(random_double(),random_double(), random_double());
        }

        //get vector of random_double within range
        inline static Vec3 random(double min, double max) {
            return Vec3(random_double(min,max),random_double(min,max), random_double(min,max));
        }

};


        Vec3 unit_sphere_random() {
            while(true) {
                auto p = Vec3::random(-1,1);
                if(p.length_sq() >= 1) continue;
                return p;
            }
        }

        inline std::ostream& operator <<(std::ostream& out, const Vec3& vec) {
            return out<<vec.ord[0]<<' '<<vec.ord[1]<<' '<<vec.ord[2];
        }
        
        //overloading + operator
        inline Vec3 operator +(const Vec3& v1, const Vec3& v2) {
            return Vec3(v1.ord[0] + v2.ord[0], v1.ord[1] + v2.ord[1], v1.ord[2] + v2.ord[2]);
        }

        //overloading - operator
        inline Vec3 operator -(const Vec3& v1, const Vec3& v2) {
            return Vec3(v1.ord[0] - v2.ord[0], v1.ord[1] - v2.ord[1], v1.ord[2] - v2.ord[2]);
        }

        //overloading * operator for two vectors
        inline Vec3 operator *(const Vec3& v1,const Vec3& v2) {
            return Vec3(v1.ord[0] * v2.ord[0], v1.ord[1] * v1.ord[1], v1.ord[2] * v2.ord[2]);
        }

        //overloading * operator for scalar and a vector
        inline Vec3 operator *(double n, const Vec3& v1) {
            return Vec3(n*v1.ord[0], n*v1.ord[1], n*v1.ord[2]);
        }

        //overloading / operator
        inline Vec3 operator /(const Vec3 v, double n) {
            return static_cast<double>(1/n) * v;
        }
        
        inline Vec3 unit_vector(Vec3 v) {
            return v/v.length();
        }
        //dot product
        inline double dot(Vec3 v1, Vec3 v2) {
            return (v1.ord[0]*v2.ord[0] + v1.ord[1]*v2.ord[1] + v1.ord[2]*v2.ord[2]);
        }

        //cross product. Can't constexpr because return type doesn't have a constexpr constructor (copy or move constructor)
        inline Vec3 cross(Vec3 v1, Vec3 v2) {
            return Vec3(v1.ord[1]*v2.ord[2] - v1.ord[2]*v2.ord[1],v1.ord[0]*v2.ord[2] - v1.ord[2]*v2.ord[0],v1.ord[0]*v2.ord[1] - v1.ord[1]*v2.ord[0]);
        }

#endif
