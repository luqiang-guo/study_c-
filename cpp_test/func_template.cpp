#include <iostream>


void a(void) {
    printf("--> a\n");
}

void b(void) {
    printf("--> b\n");
}

// template<typename F>
// void test(F* func) {
//     func();
// }

using Func = void(void);

template<Func func>
void test() {
    func();
}
int main(void) {
    test<a>();
    return 0;
}