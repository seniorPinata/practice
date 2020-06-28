#include "HashGraph.h"
#include <iostream>

HashGraph::HashGraph( void )
{
	std::cout << "HashGraph constructor\n";
	clear_graph();
}
HashGraph::~HashGraph( void )
{
	std::cout << "HashGraph destructor\n";
}
void HashGraph::clear_graph( void )
{
	tracker.clear();
}

/** @brief Update internal array with new edge
 *
 * @param[in] e Edge between 2 nodes
 * @return True on success, False on failure.
 */
bool HashGraph::add_edge( const Edge* const e )
{
	bool ret_val = false;
	int val1, val2;

	if (!e)
	{
		std::cout << "Error: NULL edge\n";
	}
	else if ((val1 = e->get_val1()) ==
		     (val2 = e->get_val2()))
	{
		std::cout << "Error: Can't edge to oneself\n";
	}
	else
	{
		int p1 = find_parent(val1);
		int p2 = find_parent(val2);
		
		/* Same parent means loop, so fail */
		if (p1 == p2)
		{
			std::cout << "Error: Adding edge will introduce loop " <<
			"(" << val1 << "," << val2 << ")\n";
		}
		/* Different parents so join */
		else
		{
			tracker[p1] += tracker[p2];
			tracker[p2] = p1;
			ret_val = true;
			std::cout << "Info: Added edge " <<
			"(" << val1 << "," << val2 << ")\n";
		}
	}

	return ret_val;
}

/** @brief Retrieve the parent for the given node value.
 *
 * In the hash implementation we assume a node's value is
 * it's key into the hash.
 * If the hash value is negative we have found the parent,
 * otherwise we keep chasing until we find it.
 *
 * @param[in] val Node value to trace
 * @return Key of the Node's parent.
 */
int HashGraph::find_parent( const int val )
{
	int parent = val;

	/* New key, so make itself the parent and return */
	if (0 == tracker.count(val))
	{
		tracker[val] = -1;
		parent = val;
	}
	/* Key exists, trace the key */
	else
	{
		while (0 <= tracker[parent])
		{
			parent = tracker[parent];
		}
	}

	return parent;
}