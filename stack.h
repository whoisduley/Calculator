#ifndef STACK
#define STACK

#include <stdexcept>
#include <iostream>

using namespace std;

template <typename MyType> class Stack {
private:
	int maxSize;
	MyType* storage;
	int sp;

public:
	Stack() {
		maxSize = 10;
		storage = new MyType[maxSize];
		sp = 0;
	};
	
	void push(MyType a) {
		if(sp < maxSize) {
			storage[sp] = a;
			sp++;
		}
		else {
			int oldMax = maxSize;
			maxSize = oldMax * 1.5;
			MyType* oldStack = storage;
			storage = new MyType[maxSize];
			for(int b = 0; b < oldMax; b++) {
				*(storage + b) = oldStack[b];
			}
			delete[] oldStack;
			storage[sp] = a;
			sp++;
		}
	};

	MyType pop() {
		sp--;
		if(sp < 0) {
			throw out_of_range("The Stack is Empty");
		}
		return storage[sp];
	};

	bool isEmpty() {
		if(sp == 0) {
			return true;
		}
		else {
			return false;
		}
	};

	int size() {
		return sp+1;
	};

	// Return top of stack
	MyType top() {
		int asp = sp-1;
		if (asp < 0) {
			throw out_of_range("The Stack is Empty");
		}
		return storage[asp];
	}
};

#endif