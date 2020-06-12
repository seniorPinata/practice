#define CATCH_CONFIG_MAIN
#include "catch.hpp"

using namespace std;

#include "sorter.h"
#include "bubble_sorter.h"
#include <iostream>

TEST_CASE( "Sort Class Tests (Abstract)", "[Sort]" )
{
	int arr_len = 10;
	int arr[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };

	Sorter abstractSort( string("Abstract") );
	cout << abstractSort.getName() << endl;
	abstractSort.sort( arr_len, arr );
}

TEST_CASE( "BubbleSort Class Tests", "[BubbleSort]" )
{
	int arr_len = 10;
	int arr[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	
	BubbleSorter bs;
	cout << bs.getName() << endl;
	bs.sort( arr_len, arr );
}