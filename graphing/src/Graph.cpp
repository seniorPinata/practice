#include "Graph.h"
#include <iostream>
#include <assert.h>

Graph::Graph( void )
{
	std::cout << "Graph constructor\n";
}
Graph::~Graph( void )
{
	std::cout << "Graph destructor\n";
}
void Graph::unittest( void )
{
	int num_edges = 0;

	/* NULL edge(s) */
	assert( false == add_edge( NULL ) );
	assert( false == add_edges( NULL, num_edges ) );

	/* Edge to oneself 1-1 */
	Edge e1 = Edge( 1, 1 );
	assert( false == add_edges( &e1, 0 ) );
	assert( false == add_edge( &e1 ) );

	/* Normal edge 1-2 */
	Edge e2 = Edge( 1, 2 );
	assert( true == add_edge( &e2 ) );

	/* Second disjoint edge 3-4 */
	Edge e3 = Edge( 3, 4 );
	assert( true == add_edge( &e3 ) );

	/* Third disjoint edge 5-6 */
	Edge e4 = Edge( 5, 6 );
	assert( true == add_edge( &e4 ) );

	/* Fourth joint edge 2-3 */
	Edge e5 = Edge( 2, 3 );
	assert( true == add_edge( &e5 ) );

	/* Fifth joint edge 1-4 */
	Edge e6 = Edge( 1, 4 );
	assert( false == add_edge( &e6 ) );
}
bool Graph::add_edges( const Edge* const es, const int num_edges )
{
	bool ret_val = false;

	if (!es)
	{
		std::cout << "Error: NULL edges array\n";
	}
	else if (1 > num_edges)
	{
		std::cout << "Error: " << num_edges << " length edge array\n";
	}
	else
	{
		ret_val = true;

		for (int i = 0; i < num_edges; ++i)
		{
			if (!add_edge( es + i ))
			{
				ret_val = false;
		 		break;
			}
			else { /* No error, continue. */ }
		}
	}

	return ret_val;
}
void Graph::clear_graph( void )
{
	std::cout << "Implement me!\n";
}
bool Graph::add_edge( const Edge* const e )
{
	std::cout << "Implement me!\n";
	return false;
}
int Graph::find_parent( const int val )
{
	std::cout << "Implement me!\n";
	return -1;
}