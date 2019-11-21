#include "stdafx.h"
#include "moving_sphere.h"


moving_sphere::moving_sphere()
{
}


moving_sphere::~moving_sphere()
{
}

bool moving_sphere::hit(const ray& r, float tmin, float tmax, hit_record& rec)const {
	rec.mat = material;
	vec3 cur_center = center(r.time());
	vec3 oc = r.origin() -cur_center;
	float a = dot(r.direction(), r.direction());
	float b = dot(oc, r.direction());
	float c = dot(oc, oc) - radius * radius;
	//float res = b * b - 4.0 * a*c;
	float res = b * b - a * c;
	//��������н⣬Ҳ�����ཻ
	if (res >= 0)
	{
		//������ֻȡ���е�һ���������������㷨�ǲ��������⣺û���жϵ���ʽ�ĸ����뷢��������
		float tamp = (-b - sqrt(b*b - a * c)) / a;
		if (tamp <tmax&&tamp>tmin) {
			rec.t = tamp;
			rec.p = r.point_at_parameter(rec.t);
			rec.normal = (rec.p - cur_center) / radius;
			return true;
		}
		tamp = (-b + sqrt(b*b - a * c)) / a;
		if (tamp <tmax&&tamp>tmin) {
			rec.t = tamp;
			rec.p = r.point_at_parameter(rec.t);
			//��������һ��
			rec.normal = (rec.p - cur_center) / radius;
			return true;
		}
	}
	return false;
}

