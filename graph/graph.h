/* File: graph.h */
/* File to store ADT Graph */

#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"

typedef int infotype;
typedef struct tNodeU* uAddress;
typedef struct tNodeV* vAddress;

typedef struct tNodeU {
	infotype info;
	vAddress firstChild;
	uAddress next;
} nodeU;


typedef struct tNodeV {
	infotype info;
	vAddress nextChild;
} nodeV;

typedef struct {
	uAddress firstGraph;
} graph;

#define info(P) (P)->info
#define next(P) (P)->next
#define nextChild(P) (P)->nextChild
#define child(P) (P)->firstChild
#define firstGraph(G) ((G).firstGraph)

// Allocate node for incoming node
uAddress allocateNodeU(infotype N);

// Allocate node for child node
vAddress allocateNodeV(infotype N);

// Check if Node empty
boolean isNodeEmpty(uAddress P);

// Make empty graph with nodeCount nodes
void createGraph(graph *G, int nodeCount);

// Insert connection in node P node M 
void insertChildP(uAddress P, int M);

// Insert connection in node n
// I.S : Graph  is defined
void insertChild(graph *G, int N, int M);

// Output graph for testing
void printGraph(graph G);

// Check if node N is connected to node M
boolean isConnected(graph G, int N, int M);

#endif