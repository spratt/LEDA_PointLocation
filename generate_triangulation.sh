#!/bin/bash
if [ $# -lt 2 ]; then
	echo "Usage: $0 n maxc"
	echo "       Where n is the number of points to generate"
	echo "       and the points have coordinates in [-maxc,maxc]"
else
	./generate_node_file.sh $1 $2 > random.node
	triangle random && rm random.node
fi