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

//




    HANDLE outputHandle= GetStdHandle(STD_OUTPUT_HANDLE);

    system("cls");
    for (int i=0; i < x; i++)
    {
        // hier muss interger sein und keine array fehld
        // zeihst du ?
        // du hast string in der Array drin und kein integer
        SetConsoleTextAttribute(outputHandle, colors[waehler[i]]);
        // if( partei[i]== 0)
        // {
        // SetConsoleTextAttribute(outputHandle, 4);
        // }
        // if( partei[i]== 1)
        // {
        // SetConsoleTextAttribute(outputHandle, 7);
        // }


        cout<< waehler[i];
        if( (i+1) % width == 0)
        // if( (i+1) % width_of_the_column == 0)
        {
            cout<<endl;
        }
//        {
//            if(arr[i] != 0 || arr[i] !=1)
//            {
//                isZero = false;
//            }
//            if(isZero)
//            {
//                exit(0);
//            }
//        }
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
   // int seconds = 30;// bruder wie willst simulation machen ohne das Program im abläuf zu bringen ?

    time_t now = time(nullptr);
   // time_t endwait = now + seconds;
    for (i=0; i<arrayLength; i++)
    {
        partei[i]= rand()% numberOfParties;
    }


// for (i=0; i<arrayLength; i++)
// {
// SetConsoleTextAttribute(outputHandle, colors[partei[i]]);
// cout<< partei[i];
// if( (i+1) % width_of_the_column == 0) {
// cout<<endl;
// }
// }

// for (;;)

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


            // int k=width_of_the_column;
            // if(rand()%2 == 0)
            // {
            // //rechts
            // j = 1;
            // }
            // else if (k = 50)
            // {
            // //oben

            // }
            // else if (k = -50)
            // {
            // //unten

            // }
            // else
            // {
            // //links
            // j = -1;
            // }

            int direction = rand()%2;

            if(direction == 0)

            {
                //rechts
                j = 1;
            }
            // else if (direction == 1)
            // {
            // //oben
            // j -= 50;
            // }
            // else if (direction == 2)
            // {
            // //unten
            // j += 50;
            // }
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

