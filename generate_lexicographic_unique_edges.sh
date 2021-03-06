#!/bin/bash
if [ $# -lt 2 ]; then
	echo "Usage: $0 n maxc"
	echo "       Where n is the number of points to generate"
	echo "       and the points have coordinates in [-maxc,maxc]"
	exit 1
fi

./generate_triangle_edges.py $1 $2 | ./lexicographize_edges.py | sort --unique