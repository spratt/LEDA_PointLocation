#!/bin/bash

if [ $# -lt 2 ]; then
	echo "Usage: $0 n maxc"
	echo "       Where n is the number of points to generate"
	echo "       and the points have coordinates in [-maxc,maxc]"
	exit 1
fi

./generate_lexicographic_unique_edges.sh $1 $2 > segments.txt