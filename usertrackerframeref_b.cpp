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
