#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* addLists(struct Node* l1, struct Node* l2) {
    struct Node* dummy = (struct Node*)malloc(sizeof(struct Node));
    struct Node* curr = dummy;
    int carry = 0;

    while (l1 || l2 || carry) {
        int sum = (l1 ? l1->data : 0) + (l2 ? l2->data : 0) + carry;
        carry = sum / 10;
        curr->next = (struct Node*)malloc(sizeof(struct Node));
        curr->next->data = sum % 10;
        curr->next->next = NULL;
        curr = curr->next;
        l1 = l1 ? l1->next : NULL;
        l2 = l2 ? l2->next : NULL;
    }

    struct Node* result = dummy->next;
    free(dummy);
    return result;
}

int main() {
    struct Node n1 = { 2, NULL };
    struct Node n2 = { 4, NULL };
    struct Node n3 = { 3, NULL };
    n1.next = &n2;
    n2.next = &n3;

    struct Node m1 = { 5, NULL };
    struct Node m2 = { 6, NULL };
    struct Node m3 = { 4, NULL };
    m1.next = &m2;
    m2.next = &m3;

    struct Node* sum = addLists(&n1, &m1);
    while (sum) {
        printf("%d ", sum->data);
        sum = sum->next;
    }

    return 0;
}
