/* https://www.udemy.com/course/coding-interview-bootcamp-algorithms-and-data-structure/
 * https://www.udemy.com/course/data-structures-and-algorithms-cplusplus-for-interviews/
 * https://www.udemy.com/course/data-structures-and-algorithms-bootcamp/
 * https://www.udemy.com/course/algorithms-bootcamp-in-c/

 * bubble sort (compare adjecent items if they are out of order, keep redoing this until done)
 * selection sort (find the smallest element and move it up, repeat until done)
 * insertion sort (as soon as you see something smaller than all previous insert it into place,
 *                 no need to find the smallest every round, just need to find anything smaller)
 * merge sort
 * quick sort
 *
 * sudo apt install build-essential
 * g++ -c sorting.cpp -g
 * g++ sorting.o -o sorting
 */

#include <stdio.h>
#include <string.h>
#include <assert.h>

/* Forward declarations */
void sort_unit_tests( bool (*sorter)(int, int*) );
bool bubble_sort( int array_len, int* array );
bool selection_sort( int array_len, int* array );
void selection_sort_unit_tests( void );

int main( int argc, char* argv[] )
{
	sort_unit_tests( bubble_sort );
	printf("Bubble sort tests passed\n");
	sort_unit_tests( selection_sort );
	printf("Selection sort tests passed\n");
}

/**
 * @brief Sorts array of ints using specified function.
 *
 * @param[in] sorter Pointer to sorting function
 */
void sort_unit_tests( bool (*sorter)(int, int*) )
{
	/* Bad len check */
	int len = 0;
	int arr[] = { 1 };
	int expected[] = { 1 };
	assert( false == sorter(len, arr) );

	/* Bad pointer check */
	len = 1;
	assert( false == sorter(len, NULL) );

	/* Single element */
	len = 1;
	assert( true == sorter(len, arr) );
	assert( 0 == memcmp( arr, expected, len ) );

	/* Odd elements greater than 1 */
	len = 11;
	int arr_odd[] = { 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	int arr_odd_expected[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };
	assert( true == sorter(len, arr_odd) );
	assert( 0 == memcmp( arr_odd, arr_odd_expected, len ) );

	/* Even elements greater than 1 */
	len = 12;
	int arr_even[] = { -12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	int arr_even_expected[] = { -12, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };
	assert( true == sorter(len, arr_even) );
	assert( 0 == memcmp( arr_even, arr_even_expected, len ) );

	/* Repititions */
	len = 11;
	int arr_reps[] = { 11, 10, 1, 8, 7, 6, 6, 4, 3, 2, 11 };
	int arr_reps_expected[] = { 1, 2, 3, 4, 6, 6, 7, 8, 10, 11, 11 };
	assert( true == sorter(len, arr_reps) );
	assert( 0 == memcmp( arr_reps, arr_reps_expected, len ) );
}

/**
 * @brief Sorts array of ints using bubble sort.
 *
 * Swap adjacent elements if out of order
 *
 * @param[in]     array_len	Length of the array to sort
 * @param[in,out] array 	Array to sort, will be directly modified
 * @return True on success, False otherwise.
 */
bool bubble_sort( int array_len, int* array )
{
	bool done = false;

	if (!array || 0 == array_len)
	{
		printf( "Array is empty nothing to sort\n" );
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
					printf( "Swapping %d with %d\n", array[i-1], array[i] );
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
static bool shift_right( int array_len, int* array, int start_idx, int end_idx )
{
	bool success = false;

	if (start_idx >= array_len)
	{
		printf( "Starting index %d is larger than array length %d\n",
				start_idx, array_len );
	}
	else if (end_idx >= array_len)
	{
		printf( "Ending index %d is larger than array length %d\n",
				end_idx, array_len );
	}
	else if (start_idx > end_idx)
	{
		printf( "Starting index %d is larger than Ending index %d\n",
				start_idx, end_idx );
	}
	else if (start_idx == end_idx)
	{
		printf( "Single element, nothing to do\n" );
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
bool selection_sort( int array_len, int* array )
{
	bool done = true;

	if (!array || 0 == array_len)
	{
		printf( "Array is empty nothing to sort\n" );
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
				printf("Critical error\n");
				done = false;
				break;
			}
			/* Move the smallest value into the sorted tail */
			else
			{
				printf( "Moving value:%d to idx:%d\n",
						smallest_value, sorted_tail_idx );
				array[sorted_tail_idx] = smallest_value;
				sorted_tail_idx++;
			}
		} while (sorted_tail_idx < array_len);
	}

	return done;
}