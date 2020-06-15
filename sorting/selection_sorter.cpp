#include "selection_sorter.h"

SelectionSorter::SelectionSorter() : Sorter( "SelectionSort" )
{
	debug_log( "SelectionSorter constructor\n" );
}

SelectionSorter::~SelectionSorter( void )
{
	debug_log( "SelectionSorter destructor\n" );
}

/**
 * @brief Sorts array of ints using selection sort.
 *
 * Find smallest value and move to front
 *
 * @param[in]     array_len	Length of the array to sort
 * @param[in,out] array 	Array to sort, will be directly modified
 * @return True on success, False otherwise.
 */
bool SelectionSorter::sort( int array_len, int* array )
{
	bool done = true;

	if (!array || 0 == array_len)
	{
		debug_log( "Array is empty nothing to sort\n" );
		done = false;
	}
	else if (1 == array_len)
	{
		done = true;
	}
	/* Guaranteed to have 2 elements */
	else
	{
		int smallest_idx = 0;
		int sorted_tail_idx = 0;
		int smallest_value = 0;

		do
		{
			smallest_idx = sorted_tail_idx;

			/* Loop over unsorted elements */
			for (int i = sorted_tail_idx; i < array_len; ++i)
			{
				if (array[i] < array[smallest_idx])
				{
					smallest_idx = i;
				}
				else { /* Continue looping */ }
			}
	
			/* Shift everything to the right such that:
			 * 1) the sorted_tail_idx is freed up
			 * 2) the smallest_idx is overwritten by smallest_idx-1
			 */
			smallest_value = array[smallest_idx];
			if (!shift_right( array_len, array, sorted_tail_idx, smallest_idx ))
			{
				error_log( "Critical error\n" );
				done = false;
				break;
			}
			/* Move the smallest value into the sorted tail */
			else
			{
				debug_log( "Moving value:%d to idx:%d\n",
						   smallest_value, sorted_tail_idx );
				array[sorted_tail_idx] = smallest_value;
				sorted_tail_idx++;
			}
		} while (sorted_tail_idx < array_len);
	}

	return done;
}