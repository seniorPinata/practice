using namespace std;

#include "sorter.h"

#include <iostream>

Sorter::Sorter( string alg_name ) : m_alg_name( alg_name )
{
	cout << "Template class: created " << m_alg_name << " sorter\n";
}

Sorter::~Sorter( void )
{
	cout << "Template class: deleted " << m_alg_name << " sorter\n";
}

string Sorter::getName( void )
{
	return m_alg_name;
}

bool Sorter::sort( int array_len, int* array )
{
	cout << "Template class: implement me in subclasses\n";
	return false;
}
