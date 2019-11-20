#pragma once
#ifndef HIT_RECORDH
#define HIT_RECORDH

class material
{
public:
	material();
	~material();
	virtual bool scatter(const ray& in, const hit_record& rec, vec3& att, ray& scattered)const = 0;
};

inline vec3 reflect(const vec3& v, const vec3& n) {
	return v - 2 * dot(v, n)*n;
}
inline bool refract(const vec3& v, const vec3& n, float ni_over_nt, vec3& refracted) {
	vec3 uv = unit_vector(v);
	float dt = dot(uv, n);


	float dis = 1.0 - ni_over_nt * ni_over_nt*(1 - dt * dt);
	if (dis > 0) {
	//这里用了勾股定理加折射定理：

   /* uv*uv-n*n,uv=1
	------
	\	 |
	 \   |
uv    \  | n
	   \ |
		\|
	——————————
		 |\
		 | \
		 |  \
		 |   \
		 |    \
		 -------
		(uv * uv - n * n)*ni_over_nt*ni_over_nt*/

		refracted = ni_over_nt * (uv - n * dt) - n * sqrt(dis);
		return true;
	}
	else
	{
		return false;
	}
}
inline float schlick(float cosine, float ref_index) {
	float r0 = (1 - ref_index) / (1 + ref_index);
	r0 = r0 * r0;
	return r0 + (1 - r0)*pow((1 - cosine), 5);
}
#endif // !HIT_RECORDH
