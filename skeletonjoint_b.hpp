#ifndef SKELETONJOINT_B_HPP
#define SKELETONJOINT_B_HPP
// Alexandre Coninx
// Imperial College London, 21/05/2014

#include <NiTE.h>
#include <OpenNI.h>
#include <boost/python.hpp>


namespace py = boost::python;


class SkeletonJoint_b
{
public:
	SkeletonJoint_b();
	SkeletonJoint_b(const nite::SkeletonJoint & sj);
	py::list getOrientation();
	py::list getPosition();
	float getOrientationConfidence() {return joint->getOrientationConfidence(); };
	float getPositionConfidence() {return joint->getPositionConfidence(); };
	nite::JointType getType() {return joint->getType(); };

	~SkeletonJoint_b();
private:
	nite::SkeletonJoint * joint;

};


#endif // SKELETONJOINT_B_HPP

