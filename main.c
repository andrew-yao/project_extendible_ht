#include <stdio.h>

#define _PROJECT_

int main_project(int argc, char* argv[]);
int main_testing(int argc, char* argv[]);
int main_munit_example(int argc, char* argv[]);

int main(int argc, char* argv[])
{
	#if defined( _PROJECT_ )
		return main_project(argc, argv);
	#elif defined( _TEST_ )
		return main_testing(argc, argv);
	#elif defined( _EXAMPLE_ )
		return main_munit_example(argc, argv);
	#else
		printf("no main() defined\n");
	#endif // _PROJECT_
}