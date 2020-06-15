#ifndef SELECTION_SORTER_H
#define SELECTION_SORTER_H

#include "sorter.h"

class SelectionSorter : public Sorter
{
public:
	SelectionSorter();
	~SelectionSorter( void );
	bool sort( int array_len, int* array ) override;
};

#endif /* SELECTION_SORTER_H */