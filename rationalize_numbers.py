#!/usr/bin/env python2.6

import sys

for line in sys.stdin:
    parts = line.split()
    for part in parts:
        print part + "/1",
    print
