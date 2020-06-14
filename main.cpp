#include "headers.h"
#include "allhittable.h"
#include "color.h"
#include "sphere.h"
#include "camera.h"

Vec3 ray_color(const Ray& r, const Hittable& world,int bounces) {

    hit_record rec;

    if(bounces <= 0)
        return Vec3(0,0,0);

    // the 0.001 is for shadow acne removal
    if(world.hit(r,0.001,infinity,rec)) {
        Vec3 target = rec.p + rec.normal + unit_sphere_random();
        return 0.5*ray_color(Ray(rec.p, target  - rec.p), world,bounces - 1);
    }

    Vec3 unit_direction = unit_vector(r.direction());

    //design decision. diff here
    auto t =  unit_direction.y();
    
    //returning linear interpolation aka lerp. formula is blendedVal = (1- t).startVal + t.endVal
    return (1.0 - t)*Vec3(1.0,1.0,1.0) + t*Vec3(0.50,0.70,1.00);
}


int main()
{
    const auto aspect_ratio = 16.0 / 9.0;
    const int image_width = 384;
    const int image_height = static_cast<int>(image_width/aspect_ratio);
    const int samples_per_pixel = 100;
    const int bounces = 50;

    Camera cam;

    Allhittables world;
    world.add(make_shared<Sphere>(Vec3(0,0,-1),0.5));
    world.add(make_shared<Sphere>(Vec3(0,-100.5,-1),100));

    std::cout<<"P3\n"<<image_width<<" "<<image_height<<"\n255\n";
    for(int j = image_height - 1; j >= 0 ; --j) {
//        std::cerr<<"scanline remaining "<<j<<'\n';
        for(int i = 0 ; i < image_width ; ++i) {
            Vec3 pixel_color(0,0,0);
            for(auto s = 0 ; s < samples_per_pixel; ++s) {
                double u = (i + random_double())/(image_width - 1);
                double v = (j + random_double())/(image_height -1);
                Ray r = cam.get_ray(u,v);
                pixel_color += ray_color(r,world,bounces);
            }
            cout_color(std::cout,pixel_color,samples_per_pixel);
        }
    }
    std::cerr<<"Done\n";
}
