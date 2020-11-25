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

void LinkedList::remove(double value)
{
    ListNode *nodePtr, *previous;
    // If the list is empty, do nothing
    if(!head) return;

    // Determine if the first node is the one to delete
    if(head->value == value)
    {
        nodePtr = head;
        head = head->next;
        delete nodePtr;
    } else
    {
        // Initialize nodePtr to the head of the list
        nodePtr = head;

        // Skip nodes whose value member is not value
        while(nodePtr != nullptr && nodePtr->value != value)
        {
            previous = nodePtr;
            nodePtr = nodePtr->next;
        }

        // Link the previous node to the node after
        // nodePtr, then delete nodePtr
        if(nodePtr)
        {
            previous->next = nodePtr->next;
            delete nodePtr;
        }
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


/**
 * If the position is zero, the start of the list, then use add() to
 * add the element to the front of the list.
 * Otherwise set up a current and previous pointers to ListNode.
 * Starting at the head, index zero, loop through each node in the list
 * until the current node's next pointer points to null, which is the
 * last node in the list. While traversing the list, check if the index
 * matches the position requested. If so, set the previous node's next
 * pointer to point to the new node, with the value and pointing to the
 * current node. If the index does not match the position, then store
 * the current node's address, move to the next node, and increment the
 * index. Then check again if the index matches the position. If the
 * last node is reached without matching the position, then insert the
 * new node at the end of the list.
 * @param value New double value to insert in the list
 * @param pos The position in the list to insert the new node
 */
void LinkedList::insert(double value, int pos)
{
    if(pos == 0)
    {
        add(value);
    } else {
        ListNode *nodePtr = head, *previous = nullptr;
        int index = 0;
        while(nodePtr->next != nullptr)
        {
            if(pos == index) {
                previous->next = new ListNode(value, nodePtr);
                return;
            }
            previous = nodePtr;
            nodePtr = nodePtr->next;
            index++;
        }
        nodePtr->next = new ListNode(value);
    }
}