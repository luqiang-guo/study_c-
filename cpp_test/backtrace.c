

#include<stdio.h>

#include<stdlib.h>

#include<unistd.h>
#include<execinfo.h>

// void print_stacktrace()
// {
//     int size = SIZE;
//     void * array[SIZE];
//     int stack_num = backtrace(array, size);
//     char ** stacktrace = backtrace_symbols(array, stack_num);
	
//     for (int i = 0; i < stack_num; ++i)
//     {
//         printf("%s\n", stacktrace[i]);
//     }
//     free(stacktrace);
// }

void print_stacktrace(void)
{
#define SIZE 1024
	int j, nptrs;
	void *buffer[SIZE];
	char **strings;

	nptrs = backtrace(buffer, SIZE);
	printf("backtrace() returned %d addresses\n", nptrs);
	/* The call backtrace_symbols_fd(buffer, nptrs, STDOUT_FILENO)
	 *  would produce similar output to the following: */

	strings = backtrace_symbols(buffer, nptrs);

	if (strings == NULL) {
		perror("backtrace_symbols");
		exit(EXIT_FAILURE);
	}

	for (j = 0; j < nptrs; j++)
		printf("%s\n", strings[j]);

	free(strings);

}

void myfunc2 (void)
{

	print_stacktrace();

}



void myfunc(int ncalls)
{

	if (ncalls > 1)

		myfunc(ncalls - 1);

	else

		myfunc2();

}



int main(int argc,char *argv[])
{

	if (argc != 2) {

		fprintf(stderr,"%s num-calls\n", argv[0]);

		exit(EXIT_FAILURE);

	}

	myfunc(atoi(argv[1]));

	exit(EXIT_SUCCESS);

}
