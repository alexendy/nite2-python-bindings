// Alexandre Coninx
// Imperial College London, 21/05/2014

#include "usertrackerframeref_b.hpp"



UserTrackerFrameRef_b::UserTrackerFrameRef_b()
{
	utfr = new nite::UserTrackerFrameRef;
}

UserTrackerFrameRef_b::UserTrackerFrameRef_b(nite::UserTrackerFrameRef * frame)
{
	utfr = frame;
}

UserTrackerFrameRef_b::~UserTrackerFrameRef_b()
{
	delete utfr;
}


UserData_b * UserTrackerFrameRef_b::getUserById(int id)
{
	nite::UserData * ud;
	ud = const_cast<nite::UserData *> (utfr->getUserById(id));
	UserData_b * ud_b;
	ud_b = new UserData_b(ud);
	return ud_b;
}

py::list UserTrackerFrameRef_b::getUsers()
{
	py::list l;
	// TODO: Fill l
	return l;
}


