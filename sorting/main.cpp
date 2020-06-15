#include "bubble_sorter.h"
#include "selection_sorter.h"
#include "insertion_sorter.h"

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
	return 0;
}