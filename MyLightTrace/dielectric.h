#pragma once
#include "material.h"
class dielectric :
	public material
{
public:
	dielectric(float ri): ref_index(ri) {};
	~dielectric();

	virtual bool scatter(const ray& in, const hit_record& rec, vec3& att, ray& scattered)const {
		vec3 outward_normal;
		vec3 reflected =  reflect(in.direction(), rec.normal);
		float ni_over_nt;
		att = vec3(1.0, 1.0, 1.0);
		vec3 refracted;
		float reflect_prob;
		float cosine;
		if (dot(in.direction(), rec.normal) > 0) {
			outward_normal = -rec.normal;
			ni_over_nt = ref_index;
			cosine = ref_index * dot(in.direction(), rec.normal)/in.direction().length();

		}
		else
		{
			outward_normal = rec.normal;
			ni_over_nt = 1.0/ref_index;
			cosine = -dot(in.direction(), rec.normal) / in.direction().length();
		}
		if (refract(in.direction(),outward_normal,ni_over_nt,refracted))
		{
			reflect_prob = schlick(cosine, ref_index);
			//scattered = ray(rec.p, refracted);
		}
		else
		{
			//scattered = ray(rec.p, reflected);
			reflect_prob = 1.0;
		}
		random tampR;
		if (tampR.drand() < reflect_prob) {
			scattered = ray(rec.p, reflected);
		}
		else {
			scattered = ray(rec.p, refracted);
		}
		return true;
		

	}

	float ref_index;
};

