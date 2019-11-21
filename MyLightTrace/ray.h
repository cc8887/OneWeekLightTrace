#pragma once
#ifndef RAYH
#define RAYH


#include "vec3.h"
class ray
{
public:
	
	ray();
	ray(const vec3& a, const vec3& b);
	ray(const vec3& a, const vec3& b, float ti = 0.0);
	~ray();
	float time() const;

	vec3 origin() const;
	vec3 direction() const;
	vec3 point_at_parameter(float t) const;
	vec3 A;
	vec3 B;
	float _time;
};

#endif // !RAYH