//NUMBER GUESSING GAME
#include<iostream>
#include<cstdlib>
#include<time.h>

using namespace std;

int main()
{
    cout<<"************************************************"<<endl;
    cout<<"           'WELCOME TO NUMBER GUESSING GAME'"<<endl;
    cout<<"************************************************"<<endl;
    int ranum;//variable to take guess from user
    srand(time(0));
    int rnum=rand()%100;//storing the generated random number
    cout<<"Guess a number less than 100"<<endl;
    do
    {
        cout<<"\nGuess the number:";
        cin>>ranum;
        if(rnum>ranum)
            cout<<"Your guess is too low "<<endl;
        else if(rnum<ranum)
            cout<<"Your guess is too high "<<endl;
    }while(ranum!=rnum);
    cout<<"\nWoohooo you got it right!!"<<endl;
    cout<<"************************************************"<<endl;

    return 0;
}
