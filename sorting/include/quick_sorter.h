#ifndef QUICK_SORTER_H
#define QUICK_SORTER_H

#include "sorter.h"

class QuickSorter : public Sorter
{
public:
	QuickSorter();
	~QuickSorter( void );
	bool sort( int array_len, int* array ) override;
};

#endif /* QUICK_SORTER_H */