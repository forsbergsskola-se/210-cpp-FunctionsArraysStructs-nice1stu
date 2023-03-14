#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

int main()
{
    // just add your code here
    // the following code creates a leak:
    char* name = new char[100];
    _CrtDumpMemoryLeaks();
    return 0;
}