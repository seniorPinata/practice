#ifndef MERGE_SORTER_H
#define MERGE_SORTER_H

#include "sorter.h"

class MergeSorter : public Sorter
{
public:
	MergeSorter();
	~MergeSorter( void );
	bool sort( int array_len, int* array ) override;
};

#endif /* MERGE_SORTER_H */