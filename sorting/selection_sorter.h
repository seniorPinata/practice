#ifndef SELECTION_SORTER_H
#define SELECTION_SORTER_H

#include "sorter.h"

class SelectionSorter : public Sorter
{
private:
	bool shift_right( int array_len, int* array, int start_idx, int end_idx );
public:
	SelectionSorter();
	~SelectionSorter( void );
	bool sort( int array_len, int* array ) override;
};

#endif /* BUBBLE_SORTER_H */