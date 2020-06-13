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
 * @brief Shifts an array to the right.
 *
 * @param[in]     array_len	Length of the array
 * @param[in,out] array 	Array to shift, will be directly modified
 * @param[in]     start_idx	Index of the first element to shift
 * @param[in]     end_idx	Index of the last element we are going to overwrite
 *                          Caller is repsonsible for saving this value off
 * @return True on success, False otherwise.
 */
bool SelectionSorter::shift_right( int array_len, int* array, int start_idx, int end_idx )
{
	bool success = false;

	if (start_idx >= array_len)
	{
		debug_log( "Starting index %d is larger than array length %d\n",
				   start_idx, array_len );
	}
	else if (end_idx >= array_len)
	{
		debug_log( "Ending index %d is larger than array length %d\n",
				   end_idx, array_len );
	}
	else if (start_idx > end_idx)
	{
		debug_log( "Starting index %d is larger than Ending index %d\n",
				   start_idx, end_idx );
	}
	else if (start_idx == end_idx)
	{
		debug_log( "Single element, nothing to do\n" );
		success = true;
	}
	/* Guaranteed to have 2 spots */
	else
	{
		for (int i = end_idx; i > start_idx; --i)
		{
			array[i] = array[i-1];
		}

		success = true;
	}

	return success;
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