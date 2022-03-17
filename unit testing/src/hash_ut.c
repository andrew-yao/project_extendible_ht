#include "../../include/c_hash.h"
#include "../include/c_hash.h"

static MunitResult
create_hash_table(const MunitParameter params[], void* data) {
    // Arrange
    h_table* hash_table;
    // Act
    hash_table = init_table(15, NULL);
    // Assert
	munit_assert_ptr(hash_table, !=, NULL);

    return MUNIT_OK;
}