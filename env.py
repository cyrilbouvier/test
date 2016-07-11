#!/usr/bin/env python

import os
import sys

print(sys.version)

for key in os.environ.keys():
  print("%s = %s"%(key, os.environ[key]))
