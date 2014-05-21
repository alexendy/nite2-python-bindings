// Alexandre Coninx
// Imperial College London, 20/05/2014

#include "nite_b.hpp"
#include "usertrackerframeref_b.hpp"
#include "userdata_b.hpp"
#include "usertracker_b.hpp"
#include "skeleton_b.hpp"
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

	class_<Skeleton_b>("Skeleton") // No need to expose the non-default constructor
        ;

	class_<UserTrackerFrameRef_b>("UserTrackerFrameRef") // No need to expose the non-default constructor
		.def("getFrameIndex", &UserTrackerFrameRef_b::getFrameIndex)
		.def("getTimestamp",  &UserTrackerFrameRef_b::getTimestamp)
//		.def("getUserById", &UserTrackerFrameRef_b::getUserById)
//		.def("getUserById", &UserTrackerFrameRef_b::getUserById, return_value_policy<reference_existing_object>() )
		.def("getUserById", &UserTrackerFrameRef_b::getUserById, return_value_policy<manage_new_object>() )
		.def("getUsers", &UserTrackerFrameRef_b::getUsers)
		.def("isValid", &UserTrackerFrameRef_b::isValid)
		.def("release", &UserTrackerFrameRef_b::release)

        ;



	class_<UserData_b>("UserData") // No need to expose the non-default constructor
		.def("getId",&UserData_b::getId)
		.def("getSkeleton",&UserData_b::getSkeleton, return_value_policy<manage_new_object>())
		.def("isLost",&UserData_b::isLost)
		.def("isNew",&UserData_b::isNew)
		.def("isVisible",&UserData_b::isVisible)
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




