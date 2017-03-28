#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct node {
    void *data;
    struct node *next;
};

struct list {
    int elem_size;
    int list_size;
    struct node *head;
    struct node *tail;
    void (*free)(void *);
};

void list_create(struct list *list, int elem_size, void (*free_funct)(void *));
void list_delete(struct list *list);

void list_prepend(struct list *list, void *data);
void list_append(struct list *list, void *data);
int list_size(struct list *list);

void list_for_each(struct list *list, int (*list_iterator)(void *));
void list_head(struct list *list, void *data);
void list_tail(struct list *list, void *data);

void list_dequeue_head(struct list *list, void *data);
void list_dequeue_tail(struct list *list, void *data);

#endif /* LINKED_LIST_H */
