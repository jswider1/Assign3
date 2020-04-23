//Class: CS 3305 Section 05
//Term: Spring 2020
//Name: Justin Swiderski
//Instructor: Pablo Ordonez
//Assignment: Assignment 3

//#include <bits/stdc++.h>
#include <map>
#include <iostream>
#include <stdio.h>
#include <cstdlib>
using namespace std;

struct Node{
    typedef int Item;
    int data;
    Node *link;
};

struct Point3D {
    double x, y, z;
};

struct Node2{
    typedef Point3D Item;
    Item data;
    Node2 *link;
};

double distance(Node2* node1, Node2* node2) {
    double sqrX = sqrt(node1->data.x - node2->data.x);
    double sqrY = sqrt(node1->data.y - node2->data.y);
    double sqrZ = sqrt(node1->data.z - node2->data.z);

    double res = sqrt(sqrX + sqrY + sqrZ);

    return res;
}

double length(Node2* head_ptr) {
    if (head_ptr == NULL || head_ptr->link == NULL) {
        return 0;
    }

    double res = 0;
    Node2* ptr = head_ptr;
    while (ptr->link != NULL) {
        res += distance(ptr, ptr->link);
        ptr = ptr->link;
    }
    return res;
}

double sqrt(double val) {
    return val * val;
}

void concatenate(Node*& h1, Node* h2) {
    Node* ptr = h1;
    while (ptr->link != NULL) {
        ptr = ptr->link;
    }
    while (h2 != NULL) {
        Node* newNode = new Node();
        newNode->data = h2->data;
        newNode->link = NULL;
        ptr->link = newNode;
        ptr = newNode;
        h2 = h2->link;
    }
}

void print(Node* h1) {
    Node* ptr = h1;
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
    printf("\n");
}

Node* newNodeWithValue(int value) {
    Node* temp = new Node();
    temp->link = NULL;
    temp->data = value;

//    printf("%d ", int(temp->data));
    return temp;
}

Node2* newNodeWithValue(double valX, double valY, double valZ) {
    Node2* temp = new Node2();
    temp->data.x = valX;
    temp->data.y = valY;
    temp->data.z = valZ;

    return temp;
}

void insertith(Node*& head_ptr, int value, size_t i) {
    Node* newNode = newNodeWithValue(value);
    if (i == 1) {
        newNode->link = head_ptr;
        head_ptr = newNode;
        return;
    }
    Node* ptr = head_ptr;
    while (--i > 2 && ptr->link != NULL) {
        ptr = ptr->link;
    }
    newNode->link = ptr->link;
    ptr->link = newNode;
}

void removeDups(Node*& head_ptr) {
    map<int, bool> exist;
    exist.clear();
    exist[head_ptr->data] = true;
    Node* ptr = head_ptr;
    while (ptr != NULL && ptr->link != NULL) {
//            printf("hello %d", ptr->link->data);
        if (exist[ptr->link->data]) {
//                printf("%d ", ptr->link->data);
            if (ptr->link->link == NULL) {
//                    printf("%d ", ptr->link->data);
                ptr->link = NULL;
            } else {
                ptr->link = ptr->link->link;
            }
        }

        if (ptr->link != NULL) {
            exist[ptr->link->data] = true;
        }

        ptr = ptr->link;
    }

//    printf("end");
}

int main() {
    Node* h1 = newNodeWithValue(1);
    Node* h2 = newNodeWithValue(2);
    Node* h3 = newNodeWithValue(3);
    Node* h4 = newNodeWithValue(4);

    Node* h5 = newNodeWithValue(5);
    Node* h6 = newNodeWithValue(6);
    Node* h7 = newNodeWithValue(7);

    h1->link = h2;
    h2->link = h3;
    h3->link = h4;
    h5->link = h6;
    h6->link = h7;
	
	print(h1);
	print(h5);
    concatenate(h1, h5);
    print(h1);
//    print(h5);

    insertith(h1, 42, 2);
    print(h1);

    Node* h8 = newNodeWithValue(8);
    Node* h9 = newNodeWithValue(9);
    Node* h10 = newNodeWithValue(10);
    Node* h11 = newNodeWithValue(9);

    h8->link = h9;
    h9->link = h10;
    h10->link = h11;
	
	print (h8);
    removeDups(h8);
    print(h8);

    Node2* h12 = newNodeWithValue(0, 0, 1);
    Node2* h13 = newNodeWithValue(0, 0, 2);
    Node2* h14 = newNodeWithValue(0, 0, 3);

    h12->link = h13;
    h13->link = h14;

    printf("%f", length(h12));
	printf("\n");

	system("pause");
    return 0;
}
