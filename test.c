#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include "unity.h"
#include "linked_list.h"

static void create_int_list(void)
{
    struct list l;
    list_create(&l, sizeof(int), NULL);
    TEST_ASSERT_NULL(l.head);
    TEST_ASSERT_NULL(l.tail);
    TEST_ASSERT_NULL(l.free);
    TEST_ASSERT_EQUAL_INT(sizeof(int), l.elem_size);
    TEST_ASSERT_EQUAL_INT(0, l.list_size);
}

static void delete_int_list(void)
{
    struct list l;
    int i;
    
    list_create(&l, sizeof(int), NULL);

    for(i = 0; i < 100; i++) {
        list_append(&l, &i);
    }
    
    TEST_ASSERT_NOT_NULL(l.head);
    TEST_ASSERT_NOT_NULL(l.tail);
    
    list_delete(&l);

    TEST_ASSERT_NULL(l.head);
    TEST_ASSERT_NULL(l.tail);
}




int main(int argc, const char *argv[])
{
    /* TODO: Run tests here. */
    UNITY_BEGIN();
    RUN_TEST(create_int_list);
    RUN_TEST(delete_int_list);
    return UNITY_END();
}
