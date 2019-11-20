#include "stdafx.h"
#include "float.h"


//void build_1_1();
//void build_1_2(std::string name);
//void build_2_1(std::string name);
//void build_2_3(std::string name);
//void build_2_4(std:: string name);
void build_2_5(std::string name);
vec3 color(const ray&r);
vec3 color(const ray&r, hitable *world);
vec3 color(const ray&r, hitable *world, int depth);
bool hit_sphere(const vec3& center, float raduis, const ray& r);
float hit_point(const vec3& center, float raduis, const ray& r);