// Code written by Aaron Bloomfield, 2014
// Released under a CC BY-SA license
// This code is part of the https://github.com/aaronbloomfield/pdr repository

#include <iostream>
#include "heap.h"
#include "huffmanNode.h"
#include <vector>
using namespace std;

// default constructor
heap::heap() : heapSize(0) {
    huffHeap.push_back(0);
}

// builds a heap from an unsorted vector
heap::heap(vector<huffmanNode*> vec) : heapSize(vec.size()) {
    huffHeap = vec;
    huffHeap.push_back(huffHeap[0]);
    huffHeap[0] = 0;
    for (int i = heapSize/2; i > 0; i--) {
        percolateDown(i);
    }
}

// the destructor doesn't need to do much
heap::~heap() {
}

void heap::insert(huffmanNode* x) {
    // a vector push_back will resize as necessary
    huffHeap.push_back(x);
    // move it up into the right position
    percolateUp(++heapSize);
}

void heap::percolateUp(int hole) {
    // get the value just inserted
    huffmanNode* x = huffHeap[hole];
    // while we haven't run off the top and while the
    // value is less than the parent...
    for ( ; (hole > 1) && (x < huffHeap[hole/2]); hole /= 2) {
        huffHeap[hole] = huffHeap[hole/2]; // move the parent down
    }
    // correct position found!  insert at that spot
    huffHeap[hole] = x;
}

huffmanNode* heap::deleteMin() {
    // make sure the heap is not empty
    if (heapSize == 0) {
        throw "deleteMin() called on empty heap";
    }

    // save the value to be returned
    huffmanNode* ret = huffHeap[1];
    // move the last inserted position into the root
    huffHeap[1] = huffHeap[heapSize--];
    // make sure the vector knows that there is one less element
    huffHeap.pop_back();
    // percolate the root down to the proper position
    if (!isEmpty()) {
        percolateDown(1);
    }
    // return the old root node
    return ret;
}

void heap::percolateDown(int hole) {
    // get the value to percolate down
    huffmanNode* x = huffHeap[hole];
    // while there is a left child...
    while (hole*2 <= heapSize) {
        int child = hole*2; // the left child
        // is there a right child?  if so, is it lesser?
        if ((child+1 <= heapSize) && (huffHeap[child+1]->freq < huffHeap[child]->freq)) {
            child++;
        }
        // if the child is greater than the node...
        if (x->freq > huffHeap[child]->freq) {
            huffHeap[hole] = huffHeap[child]; // move child up
            hole = child;             // move hole down
        } else {
            break;
        }
    }
    // correct position found!  insert at that spot
    huffHeap[hole] = x;
}

huffmanNode* heap::findMin() {
    if (heapSize == 0) {
        throw "findMin() called on empty heap";
    }
    return huffHeap[1];
}

unsigned int heap::size() {
    return heapSize;
}

void heap::makeEmpty() {
    heapSize = 0;
    huffHeap.resize(1);
}

bool heap::isEmpty() {
    return heapSize == 0;
}

void heap::print() {
    cout << "(" << huffHeap[0] << ") ";
    for (int i = 1; i <= heapSize; i++) {
        cout << huffHeap[i] << " ";
        // next line from http://tinyurl.com/mf9tbgm
        bool isPow2 = (((i+1) & ~(i))==(i+1))? i+1 : 0;
        if (isPow2) {
            cout << endl << "\t";
        }
    }
    cout << endl;
}


