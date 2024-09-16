#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev_node;
    struct Node *next_node;
};

struct Node* create_node(int data);
struct Node* insert_node(struct Node* node, int data); // 이전 노드를 찾아야한다.
void delete_node(struct Node* node);
void print_node(struct Node* head);
int count_node(struct Node* head);

int main() {
    struct Node *node1 = create_node(100);
    struct Node *node2 = insert_node(node1, 200);
    struct Node *node3 = insert_node(node2, 300);
    struct Node *node4 = insert_node(node2, 400);
    print_node(node1); // 100, 200, 400, 300
    delete_node(node2);
    print_node(node1); // 100, 400, 300

    printf("total : %d \n", count_node(node1));
}

struct Node* create_node(int data){
    struct Node *new_node;
    new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->prev_node = new_node;
    new_node->next_node = new_node;
    return new_node;
}

struct Node* insert_node(struct Node* node, int data){
    struct Node *next = node->next_node;

    struct Node *new_node;
    new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->prev_node = node;
    new_node->next_node = next;

    node->next_node = new_node;
    return new_node;
}

void delete_node(struct Node* node){
    node->prev_node->next_node = node->next_node;
    node->next_node->prev_node = node->prev_node;
    free(node);
}

void print_node(struct Node* from){
    printf("%d ", from->data);
    struct Node* next = from->next_node;
    while (next != from)
    {
        printf("%d ", next->data);
        next = next->next_node;
    }
    printf("\n");
}

int count_node(struct Node* head){
    int count = 1;
    struct Node* next = head->next_node;
    while (next != head)
    {
        next = next->next_node;
        count++;
    }
    return count;
}