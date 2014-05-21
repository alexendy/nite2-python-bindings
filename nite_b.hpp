#ifndef NITE_b_HPP
#define NITE_b_HPP
// Alexandre Coninx
// Imperial College London, 20/05/2014


#include <NiTE.h>
#include <OpenNI.h>

class NiTE_b // Implemented as normal instance method though everything is static. That's bad.
{
public:
	bool initialize();
	void shutdown();
	// TODO: not implemented
	// char * getVersion();
private:
	bool initialized = false;
};


#endif // NITE_B_HPP

