using namespace std;

#include "sorter.h"
#include "bubble_sorter.h"
#include <iostream>

int main(int argc, char const *argv[])
{
	int arr_len = 10;
	int arr[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };

	Sorter abstractSort( string("Abstract") );
	cout << abstractSort.getName() << endl;
	abstractSort.sort( arr_len, arr );

	BubbleSorter bs;
	cout << bs.getName() << endl;
	bs.sort( arr_len, arr );
	return 0;
}