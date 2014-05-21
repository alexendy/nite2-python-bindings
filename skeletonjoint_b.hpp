#ifndef SKELETONJOINT_B_HPP
#define SKELETONJOINT_B_HPP
// Alexandre Coninx
// Imperial College London, 21/05/2014

#include <NiTE.h>
#include <OpenNI.h>

class SkeletonJoint_b
{
public:
	SkeletonJoint_b();
	SkeletonJoint_b(const nite::SkeletonJoint & sj);
	~SkeletonJoint_b();
private:
	nite::SkeletonJoint * joint;

};


#endif // SKELETONJOINT_B_HPP

