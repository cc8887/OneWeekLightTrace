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
	//大于零就有解，也就是相交
	if (res >= 0)
	{
		//两个解只取其中的一个（但是这样的算法是不是有问题：没法判断到底式哪个解离发光点更近）
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
			//法向量归一化
			rec.normal = (rec.p - cur_center) / radius;
			return true;
		}
	}
	return false;
}

