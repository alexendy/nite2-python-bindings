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

py::list SkeletonJoint_b::getOrientation()
{
	py::list l;
	l.append(joint->getOrientation().w);
	l.append(joint->getOrientation().x);
	l.append(joint->getOrientation().y);
	l.append(joint->getOrientation().z);
	return l;
}

py::list SkeletonJoint_b::getPosition()
{
	py::list l;
	l.append(joint->getPosition().x);
	l.append(joint->getPosition().y);
	l.append(joint->getPosition().z);
	return l;
}

SkeletonJoint_b::~SkeletonJoint_b()
{
	delete joint;
}


