#ifndef BUBBLE_SORTER_H
#define BUBBLE_SORTER_H

#include "sorter.h"

/* There are 3 ways to inherit.
 * ": private" means the parent public and protected members
 *     turn private in this subclass
 * ": protected" means the parent public and members
 *     turn protected in this subclass
 * ": public" means the parent members all remain as they are
 */
class BubbleSorter : public Sorter
{
public:
	BubbleSorter();
	~BubbleSorter( void );
	/* override isn't necessary, but helps with readability
	 * It tells the compiler we are overriding a virtual function */
	bool sort( int array_len, int* array ) override;
};

#endif /* BUBBLE_SORTER_H */