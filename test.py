#!/usr/bin/python
# -*- coding: utf-8 -*-

""" Alexandre Coninx
    Imperial College London, 21/05/2014
""" 

import numpy as np
from nite2 import *

import time



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
			head = user.getSkeleton().getJoint(JointType.JOINT_HEAD)
			print(head.getPosition())
			

tracker.destroy()
NiTE.shutdown()
