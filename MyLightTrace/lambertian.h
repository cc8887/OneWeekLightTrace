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
		scattered = ray(rec.p, target);
		att = albedo;
		return true;
	}
	//���������¼��ǰ���϶�rgb������ɫ��˥��ϵ��
	vec3 albedo;
};

