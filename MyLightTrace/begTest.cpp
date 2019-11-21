#include "stdafx.h"
#include "begTest.h"


#define stds std::
#define ELENUM 4
//void build_1_1()
//{
//	const stds string s1[3] = { "255 0 0","0 255 0","0 0 255" };
//	const stds string s2[3] = { "255 255 0","255 255 255","0 0 0" };
//	stds ofstream file("graph1-1.ppm");
//	if (file.is_open())
//	{
//		file << "P3\n" << 60 << " " << 40 << "\n255\n";
//		for (int i = 0; i < 20; ++i)
//			for (int j = 0; j < 60; ++j)
//				file << s1[j / 20] << stds endl;
//
//		for (int i = 0; i < 20; ++i)
//			for (int j = 0; j < 60; ++j)
//				file << s2[j / 20] << stds endl;
//		file.close();
//		stds cout << "completed" << stds endl;
//	}
//	else stds cerr << "error" << stds endl;
//}
//void build_1_2(stds string name) {
//	int nx = 200;
//	int ny = 100;
//	stds ofstream file(name);
//	file << "P3\n"<<nx <<" "<<ny<<"\n 255 \n";
//	for (int i = 0; i < ny; i++)
//	{
//		for (int j = 0; j < nx; j++)
//		{
//			float r = float(i) / float(ny);
//			float g = float(j) / float(nx);
//			float b = 0.8;
//			int ir = int(255.99*r);
//			int ig = int(255.99*g);
//			int ib = int(255.99*b);
//			file << ir << " " << ig << " " << ib << "\n";
//		}
//	}
//	file.close();
//
//}
//void build_1_3(stds string name) {
//	int nx = 200;
//	int ny = 100;
//	stds ofstream file(name);
//	file << "P3\n" << nx << " " << ny << "\n 255 \n";
//	for (int i = 0; i < ny; i++)
//	{
//		for (int j = 0; j < nx; j++)
//		{
//			vec3 ele(float(i) / float(nx), float(j) / float(ny), 0.1);
//			int ir = int(255.99*ele[0]);
//			int ig = int(255.99*ele[1]);
//			int ib = int(255.99*ele[2]);
//			file << ir << " " << ig << " " << ib << "\n";
//		}
//	}
//	file.close();
//}
//void build_2_1(stds string name) {
//	int nx = 200;
//	int ny = 100;
//	stds ofstream file(name);
//	file << "P3\n" << nx << " " << ny << "\n 255 \n";
//	vec3 low_left_corner(-2.0, -1.0, -1.0);
//	vec3 hor(4.0, 0.0, 0.0);
//	vec3 ver(0, 2.0, 0.0);
//	vec3 origin(0.0, 0.0, 0.0);
//
//	for (int i = ny-1; i >= 0; i--)
//	{
//		for (int j = 0; j < nx; j++)
//		{
//			float u = float(i) / float(ny);
//			float v = float(j) / float(nx);
//			vec3 tamp = v * hor + u * ver + low_left_corner;
//			ray r(origin, tamp);
//			vec3 ele = color(r);
//			int ir = int(255.99*ele[0]);
//			int ig = int(255.99*ele[1]);
//			int ib = int(255.99*ele[2]);
//			file << ir << " " << ig << " " << ib << "\n";
//		}
//	}
//	file.close();
//
//}
//void build_2_3(stds string name) {
//	int nx = 200;
//	int ny = 100;
//	stds ofstream file(name);
//	file << "P3\n" << nx << " " << ny << "\n 255 \n";
//	vec3 low_left_corner(-2.0, -1.0, -1.0);
//	vec3 hor(4.0, 0.0, 0.0);
//	vec3 ver(0, 2.0, 0.0);
//	vec3 origin(0.0, 0.0, 0.0);
//
//	hitable *list[2];
//	list[1] =new sphere(vec3(0, 0, -1), 0.5);
//	list[0] = new sphere(vec3(0, -100.5, -1), 100);
//	hitable_list *world = new hitable_list(list, 2);
//	for (int i = ny - 1; i >= 0; i--)
//	{
//		for (int j = 0; j < nx; j++)
//		{
//			float u = float(i) / float(ny);
//			float v = float(j) / float(nx);
//			vec3 tamp = v * hor + u * ver + low_left_corner;
//			ray r(origin, tamp);
//			vec3 ele = color(r,world);
//			int ir = int(255.99*ele[0]);
//			int ig = int(255.99*ele[1]);
//			int ib = int(255.99*ele[2]);
//			file << ir << " " << ig << " " << ib << "\n";
//		}
//	}
//	file.close();
//
//}
//void build_2_4(stds string name) {
//	int nx = 200;
//	int ny = 100;
//	int ns = 10;
//	stds ofstream file(name);
//	file << "P3\n" << nx << " " << ny << "\n 255 \n";
//	random rand;
//	camare cam;
//	hitable *list[2];
//	list[0] = new sphere(vec3(0, 0, -1), 0.5);
//	list[1] = new sphere(vec3(0, -100.5, -1), 100);
//	hitable_list *world = new hitable_list(list, 2);
//	for (int i = ny - 1; i >= 0; i--)
//	{
//		stds cout << float(ny - 1 - i) / float(ny)<<stds endl;
//		for (int j = 0; j < nx; j++)
//		{
//			vec3 ele(0, 0, 0);
//			for (int k = 0; k < ns; k++)
//			{
//				float v = float(i + rand.get()) / float(ny);
//				float u = float(j + rand.get()) / float(nx);
//				ele += color(cam.get_ray(u, v), world);
//			}
//			ele /= float(ns);
//			ele = vec3(sqrt(ele.x()), sqrt(ele.y()), sqrt(ele.z()));
//			int ir = int(255.99*ele[0]);
//			int ig = int(255.99*ele[1]);
//			int ib = int(255.99*ele[2]);
//
//			
//			file << ir << " " << ig << " " << ib << "\n";
//		}
//	}
//	file.close();
//
//}
void build_2_5(stds string name) {
	int nx = 200;
	int ny = 100;
	int ns = 100;
	stds ofstream file(name);
	file << "P3\n" << nx << " " << ny << "\n 255 \n";
	random rand;
	//camare cam(135,float(nx)/float(ny));
	float apeture = 10;
	vec3 lookfrom(3, 3, 2);
	vec3 lookto(0, 0, -1);
	float dis = (lookfrom - lookto).length();
	camare cam(lookfrom, lookto, vec3(0, 1, 0), 20,float(nx) / float(ny),apeture,dis);
	
	hitable *list[ELENUM];
	list[0] = new sphere(vec3(0, 0, -1), 0.5,new lambertian(vec3(0.8,0.3,0.3)));
	list[1] = new sphere(vec3(0, -100.5, -1), 100, new lambertian(vec3(0.8, 0.8, 0.0)));
	list[2] = new sphere(vec3(1, 0, -1), 0.5, new metal(vec3(0.3, 0.1, 0.3)));
	list[3] = new sphere(vec3(-1, 0, -1), 0.5, new dielectric(0.1));
	hitable_list *world = new hitable_list(list, ELENUM);
	for (int i = ny - 1; i >= 0; i--)
	{
		system("cls");
		stds cout <<"渲染进度\t"<< float(ny - 1 - i) / float(ny)*100<<"\t%" << stds endl;
		for (int j = 0; j < nx; j++)
		{
			vec3 ele(0, 0, 0);
			for (int k = 0; k < ns; k++)
			{
				float v = float(i + rand.drand()) / float(ny);
				float u = float(j + rand.drand()) / float(nx);
				ele += color(cam.get_ray(u, v), world,0);
			}
			ele /= float(ns);
			ele = vec3(sqrt(ele.x()), sqrt(ele.y()), sqrt(ele.z()));
			int ir = int(255.99*ele[0]);
			int ig = int(255.99*ele[1]);
			int ib = int(255.99*ele[2]);


			file << ir << " " << ig << " " << ib << "\n";
		}
	}
	file.close();
	stds cout << "渲染完成" << stds endl;

}


void build_2_6(stds string name) {

}

vec3 color(const ray&r) {
	//if (hit_sphere(vec3(0, 0, -2), 0.5, r))
	//{
	//	return vec3(1, 0, 0);
	//}
	float t = hit_point(vec3(0, 0, -1.0), 0.5, r);
	if (t>0.0)
	{
		vec3 n = unit_vector(r.point_at_parameter(t) - vec3(0, 0, -1.0));
		//return 0.5*vec3(n.x() + 1.0, n.y()+1.0, n.z() + 1.0);
		//return vec3(abs(n.x()), abs(n.y()), abs(n.z()));
		return 0.5*vec3(abs(n.x())+1.0, abs(n.y())+1.0, abs(n.z())+1.0);
	}
	vec3 unit_direction = unit_vector(r.direction());
	t = 0.5*(unit_direction.y() + 1.0);
	return (1.0 - t)*vec3(1.0, 1.0, 1.0) + t* vec3(0, 0, 0);
}
vec3 color(const ray&r, hitable *world) {
	hit_record rec;
	if (world->hit(r,0.01, 100000000.0 ,rec))
	{
		random tampR;
		//rec.normal =  (rec.normal + tampR.sphere());
		//rec.normal.make_unit_vector();
		//return 0.5*vec3(rec.normal.x() + 1, rec.normal.y() + 1, rec.normal.z() + 1);
		vec3 target = rec.normal + tampR.sphere();
		return 0.5*color(ray(rec.p, target,r.time()), world);
	}
	else
	{
		vec3 unit_direction = unit_vector(r.direction());
		float t = 0.5*(unit_direction.y() + 1.0);
		return (1.0 - t)*vec3(1.0, 1.0, 1.0) + t * vec3(0.5, 0.3, 0.7);
	}
}

//这里通过depth对反射次数做限制
vec3 color(const ray& r, hitable *world, int depth) {
	hit_record rec;
	if (world->hit(r, 0.1, 1000000.0, rec))
	{
		ray scattered;
		vec3 att;
		if (depth < 5 && rec.mat->scatter(r, rec, att, scattered)) {
			return att * color(scattered, world, depth + 1);
		}
		else {
			return vec3(0.01, 0.01, 0.01);
		}
	}
	else
	{
		vec3 unit_direction = unit_vector(r.direction());
		float t = 0.5*(unit_direction.y() + 1.0);
		return (1.0 - t)*vec3(1.0, 1.0, 1.0) + t * vec3(0.5, 0.3, 0.7);
	}

}


bool hit_sphere(const vec3& center, float raduis, const ray& r) {
	vec3 oc = r.origin() - center;
	float a = dot(r.direction(), r.direction());
	float b = 2.0*dot(oc, r.direction());
	float c = dot(oc, oc) - raduis * raduis;
	float res = b * b - 4*a*c;
	//大于零就有解，也就是相交
	return res > 0;
}

float hit_point(const vec3& center, float raduis, const ray& r) {
	vec3 oc = r.origin() - center;
	float a = dot(r.direction(), r.direction());
	float b = 2.0*dot(oc, r.direction());
	float c = dot(oc, oc) - raduis * raduis;
	float res = b * b - 4.0 * a*c;
	//大于零就有解，也就是相交
	if (res>=0)
	{
		return (-b - sqrt(res)) / (2.0*a);
	}
	else
	{
		return -1.0;
	}
}

