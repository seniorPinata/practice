#include "ArrayGraph.h"
#include "HashGraph.h"

int main(int argc, char const *argv[])
{
	ArrayGraph ag;
	ag.unittest();

	HashGraph hg;
	hg.unittest();
	return 0;
}