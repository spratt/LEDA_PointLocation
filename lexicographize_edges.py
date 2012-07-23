#!/usr/bin/env python2.6

import sys

for line in sys.stdin:
    parts=line.strip().split()
    if parts[0] + parts[1] < parts[2] + parts[3]:
        print parts[0], parts[1], parts[2], parts[3]
    else:
        print parts[2], parts[3], parts[0], parts[1]
