#ifndef INSERTION_SORTER_H
#define INSERTION_SORTER_H

#include "sorter.h"

class InsertionSorter : public Sorter
{
public:
	InsertionSorter();
	~InsertionSorter( void );
	bool sort( int array_len, int* array ) override;
};

#endif /* INSERTION_SORTER_H */