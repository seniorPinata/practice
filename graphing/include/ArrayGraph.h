#ifndef ARRAY_GRAPH_H
#define ARRAY_GRAPH_H

#include "Graph.h"

#define MIN_NODE_VAL 0
#define MAX_NODE_VAL 100
#define TRACKER_SIZE (MAX_NODE_VAL + 1)

class ArrayGraph : public Graph
{
public:
	ArrayGraph( void );
	~ArrayGraph( void );
	void clear_graph( void ) override;
	bool add_edge( const Edge* const e ) override;
private:
	virtual int find_parent( const int val ) override;
	int tracker[TRACKER_SIZE];

};

#endif /* ARRAY_GRAPH_H */