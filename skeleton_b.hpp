#ifndef SKELETON_B_HPP
#define SKELETON_B_HPP
// Alexandre Coninx
// Imperial College London, 21/05/2014

#include <NiTE.h>
#include <OpenNI.h>

#include "skeletonjoint_b.hpp"

class Skeleton_b
{
public:
	Skeleton_b();
	Skeleton_b(const nite::Skeleton & s);
	~Skeleton_b();
	SkeletonJoint_b * getJoint(nite::JointType joint);
	nite::SkeletonState getState() {return sk->getState(); };

private:
	nite::Skeleton * sk;
};

#endif // SKELETON_B_HPP

