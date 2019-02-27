///
///@file     String.cc
///@author     Jason(13933536151@163.com)
///@data     2019-02-26 19:56:1551239776
///
  
#include<iostream>
#include<string.h>
#include<stdio.h>
using std::cout;
using std::cin;
using std::endl;
using std::string; 
class String{
    public:
        String()
        //: _pstr(new char[strlen(_pstr)+1]())//这里是进行传参的构造函数
        : _pstr(new char[1]())//通过构造函数对字符指针初始化
        //数组后面加一个小括号就直接赋值为'/0'
        {
            //string s = "Hi Rebecca";
            //_pstr =&s;
            *_pstr='*';//
            cout << "String()" << endl;//只要新建一个String对象就会自动执行构造函数
            //这里的cout 是为了验证是否自动执行构造函数。
        }

        String(const char * pstr)
        : _pstr(new char[strlen(pstr)+1]())
          //数组后面不加小括号的时候可以没有进行初始化
          //这里是进行传参的构造函数
          //传递的参数是字符串的首地址，也就是指向字符串的指针。
          //新建空间的时候比字符串长度大1
        {
            cout << "String(const char *)"<<endl;
            strcpy(_pstr,pstr);//执行复制
        }

        String(const String & rhs)//引用String对象rhs
        : _pstr(new char[strlen(rhs._pstr)+1]())
        {
            strcpy(_pstr,rhs._pstr);
        }//同上面传递字符串指针的作用是一样的

        //s1=s2;
        String & operator = (const String &rhs)
        {
            if(this !=&rhs)//自复制
            {
                delete [] _pstr;//回收左操作数的空间

                _pstr = new char [strlen(rhs._pstr)+1]();
                strcpy(_pstr,rhs._pstr);
            }
            return *this;
        }

        ~String()
        {
            delete [] _pstr;
            cout << "~String()"<<endl;
        }

        void print() const
        {
            cout<< "print() 1111"<<endl;//测试cout<< _pstr<<endl;是否执行
            cout << _pstr << endl;//当cout 执行打印空指针的时候，程序直接崩了
            //即当_pstr为空指针的时候，程序直接蹦了
            cout<< "print() 2222"<<endl;//测试cout<< _pstr<<endl;是否执行
        }

    private:
        char * _pstr;
};
 
int main()
{
    String s1;
    s1.print();//这里s1._pstr里面的内容为空，不做任何输出
    String s2("hello,world");
    s2.print();

    return 0;
 
}
