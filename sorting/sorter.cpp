#include "sorter.h"
#include <string.h>
#include <assert.h>

/** @brief Sorter constructor
 *
 * @param[in] alg_name Used to set m_alg_name
 */
Sorter::Sorter( std::string alg_name ) :
	Loggable( LOG_LEVEL_INFO ), m_alg_name( alg_name )
{
	debug_log( "Template class: created %s\n", m_alg_name.c_str() );
}

/** @brief Sorter destructor */
Sorter::~Sorter( void )
{
	debug_log( "Template class: deleted %s\n", m_alg_name.c_str() );
}

/** @brief Returns the Sorter name 
 *
 * @return Sorter name set in constructor
 */
std::string Sorter::getName( void )
{ 
	return m_alg_name; 
}

/**
 * @brief Template sort function.
 *
 * To be overriden by child classes.
 *
 * @note Only need "virtual" in the header
 *
 * @param[in]     array_len	Length of the array to sort
 * @param[in,out] array 	Array to sort, will be directly modified
 * @return True on success, False otherwise.
 */
bool Sorter::sort( int array_len, int* array )
{
	info_log( "Template class: implement me in subclasses\n" );
	return false;
}

void Sorter::unittest( void )
{
	info_log( "Unittesting %s...\n", m_alg_name.c_str() );

	/* Bad len check */
	int len = 0;
	int arr[] = { 1 };
	int expected[] = { 1 };
	assert( false == sort(len, arr) );

	/* Bad pointer check */
	len = 1;
	assert( false == sort(len, NULL) );

	/* Single element */
	len = 1;
	assert( true == sort(len, arr) );
	assert( 0 == memcmp( arr, expected, len ) );

	/* Even elements greater than 1 */
	len = 12;
	int arr_even[] = { -12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	int arr_even_expected[] = { -12, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };
	assert( true == sort(len, arr_even) );
	assert( 0 == memcmp( arr_even, arr_even_expected, len ) );
	
	/* Odd elements greater than 1 */
	len = 11;
	int arr_odd[] = { 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	int arr_odd_expected[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };
	assert( true == sort(len, arr_odd) );
	assert( 0 == memcmp( arr_odd, arr_odd_expected, len ) );

	/* Repititions */
	len = 11;
	int arr_reps[] = { 11, 10, 1, 8, 7, 6, 6, 4, 3, 2, 11 };
	int arr_reps_expected[] = { 1, 2, 3, 4, 6, 6, 7, 8, 10, 11, 11 };
	assert( true == sort(len, arr_reps) );
	assert( 0 == memcmp( arr_reps, arr_reps_expected, len ) );

	/* Already sorted */
	len = 11;
	int arr_sorted[] = { 1, 2, 3, 4, 6, 6, 7, 8, 10, 11, 11 };
	int arr_sorted_expected[] = { 1, 2, 3, 4, 6, 6, 7, 8, 10, 11, 11 };
	assert( true == sort(len, arr_sorted) );
	assert( 0 == memcmp( arr_sorted, arr_sorted_expected, len ) );

	info_log( "Tests passed.\n" );
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
bool Sorter::shift_right( int array_len, int* array, int start_idx, int end_idx )
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
			debug_log( "Moving spot %d[%d] into spot %d[%d]\n",
						   i-1, array[i-1], i, array[i] );
			array[i] = array[i-1];
		}

		success = true;
	}

	return success;
}

/**
 * @brief Swap the 2 values.
 *
 * @param[in,out] val1		Pointer to first value
 *                          Will hold second value on success
 * @param[in,out] val2		Pointer to second value
 *                          Will hold first value on success
 * @return True on success, False otherwise.
 */
bool Sorter::swap_values( int* val1, int* val2 )
{
	bool success = false;
	int tmp;

	if (val1 && val2)
	{
		debug_log( "Swapping %d with %d\n", *val1, *val2 );
		tmp = *val1;
		*val1 = *val2;
		*val2 = tmp;
		success = true;
	}
	else
	{
		error_log( "Attempted to swap NULL elements\n" );
	}

	return success;
}

/**
 * @brief Log array contents.
 *
 * @param[in]     array_len	Length of the array
 * @param[in,out] array 	Array to log
 */
void Sorter::print_array( int array_len, int* array )
{
	debug_log( "######################################\n" );
	debug_log( "Printing array...\n" );
	for (int i = 0; i < array_len; ++i)
	{
		debug_log( "Index:%d, Value:%d\n", i, array[i] );
	}
	debug_log( "######################################\n" );
}