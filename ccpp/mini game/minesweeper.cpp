#include <iostream>
#include <algorithm>
#include <random>
#include <ctime>
#include <windows.h>
#include <conio.h>
typedef unsigned char UCHR;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
class map{
    public:
    int height, width;
    int cursorX=0, cursorY=0;
    int not_revealed, mines;
    int** minemap;
    bool** revealed;
    public:
    void inc(int x, int y, int h, int w);
    void spawnmines(int h, int w, int minec);
    void reveal(int x, int y);
    void ingame_print();
    int controller();
    void failed();
    void succeed();
    map(int h, int w, int minecount): height(h), width(w), mines(minecount){
        srand(time(0));
        while(h<=0 || w<=0 || minecount<=0){
            std::cout << "K DC DAU, HAY NHAP LAI\n";
            std::cout << "NHAP SO HANG: ";
            std::cin >> h;
            std::cout << "NHAP SO COT: ";
            std::cin >> w;
            std::cout << "NHAP SO LUONG BOM: ";
            std::cin >> minecount;
            system("cls");
        }this->height=h, this->width=w; mines=minecount;
        if(h*w<=minecount*4 || minecount<=0){
            minecount=int(h*w/4);
            printf("KO CHOI DC DAU, SO LUONG BOM DAT THANH %d.\n", minecount);
        }
        not_revealed=h*w;
        minemap=new int*[h];
        revealed=new bool*[h];
        for(int i=0; i<h; ++i){
            minemap[i]=new int[w];
            revealed[i]=new bool[w];
            std::fill(minemap[i], minemap[i]+w, 0);
            std::fill(revealed[i], revealed[i]+w, false);
        }
    }
    void print(UCHR m=178){
        for(int i=0; i<this->height; ++i){
            for(int j=0; j<this->width; ++j){
                if(minemap[i][j]==-1) std::cout << m << " ";
                else std::cout << minemap[i][j] << " ";
            }
            printf("\n");
        }std::cout << "\n";
    }
    ~map(){
        for(int i=0; i<this->height; ++i){
            delete this->minemap[i];
        }delete this->minemap;
    }
};
void map::spawnmines(int h, int w, int minec){
    while(minec--){
        int x=rand()%w, y=rand()%h;
        while(minemap[y][x]==-1 || (x==cursorX && y==cursorY)) x=rand()%w, y=rand()%h;
        minemap[y][x]=-1;
        inc(x, y, h, w);
    }
    return;
}
void map::inc(int x, int y, int h, int w){
    for(int i=x-1; i<=x+1; ++i){
        for(int j=y-1; j<=y+1; ++j){
            if(0<=i && i<w && 0<=j && j<h && minemap[j][i]!=-1) ++minemap[j][i];
        }
    }
    return;
}
void map::reveal(int x, int y){
    revealed[y][x]=true; --not_revealed;
    if(x>=0 && x<this->width && y>=0 && y<this->height && minemap[y][x]==0){  
        if(x>0){
            if(revealed[y][x-1]==false) reveal(x-1, y);
        }
        if(x<this->width-1){
            if(revealed[y][x+1]==false) reveal(x+1, y);
        }
        if(y>0){
            if(revealed[y-1][x]==false) reveal(x, y-1);
        }
        if(y<this->height-1){
            if(revealed[y+1][x]==false) reveal(x, y+1);
        }
        if(x>0 && y>0){
            if(revealed[y-1][x-1]==false) reveal(x-1, y-1);
        }
        if(y<this->height-1 && x<this->width-1){
            if(revealed[y+1][x+1]==false) reveal(x+1, y+1);
        }
        if(y<this->height-1 && x>0){
            if(revealed[y+1][x-1]==false) reveal(x-1, y+1);
        }
        if(x<this->width-1 && y>0){
            if(revealed[y-1][x+1]==false) reveal(x+1, y-1);
        }
    }else return;
}
void map::ingame_print(){
    UCHR m=254, nr=178;
    for(int i=0; i<this->height; ++i){
        for(int j=0; j<this->width; ++j){
            if(i==this->cursorY && j==this->cursorX){
                if (revealed[i][j] == true){
                    SetConsoleTextAttribute(hConsole, 6);
                    std::cout << minemap[i][j] << " ";
                    SetConsoleTextAttribute(hConsole, 7);
                }else{
                    SetConsoleTextAttribute(hConsole, 6);
                    std::cout << "+ ";
                    SetConsoleTextAttribute(hConsole, 7);
                }
            }else if (revealed[i][j] == true){
                if (minemap[i][j]==-1) std::cout << m << " ";
                else std::cout << minemap[i][j] << " ";
            }else std::cout << nr << " ";
        }
        printf("\n");
    }std::cout << "\n";
}
int map::controller(){
    char cmd; bool need_to_spawn=true;
    while(not_revealed!=mines){
        cmd=getch();
        system("cls");
        switch(cmd){
            case 'a':{
                cursorX=(cursorX==0)?0:(cursorX-1);
                break;
            }
            case 'd':{
                cursorX=(cursorX==this->width-1)?cursorX:(cursorX+1);
                break;
            }
            case 'w':{
                cursorY=(cursorY==0)?0:(cursorY-1);
                break;
            }
            case 's':{
                cursorY=(cursorY==this->width-1)?cursorY:(cursorY+1);
                break;
            }
            case ' ':{
                if(need_to_spawn==true){spawnmines(this->height, this->width, this->mines); need_to_spawn=false;}
                reveal(cursorX, cursorY);
                if(minemap[cursorY][cursorX]==-1) return 0;
                break;
            }
        }
        ingame_print();
    }
    return 1;
}
void map::failed(){
    system("cls");
    system("color 04");
    UCHR nr=178;
    for(int i=0; i<this->height; ++i){
        for(int j=0; j<this->width; ++j){
            if (minemap[i][j]==-1){std::cout << "X" << " ";}
            else if (revealed[i][j] == true){std::cout << minemap[i][j] << " ";}
            else std::cout << nr << " ";
        }
        printf("\n");
    }
    std::cout << "___________________________________________\n";
    std::cout << "|------------ BAN DA THAT BAI ------------|\n";
    std::cout << "|                                         |\n";
    std::cout << "|--------NHAN PHIM BAT KI DE THOAT--------|\n";
    std::cout << "___________________________________________\n";
    return;
}
void map::succeed(){
    system("cls");
    system("color 09");
    UCHR m=254;
    for(int i=0; i<this->height; ++i){
        for(int j=0; j<this->width; ++j){
            if (minemap[i][j]==-1) std::cout << m << " ";
            else std::cout << minemap[i][j] << " ";
        }
        printf("\n");
    }
    std::cout << "___________________________________________\n";
    std::cout << "|--------------- THANH CONG --------------|\n";
    std::cout << "|                                         |\n";
    std::cout << "|--------NHAN PHIM BAT KI DE THOAT--------|\n";
    std::cout << "___________________________________________\n";
    return;
}
int main(){
    std::cout << "_______________________________________________________\n";
    std::cout << "|------------ MINESWEEPER CONSOLE EDITION ------------|\n";
    std::cout << "|HUONG DAN: ------------------------------------------|\n";
    std::cout << "|--- [ADSW] DI CHUYEN --------------------------------|\n";
    std::cout << "|--- [SPACE] DAO -------------------------------------|\n";
    std::cout << "|--- SO TRONG 1 O CHI RA SO BOM TRONG 8 O ------------|\n";
    std::cout << "|--- XUNG QUANH O DO ---------------------------------|\n";
    std::cout << "|-------------NHAN PHIM BAT KI DE DI TIEP-------------|\n";
    std::cout << "_______________________________________________________\n";
    getch();
    system("cls");
    std::cout << "_______________________________________________________\n";
    std::cout << "|----------------CHON DO KHO:-------------------------|\n";
    std::cout << "|--- [1] DE VAI: MAP 9X9, 10 BOM ----------------------|\n";
    std::cout << "|--- [2] BTHUONG: MAP 16X16, 40 BOM ------------------|\n";
    std::cout << "|--- [3] KHO: MAP 20X30, 99 BOM ----------------------|\n";
    std::cout << "|--- [PHIM BAT KI] CUSTOM ----------------------------|\n";
    std::cout << "_______________________________________________________\n";
    int cmd=getch()-'0', heigheight, width, minecount;
    switch(cmd){
        case 1:{heigheight=width=9, minecount=10; break;}
        case 2:{heigheight=width=16, minecount=40; break;}
        case 3:{heigheight=20, width=30, minecount=99; break;}
        default:{
            std::cout << "NHAP SO HANG: ";
            std::cin >> heigheight;
            std::cout << "NHAP SO COT: ";
            std::cin >> width;
            std::cout << "NHAP SO LUONG BOM: ";
            std::cin >> minecount;
            break;
        }
    }
    system("cls");
    map mines(heigheight, width, minecount);
    //mines.ingame_print();
    //mines.print();
    mines.ingame_print();
    int RESULT=mines.controller();
    if(RESULT==0) mines.failed();
    else mines.succeed();
    mines.~map();
    return 0;
}