#include <iostream>
#include <string>
using namespace std;

struct Node
{
    int Data;
    Node* pNext;
};

struct stack
{
    Node* pHead = nullptr;
    Node* pTail = nullptr;
};

bool empty(stack s)
{
    return s.pHead == nullptr;
}

bool push(stack& s, int value)
{
    Node* newNode = new Node{ value, nullptr };
    if (!newNode)
        return false;

    if (s.pHead == nullptr)
    {
        s.pHead = newNode;
        s.pTail = newNode;
    }
    else
    {
        newNode->pNext = s.pHead;
        s.pHead = newNode;
    }
    return true;
}

int pop(stack& s)
{
    if (!empty(s))
    {
        Node* temp = s.pHead;
        int poppedValue = temp->Data;
        s.pHead = s.pHead->pNext;
        delete temp;
        if (s.pHead == nullptr)
            s.pTail = nullptr;
        return poppedValue;
    }
    return -1; // Indicate an empty stack
}

int top(stack& s)
{
    if (!empty(s))
    {
        return s.pHead->Data;
    }
    return -1; // Indicate an empty stack
}

void Testing_Push_Pop_Top_Stack(stack& s)
{
    int a;
    string x;

    while (true)
    {
        cin >> a;

        if (a == -1)
            break;

        if (a == 0)
        {
            int poppedValue = pop(s);
            if (poppedValue != -1)
            {
                x += to_string(poppedValue) + " ";
            }
        }
        else
        {
            push(s, a);
        }
    }
    cout << "output: " << x << endl;
    cout << "top: ";
    int topValue = top(s);
    if (topValue != -1)
        cout << topValue << endl;
}

int main()
{
    stack s;
    Testing_Push_Pop_Top_Stack(s);
    return 0;
}
