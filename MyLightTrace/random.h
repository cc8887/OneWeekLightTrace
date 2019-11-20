#ifndef RANDOMH
#define RANDOMH
#define MAX 1000


#include "time.h"


static unsigned long long seed = 1;




class random
{
public:
	random() { srand(time(NULL)); };
	~random();

	float get() { srand(time(NULL)); return float(rand() % MAX) / float(MAX); }
	double drand()
	{
		seed = (0x5DEECE66DLL * seed + 0xB16) & 0xFFFFFFFFFFFFLL;
		unsigned int x = seed >> 16;
		return  ((double)x / (double)0x100000000LL);

	}

	void srand(unsigned int i)
	{
		seed = (((long long int)i) << 16) | rand();
	}
	vec3 sphere() {
		vec3 p;
		//这里分别采用了自己写的random算法和仿照unix下drand48写的random函数，事实证明原先的系统函数要高效很多！！！
		//p = 2*vec3(get(), get(), get())-vec3(1,1,1);
		//p.make_unit_vector();
		do
		{
			//这里为什么用两倍的这个向量？
			p = 2.0*vec3(drand(), drand(), drand()) - vec3(1, 1, 1);
		} while (p.squared_length()>=1);
		return p;
	}
};





#endif // !RANDOMH



