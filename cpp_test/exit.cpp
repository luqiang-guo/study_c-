# include <iostream>
# include <unistd.h>

class A
{
private:
    /* data */
public:
    A() {printf("init -->\n");}
    ~A() {printf("close -->\n");}
};



int main() {

    A a;
    _exit(-1);
    return 0;
}