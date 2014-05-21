#ifndef USERTRACKER_B_HPP
#define USERTRACKER_B_HPP
// Alexandre Coninx
// Imperial College London, 20/05/2014


#include <NiTE.h>
#include <OpenNI.h>

#include "usertrackerframeref_b.hpp"

class UserTracker_b
{
public:
	UserTracker_b();
	~UserTracker_b();
	bool create();
	void destroy();
	float getSkeletonSmoothingFactor() { return ut->getSkeletonSmoothingFactor(); };
	bool isValid() { return ut->isValid(); };
	UserTrackerFrameRef_b * readFrame(); // Break original C++ syntax for simplicity and pythonicity's sake
	bool setSkeletonSmoothingFactor(float factor);
	bool startSkeletonTracking(int id);
	void stopSkeletonTracking(int id);

	//TODO: Not implemented
	//void addNewFrameListener(...);
	//bool convertDepthCoordinatesToJoint(...);
	//bool convertJointCoordinatesToDepth(...);
	//void removeNewFrameListener(...);
	//bool startPoseDetection (...);
	//void stopPoseDetection(...);


private:
	nite::UserTracker* ut;
};



#endif // USERTRACKER_B_HPP

