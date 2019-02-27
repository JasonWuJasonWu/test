///
///@file     Stack.cc
///@author     Jason(13933536151@163.com)
///@data     2019-02-26 21:18:1551244685
///
  
#include<iostream>
using std::cout;
using std::cin;
using std::endl;
 
class Stack
{
public:
    Stack(int size= 10)
    : _top(-1)
    , _size(size)
    , _array(new int [_size]())
    {}

    bool full() const
    {
        return _top == _size -1;
    }

    bool empty() const
    {
        return _top == -1;
    }

    int top() const
    {
        return _array[_top];
    }

    void push(int number)
    {//实现push操作的时候，要考虑到两种情况，
        //1、栈未满
        //2、栈满了，不能进行入栈操作
        if(!full())
        {
            _array[++_top]=number;//top指针先加一，再赋值
        } 
        else
        {
            cout << "stack has full, cannot push any element!"<<endl;
        }
    }

    void pop()
    {
        if(!empty())
        {
            cout << "出栈元素为："<< _array[_top]<<'\t';
            --_top;//top指针自减一
        }
        else
        {
            cout << "stack has empty"<<endl;
        }
    }

    ~Stack()
    {
        delete [] _array;
    }

private:
    int _top;
    int _size;
public:
    int * _array;

};

int main(void)
{
    Stack stack;
    cout << "此时栈是否为空？"<< stack.empty()<< endl;
    cout << "第一次入栈操作后，栈顶元素：";
    stack.push(1);
    cout << stack.top()<<endl;
    cout << "此时栈是否为空？"<< stack.empty()<< endl;
    
   for (int idx =2;idx != 11; ++idx)
   {
       for(int i=0;i<idx;i++)
       {
           cout << stack._array[i];
       }
       cout << endl;
       cout << "第"<<idx<<"次入栈操作前，栈顶元素："<<stack.top()<<'\t';
       stack.push(idx);
       cout << "第"<<idx<<"次入栈操作后，栈顶元素："<<stack.top()<<endl;//每入一次栈，打印一次栈顶元素
   } 
    cout << "此时栈是否已满？"<< stack.full()<< endl;
    stack.push(100);    
    while(!stack.empty())
    {
        cout <<"出栈前的栈顶元素："<< stack.top()<<'\t';
        stack.pop();
        cout << "\t\t出栈后的栈顶元素：\t"<<stack.top()<<endl;
    }
    cout << "此时栈是否为空？"<< stack.empty() <<endl;
    stack.pop();
    return 0;
}
