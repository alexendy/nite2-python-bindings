#ifndef USERDATA_B_HPP
#define USERDATA_B_HPP
// Alexandre Coninx
// Imperial College London, 21/05/2014

#include <NiTE.h>
#include <OpenNI.h>


class UserData_b
{
public:
	UserData_b();
	UserData_b(nite::UserData * data);
	~UserData_b();


private:
	nite::UserData * ud;
};

#endif // USERDATA_B_HPP

