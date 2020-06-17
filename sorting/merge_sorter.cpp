#include "merge_sorter.h"
#include <cstring>

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
 * Use a second array to do the merging. This is the
 * traditional way to get O(nlogn)
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
		/* Calculate boundary info */
		int len1 = array_len / 2;
		int len2 = array_len - len1;
		int main_pos = 0;
		int pos1 = 0;
		int pos2 = len1;
		int* array1 = NULL;
		int* array2 = NULL;

		sort( len1, array + pos1 );
		sort( len2, array + pos2 );

		/* Prepare tmp arrays to merge into main array */
		array1 = new int[len1];
		array2 = new int[len2];
		/* Copy sorted arrays to merge into main array */
		memcpy( array1, array + pos1, sizeof(int) * len1 );
		memcpy( array2, array + pos2, sizeof(int) * len2 );

		/* Loop over both and merge */
		pos1 = pos2 = 0;
		while( pos1 < len1 && pos2 < len2 )
		{
			/* Write pos1 if smaller, pos2 otherwise. */
			if (array1[pos1] < array2[pos2])
			{
				array[main_pos] = array1[pos1];
				pos1++;
			}
			else
			{
				array[main_pos] = array2[pos2];
				pos2++;
			}
			main_pos++;
		}

		/* Loop ends when at least 1 array is empty
		 * Write the rest of the other array out */
		for (; pos1 < len1; ++pos1)
		{
			array[main_pos] = array1[pos1];
			pos1++;
			main_pos++;
		}
		for (; pos2 < len2; ++pos2)
		{
			array[main_pos] = array2[pos2];
			pos2++;
			main_pos++;
		}

		debug_log( "Merged array:\n" );
		print_array( array_len, array );
	}

	return done;
}

/**
 * @brief Sorts array of ints using Merge sort.
 *
 * Sort half of the array, sort the other half
 * Then merge the 2 halves
 *
 * @note This implementation works, but is not ideal.
 *       Shifting the array adds too many extra cycles.
 *       It shifts multiple times during each recursion step.
 *       Copying the array would waste space, but only happen once
 *       per recursion step.
 *       It would speed it up to O(nlogn)
 *
 * @param[in]     array_len	Length of the array to sort
 * @param[in,out] array 	Array to sort, will be directly modified
 * @return True on success, False otherwise.
 */
bool MergeSorter::slowSort( int array_len, int* array )
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