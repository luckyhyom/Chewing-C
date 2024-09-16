#include <stdio.h>
#include <stdlib.h>

/*
    10분 남음!
    이런 핵심에서 살짝 벗어난 호기심이 공부할때는 도움이 될수도 있는건가?

    Q1. 함수에서 문자열이나 구조체를 포인터가 아닌 그대로 반환하도록 구현 가능한가? (필요없는 기능이지만)
*/
struct Node
{
    int data;
    struct Node *next_node;
};

struct Node* create_node(int data);
struct Node* insert_node(struct Node* node, int data); // 이전 노드를 찾아야한다.
void delete_node(struct Node* node, struct Node* head);
void print_node(struct Node* head);


int main() {
    struct Node *node1 = create_node(100);
    struct Node *node2 = insert_node(node1, 200);
    struct Node *node3 = insert_node(node2, 300);
    struct Node *node4 = insert_node(node2, 400);
    print_node(node1); // 100, 200, 400, 300
    delete_node(node2, node1);
    print_node(node1); // 100, 400, 300
}

struct Node* create_node(int data){
    struct Node *new_node;
    new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next_node = NULL;
    return new_node;
}

struct Node* insert_node(struct Node* node, int data){
    struct Node *next = node->next_node;

    struct Node *new_node;
    new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next_node = next;

    node->next_node = new_node;
    return new_node;
}

void delete_node(struct Node* node, struct Node* head){
    struct Node* next = head;

    if(node == head) {
        free(head);
    }

    while (next)
    {
        if(next->next_node == node) {
            next->next_node = node->next_node;
            free(node);
        }
        next = next->next_node;
    }
}

void print_node(struct Node* from){
    struct Node* next = from;
    while (next)
    {
        printf("%d ", next->data);
        next = next->next_node;
    }
    printf("\n");
}