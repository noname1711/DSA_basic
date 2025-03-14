#include<iostream>
using namespace std;

bool checkwin(char board[3][3], char player){

    // for horizontal
    for(int i=0;i<3;i++){
        if(board[i][0]==player && board[i][1]==player && board[i][2]==player){
            return true;
        }
    }

    // for vertical
    for(int i=0;i<3;i++){
        if(board[0][i]==player && board[1][i]==player && board[2][i]==player){
            return true;
        }
    }

    // for diagonal
    if(board[0][0]==player && board[1][1]==player && board[2][2]==player){
        return true;
    }

    if(board[0][2]==player && board[1][1]==player && board[2][0]==player){
        return true;
    }

    return false; // return false if no above conditions are matched.

}

void showBoard(char board[3][3]){

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<board[i][j];
            cout<<" ";
        }
        cout<<endl;
    }

}

bool checkplace(char board[3][3], int x, int y){

    if(x>=3 || y>=3){
        cout<<"Please enter valid position."<<endl;
        return false;
    }

    if(board[x][y]=='-'){
        return true;
    }
    else{
        cout<<x+1<<" "<<y+1<<" is already occupied."<<endl;
        return false;
    }

}

bool play(char board[3][3], int &count,char player){

    int x, y;
    cout<<endl<<player<<" turn"<<endl;

    do{

        cout<<"Enter Place: ";
        cin>>x>>y;

    }while(!checkplace(board,x-1,y-1));

    board[x-1][y-1] = player;

    count++;

    if(checkwin(board,player))
        return true;
    else
        return false;

}

int main(){

    char board[3][3] = {{'-','-','-'},{'-','-','-'},{'-','-','-'}};
    int count=0;

    do{
        system("cls");

        showBoard(board);

        if(count%2==0){

            if(play(board, count,'X')) break;

        }
        else{

            if(play(board, count,'O')) break;

        }
        cout<<endl;

    }while(count<9);

    system("cls");
    showBoard(board);


    if(count%2 == 0 && count < 9)
        cout<<"\nO WINS !!\n";
    else if(count%2 == 1 && count < 9)
        cout<<"\nX WINS !!\n";
    else
        cout<<"\nGAME DRAW\n";


    return 0;

}
