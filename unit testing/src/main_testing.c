#include "../../munit/munit.h"

MunitResult hash_creation(const MunitParameter params[], void* data)
{
	
	return MUNIT_OK;
}

MunitTest hash_testing[] = 
{
	{ "/hash", hash_creation, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    NULL
};

static const MunitSuite hash_suite = 
{
	"/tests", hash_testing,	NULL, 1, MUNIT_SUITE_OPTION_NONE
};

int main_testing(int argc, char* argv[])
{
	return EXIT_SUCCESS;
}