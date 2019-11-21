#pragma once
#include "material.h"
class lambertian :
	public material
{
public:
	lambertian(const vec3& v) :albedo(v) {}
	~lambertian();
	virtual bool scatter(const ray& in, const hit_record& rec, vec3& att, ray& scattered)const {
		random tampR;
		vec3 target = rec.normal + tampR.sphere();
		float t = in.time();
		scattered = ray(rec.p, target, t);
		att = albedo;
		return true;
	}


	//这个用来记录当前材料对rgb三种颜色的衰减系数
	vec3 albedo;
};

