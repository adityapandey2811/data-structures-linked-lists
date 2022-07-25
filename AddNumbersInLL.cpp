#include <bits/stdc++.h>
#include "Headers/ll.h"
using namespace std;
void addZeros(node **num, int n)
{
    node *temp = NULL;
    while (n--)
    {
        temp = new node();
        temp->data = 0;
        temp->next = *num;
        *num = temp;
    }
}
void append(node **num1, node **num2)
{
    int l1 = length(*num1), l2 = length(*num2);
    if (l1 == l2)
    {
        addZeros(num2, 1);
        addZeros(num1, 1);
    }
    else if (l1 > l2)
    {
        addZeros(num2, (l1 - l2) + 1);
        addZeros(num1, 1);
    }
    else
    {
        addZeros(num1, (l2 - l1) + 1);
        addZeros(num2, 1);
    }
}
node *sum(node *num1, node *num2)
{
    if (num1 == NULL)
        return NULL;
    node *temp = new node();
    temp->next = sum(num1->next, num2->next);
    temp->data = num1->data + num2->data;
    return temp;
}
int main()
{
    node *num1 = NULL, *num2 = NULL, *num3 = NULL, *temp = NULL;
    for (int i = 0; i < 3; i++)
    {
        num1 = insert(num1, i);
    }
    for (int i = 0; i < 5; i++)
    {
        num2 = insert(num2, i + 3);
    }
    display(num1);
    display(num2);
    append(&num1, &num2);
    num3 = sum(num1, num2);
    if (num3->data == 0)
    {
        temp = num3;
        num3 = num3->next;
        free(num3);
    }
    display(num3);
    return 0;
}
