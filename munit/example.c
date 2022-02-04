#include "munit.h"

MunitResult assert_examples(const MunitParameter params[], void* data)
{
	munit_assert(3 != 2);
	munit_assert_int(1, == , 1);
	munit_assert_char('c', !=, 'b');
	munit_assert_size(strlen("dinosaur"), ==, strlen("giraffes"));

	return MUNIT_OK;
}

MunitResult more_assert_examples(const MunitParameter params[], void* data)
{
	int iRandom_Number = munit_rand_int_range(0, 155);
	munit_assert_int(iRandom_Number, <=, 155);
	munit_assert_int(iRandom_Number, >=, 0);
	
	return MUNIT_OK;
}

MunitTest test_examples[] = 
{
	{ "/assert", assert_examples, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
	{ "/more-asserts", more_assert_examples, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}
};

static const MunitSuite assert_suite = 
{
	"/tests",
	test_examples,
	NULL,
	1,
	MUNIT_SUITE_OPTION_NONE
};

int main_munit_example(int argc, char* argv[MUNIT_ARRAY_PARAM(argc + 1)])
{
	return munit_suite_main(&assert_suite, (void*) "unit", argc, argv);
}