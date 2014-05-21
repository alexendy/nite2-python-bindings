#ifndef USERTRACKERFRAMEREF_B_HPP
#define USERTRACKERFRAMEREF_B_HPP
// Alexandre Coninx
// Imperial College London, 21/05/2014

#include <NiTE.h>
#include <OpenNI.h>


class UserTrackerFrameRef_b
{
public:
	UserTrackerFrameRef_b();
	UserTrackerFrameRef_b(nite::UserTrackerFrameRef * frame);
	~UserTrackerFrameRef_b();

private:
	nite::UserTrackerFrameRef * utfr;
};

#endif // USERTRACKERFRAMEREF_B_HPP

