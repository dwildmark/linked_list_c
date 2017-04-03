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

static void prepend_int_list(void)
{
    struct list l;
    int i;
    int a = 10;

    list_create(&l, sizeof(int), NULL);

    for(i = 0; i < 100; i++) {
        list_append(&l, &i);
    }

    TEST_ASSERT_EQUAL_INT(0, *(int *)l.head->data);

    list_prepend(&l, &a);

    TEST_ASSERT_EQUAL_INT(10, *(int *)l.head->data);
}

static void append_int_list(void)
{
    struct list l;
    int i;
    int a = 10;

    list_create(&l, sizeof(int), NULL);

    for(i = 0; i < 100; i++) {
        list_append(&l, &i);
    }

    TEST_ASSERT_EQUAL_INT(99, *(int *)l.tail->data);

    list_append(&l, &a);

    TEST_ASSERT_EQUAL_INT(10, *(int *)l.tail->data);
}

static void size_int_list(void)
{
    struct list l;
    struct node n;
    int i;
    int a = 10;

    list_create(&l, sizeof(int), NULL);

    for(i = 0; i < 100; i++) {
        list_append(&l, &i);
    }

    TEST_ASSERT_EQUAL_INT(100, list_size(&l));

    list_prepend(&l, &a);

    TEST_ASSERT_EQUAL_INT(101, list_size(&l));

    list_dequeue_head(&l, &n);

    TEST_ASSERT_EQUAL_INT(100, list_size(&l));
}



int main(int argc, const char *argv[])
{
    UNITY_BEGIN();

    RUN_TEST(create_int_list);
    RUN_TEST(delete_int_list);
    RUN_TEST(prepend_int_list);
    RUN_TEST(append_int_list);
    RUN_TEST(size_int_list);

    return UNITY_END();
}
