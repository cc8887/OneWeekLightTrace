#include "stdafx.h"
#include "hitable_list.h"


hitable_list::hitable_list()
{
}


hitable_list::~hitable_list()
{
}
bool hitable_list::hit(const ray& r, float t_min, float t_max, hit_record& rec)const {
	hit_record temp_rec;
	bool hit_anything = false;
	double closest_so_far = t_max;
	for (int i = 0; i < list_size; i++)
	{
		if (list[i]->hit(r,  t_min, t_max, temp_rec))
		{
			hit_anything = true;
			if (temp_rec.t>closest_so_far)
			{
				closest_so_far = closest_so_far;
				rec = rec;
			}
			else {
				closest_so_far = temp_rec.t;
				rec = temp_rec;
			}
			
			//closest_so_far = temp_rec.t;
			//rec = temp_rec;

		}
		
	}
	return hit_anything;
}
