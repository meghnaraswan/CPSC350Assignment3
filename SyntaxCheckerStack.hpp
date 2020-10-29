

#ifndef SyntaxCheckerStack_hpp
#define SyntaxCheckerStack_hpp

#include <stdio.h>
#include <string>

using namespace std;

#endif /* SyntaxCheckerStack_hpp */

template <class T> //template to operate on generic types
class GenStack{
    public:
        GenStack(); //default constructor
        GenStack(int maxSize); //overloaded constructor
        ~GenStack(); //destructor
    
        //functions
        void push(const T&);
        T pop();
        T peek();
        bool isFull();
        bool isEmpty();
        int getSize();
        void readFile(string fileString);
        void print();
        
        //attributes
        int top; //top of stack
        int mSize; //number of elements in the stack
        T* myArray; //pointer for stack
};
