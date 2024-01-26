/*
Game Board: Create a 3x3 grid as the game board.
Players: Assign "X" and "O" to two players.
Display Board: Show the current state of the board.
Player Input: Prompt the current player to enter their move.
Update Board: Update the game board with the player's move.
Check for Win: Check if the current player has won.
Check for Draw: Determine if the game is a draw.
Switch Players: Alternate turns between "X" and "O" players.
Display Result: Show the result of the game (win, draw, or ongoing).
Play Again: Ask if the players want to play another game.
*/
#include <iostream>

using namespace std;

 char Board[3][3]={'1','2','3','4','5','6','7','8','9'};
 char turn= 'X';
 bool draw = false;
//Game Board
void Game_Board()
{
    turn= 'X';
    draw = false;
}


// to mark the player's turn
int choice;// to choose the grid number
int r,c;// r denotes the row number and c denotes the column number of grid


void Display_Board()
{
    cout<<"\n PLAYER-1 [X]\t PLAYER-2[O]\n\n";
    cout<<"\t\t     |     |     \n";
    cout<<"\t\t  "<<Board[0][0]<<"  | "<<Board[0][1]<<"   |  "<<Board[0][2]<<" \n";
    cout<<"\t\t_____|_____|_____\n";
    cout<<"\t\t     |     |     \n";
    cout<<"\t\t  "<<Board[1][0]<<"  | "<<Board[1][1]<<"   |  "<<Board[1][2]<<" \n";
    cout<<"\t\t_____|_____|_____\n";
    cout<<"\t\t     |     |     \n";
    cout<<"\t\t  "<<Board[2][0]<<"  | "<<Board[2][1]<<"   |  "<<Board[2][2]<<" \n";
    cout<<"\t\t     |     |     \n";

}

void Player_Input()
{
    //PLAYER INPUT
    if(turn=='X')
        cout<<"\n PLAYER-1 [X] Turn:";
    else
        cout<<"\n PLAYER-2 [O] Turn:";

    cin>>choice;

    switch(choice)
    {
        case 1: r=0;c=0; break;
        case 2: r=0;c=1; break;
        case 3: r=0;c=2; break;
        case 4: r=1;c=0; break;
        case 5: r=1;c=1; break;
        case 6: r=1;c=2; break;
        case 7: r=2;c=0; break;
        case 8: r=2;c=1; break;
        case 9: r=2;c=2; break;
        default: cout<<"Invalid Move!"<<endl;
    }

    //BOARD UPDATION
    if(turn=='X'&& Board[r][c]!='X' && Board[r][c]!='O')
    {
        Board[r][c]='X';
        turn='O';
    }
    else if(turn=='O'&& Board[r][c]!='X' && Board[r][c]!='O')
    {
        Board[r][c]='O';
        turn='X';
    }
    else{
        cout<<"\nPlease choose another Box!!\n";
        Player_Input();
    }

    Display_Board();
}

bool Game_Result()
{
    //CHECKING FOR WIN
    //ROWS AND COLUMNS
    for(int j=0;j<3;j++)
    {
        if(Board[j][0]==Board[j][1] && Board[j][0]==Board[j][2] || Board[0][j]==Board[1][j] && Board[0][j]==Board[2][j])
            return false;
    }

    //CHECKING FOR WIN
    //DIAGONALS
    if(Board[0][0]==Board[1][1] && Board[0][0]==Board[2][2] || Board[0][2]==Board[1][1] && Board[0][2]==Board[2][0])
        return false;

   //CHECKING FOR ONGOING GAME
   for(int i=0;i<3;i++)
   {
       for(int j =0;j<3;j++)
       {
           if(Board[i][j]!='X' && Board[i][j]!='O')
            return true;
       }
   }

   //CHECKING FOR DRAW
   draw = true;
   return false;

}



int main()
{
    cout<<"****************************************************************************"<<endl;
    cout<<"            WELCOME TO THE GAME OF TIC-TAC-T0E GAME FOR TWO PLAYERS"<<endl;
    cout<<"****************************************************************************"<<endl;
    char ch='y';
    do{
    Game_Board();
    char a='1';
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            Board[i][j]=a;
            a++;
        }

    }
    //Board[3][3]={'1','2','3','4','5','6','7','8','9'};
    while(Game_Result())
    {
        Display_Board();
        Player_Input();
        Game_Result();
    }
    if(turn=='X' && draw == false)
        cout<<"\n\nCongratulations!! Player-2[O] Wins "<<endl;
    else if(turn == 'O' && draw == false)
        cout<<"\n\nCongratulations!! Player-1[X] Wins "<<endl;
    else
        cout<<"\n\n It's A Draw"<<endl;

    cout<<"\n Do you want to play another Game?(y/n)";
    cin>>ch;
    }while(ch=='y' || ch=='Y');
    return 0;
}
