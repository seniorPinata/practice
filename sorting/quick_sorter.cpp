#include "quick_sorter.h"
#include <cstring>

QuickSorter::QuickSorter() : Sorter( "QuickSort" )
{
	debug_log( "QuickSorter constructor\n" );
}

QuickSorter::~QuickSorter( void )
{
	debug_log( "QuickSorter destructor\n" );
}

/**
 * @brief Sorts array of ints using Quick sort.
 *
 * Pick a random index and call it pivot.
 * Rearrange the array such that everything to the left
 * of the pivot is less than it and everything to the right
 * of the pivot is greater than or equal to it.
 * This does not mean the sides need to be sorted!
 *
 * @param[in]     array_len	Length of the array to sort
 * @param[in,out] array 	Array to sort, will be directly modified
 * @return True on success, False otherwise.
 */
bool QuickSorter::sort( int array_len, int* array )
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
		/* Choose the last index as the pivot
		 * We can randomize this later */
		int start = 0;
		int end = array_len -1;
		int pivot = end;

		/* Loop over the array until the pivot is in place */
		while (start <= end)
		{
			/* If the current index is the pivot skip it and continue */
			if (pivot == start)
			{
				start++;
			}
			else if (pivot == end)
			{
				end--;
			}
			/* If START is less than pivot then it's already valid.
			 * Skip it and continue */
			else if (array[start] < array[pivot])
			{
				start++;
			}
			/* If END is greater than or equal to pivot then it's
			 * already valid.
			 * Skip it and continue */
			else if (array[pivot] <= array[end])
			{
				end--;
			}
			/* Both START and END are out of place, swap them */
			else if (!swap_values( array + start, array + end ))
			{
				error_log( "Critical error\n" );
				break;
			}
			/* Success, find the next out of order pair */
			else
			{
				start++;
				end--;
			}
		}

		/* Put the pivot in place
		 * We break when START crosses END so START must be at the
		 * first GTE spot */
		debug_log( "Swapping pivot: " );
		if (!swap_values( array + start, array + pivot ))
		{
			error_log( "Critical error\n" );
		}
		else
		{
			pivot = start;
			start = 0;       // start of first array
			end = pivot + 1; // start of the second array
			debug_log( "Pivot:%d, Pivoted array:\n", array[pivot] );
			print_array( array_len, array );

			/* Sort both sides of the pivot */
			sort( pivot, array + start );
			sort( array_len - pivot - 1, array + end );
			done = true;
		}
	}

	return done;
}