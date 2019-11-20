#ifndef SPHEREH
#define SPHEREH
#include "hitable.h"
//#include "metal.h"
//#include "lambertian.h"
class sphere:public hitable
{
public:

	sphere();
	//sphere(vec3 cen, float r) :center(cen), raduis(r) { mat = new metal(vec3(1, 1, 1)); };
	sphere(vec3 cen, float r,material *m) :center(cen), raduis(r),mat(m) {};
	virtual bool hit(const ray& r, float t_min, float t_max, hit_record& rec)const;
	~sphere();

	vec3 center;
	float raduis;
	material *mat;
};

#endif // !SPHERE