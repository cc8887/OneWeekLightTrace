#pragma once
#include "hitable.h"
class moving_sphere :
	public hitable
{
public:
	moving_sphere();
	moving_sphere(vec3 cen0, vec3 cen1, float t0, float t1, float r, material *m) :
		center0(cen0), center1(cen1), time0(t0), time1(t1), radius(r), material(m) {};
	~moving_sphere();

	virtual bool hit(const ray& r, float tmin, float tmax, hit_record& rec)const;
	vec3 center(float time)const;
	float time0, time1;
	vec3 center0, center1;
	float radius;
	material *material;
};

