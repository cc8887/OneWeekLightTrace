#ifndef HITABLE_LISTH
#define HITABLE_LISTH
#include "hitable.h"
class hitable_list :
	public hitable
{
public:
	hitable_list();
	hitable_list(hitable **l, int n) { list = l; list_size = n; }
	bool hit(const ray& r, float t_min, float t_max, hit_record& rec)const;
	~hitable_list();

	hitable **list;
	int list_size;
};
#endif // !HITABLE_LISTH