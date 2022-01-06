#include <bits/stdc++.h>
using namespace std;

//char square[10] = {'o','1','2','3','4','5','6','7','8','9'};

int checkwin(char[]);
void board(char[]);
void singleplayer(char[]);
void twoplayer(char[]);
int random_mark(char[]);
void start_menu();

int main()
{
    start_menu();
    return 0;
}

void start_menu()
{
    int continu;
    int singlevsdouble;
    do
    {
        char square[10] = {'o','1','2','3','4','5','6','7','8','9'};
        cout<<"1.)Two Player game"<<endl;
        cout<<"2.)Player v/s computer"<<endl;
        cin>>singlevsdouble;
        switch(singlevsdouble)
        {
            case 1:twoplayer(square);             break;
            case 2:singleplayer(square);          break;
            default:cout<<"Invalid input";
                    start_menu();
        }
        cout<<"\nTry Again?(0/1)";
        cin>>continu;
        cout<<endl;
    }while(continu);
}

void singleplayer(char square[])
{
    int player = 1,i,choice;
    char mark;
    do
    {
        int randm;
        srand(time(NULL));
        board(square);
        player=(player%2)?1:2;
        if(player==2)
        {
            cout << "Player " << player << ", enter a number:  ";
            cin >> choice;
        }
        else
        {
            cin.get();
            cin.ignore();
            choice=random_mark(square);
        }
        mark=(player == 1) ? 'X' : 'O';

        if (choice == 1 && square[1] == '1')

            square[1] = mark;
        else if (choice == 2 && square[2] == '2')

            square[2] = mark;
        else if (choice == 3 && square[3] == '3')

            square[3] = mark;
        else if (choice == 4 && square[4] == '4')

            square[4] = mark;
        else if (choice == 5 && square[5] == '5')

            square[5] = mark;
        else if (choice == 6 && square[6] == '6')

            square[6] = mark;
        else if (choice == 7 && square[7] == '7')

            square[7] = mark;
        else if (choice == 8 && square[8] == '8')

            square[8] = mark;
        else if (choice == 9 && square[9] == '9')

            square[9] = mark;
        else
        {
            cout<<"Invalid move ";

            player--;
            cin.ignore();
            cin.get();
        }
        i=checkwin(square);

        player++;
    }while(i==-1);
    board(square);
    if(i==1)

        cout<<"==>\aPlayer "<<--player<<" win ";
    else
        cout<<"==>\aGame draw";

    cin.ignore();
    cin.get();
}


int random_mark(char square[])
{
    int randm;
    randm=rand()%9+1;
    if(square[randm]!='X'&&square[randm]!='O')
    {
        return randm;
    }
    return random_mark(square);
}


void twoplayer(char square[])
{
    	int player = 1,i,choice;

    char mark;
    do
    {
        board(square);
        player=(player%2)?1:2;

        cout << "Player " << player << ", enter a number:  ";
        cin >> choice;

        mark=(player == 1) ? 'X' : 'O';

        if (choice == 1 && square[1] == '1')

            square[1] = mark;
        else if (choice == 2 && square[2] == '2')

            square[2] = mark;
        else if (choice == 3 && square[3] == '3')

            square[3] = mark;
        else if (choice == 4 && square[4] == '4')

            square[4] = mark;
        else if (choice == 5 && square[5] == '5')

            square[5] = mark;
        else if (choice == 6 && square[6] == '6')

            square[6] = mark;
        else if (choice == 7 && square[7] == '7')

            square[7] = mark;
        else if (choice == 8 && square[8] == '8')

            square[8] = mark;
        else if (choice == 9 && square[9] == '9')

            square[9] = mark;
        else
        {
            cout<<"Invalid move ";

            player--;
            cin.ignore();
            // cin.get();
            getc();
        }
        i=checkwin(square);

        player++;
    }while(i==-1);
    board(square);
    if(i==1)

        cout<<"==>\aPlayer "<<--player<<" win ";
    else
        cout<<"==>\aGame draw";

    cin.ignore();
    cin.get();
}

int checkwin(char square[])
{
    if (square[1] == square[2] && square[2] == square[3])

        return 1;
    else if (square[4] == square[5] && square[5] == square[6])

        return 1;
    else if (square[7] == square[8] && square[8] == square[9])

        return 1;
    else if (square[1] == square[4] && square[4] == square[7])

        return 1;
    else if (square[2] == square[5] && square[5] == square[8])

        return 1;
    else if (square[3] == square[6] && square[6] == square[9])

        return 1;
    else if (square[1] == square[5] && square[5] == square[9])

        return 1;
    else if (square[3] == square[5] && square[5] == square[7])

        return 1;
    else if (square[1] != '1' && square[2] != '2' && square[3] != '3'
                    && square[4] != '4' && square[5] != '5' && square[6] != '6'
                  && square[7] != '7' && square[8] != '8' && square[9] != '9')

        return 0;
    else
        return -1;
}

void board(char square[])
{
    system("cls");
    cout << "\n\n\tTic Tac Toe\n\n";

    cout << "Player 1 (X)  -  Player 2 (O)" << endl << endl;
    cout << endl;

    cout << "     |     |     " << endl;
    cout << "  " << square[1] << "  |  " << square[2] << "  |  " << square[3] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << square[4] << "  |  " << square[5] << "  |  " << square[6] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << square[7] << "  |  " << square[8] << "  |  " << square[9] << endl;

    cout << "     |     |     " << endl << endl;
}
