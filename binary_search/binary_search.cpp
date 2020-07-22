#include <iostream>
#include <assert.h>

int binary_search( const int* arr, const int arr_len, const int value )
{
	int ret_val = -1;

	std::cout << "len: " << arr_len << std::endl;
	for (int i = 0; i < arr_len; ++i)
	{
		std::cout << arr[i] << ", ";
	}
	std::cout << std::endl;

	if (arr_len <= 0)
	{
		/* No match, error already set. */
	}
	else if (arr_len == 1)
	{
		if (value == arr[0])
		{
			ret_val = 0;
		}
		else { /* No match, error already set. */ }
	}
	/* At least 2 elements so divide */
	else
	{
		/* Find the middle point (floor) */
		int middle = arr_len / 2;

		/* Decide which side to search in */
		if (value == arr[middle])
		{
			ret_val = middle;
		}
		else if (value < arr[middle])
		{
			/* Search the left side */
			ret_val = binary_search( arr, middle, value );
		}
		else
		{
			/* Search the right side */
			middle += 1;
			ret_val = binary_search( arr + middle, arr_len - middle, value );

			if (-1 != ret_val)
			{
				ret_val += middle;
			}
			else { /* No match, error already set. */ }
		}
	}

	std::cout << "Returning: " << ret_val << std::endl;
	return ret_val;
}

int nr_binary_search( const int* arr, const int arr_len, const int value )
{
	int ret_val = -1;
	int front = 0;
	int back = arr_len - 1;
	int middle = 0;
	
	while ( front <= back )
	{
		middle = (front + back) / 2;
		
		if (value == arr[middle])
		{
			ret_val = middle;
			break;
		}
		else if (value < arr[middle])
		{
			back = middle - 1;
			std::cout << "Set BACK to " << back << std::endl;
		}
		else
		{
			front = middle + 1;
			std::cout << "Set FRONT to " << front << std::endl;
		}
	}

	return ret_val;
}

int main(int argc, char const *argv[])
{
	/* Bad len check */
	int value = 1;
	int len = 0;
	int arr[] = { 1 };
	int expected = -1;
	assert( expected == binary_search(arr, len, value) );
	assert( expected == nr_binary_search(arr, len, value) );
	std::cout << "######################################\n";

	/* Not there */
	value = 1;
	len = 1;
	int arr1[] = { 0 };
	expected = -1;
	assert( expected == binary_search(arr1, len, value) );
	assert( expected == nr_binary_search(arr1, len, value) );
	std::cout << "######################################\n";

	/* Easy case */
	value = 1;
	len = 1;
	int arr2[] = { 1 };
	expected = 0;
	assert( expected == binary_search(arr2, len, value) );
	assert( expected == nr_binary_search(arr2, len, value) );
	std::cout << "######################################\n";

	/* It's the middle */
	value = 1;
	len = 2;
	int arr3[] = { -10, 1 };
	expected = 1;
	assert( expected == binary_search(arr3, len, value) );
	assert( expected == nr_binary_search(arr3, len, value) );
	std::cout << "######################################\n";

	/* It's the middle */
	value = 1;
	len = 3;
	int arr4[] = { -10, 1, 2 };
	expected = 1;
	assert( expected == binary_search(arr4, len, value) );
	assert( expected == nr_binary_search(arr4, len, value) );
	std::cout << "######################################\n";

	/* in left hand side*/
	value = 1;
	len = 6;
	int arr5[] = { 1, 2, 3, 4, 5, 6 };
	expected = 0;
	assert( expected == binary_search(arr5, len, value) );
	assert( expected == nr_binary_search(arr5, len, value) );
	std::cout << "######################################\n";

	/* in right hand side*/
	value = 6;
	len = 6;
	int arr6[] = { 1, 2, 3, 4, 5, 6 };
	expected = 5;
	assert( expected == binary_search(arr6, len, value) );
	assert( expected == nr_binary_search(arr6, len, value) );
	std::cout << "######################################\n";

	std::cout << "All tests passed\n";
	return 0;
}