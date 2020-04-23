# Assign3
LinkedLists
1 Use the following Node definition for problems 1, 2, and 3:
struct Node{
typedef int Item;
Item data;
Node *link;
}
1.1 Write a function to concatenate two linked lists. Given lists l1 = (2, 3, 1) and l2 = (4, 5), after return from
concatenate(l1,l2) the list l1 should be changed to be l1 = (2, 3, 1, 4,5). Your function should not change
l2 and should not directly link nodes from l1 to l2 (i.e. the nodes inserted into l1 should be copies of the
nodes from l2.)
void concatenate(Node*& h1, Node* h2)
//
// Precondition: h1 and h2 are head pointers of linked lists.
// The lists may be empty or non-empty.
// Postcondition: A copy of list h2 is concatenated (added to the end)
// of list h1. List h2 should be unchanged by the function.
// NOTE: The nodes added to the list h1 must be copies of the
// nodes in list h2.
1.2 Write a function to insert a number as the new ith node of a linked list. Nodes initially in positions
𝑖, 𝑖 + 1, … , 𝑛 should be shifted to positions 𝑖 + 1, 𝑖 + 2, … , 𝑛 + 1. Thus, the length of the list will increase
by 1. If the original list contains fewer that 𝑖 − 1 nodes, then the number should be inserted at end of
the list.
void insertith(Node*& head_ptr, int value, size_t i);
//
// Precondition: head_ptr is the head pointer of a linked list.
// The list may be empty or non-empty.
//
// Postcondition: The number value is inserted as the ith member
// of the list head_ptr. If the list head_ptr has fewer than i-1 nodes
// in it, then value is inserted as the last node in the list.
1.3 Write a function to remove duplicate entries in a linked list. For example, given the list (5, 2, 2, 5, 3, 9, 2)
as input, your function should change the list so that on return from the function it contains (5, 2, 3, 9).
void removeDups ---- FILL IN ARGUMENTS -------------------
//
// Precondition: ---- FILL IN -------
//
// Postcondition: ---- FILL IN -------
//
//
2 Use the following Node definition for problem 4:
struct Node{
typedef Point3D Item;
Item data;
Node *link;
}
2.1 Write a function to calculate the length of a sequence of line segments in a polyline. A polyline is defined
by a sequence of three-dimensional points. Adjacent points in the sequence represent the line segment
that connects them. Thus, the sequence l1 = ( (0.0, 0.0, 1.0), (0.0, 0.0, 2.0), (0.0, 0.0, 3.0)) is a polyline
consisting of two segments that lie on the z axis. Both segments have length 1.0. Therefore the length
of polyline is 2.0.
double length(Node* head_ptr);
//
// Precondition: head_ptr is the head pointer of a linked list
// of three-dimensional points (p1, p2, ..., pn).
// The list may be empty or non-empty.
//
// Postcondition: The value returned is the sum of the lengths
// of the line segments (p1,p2), (p2,p3), ..., (pn-1, pn). If the
// list is empty, the function should return 0.
