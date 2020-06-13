#include "bubble_sorter.h"

BubbleSorter::BubbleSorter() : Sorter( "BubbleSort" )
{
	debug_log( "BubbleSorter constructor\n" );
}

BubbleSorter::~BubbleSorter( void )
{
	debug_log( "BubbleSorter destructor\n" );
}

/**
 * @brief Sorts array of ints using bubble sort.
 *
 * Swap adjacent elements if out of order
 *
 * @note Only need "override" in the header
 *
 * @param[in]     array_len	Length of the array to sort
 * @param[in,out] array 	Array to sort, will be directly modified
 * @return True on success, False otherwise.
 */
bool BubbleSorter::sort( int array_len, int* array )
{
	bool done = false;

	if (!array || 0 == array_len)
	{
		debug_log( "Array is empty nothing to sort\n" );
	}
	else if (1 == array_len)
	{
		done = true;
	}
	/* Guaranteed to have 2 elements */
	else
	{
		bool made_change = false;
		int tmp = 0;

		/* Keep looping until there are no changes */
		do
		{
			made_change = false;

			/* Iterate over all elements */
			for (int i = 1; i < array_len; ++i)
			{
				/* Swap if out of order */
				if (array[i-1] > array[i])
				{
					debug_log( "Swapping %d with %d\n", array[i-1], array[i] );
					tmp = array[i-1];
					array[i-1] = array[i];
					array[i] = tmp;
					made_change = true;
				}
				else { /* Correct order */ }
			}
		} while (made_change);

		done = true;
	}

	return done;
}
