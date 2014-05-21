// Alexandre Coninx
// Imperial College London, 21/05/2014

#include "skeletonjoint_b.hpp"



SkeletonJoint_b::SkeletonJoint_b()
{
	joint = new nite::SkeletonJoint;
}

SkeletonJoint_b::SkeletonJoint_b(const nite::SkeletonJoint & sj)
{
	joint = new nite::SkeletonJoint(sj); //Inefficient but better than trying to second guess NiTE's reference handling
}


SkeletonJoint_b::~SkeletonJoint_b()
{
	delete joint;
}


