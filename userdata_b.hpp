#ifndef USERDATA_B_HPP
#define USERDATA_B_HPP
// Alexandre Coninx
// Imperial College London, 21/05/2014

#include <NiTE.h>
#include <OpenNI.h>

#include "skeleton_b.hpp"

class UserData_b
{
public:
	UserData_b();
	UserData_b(nite::UserData * data);
	~UserData_b();
	int getId() {return ud->getId(); };
	Skeleton_b * getSkeleton();
	bool isLost() {return ud->isLost(); };
	bool isNew() {return ud->isNew(); };
	bool isVisible() {return ud->isVisible(); };

	// TODO:
	// getPose()
	// getBoundingBox
	// getCenterOfMass

private:
	nite::UserData * ud;
};

#endif // USERDATA_B_HPP

