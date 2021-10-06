// AllocaSample.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// crt_alloca.c
// This program demonstrates the use of
// _alloca and trapping any exceptions
// that may occur.

#include <windows.h>
#include <stdio.h>
#include <malloc.h>

void Test(int arg1, int arg2, int arg3)
{
    int a = arg1 + arg2 + arg3;
}

int main()
{
    int     size = 1000;
    int     errcode = 0;
    void* pData = NULL;
    void* pData2 = NULL;

    // Note: Do not use try/catch for _alloca,
    // use __try/__except, since _alloca throws
    // Structured Exceptions, not C++ exceptions.

    __try {
        // An unbounded _alloca can easily result in a
        // stack overflow.
        // Checking for a size < 1024 bytes is recommended.
        if (size > 0 && size < 1024)
        {
            pData = _alloca(size);
            printf_s("Allocated %d bytes of stack at 0x%p",
                size, pData);
            Test(1, 2, 3);
            pData2 = _alloca(size);
            Test(1, 2, 3);
            pData = _alloca(size);
            Test(1, 2, 3);
            pData2 = _alloca(size);
            Test(1, 2, 3);
            pData = _alloca(size);

        }
        else
		{
            printf_s("Tried to allocate too many bytes.\n");
        }
    }

    // If an exception occurred with the _alloca function
    __except (GetExceptionCode() == STATUS_STACK_OVERFLOW)
    {
        printf_s("_alloca failed!\n");

        // If the stack overflows, use this function to restore.
        errcode = _resetstkoflw();
        if (errcode)
        {
            printf_s("Could not reset the stack!\n");
            _exit(1);
        }
    };
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
