#include <stdio.h>
#include <string.h>

void vuln(char *str) {
    char buf[4];
    strcpy(buf, str);
    printf("child buf: %s", buf);
}

int main(int argc, char **argv) {
    puts("child started");
    vuln(argv[1]);
    return 0;
}
