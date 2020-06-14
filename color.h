#ifndef COLOR_H
#define COLOR_H

#include "headers.h"

void cout_color(std::ostream &out, Vec3 color, int samples_per_pixel) {

    auto r = color.x();
    auto g = color.y();
    auto b = color.z();
    
    //Antialiasing steps;
    auto scale = 1.0/ samples_per_pixel;

    //gamma correction is gamma-th root of r,g,b resp
    r = sqrt(r * scale);
    g = sqrt(g * scale);
    b = sqrt(b * scale);

    out<<static_cast<int>(256 * std::clamp(r,0.0,0.999))<<' '
    <<static_cast<int>(256 * std::clamp(g,0.0,0.999))<<' '
    <<static_cast<int>(256 * std::clamp(b,0.0,0.999))<<'\n';
}

#endif
