#include "stdafx.h"
#include "sphere.h"

bool sphere::hit(const ray& r, float t_min, float t_max, hit_record& rec)const
{
	rec.mat = mat;
	vec3 oc = r.origin() - center;
	float a = dot(r.direction(), r.direction());
	float b = dot(oc, r.direction());
	float c = dot(oc, oc) - raduis * raduis;
	//float res = b * b - 4.0 * a*c;
	float res = b * b -a*c;
	//��������н⣬Ҳ�����ཻ
	if (res >= 0)
	{
		//������ֻȡ���е�һ���������������㷨�ǲ��������⣺û���жϵ���ʽ�ĸ����뷢��������
		float tamp = (-b - sqrt(b*b - a * c)) / a;
		if (tamp <t_max&&tamp>t_min) {
			rec.t = tamp;
			rec.p = r.point_at_parameter(rec.t);
			rec.normal = (rec.p - center) / raduis;
			return true;
		}
		tamp = (-b + sqrt(b*b - a * c)) / a;
		if (tamp <t_max&&tamp>t_min) {
			rec.t = tamp;
			rec.p = r.point_at_parameter(rec.t);
			//��������һ��
			rec.normal = (rec.p - center) / raduis;
			return true;
		}
	}
	return false;

}

sphere::sphere()
{
}


sphere::~sphere()
{
}
