#ifndef USERTRACKERFRAMEREF_B_HPP
#define USERTRACKERFRAMEREF_B_HPP
// Alexandre Coninx
// Imperial College London, 21/05/2014

#include <NiTE.h>
#include <OpenNI.h>
#include <boost/python.hpp>

#include "userdata_b.hpp"

namespace py = boost::python;

class UserTrackerFrameRef_b
{
public:
	UserTrackerFrameRef_b();
	UserTrackerFrameRef_b(nite::UserTrackerFrameRef * frame);
	~UserTrackerFrameRef_b();
	int getFrameIndex() {return utfr->getFrameIndex(); };
	long long int getTimestamp() {return utfr->getTimestamp(); };
	UserData_b * getUserById(int id);
	py::list getUsers();
	bool isValid() { return utfr->isValid(); };
	void release(){ utfr->release(); };

	//TODO: Not implemented
	//getDepthFrame
	//getFloor
	//getFloorConfidence
	//getUserMap
	//operator=

private:
	nite::UserTrackerFrameRef * utfr;
};

#endif // USERTRACKERFRAMEREF_B_HPP

