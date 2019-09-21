#include <iostream>

class stack{
    private:
        int *arr;
        int size;
        int last;
    public:
        stack(int size = 10);   // Use default size of 10 if no size is provided
        void push(int element);   // Push an element to top of the array
        void pop();
        void peek();
};

stack::stack(int size=10){
    this->size = size;
    this->arr = new int[this->size];
    this->last = -1;
};

void stack::push(int element){
  // Under progress
}
