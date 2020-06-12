#include "sorter.h"

#include <iostream>
#include <string.h>
#include <assert.h>

/** @brief Sorter constructor
 *
 * @param[in] alg_name Used to set m_alg_name
 */
Sorter::Sorter( std::string alg_name ) : m_alg_name( alg_name )
{
	std::cout << "Template class: created " << m_alg_name << " sorter\n";
}

/** @brief Sorter destructor */
Sorter::~Sorter( void )
{
	std::cout << "Template class: deleted " << m_alg_name << " sorter\n";
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
	std::cout << "Template class: implement me in subclasses\n";
	return false;
}

void Sorter::unittest( void )
{
	std::cout << "Unittesting " << m_alg_name << "...\n";

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

	/* Odd elements greater than 1 */
	len = 11;
	int arr_odd[] = { 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	int arr_odd_expected[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };
	assert( true == sort(len, arr_odd) );
	assert( 0 == memcmp( arr_odd, arr_odd_expected, len ) );

	/* Even elements greater than 1 */
	len = 12;
	int arr_even[] = { -12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	int arr_even_expected[] = { -12, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };
	assert( true == sort(len, arr_even) );
	assert( 0 == memcmp( arr_even, arr_even_expected, len ) );

	/* Repititions */
	len = 11;
	int arr_reps[] = { 11, 10, 1, 8, 7, 6, 6, 4, 3, 2, 11 };
	int arr_reps_expected[] = { 1, 2, 3, 4, 6, 6, 7, 8, 10, 11, 11 };
	assert( true == sort(len, arr_reps) );
	assert( 0 == memcmp( arr_reps, arr_reps_expected, len ) );

	std::cout << "Tests passed.\n";
}