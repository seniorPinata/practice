#ifndef SORTER_H
#define SORTER_H

#include <string>

/*
 * Public, Protected, and Private are accessibility specifiers.
 * They dictate whether subclasses and non-subclasses have access.
 *
 * Virtual and Override are override specifiers.
 * They dictate whether subclasses can override methods.
 */
class Sorter
{
private:
	std::string m_alg_name;
public:
	Sorter( std::string alg_name );
	~Sorter( void );
	std::string getName( void );
	/* virtual is needed for polymorphism
	 * without it, the child classes don't actually override the function */
	virtual bool sort( int array_len, int* array );
	void unittest( void );
};

#endif /* SORTER_H */