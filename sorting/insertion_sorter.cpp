#include "insertion_sorter.h"

InsertionSorter::InsertionSorter() : Sorter( "InsertionSort" )
{
	debug_log( "InsertionSorter constructor\n" );
}

InsertionSorter::~InsertionSorter( void )
{
	debug_log( "InsertionSorter destructor\n" );
}

/**
 * @brief Sorts array of ints using Insertion sort.
 *
 * Pretend you are drawing cards 1 at a time.
 * As you draw a new card you put it in the correct place.
 * You sort an increasingly larger array each time.
 *
 * @param[in]     array_len	Length of the array to sort
 * @param[in,out] array 	Array to sort, will be directly modified
 * @return True on success, False otherwise.
 */
bool InsertionSorter::sort( int array_len, int* array )
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
		int new_spot = 1;
		int insert_spot = 0;
		int new_value = 0;

		do
		{
			new_value = array[new_spot];
			insert_spot = new_spot;

			/* Iterate from new_spot-1 to 0 until we find lowest place to insert */
			for (int i = new_spot-1; 0 <= i ; --i)
			{
				debug_log( "Comparing spot %d[%d] with spot %d[%d]\n",
						   i, array[i], new_spot, array[new_spot] );

				if (new_value < array[i])
				{
					insert_spot = i;
				}
				else { /* If it's greater or equal keep moving down */ }
			}

			/* Oepn lowest found spot by shifting everything over until
			 * new_spot is overwritten */
			if (!shift_right( array_len, array, insert_spot, new_spot ))
			{
				error_log( "Critical error\n" );
				done = false;
				break;
			}
			/* Success, save new_value into opened spot */
			else
			{
				array[insert_spot] = new_value;
			}

			new_spot++;
		} while (new_spot < array_len);
	}

	return done;
}