#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "linked_list.h"

void list_create(struct list *list, int elem_size, void (*free_funct)(void *))
{
    assert(elem_size > 0);
    
    list->elem_size = elem_size;
    list->list_size = 0;
    list->head = NULL;
    list->tail = NULL;
    list->free = free_funct;
}

void list_delete(struct list *list)
{
    struct node *target;
    struct node *next_target;
    
    target = list->head;
    
    while(target) {
        next_target = target->next;
        
        if (NULL != list->free) {
            list->free(target);
        } else {
            free(target);
        }
        
        target = next_target;
    }
    
    list->head = NULL;
    list->tail = NULL;
}

void list_prepend(struct list *list, void *data)
{
    struct node *node = malloc(sizeof(*node));
    node->data = malloc(list->elem_size);
    memcpy(node->data, data, list->elem_size);
    node->next = list->head;
    list->head = node;
    
    if (NULL == list->tail) {
        list->tail = list->head;
    }
    
    list->list_size++;
}

void list_append(struct list *list, void *data)
{
    struct node *node = malloc(sizeof(*node));
    node->data = malloc(list->elem_size);
    memcpy(node->data, data, list->elem_size);
    node->next = NULL;
    if (NULL != list->tail) {
        list->tail->next = node;
    } else {
        list->head = node;
    }
    
    list->tail = node;
    list->list_size++;
}

int list_size(struct list *list)
{
    return list->list_size;
}

void list_for_each(struct list *list, int (*list_iterator)(void *))
{
    int result;
    struct node *current_node;
    
    assert(NULL != list_iterator);
    
    result = 0;
    current_node = list->head;
    
    while(current_node && 0 == result) {
        result = list_iterator(current_node->data);
        current_node = current_node->next;
    }
}

void list_head(struct list *list, void *data)
{
    data = malloc(list->elem_size);
    memcpy(data, list->head->data, list->elem_size);
}

void list_tail(struct list *list, void *data)
{
    data = malloc(list->elem_size);
    memcpy(data, list->tail->data, list->elem_size);
}

void list_dequeue_head(struct list *list, void *data)
{
    struct node *temp;
    
    data = malloc(list->elem_size);
    memcpy(data, list->head->data, list->elem_size);
    temp = list->head;
    list->head = temp->next;
    if (NULL != list->free) {
        list->free(temp);
    } else {
        free(temp);
    }
}

