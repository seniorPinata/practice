#include "ArrayGraph.h"
#include <iostream>

ArrayGraph::ArrayGraph( void )
{
	std::cout << "ArrayGraph constructor\n";
	clear_graph();
}
ArrayGraph::~ArrayGraph( void )
{
	std::cout << "ArrayGraph destructor\n";
}
void ArrayGraph::clear_graph( void )
{
	for (int i = 0; i < TRACKER_SIZE; ++i)
	{
		tracker[i] = -1;
	}
}

/** @brief Update internal array with new edge
 *
 * @note This solution depends on the nodes being
 *       numbered from 0 to 100.
 *
 * @param[in] e Edge between 2 nodes
 * @return True on success, False on failure.
 */
bool ArrayGraph::add_edge( const Edge* const e )
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
	else if (MIN_NODE_VAL > val1 || MAX_NODE_VAL < val2)
	{
		std::cout << "Error: Node(s) not within range" <<
		   "(" << val1 << "," << val2 << ")\n";
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
 * In the array implementation we assume a node's value is
 * it's index into the tracker array.
 * If the array value is negative we have found the parent,
 * otherwise we keep chasing until we find it.
 *
 * @param[in] val Node value to trace
 * @return Index of the Node's parent.
 */
int ArrayGraph::find_parent( const int val )
{
	int parent = val;

	while (0 <= tracker[parent])
	{
		parent = tracker[parent];
	}

	return parent;
}