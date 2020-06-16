#include "bubble_sorter.h"
#include "selection_sorter.h"
#include "insertion_sorter.h"
#include "merge_sorter.h"

int main(int argc, char const *argv[])
{
	BubbleSorter bs;
	bs.set_log_level( LOG_LEVEL_INFO );
	bs.unittest();

	SelectionSorter ss;
	ss.set_log_level( LOG_LEVEL_INFO );
	ss.unittest();

	InsertionSorter is;
	is.set_log_level( LOG_LEVEL_INFO );
	is.unittest();

	MergeSorter ms;
	ms.set_log_level( LOG_LEVEL_INFO );
	ms.unittest();
	return 0;
}