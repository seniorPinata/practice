#ifndef SORTER_H
#define SORTER_H

#include <string>

class Sorter
{
private:
	std::string m_alg_name;
public:
	Sorter( string alg_name );
	~Sorter( void );
	std::string getName( void );
	bool sort( int array_len, int* array );
};

#endif /* SORTER_H */