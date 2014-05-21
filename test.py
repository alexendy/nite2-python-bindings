#!/usr/bin/python
# -*- coding: utf-8 -*-

""" Alexandre Coninx
    Imperial College London, 21/05/2014
""" 

import numpy as np
from nite2 import *

import time

# Test code -- print head coordinates of users

NiTE.initialize()

tracker = UserTracker()
tracker.create()

while(True):
	f = tracker.readFrame()
	for uid in f.getUsers():
		user = f.getUserById(uid)
		if user.isNew():
			print("New user id %d !" % uid)
			tracker.startSkeletonTracking(uid)
		else:
			if user.isVisible():
				head = user.getSkeleton().getJoint(JointType.JOINT_HEAD)
				print("User {} : {}".format(uid, head.getPosition()))
			

tracker.destroy()
NiTE.shutdown()
