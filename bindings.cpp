// Alexandre Coninx
// Imperial College London, 20/05/2014

#include "nite_b.hpp"
#include <boost/python.hpp>

using namespace boost::python;



BOOST_PYTHON_MODULE(nite2)
{
	class_<NiTE_b>("NiTE")
		.def("initialize", &NiTE_b::initialize)
		.def("shutdown", &NiTE_b::shutdown)
        ;
}




