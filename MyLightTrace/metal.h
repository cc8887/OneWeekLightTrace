#pragma once
#include "material.h"


class metal :
	public material
{
public:
	metal(const vec3& v) :albedo(v) { fuzz = 0.4; };
	~metal();

	virtual bool scatter(const ray& in, const hit_record& rec, vec3& att, ray& scattered)const {
		random tampR;
		//vec3 target = rec.normal + tampR.sphere();
		vec3 target = reflect(unit_vector(in.direction()), rec.normal);
		scattered = ray(rec.p, target+fuzz*tampR.sphere());
		att = albedo;
		return (dot(scattered.direction(),rec.normal))>0;
	}
	//���������¼��ǰ���϶�rgb������ɫ��˥��ϵ��
	vec3 albedo;
	float fuzz;

};



