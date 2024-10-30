#!/bin/python
# ***************************************************************************************************************************
# linked_list.py - The code defines two classes: Node and LinkedList.
#
# Node Class: This class is used to create a new node. Each node has two attributes:
#   data: It stores the data of the node.
#   next: It is a pointer that points to the next node in the linked list. By default, it is set to None.
#
# LinkedList Class: This class creates a new linked list. It has two methods:
#   insert(data): This method inserts a new node at the end of the linked list. If the linked list is empty (i.e., the
#   head is None), it will add a new node as the head. Otherwise, it will append the new node at the end.
#
# display(): This method returns all the elements in the linked list. It starts from the head of the linked list and
#   traverses through the linked list until it reaches the end (i.e., None). It adds the data of each node to the elements
#   list.
#
# ASC and DESC: These are class-level attributes defined in the LinkedList class. They are used to specify the sort order
#   in the sort method. ASC stands for ascending order, and DESC stands for descending order. You can refer to these
#   attributes as LinkedList.ASC and LinkedList.DESC when you call the sort method.
#
# sort method: This is a method of the LinkedList class. It sorts the linked list in either ascending or descending order,
#   depending on the argument passed to it. The method takes one argument, order, which should be either LinkedList.ASC or
#   LinkedList.DESC. If order is LinkedList.ASC, the method sorts the linked list in ascending order. If order is
#   LinkedList.DESC, the method sorts the linked list in descending order. The method uses a simple bubble sort algorithm
#   to sort the linked list. If the order argument is not LinkedList.ASC or LinkedList.DESC, the method prints an error
#   message and returns.
#
# The usage example creates a linked list, inserts the numbers 1, 2, and 3 into the list, and then prints these numbers. The
# output of the print statement is [1, 2, 3], which are the elements of the linked list.
# ---------------------------------------------------------------------------------------------------------------------------
# Author:       Patrik Eigenmann
# eMail:        p.eigenmann@gmx.net
# ---------------------------------------------------------------------------------------------------------------------------
# Sun 2023-12-31 File created.                                                                                 Version: 00.01
# Fri 2024-01-05 Add variables static ASC/DESC and the method sort.                                            Version: 00.02
# Fri 2024-01-05 Add parameter algorythm to sort and the methods bubble sort and quick sort.                   Version: 00.03
# ***************************************************************************************************************************

class Node:
    def __init__(self, data=None):
        self.data = data
        self.next = None

class LinkedList:
    ASC = "asc"
    DESC = "desc"
    BUBBLE_SORT = "bubble_sort"
    QUICK_SORT = "quick_sort"

    def __init__(self):
        self.head = None

    def insert(self, data):
        if not self.head:
            self.head = Node(data)
        else:
            current = self.head
            while current.next:
                current = current.next
            current.next = Node(data)

    def display(self):
        elements = []
        current_node = self.head
        while current_node:
            elements.append(current_node.data)
            current_node = current_node.next
        return elements

    def sort(self, order, algorithm):
        if self.head is None:
            return

        if order not in [self.ASC, self.DESC]:
            print(f"Order must be either '{self.ASC}' or '{self.DESC}'")
            return

        if algorithm == self.BUBBLE_SORT:
            self.bubble_sort(order)
        elif algorithm == self.QUICK_SORT:
            self.head = self.quick_sort(self.head, order)
        else:
            print(f"Algorithm must be either '{self.BUBBLE_SORT}' or '{self.QUICK_SORT}'")

    def bubble_sort(self, order):
        swapped = True
        while swapped:
            swapped = False
            node = self.head
            while node.next:
                if (order == self.ASC and node.data > node.next.data) or (order == self.DESC and node.data < node.next.data):
                    node.data, node.next.data = node.next.data, node.data
                    swapped = True
                node = node.next

    def quick_sort(self, head, order):
        if head is None or head.next is None:
            return head

        pivot_prev = None
        pivot = head
        node = head
        while node:
            if (order == self.ASC and node.data < pivot.data) or (order == self.DESC and node.data > pivot.data):
                if pivot_prev:
                    pivot_prev.next = node.next
                else:
                    head = node.next
                node.next = pivot
                pivot_prev = node
                node = pivot.next
            else:
                pivot_prev = pivot
                pivot = pivot.next
                node = node.next

        head = self.quick_sort(head, order)
        pivot.next = self.quick_sort(pivot.next, order)
        return head

# Usage
linked_list = LinkedList()
linked_list.insert(3)
linked_list.insert(23)
linked_list.insert(1)



print(linked_list.display())  # Output: [1, 2, 3]

linked_list.sort(LinkedList.ASC, LinkedList.BUBBLE_SORT)

print(linked_list.display())  # Output: [1, 2, 3]

linked_list.sort(LinkedList.DESC, LinkedList.BUBBLE_SORT)

print(linked_list.display())  # Output: [1, 2, 3]
