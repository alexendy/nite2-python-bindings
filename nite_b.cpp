// Alexandre Coninx
// Imperial College London, 20/05/2014

#include "nite_b.hpp"
#include <iostream>


bool NiTE_b::initialize()
{
	nite::Status niteRc;
	if(initialized)
	{
		std::cerr << "System already initialized" << std::endl;
		return false;
	}

	/* OK, it is documented nowhere but it looks like NiTE2 sometimes
	  throw exceptions when failing to init -_- */
	try
	{

		niteRc = nite::NiTE::initialize();
		if(niteRc != nite::STATUS_OK)
		{
			std::cerr << "Couldn't initialize NiTE" << std::endl;
			return false;
		}
		initialized = true;
		return true;
	} catch (std::exception& e) {
		std::cout << "The freenect/OpenNI2/NiTE2 stack somehow refused to initialize and threw me an exception. Here it is : " << e.what() << std::endl;
		return false;
	}

}

	
void NiTE_b::shutdown()
{
	nite::NiTE::shutdown();
}



