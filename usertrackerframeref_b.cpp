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
	const nite::Array<nite::UserData>& nite_users = utfr->getUsers();
	for (int i = 0; i < nite_users.getSize(); i++)
	{
		// The UserData in the nite::Array may well get destroyed out of this contect, so it is more sure (although slower) to rebuild the list using getUserById

		// I planned to return a list of UserData_b * but I don't manage to handle memory management issues correctly. So return user IDs instead.
//		UserData_b * udb = getUserById(nite_users[i].getId());
//		l.append(udb);
		l.append(nite_users[i].getId());
	}
	return l;
}


