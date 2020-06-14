#ifndef ALLHITTABLES_H
#define ALLHITTABLES_H

#include "hittable.h"

#include<vector>
#include<memory>

using std::shared_ptr;
using std::make_shared;

class Allhittables : public Hittable {
    public :
        Allhittables() {}
        Allhittables(shared_ptr<Hittable> obj) { add(obj) ; }

        ~Allhittables() {objects.clear();}

        void add(shared_ptr<Hittable> obj) { objects.push_back(obj); }

        virtual bool hit(const Ray& r, double t_min, double t_max, hit_record& rec) const;

    public :
        std::vector<shared_ptr<Hittable>> objects;

};

bool Allhittables :: hit(const Ray& r, double t_min, double t_max, hit_record& rec)const {
    hit_record temp;
    bool isHit = false;
    auto closest = t_max;

    for(const auto& obj : objects) {
        if(obj->hit(r,t_min,closest,temp)) {
            isHit = true;
            closest = temp.t;
            rec = temp;
        }
    }
    return isHit;
}

#endif
