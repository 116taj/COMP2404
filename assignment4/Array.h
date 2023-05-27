
#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <string>
#include "defs.h"

using namespace std;

template <typename T>
class Array {

	public:
		//constructor
		Array();
				
		//destructor
		~Array();
		
		//other
		T& operator[](int i) const;
		T& operator[](int i);
		Array<T>& operator+=(T& e);		
		Array<T>& operator-=(T& e);
		int size() const;
		bool isFull() const;
		void clear();
	
	private:
		int numElements;
		T* elements;
	
};

template <class T>
Array<T>::Array(){
	elements = new T[MAX_ARR];
	numElements = 0;
}

template <class T>
Array<T>::~Array(){
}

template <class T>
Array<T>&  Array<T>::operator+=(T& t){
	if (numElements >= MAX_ARR)   return *this;
  	elements[numElements++] = t;
	return *this;
}

template <class T>
Array<T>& Array<T>::operator-=(T& t){
	int index = 0;
	while (index < numElements){
		if (t == elements[index]){
			--numElements;
			break;
		}
		++index;
	}

	while (index < numElements){
		elements[index] = elements[index + 1];
		++index;
	}
	return *this;
}

template <class T>
int Array<T>::size() const{
	return numElements;
}

template <class T>
bool Array<T>::isFull() const{
	return numElements >= MAX_ARR;
}

template <class T>
void Array<T>::clear(){
	numElements = 0;
}

template <class T>
T& Array<T>::operator[](int index){
	if (index < 0 || index >= numElements) {
		cerr<<"Array index out of bounds"<<endl;
		exit(1);
	}
	return elements[index];
}

template <class T>
T& Array<T>::operator[](int index) const{
	if (index < 0 || index >= numElements) {
		cerr<<"Array index out of bounds"<<endl;
		exit(1);
	}
	return elements[index];
}
#endif
