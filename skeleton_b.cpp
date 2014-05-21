// Alexandre Coninx
// Imperial College London, 21/05/2014

#include "skeleton_b.hpp"



Skeleton_b::Skeleton_b()
{
	sk = new nite::Skeleton;
}


Skeleton_b::Skeleton_b(nite::Skeleton * s)
{
	sk = s;
}

Skeleton_b::~Skeleton_b()
{
	delete sk;
}



