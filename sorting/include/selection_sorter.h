#ifndef SELECTION_SORTER_H
#define SELECTION_SORTER_H

#include "sorter.h"

class SelectionSorter : public Sorter
{
private:
	bool slowSort( int array_len, int* array );
public:
	SelectionSorter();
	~SelectionSorter( void );
	bool sort( int array_len, int* array ) override;
};

#endif /* SELECTION_SORTER_H */