#ifndef BUBBLE_SORTER_H
#define BUBBLE_SORTER_H

#include "sorter.h"

class BubbleSorter : public Sorter
{
public:
	BubbleSorter();
	~BubbleSorter( void );
	bool sort( int array_len, int* array );
};

#endif /* BUBBLE_SORTER_H */