#!/bin/bash
if [ $# -lt 2 ]; then
	echo "Usage: $0 n maxc"
	echo "       Where n is the number of points to generate"
	echo "       and the points have coordinates in [-maxc,maxc]"
else
	echo $1 2 0 0
	./leda_random $1 $2
fi
