#include <windows.h>
#include <time.h>

int main()
{
    srand(time(nullptr));

    int arr[400];
    for (int i=0; i<400 ; i++)
    {
        arr[i]= rand()% 2;
    }

    int i;
    i = 1;

    while (true)
    {
        if (arr[i] != arr[i-1] || i>=400)
        {
            break;
        }
        i++;
    }
}

