// Alexandre Coninx
// Imperial College London, 20/05/2014

#include "nite_b.hpp"
#include "skeletonjoint_b.hpp"
#include "usertrackerframeref_b.hpp"
#include "userdata_b.hpp"
#include "usertracker_b.hpp"
#include "skeleton_b.hpp"
#include <boost/python.hpp>

#include <NiTE.h>


using namespace boost::python;



BOOST_PYTHON_MODULE(nite2)
{
	// Nite enums
	enum_<nite::SkeletonState>("SkeletonState")
		.value("SKELETON_NONE", nite::SKELETON_NONE)
		.value("SKELETON_CALIBRATING", nite::SKELETON_CALIBRATING)
		.value("SKELETON_TRACKED", nite::SKELETON_TRACKED)
		.value("SKELETON_CALIBRATION_ERROR_NOT_IN_POSE", nite::SKELETON_CALIBRATION_ERROR_NOT_IN_POSE)
		.value("SKELETON_CALIBRATION_ERROR_HANDS", nite::SKELETON_CALIBRATION_ERROR_HANDS)
		.value("SKELETON_CALIBRATION_ERROR_HEAD", nite::SKELETON_CALIBRATION_ERROR_HEAD)
		.value("SKELETON_CALIBRATION_ERROR_LEGS", nite::SKELETON_CALIBRATION_ERROR_LEGS)
		.value("SKELETON_CALIBRATION_ERROR_TORSO", nite::SKELETON_CALIBRATION_ERROR_TORSO)
	;

	enum_<nite::JointType>("JointType")
		.value("JOINT_HEAD", nite::JOINT_HEAD)
		.value("JOINT_NECK", nite::JOINT_NECK)
		.value("JOINT_LEFT_SHOULDER", nite::JOINT_LEFT_SHOULDER)
		.value("JOINT_RIGHT_SHOULDER", nite::JOINT_RIGHT_SHOULDER)
		.value("JOINT_LEFT_ELBOW", nite::JOINT_LEFT_ELBOW)
		.value("JOINT_RIGHT_ELBOW", nite::JOINT_RIGHT_ELBOW)
		.value("JOINT_LEFT_HAND", nite::JOINT_LEFT_HAND)
		.value("JOINT_RIGHT_HAND", nite::JOINT_RIGHT_HAND)
		.value("JOINT_TORSO", nite::JOINT_TORSO)
		.value("JOINT_LEFT_HIP", nite::JOINT_LEFT_HIP)
		.value("JOINT_RIGHT_HIP", nite::JOINT_RIGHT_HIP)
		.value("JOINT_LEFT_KNEE", nite::JOINT_LEFT_KNEE)
		.value("JOINT_RIGHT_KNEE", nite::JOINT_RIGHT_KNEE)
		.value("JOINT_LEFT_FOOT", nite::JOINT_LEFT_FOOT)
		.value("JOINT_RIGHT_FOOT", nite::JOINT_RIGHT_FOOT)
	;

	// Completely static stuff
	class_<NiTE_b>("NiTE")
		.def("initialize", &NiTE_b::initialize)
		.def("shutdown", &NiTE_b::shutdown)
		.staticmethod("initialize")
		.staticmethod("shutdown")
        ;

	class_<SkeletonJoint_b>("SkeletonJoint") // No need to expose the non-default constructor
	;

	class_<Skeleton_b>("Skeleton") // No need to expose the non-default constructor
		.def("getJoint", &Skeleton_b::getJoint, return_value_policy<manage_new_object>() )
		.def("getState", &Skeleton_b::getState)
        ;


	class_<UserTrackerFrameRef_b>("UserTrackerFrameRef") // No need to expose the non-default constructor
		.def("getFrameIndex", &UserTrackerFrameRef_b::getFrameIndex)
		.def("getTimestamp",  &UserTrackerFrameRef_b::getTimestamp)
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




