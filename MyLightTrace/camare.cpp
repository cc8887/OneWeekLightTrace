#include "stdafx.h"
#include "camare.h"
#define M_PI 3.14

camare::camare()
{
	//float theta = vfow * M_PI / 180;

	corner = vec3(-2.0, -1.0, -1.0);
	hor = vec3(4.0, 0.0, 0.0);
	ver = vec3(0, 2.0, 0.0);
	origin = vec3(0.0, 0.0, 0.0);
}


//vfov ��ʾ�����ӽǣ�������׶���ǵĴ�С
camare::camare(float vfov, float aspect) {
	float theta = vfov * M_PI / 180.0;
	float half_height = tan(theta / 2);
	float half_width = aspect * half_height;
	corner = vec3(-half_width, -half_height, -1.0);
	hor = vec3(2.0*half_width, 0.0, 0.0);
	ver = vec3(0, 2.0*half_height, 0.0);
	origin = vec3(0.0, 0.0, 0.0);


}
camare::camare(vec3 lookfrom, vec3 lookat, vec3 vup, float vfov,float aspect) {
	float theta = vfov * M_PI / 180.0;
	float half_height = tan(theta / 2);
	float half_width = aspect * half_height;

	origin = lookfrom;
	w = unit_vector(lookfrom - lookat);
	u = unit_vector(cross(vup, w));
	v = unit_vector(cross(w, u));
	corner = origin - half_width * u - half_height * v - w;
	hor = 2.0*half_width*u;
	ver = 2.0*half_height*v;

}

camare::camare(vec3 lookfrom, vec3 lookat, vec3 vup, float vfov, float aspect,float aperture,float focus_dist) {
	
	lens_radius = aperture / 2;
	float theta = vfov * M_PI / 180.0;
	//������ʵĬ�Ϲ۲�㵽����ƽ��ľ�����1������Ȼ���ǣ��������ﴫ���˾���focus_dist�����Ժ����ڼ���ʱҪ����
	float half_height = tan(theta / 2);
	float half_width = aspect * half_height;

	origin = lookfrom;
	w = unit_vector(lookfrom - lookat);
	u = unit_vector(cross(vup, w));
	v = unit_vector(cross(w, u));
	corner = origin - half_width*focus_dist * u - half_height*focus_dist * v - focus_dist*w;
	hor = 2.0*half_width*u*focus_dist;
	ver = 2.0*half_height*v*focus_dist;

	//����֮������Ҫ����focus_dist����Ϊ ʵ���������ڼ���half_height��ʱ��Ӧ���ǣ�tan(theta / 2)=half_height/focus_dist
	//��˼���ǣ����ǹ۲���ӽǹ��Ϊvfov���۲�һ����۲��focus_dist��ôԶ��һ��ƽ�棬���ƽ��Ĵ�С��ͨ�����������Ĺ�ʽ����
	//������ԭ��

}

camare::~camare()
{
}

ray camare::get_ray(float s, float t) {
	vec3 rd = lens_radius* camareR.sphere();
	vec3 offset = rd.x()*u + rd.y()*v;
	float time = time0 + camareR.drand()*(time1 - time0);
	return ray(origin+offset, corner + s * hor + t * ver - origin-offset,time); 
}	