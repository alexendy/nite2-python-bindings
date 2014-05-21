// Alexandre Coninx
// Imperial College London, 21/05/2014

#include "userdata_b.hpp"

UserData_b::UserData_b()
{
	own_user_data = true;
	ud = new nite::UserData;
}


UserData_b::UserData_b(nite::UserData * data)
{
	own_user_data = false; // This is in fact part of the frame, we are merely encapsulating it
	ud = data;
}

UserData_b::~UserData_b()
{
	if(own_user_data)
		delete ud; // Only destroy data we own, avoid double free
}


Skeleton_b * UserData_b::getSkeleton()
{
	Skeleton_b * sk_b = new Skeleton_b();
	return sk_b;
}

