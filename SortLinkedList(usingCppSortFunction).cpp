#include <bits/stdc++.h>
#include "Headers/ll.h"
using namespace std;
bool compare(node *a, node *b)
{
    return (a->data < b->data);
}
void sortLL(node **head)
{
    node *temp = *head;
    vector<node *> storeLL;
    while (temp != NULL)
    {
        storeLL.push_back(temp);
        temp = temp->next;
    }
    sort(storeLL.begin(), storeLL.end(), compare);
    for (int i = 0; i < storeLL.size() - 1; i++)
    {
        storeLL[i]->next = storeLL[i + 1];
    }
    storeLL[storeLL.size() - 1]->next = NULL;
    (*head) = storeLL[0];
    storeLL.clear();
}
int main()
{
    node *head = NULL;
    for (int i = 5; i >= 0; i--)
    {
        head = insert(head, i);
    }
    sortLL(&head);
    display(head);
}
