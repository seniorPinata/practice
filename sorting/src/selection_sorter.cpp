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
 * @note It swaps instead of shifts to save cycles.
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

		do
		{
			smallest_idx = sorted_tail_idx;

			/* Loop over unsorted elements to find smallest value */
			for (int i = sorted_tail_idx; i < array_len; ++i)
			{
				if (array[i] < array[smallest_idx])
				{
					smallest_idx = i;
				}
				else { /* Continue looping */ }
			}
	
			/* Swap smallest value with the tail.
			 * Since we're adding to the tail, shifting is not necessary.
			 * Everything after the tail is unsorted anyways.
			 */
			if (!swap_values(array + smallest_idx, array + sorted_tail_idx))
			{
				error_log( "Critical error\n" );
				done = false;
				break;
			}
			/* Increment tail and continue sorting. */
			else
			{
				sorted_tail_idx++;
			}
		} while (sorted_tail_idx < array_len);
	}

	return done;
}

/**
 * @brief Sorts array of ints using selection sort.
 *
 * Find smallest value and move to front
 *
 * @note This implementation works, but is not ideal.
 *       There is no need to shift the array over.
 *       Shifting changes the complexity to O(n^2)
 *       The second part of the array is unsorted, so we can swap instead
 *       of shift.
 *
 * @param[in]     array_len	Length of the array to sort
 * @param[in,out] array 	Array to sort, will be directly modified
 * @return True on success, False otherwise.
 */
bool SelectionSorter::slowSort( int array_len, int* array )
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