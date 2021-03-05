/*
*   MasterMind.cpp
*   Author: Vrijoni Fabio
*   Date: 05/03/21
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Mastermind
{
    private:
    int map[5];
    int test[5];

    void init()
    {
        srand (time(NULL));
        for (int i=0; i<5; i++)
        {
            map[i]= (rand () % 10)+1;
        }
    }

    public:
    Mastermind ()
    {
        init();
    }

    void stampa ()
    {
        for (int i=0; i<5; i++)
        {
            cout<<map[i]<<"\t";
        }
        cout<<endl;
    }

    void play()
    {
        cout<<"Inserisci 5 numeri interi"<<endl;
        for (int i=0; i<5; i++)
        {
            cin>>test[i];
        }

        for (int i=0; i<5; i++)
        {
            cout<<test[i]<<"\t";
        }
    }

    bool check()
    {
        int strike=0, ball=0;
        for (int i=0; i<5; i++)
        {
            for (int j=0; j<5; j++)
            {
                if (test[i]==map[j])
                {
                    if (i==j)
                    {
                        strike++;
                    }
                    else
                    {
                        ball++;
                    }
                }
            }
        }
        cout<<endl<<"Strike: "<<strike<<endl<<"Ball: "<<ball<<endl;
        return strike==5;
    }

};

int main()
{
    cout<<"Programma Mastermind avviato"<<endl;
    Mastermind m;

    m.stampa();
    do
    {
        m.play();

    } while (!m.check());

}

