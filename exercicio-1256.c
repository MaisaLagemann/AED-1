#include <stdio.h>
#include <stdlib.h>

typedef struct node
{

    int value;
    struct node *next;

} Node;

typedef struct linked_list
{

    Node *head;
    Node *tail;

} LinkedList;

void insert_to_hash(LinkedList *, const int);
unsigned hash_size;

void main()
{

    unsigned num_tests;
    Node *current;
    int num_elements, index, element;

    scanf("%u", &num_tests);

    while (num_tests--)
    {

        scanf("%u %d", &hash_size, &num_elements);

        LinkedList hash_table[hash_size];
        for (index = 0; index < hash_size; ++index)
            hash_table[index].head = NULL, hash_table[index].tail = NULL;

        for (index = 0; index < num_elements; ++index)
            scanf("%d", &element), insert_to_hash(hash_table, element);

        for (index = 0; index < hash_size; ++index)
        {
            printf("%d -> ", index);
            for (current = hash_table[index].head; current; current = current->next)
                printf("%d -> ", current->value);

            printf("\\");
            printf("\n");
        }

        if (num_tests)
            printf("\n");
    }
}

void insert_to_hash(LinkedList *hash_table, const int key)
{

    Node *new_node;
    new_node = (Node *)malloc(sizeof(Node));

    if (!new_node)
        exit(1);

    int index = key % hash_size;
    if (hash_table[index].head)
        hash_table[index].tail->next = new_node;
    else
        hash_table[index].head = new_node;

    hash_table[index].tail = new_node;
    new_node->next = NULL;
    new_node->value = key;
}