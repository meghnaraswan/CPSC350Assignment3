

#include "SyntaxCheckerStack.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>

using namespace std;

//default constructor
template <class T>
GenStack<T>::GenStack(){
    myArray = new T[128];
    mSize = 128;
    top = -1;
}

//overloaded constructor
template <class T>
GenStack<T>::GenStack(int maxSize){
    myArray = new T[maxSize];
    mSize = maxSize;
    top = -1;
}

//destructor
template <class T>
GenStack<T>::~GenStack(){
    delete myArray;
}

//push function to add value to top of stack
template <class T>
void GenStack<T>::push(const T& data){ //evey data value added to the stack is pushed to the top of the stack
    myArray[++top] = data; //preincrement updates then evaluates
}

//pop function removes the value at the top of the stack and returns the same value
template <class T>
T GenStack<T>::pop(){ //as the values are rmoved (or popped) the top's value in the array keeps decrementing
    //check if empty before removing
    if(isEmpty()){
        cout << "stack is empty" << endl;
        return '\0';
    }
    return myArray[top--]; //post-decrement evaluates top and then update it back to -1
} //returns a generic data type

//peek function returns value that is at the top of the stack
template <class T>
T GenStack<T>::peek(){ //retuns index top from array
    return myArray[top];
} //returns a generic data type

//isFull function checks to see if stack is full depending on the maximum size assigned to the array
template <class T>
bool GenStack<T>::isFull(){ //returns top value which is the max size value minus 1
    return(top == mSize - 1);
}

//isEmpty function checks to see if the stack is empty
template <class T>
bool GenStack<T>::isEmpty(){ //if the stack is empty, then the top value is in the -1 position
    return(top == -1);
}

//getSize returns the maximum size of the stack
template <class T>
int GenStack<T>::getSize(){ //total size will be the top value plus 1
    return top + 1;
}

//print function prints the values in the stack
template <class T>
void GenStack<T>::print(){
    cout << "GenStack :: print()" << endl;
    for (int i = top; i >= 0; i--) { //iterate through from the top value to 0, returning the values in the array at the according indexes
        cout << myArray[i] << endl;
    }
}

//this is to explicitly instantiate the template
template class GenStack<char>;

