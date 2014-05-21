#ifndef SKELETON_B_HPP
#define SKELETON_B_HPP
// Alexandre Coninx
// Imperial College London, 21/05/2014

#include <NiTE.h>
#include <OpenNI.h>


class Skeleton_b
{
public:
	Skeleton_b();
	Skeleton_b(nite::Skeleton &s);
	~Skeleton_b();

private:
	nite::Skeleton sk;
};

#endif // SKELETON_B_HPP

