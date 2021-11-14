/* File: graph.c */
/* graph.h implementation */

#include "graph.h"

// Allocate node for incoming node
uAddress allocateNodeU(infotype N)
{
	uAddress P = (uAddress)malloc(sizeof(nodeU));
	if(P!= NULL)
	{
		info(P) = N;
		next(P) = NULL;
		child(P) = NULL;
	}
	return P;
}

// Allocate node for child node
vAddress allocateNodeV(infotype N)
{
	vAddress P = (vAddress)malloc(sizeof(nodeV));
	if(P != NULL)
	{
		info(P) = N;
		nextChild(P) = NULL;
	}
	return P;
}

// Check if Node empty
boolean isNodeEmpty(uAddress P)
{
	return child(P) == NULL;
}

// Make empty graph with nodeCount nodes
void createGraph(graph *G, int nodeCount)
{
	uAddress P = allocateNodeU(1);
	firstGraph(*G) = P;
	
	for(int i=2;i<=nodeCount;i++)
	{
		uAddress Ptemp = allocateNodeU(i);
		next(P) = Ptemp;
		P = Ptemp;
	}

}

// Insert connection from node N to node M 
// I.S : Graph is defined
void insertChildP(uAddress P, int M)
{
	vAddress Q = allocateNodeV(M);
	if(isNodeEmpty(P)) child(P) = Q;
	else
	{
		// Traverse child
		vAddress V = child(P);
		while(nextChild(V)!=NULL) V = nextChild(V);

		// Insert last
		nextChild(V)=Q;
	}
	
}

// Insert connection in node n
// I.S : Graph  is defined
void insertChild(graph *G, int N, int M)
{
	uAddress P = firstGraph(*G);
	for(int i=2;i<=N;i++) P = next(P);
	insertChildP(P, M);
}

// Output graph for testing
void printGraph(graph G)
{
	uAddress P  = firstGraph(G);
	while(P!=NULL)
	{
		printf("Node %d is connected to:\n", info(P));
		
		// Traverse connections
		vAddress Q = child(P);
		while(Q!=NULL)
		{
			printf("\tNode %d\n", info(Q));
			Q = nextChild(Q);
		}
		printf("==================================\n");

		P = next(P);
	}
	
}

// Check if node N is connected to node M
boolean isConnected(graph G, int N, int M)
{
	uAddress P = firstGraph(G);
	boolean result = false;

	for(int i=2;i<=N;i++) P = next(P);

	vAddress Q = child(P);
	while(!result && Q!=NULL)
	{
		if(info(Q)==M) result=true;
		else Q = nextChild(Q);
	}

	return result;

}