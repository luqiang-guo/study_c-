#include <iostream>

class Test{
public:
    Test(int a): a_(a) { }

    class ManagerTest{
    public:
        ManagerTest(int m_a) {
            printf("m_a = %d \n", m_a);
        }
    };


int a_;
};

void test(void)
{
    Test t{5};
    Test::ManagerTest m_t{t.a_};
}

int main(void)
{
    test();
    return 0;
}