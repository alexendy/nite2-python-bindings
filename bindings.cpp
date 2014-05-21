// Alexandre Coninx
// Imperial College London, 20/05/2014

#include "nite_b.hpp"
#include "usertrackerframeref_b.hpp"
#include "usertracker_b.hpp"
#include <boost/python.hpp>

using namespace boost::python;



BOOST_PYTHON_MODULE(nite2)
{
	class_<NiTE_b>("NiTE")
		.def("initialize", &NiTE_b::initialize)
		.def("shutdown", &NiTE_b::shutdown)
		.staticmethod("initialize")
		.staticmethod("shutdown")
        ;

	class_<UserTrackerFrameRef_b>("UserTrackerFrameRef") // No need to expose the non-default constructor
        ;

	class_<UserTracker_b>("UserTracker")
		.def("create", &UserTracker_b::create)
		.def("destroy", &UserTracker_b::destroy)
		.def("getSkeletonSmoothingFactor", &UserTracker_b::getSkeletonSmoothingFactor)
		.def("isValid", &UserTracker_b::isValid)
		.def("readFrame", &UserTracker_b::readFrame, return_value_policy<manage_new_object>() ) // Handle the pointer returned by readFrame
		.def("setSkeletonSmoothingFactor", &UserTracker_b::setSkeletonSmoothingFactor)
		.def("startSkeletonTracking", &UserTracker_b::startSkeletonTracking)
		.def("stopSkeletonTracking", &UserTracker_b::stopSkeletonTracking)
        ;

}




