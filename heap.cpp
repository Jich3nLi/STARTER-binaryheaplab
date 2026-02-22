// heap.cpp
// Peter Li

#include "heap.h"
#include <iostream>
using std::cout;

// Builds a heap from the range [start, end) using the heapify algorithm
// Should run in O(n) time
Heap::Heap(std::vector<int>::iterator start, std::vector<int>::iterator end) {
  vdata = std::vector<int>(start, end);

  for (int i = vdata.size() / 2 - 1; i >= 0; i--) {
    bubbleDown(i);
  }
}

void Heap::bubbleDown(int index) {
  int size = vdata.size();

  while (true) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && vdata[smallest] > vdata[left]) {
      smallest = left;
    } 
    
    if (right < size && vdata[smallest] > vdata[right]) {
      smallest = right;
    } 
    
    if (smallest == index) {
      break;
    }

    int temp = vdata[smallest];
    vdata[smallest] = vdata[index];
    vdata[index] = temp;
    index = smallest;
  }
}

void Heap::bubbleUp(int index) {
  while (index > 0) {
    int parent = (index - 1) / 2;
    if (vdata[parent] <= vdata[index]) {
      break;
    }
    int temp = vdata[index];
    vdata[index] = vdata[parent];
    vdata[parent] = temp;
    index = parent;
  }
}

// Pushes a value into the heap, then ensures
// the heap is correctly arranged
void Heap::push(int value) {
  vdata.push_back(value);
  bubbleUp(vdata.size() - 1);
}

// Pops the minimum value off the heap
// (but does not return it), then ensures
// the heap is correctly arranged
void Heap::pop() {
  if (vdata.empty()) {
    return;
  }
  vdata[0] = vdata.back();
  vdata.pop_back();
  bubbleDown(0);
}

// Returns the minimum element in the heap
int Heap::top() {
  return vdata[0];
}

// Returns true if the heap is empty, false otherwise
bool Heap::empty() {
  return vdata.empty();
}
