// Alexandre Coninx
// Imperial College London, 21/05/2014

#include "skeleton_b.hpp"



Skeleton_b::Skeleton_b()
{
	sk = new nite::Skeleton;
}

Skeleton_b::Skeleton_b(const nite::Skeleton & s)
{
	sk = new nite::Skeleton(s); //Inefficient but better than trying to second guess NiTE's reference handling
}

SkeletonJoint_b * Skeleton_b::getJoint(nite::JointType joint)
{
	SkeletonJoint_b * skj_b = new SkeletonJoint_b(sk->getJoint(joint));
	return skj_b;
}


Skeleton_b::~Skeleton_b()
{
	delete sk;
}


