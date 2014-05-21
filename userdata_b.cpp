// Alexandre Coninx
// Imperial College London, 21/05/2014

#include "userdata_b.hpp"

UserData_b::UserData_b()
{
	ud = new nite::UserData;
}


UserData_b::UserData_b(nite::UserData * data)
{
	ud = data;
}

UserData_b::~UserData_b()
{
	delete ud;
}


Skeleton_b * UserData_b::getSkeleton()
{
	nite::Skeleton s = ud->getSkeleton();
	Skeleton_b * sk_b = new Skeleton_b(s);
	return sk_b;
}

