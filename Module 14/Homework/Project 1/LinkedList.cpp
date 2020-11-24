//
// Created by raula on 11/22/2020.
//

#include "LinkedList.h"

LinkedList::LinkedList()
{
    head = nullptr;
}

LinkedList::~LinkedList()
{
    ListNode* nodePtr = head;
    while(nodePtr != nullptr)
    {
        // garbage keeps track of node to be deleted
        ListNode* garbage = nodePtr;
        // Move on to next node, if any
        nodePtr = nodePtr->next;
        // Delete the garbage node
        delete garbage;
    }
}

/**
 * Outputs a sequence of all values
 */
void LinkedList::print() const
{
    ListNode* nodePtr = head;
    while(nodePtr)
    {
        cout << fixed << setprecision(1) << nodePtr->value << " ";
        nodePtr = nodePtr->next;
    }
}

/**
 * Searches for value in LinkedList by traversing its node. If the
 * value is equal to the node value, then return true. Otherwise, move
 * to next node. Return false if end of LinkedList and no value matches.
 */
bool LinkedList::isMember(double value)
{
    ListNode* nodePtr = head;
    while(nodePtr)
    {
        if(value == nodePtr->value)
        {
            return true;
        }
        nodePtr = nodePtr->next;
    }
    return false;
}

/**
 * Inserts value at the front of the list
 * @param value Double value to be inserted to front of list
 */
void LinkedList::add(double value)
{
    head = new ListNode(value, head);
}

/**
 * At the current node, store the address of the next node. Then set
 * the pointer to the next node to point to the previous node. Then
 * set the previous pointer to point to the current node. Then set the
 * current node to the address of the next node, and repeat until
 * current address is null. Finally previous will store the address of
 * the last node which is now the new head of the list.
 */
void LinkedList::reverse()
{
    ListNode *nextNode, *previous = nullptr;
    while(head)
    {
        nextNode = head->next;
        head->next = previous;
        previous = head;
        head = nextNode;
    }
    head = previous;
}

/**
 * Set nodePtr and position to start of the list. Loop through each
 * node in the list until either (a) one of the node value's matches
 * the value being searched for or (b) the end of the list is reached
 * without finding the value. With each loop, move to the next node and
 * increment the position. If the value is found return the position.
 * If the end of the list is reached without finding the value, then
 * return -1.
 * @param value Search list for the double value
 * @return -1 if the value was not found. Otherwise, the position of
 * the node in which the value was found within the list.
 */
int LinkedList::search(double value)
{
    ListNode *nodePtr = head;
    int position = 0;
    while(nodePtr)
    {
        if(value == nodePtr->value)
        {
            return position;
        }
        nodePtr = nodePtr->next;
        position++;
    }
    return -1;
}

void LinkedList::insert(double value, int pos)
{
    if(pos == 0)
    {
        add(value);
    }
    ListNode *nodePtr = head;
    int index = 0;
    while (nodePtr && pos != index)
    {
        nodePtr = nodePtr->next;
        index++;
    }

}