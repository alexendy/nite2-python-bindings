// Alexandre Coninx
// Imperial College London, 20/05/2014

#include "usertracker_b.hpp"

UserTracker_b::UserTracker_b()
{
	ut = new nite::UserTracker;
}


UserTracker_b::~UserTracker_b()
{
	delete ut;
}

bool UserTracker_b::create()
{
	nite::Status niteRc;
	niteRc = ut->create();
	return(niteRc == nite::STATUS_OK);
}

void UserTracker_b::destroy()
{
	ut->destroy();
}

UserTrackerFrameRef_b * UserTracker_b::readFrame()
{
	nite::Status niteRc;
	nite::UserTrackerFrameRef * utrf = new nite::UserTrackerFrameRef;
	niteRc = ut->readFrame(utrf);
	UserTrackerFrameRef_b * utrfb;
	if(niteRc == nite::STATUS_OK)
	{
		utrfb = new UserTrackerFrameRef_b(utrf);
	} else {
		utrfb = NULL;
	}
	return utrfb;
}

bool UserTracker_b::setSkeletonSmoothingFactor(float factor)
{
	nite::Status niteRc;
	niteRc = ut->setSkeletonSmoothingFactor(factor);
	return(niteRc == nite::STATUS_OK);
}

bool UserTracker_b::startSkeletonTracking(int id)
{
	nite::Status niteRc;
	niteRc = ut->startSkeletonTracking(id);
	return(niteRc == nite::STATUS_OK);
}

void UserTracker_b::stopSkeletonTracking(int id)
{
	ut->stopSkeletonTracking(id);
}
