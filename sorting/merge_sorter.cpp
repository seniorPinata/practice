#include "merge_sorter.h"

MergeSorter::MergeSorter() : Sorter( "MergeSort" )
{
	debug_log( "MergeSorter constructor\n" );
}

MergeSorter::~MergeSorter( void )
{
	debug_log( "MergeSorter destructor\n" );
}

/**
 * @brief Sorts array of ints using Merge sort.
 *
 * Sort half of the array, sort the other half
 * Then merge the 2 halves
 *
 * @param[in]     array_len	Length of the array to sort
 * @param[in,out] array 	Array to sort, will be directly modified
 * @return True on success, False otherwise.
 */
bool MergeSorter::sort( int array_len, int* array )
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
		int len1 = array_len / 2;
		int len2 = array_len - len1;
		int pos1 = 0;
		int pos2 = len1;
		int tmp_val = 0;

		sort( len1, array + pos1 );
		sort( len2, array + pos2 );

		/* Merge second half into first half */
		while( pos1 != pos2 && pos2 < array_len )
		{
			/* If array2[i] comes before array1[j] then
			 * insert arrray2[i] before array1[j] by shifting.
			 * This will open up j and overwrite i. */
			if (array[pos2] < array[pos1])
 			{
				tmp_val = array[pos2];
				if (shift_right( array_len, array, pos1, pos2 ))
				{
					array[pos1] = tmp_val;
					pos1++;
					pos2++;
				}
				else
				{
					error_log( "Critical error\n" );
					done = false;
					break;
				}
			}
			/* Already in correct order */
			else
			{
				pos1++;
			}
		}

		print_array( array_len, array );
	}

	return done;
}