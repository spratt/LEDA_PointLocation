#!/usr/bin/env python2.6

import sys
from subprocess import call

# usage check
if len(sys.argv) < 3:
    print "Usage: %s n maxc" % sys.argv[0]
    print "       Where n is the number of points to generate"
    print "       and the points have coordinates in [-maxc,maxc]"
    exit(1)

# name input
n=sys.argv[1]
maxc=sys.argv[2]

# run triangle generation
with open("/dev/null") as abyss:
    call(args=["./generate_triangulation.sh",n,maxc],stdout=abyss,stderr=abyss)

# utility functions
def isWhitespace(s):
    return s.strip() == ''

def isComment(s):
    return s[0] == '#'
    
# read in nodes
# for documentation on node format:
# http://www.cs.cmu.edu/~quake/triangle.node.html
nodes={}
with open("random.1.node") as node_file:
    first = True
    for line in node_file:
        if first:
            first = False
            continue
        line = line.strip()
        if not isWhitespace(line) and not isComment(line):
            parts=line.split()
            nodes[parts[0]] = parts[1] + " " + parts[2]

# read in triangles
# for documentation on ele format:
# http://www.cs.cmu.edu/~quake/triangle.ele.html
triangles={}
with open("random.1.ele") as triangle_file:
    first = True
    for line in triangle_file:
        if first:
            first = False
            continue
        line = line.strip()
        if not isWhitespace(line) and not isComment(line):
            parts=line.split()
            triangles[parts[0]] = [parts[1],parts[2],parts[3]]

# compute edges
edges=[]
for i in triangles:
    edges.append([triangles[i][0],triangles[i][1]])
    edges.append([triangles[i][1],triangles[i][2]])
    edges.append([triangles[i][2],triangles[i][0]])
        
# print edge list
for edge in edges:
    print nodes[edge[0]], nodes[edge[1]]
