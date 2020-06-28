#ifndef HASH_GRAPH_H
#define HASH_GRAPH_H

#include "Graph.h"
#include <unordered_map>

class HashGraph : public Graph
{
public:
	HashGraph( void );
	~HashGraph( void );
	void clear_graph( void ) override;
	bool add_edge( const Edge* const e ) override;
private:
	virtual int find_parent( const int val ) override;
	std::unordered_map<int, int> tracker;
};

#endif /* HASH_GRAPH_H */