///
///@file     test1.cc
///@author     Jason(13933536151@163.com)
///@data     2019-02-24 19:23:1551065025
///
  #include<iostream>
//using std::cout;
//using std::cin;
//using std::endl;
 
using namespace std; 
 
int main()
{
    int total = 0,n= 0,k;
    cout << "input:\n";
    while(cin >> k)
    {
        total+=k;
        n++;
    }
    cin.clear();
    cout << "again:\n";
    while(cin>>k)
    {
        total +=k;
        n++;
    }
    cout << "total = "<<total<<"\tn="<<n<<endl;
//    return 0;
 
}
