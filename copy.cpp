#include <iostream>
#include <string>

using namespace std;

class CoMo{
public:
    CoMo(){}//Default Constructor
    CoMo(int);//Single-para Constructor
    CoMo(int, string);//Double-para Constructor
    CoMo(std::initializer_list<char>, string);//Initializer List Constructor
    ~CoMo();//Destructor
    //Copy Construction
    CoMo(const CoMo &);
    //Copy Assignment
    CoMo&operator=(const CoMo &);

    //Move Construction
    CoMo(CoMo && source);
    //Move Assignment
    CoMo& operator= (CoMo &&);

    int size;
    char * ch;
    string s;
};
CoMo::CoMo(int x):size{x},s{""}{
    ch=new char[size];
    cout << "Single-Para Constructor...." << endl;
}

CoMo::CoMo(int x, string str):size{x},s{str}
{
    ch=new char[size];
    cout << "Double-Para Constructor...." << endl;
}

CoMo::CoMo(std::initializer_list<char> list, string str)
    :s{str}
{
    size=list.size();
    ch=new char[size];
    for (int i=0;i!=size;i++){
        ch[i]=list.begin()[i];
    }
    cout << "Initializer List Constructor..." << endl;
}

CoMo::~CoMo()
{
    if(ch){
        cout << "ch = " << ch << endl;
        delete [] ch;
        cout << "Destructing the char vector..." << endl;
    }
    cout << "Destruction Completed!!" << endl;
}

CoMo::CoMo(const CoMo & source)
    :size{source.size},s{source.s}
{
    ch=new char[size];
    for (int i=0;i!=size;i++){
        ch[i]=source.ch[i];
    }
    cout << "Deep Copy Construction..." << endl;
}

CoMo& CoMo::operator= (const CoMo & source)
{
    size=source.size;
    s=source.s;
    if(!ch){delete [] ch; cout << "Deleting Target Variable Resource..." << endl;}
    ch=new char[size];
    for (int i=0;i!=size;i++){
        ch[i]=source.ch[i];
    }
    cout << "Deep Copy Assignment..." << endl;
    return *this;
}

CoMo::CoMo(CoMo && source)
    :size{source.size},ch{source.ch},s{source.s} //Initialize target object
{
    source.size=0;
    source.ch=nullptr;
    source.s="";
    cout << "Move Constructor..." << endl;
}

CoMo& CoMo:: operator= (CoMo && source){
    if (ch) {delete [] ch; cout << "Cleanup Target Resource..." << endl;} 
    //Cleanup target resource
    //Ordinary Copy Assignment
    size=source.size;
    ch=source.ch;
    s=source.s;
    //Cleanup source object
    source.size=0;
    source.ch=nullptr;
    source.s="";
    cout << "Move Assignment..." << endl;
    return *this;
}

void myprint(CoMo SC){
    cout << "Printing Elements..." << endl;
    cout << "Char Vector Size: " << SC.size << endl;
    cout << "Char Value: " << SC.ch[0] << " at the address: "
         << static_cast<void*>(SC.ch) << endl;
    cout << "String in SC is: " << SC.s << endl;
}

void myprint2(CoMo & SC)
{
    cout << "Printing Elements..." << endl;
    cout << "Char Vector Size: " << SC.size << endl;
    cout << "Char Value: " << SC.ch[0] << " at the address: "
         << static_cast<void*>(SC.ch) << endl;
    cout << "String in SC is: " << SC.s << endl;
}

CoMo MoveTest(CoMo source) {return source;}//Test Return Method

int main(){
    CoMo A{
            {'f','b','c','d','e'},"Hello"};
    CoMo B{{'g','b'},"World"};
    // CoMo B({'g','b'},"World");    

    cout << "_____________________________________" << endl;

    auto C=MoveTest(A);


    // A=B;        //Copy Assignment
    // B=move(C); 

    // CoMo C1{A};      //Copy Construction
    // CoMo C2 = A;      //Copy Construction
    // CoMo C3(A);      //Copy Construction

    // cout << "______________ Copy _______________" << endl;
    // A=B;            //Copy Assignment
    // myprint2(A);    //Copy Construction in function argument passing
    // myprint(A);
    cout << "_______________ return _______________" << endl;
    return 0;
}