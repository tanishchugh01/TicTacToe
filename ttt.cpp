#include <bits/stdc++.h>
using namespace std;

int checkwin(char[]);
void board(char[],bool);
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
        system("cls");
        
        cout << "\n\n\tTic Tac Toe\n\n";
        
        char square[10] = {'o','1','2','3','4','5','6','7','8','9'};
        
        cout<<"1.)Player v/s computer"<<endl;
        cout<<"2.)Two Player game"<<endl;
        cout<<"\n0.)Exit"<<endl;
        
        cin>>singlevsdouble;
        
        switch(singlevsdouble)
        {
            case 1: singleplayer(square);          break;
            case 2: twoplayer(square);             break;
            case 0: exit(0);
            
            default:
            {
                cout<<"Invalid input";
                
                cin.ignore();
                cin.get();
                
                start_menu();
            }
        }
        
    }while(true);
}

void singleplayer(char* square)
{
    int player = 1,i,choice;
    char mark;
    
    do
    {
        int randm;
    
        srand(time(NULL));
        
        board(square,true);
    
        player=(player%2)?1:2;
    
        if(player==2)
        {
            cout << "Your turn, enter a number:  ";
    
            cin >> choice;
        }
        else
        {
            cout<<"My turn, press and key to continue";
            cin.get();
            cin.ignore();
    
            choice=random_mark(square);
        }
    
        mark=(player == 1) ? 'X' : 'O';

        // if (choice == 1 && square[1] == '1')

        //     square[1] = mark;
        // else if (choice == 2 && square[2] == '2')

        //     square[2] = mark;
        // else if (choice == 3 && square[3] == '3')

        //     square[3] = mark;
        // else if (choice == 4 && square[4] == '4')

        //     square[4] = mark;
        // else if (choice == 5 && square[5] == '5')

        //     square[5] = mark;
        // else if (choice == 6 && square[6] == '6')

        //     square[6] = mark;
        // else if (choice == 7 && square[7] == '7')

        //     square[7] = mark;
        // else if (choice == 8 && square[8] == '8')

        //     square[8] = mark;
        // else if (choice == 9 && square[9] == '9')

        //     square[9] = mark;
        if( (choice>0  &&  choice<10)
            &&  (square[choice]== ('0'+choice) )  )
        {
            square[choice]=mark;
        }
        else
        {
            cout<<"Invalid move ";

            player--;
      
            string continu;

            cout<<"You can press 0 to end this game and move to main menu :)"<<endl;
            cout<<"Press any other number to continue"<<endl;
            
            cin>>continu;

            if(continu=="0")
            {
                return;
            }
        }
        
        i=checkwin(square);

        player++;
    }while(i==-1);
   
    board(square,true);
    
    player--;
    
    if(i==1)
    {
        if(player==1)
        {
            cout<<"==>Hello loser :)";
        }
        else
        {
            cout<<"==>You won!!"<<endl;
            cout<<"I think, I am in right hands..Huh";
        }
    }
    
    else
    {
        cout<<"==>\aGame draw";
    }
    
    cin.ignore();
    cin.get();
}

int random_mark(char* square)
{
    int randm = rand()%9+1;
 
    if(square[randm]!='X'&&square[randm]!='O')
    {
        return randm;
    }
 
    return random_mark(square);
}


void twoplayer(char* square)
{
    int player = 1,i,choice;
    char mark;
    
    do
    {
        board(square,false);
        
        player=(player%2)?1:2;

        cout << "Player " << player << ", enter a number:  ";
        cin >> choice;

        mark=(player == 1) ? 'X' : 'O';

        if(     (choice>0  &&  choice<10)
            &&  (square[choice]== ('0'+choice) )  )
        {
            square[choice]=mark;
        }
        else
        {
            cout<<"Invalid move ";

            player--;
      
            string continu;

            cout<<"You can press 0 to end this game and move to main menu"<<endl;
            cout<<"Press any other number to continue"<<endl;
            
            cin>>continu;

            if(continu=="0")
            {
                return;
            }
        }
        
        i=checkwin(square);

        player++;
        
    }while(i==-1);
    
    board(square,false);
    
    if(i==1)
    {
        cout<<"==>\aPlayer "<<--player<<" win ";
    }
    else
    {
        cout<<"==>\aGame draw";
    }
    
    cin.ignore();
    cin.get();
}

int checkwin(char* square)
{
    if (square[1] == square[2] && square[2] == square[3])
    {
        return 1;
    }
    else if (square[4] == square[5] && square[5] == square[6])
    {
        return 1;
    }
    else if (square[7] == square[8] && square[8] == square[9])
    {
        return 1;
    }
    else if (square[1] == square[4] && square[4] == square[7])
    {   
        return 1;
    }
    else if (square[2] == square[5] && square[5] == square[8])
    {
        return 1;
    }
    else if (square[3] == square[6] && square[6] == square[9])
    {
        return 1;
    }
    else if (square[1] == square[5] && square[5] == square[9])
    {
        return 1;
    }
    else if (square[3] == square[5] && square[5] == square[7])
    {
        return 1;
    }
    else if (square[1] != '1' && square[2] != '2' && square[3] != '3'
            && square[4] != '4' && square[5] != '5' && square[6] != '6'
            && square[7] != '7' && square[8] != '8' && square[9] != '9')
    {
        return 0;
    }
    
    return -1;
}

void board(char* square,bool isSinglePlayer=false)
{
    system("cls");
    
    cout << "\n\n\tTic Tac Toe\n\n";

    if(isSinglePlayer)
    {
        cout<<"Me (X)  -  You (O)"<<endl;
    }
    else
    {
        cout << "Player 1 (X)  -  Player 2 (O)" << endl;
    }
    
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
