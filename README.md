nite2-python-bindings
=====================

Python bindings for a subset of the Primesense NiTE 2 middleware


What is implemented
-------------------

Only the minimum subset of features that allow to get skeletons are implemented.

Especially:
* No hand tracking
* No NiTE posture handling
* None of the fancy stuff of the UserTrackerFrameRef class (floor location, user map, etc.)


The missing methods are mentioned as TODO in the header files.

NiTE 2 is not the cleanest library ever, its documentation is minimal and its source code is closed, so I had to make a few assumptions about the way it behaves. Usually I tried to be as safe as possible even at performance's cost.

This is far from being production level code, but I share it in hope it is useful. Feel free to use/extend/fix/break as you want.


Build
-----
Just make should be enough if your NITE2 / OpenNI2 environment variable are set

You will need Boost.Python and of course Python 2.7.x


Use
---

The classes and method follow the C++ API. Only the following has changed:
* UserTrackerFrameRef.getUsers returns a list of user IDs instead of an array of UserData objects. You have to get the UserData objects manually with UserTrackerFrameRef.getUserById
* Everything that returns a nite::Status instead returns a boolean (True if STATUS_OK, False otherwise)
* SkeletonJoint.getOrientation() and SkeletonJoint.getPosition() return lists of floats with the coordinates instead of Quaternion/Point3D objects. The order is (w, x, y, z) for orientations and (x, y, z) for positions
