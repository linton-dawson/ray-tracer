#ifndef HEADERS_H
#define HEADERS_H

#include <cmath>
#include <cstdlib>
#include <limits>
#include <memory>
#include <random>
#include <algorithm>

using std::shared_ptr;
using std::make_shared;
using std::sqrt;

constexpr const double infinity = std::numeric_limits<double>::infinity();
constexpr const double pi = 3.1415926535897932385;

constexpr double deg2rad(double degrees) {
    return degrees*pi/180;
}

inline double random_double() {
    static std::uniform_real_distribution<double> dist(0.0,1.0);
    static std::mt19937 gen;
    return dist(gen);
}

inline double random_double(double min, double max) {
    return min + (max - min)*random_double();
}

#endif
