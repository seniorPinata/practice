#ifndef GRAPH_H
#define GRAPH_H

class Edge
{
public:
	Edge( const int val1, const int val2 )
	{
		m_val1 = val1;
		m_val2 = val2;
	}
	int get_val1( void ) const { return m_val1; }
	int get_val2( void ) const { return m_val2; }
private:	
	int m_val1;
	int m_val2;
};

class Graph
{
public:
	Graph( void );
	~Graph( void );
	void unittest( void );
	bool add_edges( const Edge* const es, const int num_edges );
	virtual void clear_graph( void );
	virtual bool add_edge( const Edge* const e );
private:
	virtual int find_parent( const int val );
};

#endif /* GRAPH_H */