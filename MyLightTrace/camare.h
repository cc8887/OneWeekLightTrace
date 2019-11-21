#ifndef	CAMAREH
#define CAMAREH
#include "ray.h"
#include "random.h"
class camare
{
public:
	camare();
	camare(float vfov, float aspect);
	camare(vec3 lookfrom, vec3 lookat, vec3 vup, float vfov,float aspect);
	camare(vec3 lookfrom, vec3 lookat, vec3 vup, float vfov, float aspect, float aperture, float focus_dist);
	camare(vec3 lookfrom, vec3 lookat, vec3 vup, float vfov, float aspect, float aperture, float focus_dist,float t0, float t1);
	~camare();
	ray get_ray(float u, float v);

	vec3 origin;
	vec3 ver;
	vec3 hor;
	vec3 corner;
	random	camareR;
	vec3 u, v, w;
	float lens_radius;
	float time0, time1;

};
#endif
