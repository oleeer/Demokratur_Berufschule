#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <ctime>
#include <time.h>
#include <cstdlib>
#include <stdlib.h>     /* srand, rand */
#include <time.h>

using namespace std;

void Ausgabe(int waehler[], int x, const int width)
{
    int colors[] = {4,7,9,12,14};

    HANDLE outputHandle= GetStdHandle(STD_OUTPUT_HANDLE);

    system("cls");
    for (int i=0; i < x; i++)
    {

        SetConsoleTextAttribute(outputHandle, colors[waehler[i]]);

        cout<< waehler[i];
        if( (i+1) % width == 0)

        {
            cout<<endl;
        }

    }
}

int main()
{

    const int arrayLength = 400;
    int partei[arrayLength];
    const int numberOfParties = 5;
    bool isZero = true;
    int d=0;
    int i=0;
    const int width_of_the_column = 20;
    srand (time(nullptr));
   // int seconds = 30
    time_t now = time(nullptr);
   // time_t endwait = now + seconds;
    for (i=0; i<arrayLength; i++)
    {
        partei[i]= rand()% numberOfParties;
    }

//    while(now < endwait)
    while (true)
    {
        isZero = true;
        for (int i=1; i < arrayLength; i++)
        {
            if(partei[i] != partei[i-1] || i>=400)
            {
                isZero = false;
                break;
            }
        }

        Ausgabe(partei, arrayLength, width_of_the_column);

        if(isZero == true)
        {
            break;

            //ERFOLG
        }


//        Sleep(50);

        for (int c=0; c<999 ; c++)
        {
            i = rand()% arrayLength; // zufälliger Bürger, ausgewählt aus 400
            int j=0;

            int direction = rand()%2;

            if(direction == 0)

            {
                //rechts
                j = 1;
            }

            else
            {
                //links
                j = -1;
            }

            int person2 = i+j;

            if (person2 <0)
            {
                person2 = arrayLength-1;
            }
            else if (person2 >=arrayLength)
            {
                person2 = 0;
            }

            if(partei[i] != partei[person2])
            {
                if ((rand()%2) == 0)
                {
                    partei[i] = partei[person2];
                }
                else
                {
                    partei[person2] = partei[i];
                }

            }

            now = time(nullptr);

        }
    }
    return 0;
}

