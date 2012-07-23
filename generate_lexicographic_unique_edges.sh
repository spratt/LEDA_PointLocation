#!/bin/bash
./generate_triangle_edges.py 5 5 | ./lexicographize_edges.py | sort --unique