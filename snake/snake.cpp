#include <iostream>
#include <cstdlib>
#include<stdio.h>
#include<ctime>
#include <pthread.h>
#define Stp ((row+col)/2)
#define row 10//col
#define col 15//row
using namespace std;

#define NUM_THREADS 3
int stop = 0, flag =6, flag1 =1,board[row][col] = {{0}};


int ipos = row/2, jpos =2 ;
int itpos = row/2, jtpos = 0;
int itm = -1, jtm = -1;
int len = 2;
int score = 0;
int speed = 5;
int step = 0;
int inline max(int a, int b){
        return (a>b ? a: b);
}
void egg()
{
        int sig = 0;
        while(!sig){
                int rani = rand()%row;
                int ranj = rand()%col;
                if(board[rani][ranj] == 0){
                        board[rani][ranj] = 5;
                        if(len%5 == 0){
                                while(!sig){
                                        itm = rand()%row;
                                        jtm = rand()%col;
                                        if(board[itm][jtm] == 0){
                                                sig = 1;
                                                step = 0;
                                        }
                                }
                        }
                        sig = 1;
                }
        }
        return ;
}
void wait ( float sec )
{
        clock_t time;
        time = clock();
        while((float)(clock() - time)/CLOCKS_PER_SEC < sec);
        return ;
}

/*int c2i(char ch,int &i)
{
        if(ch >47 && ch < 58 ){
                i = (int)(ch - 48);
                return 0;
        }
        return 1;
}*/
int valid(char ch, int& i){
        switch (ch){
                case '0':
                        i = 0;
                        return 1;
                case '2':
                        i = 2;
                        return 1;
                case '4':
                        i = 4;
                        return 1;
                case '6':
                        i = 6;
                        return 1;
                case '8':
                        i = 8;
                        return 1;
        }
        return 0;
}

int icm(int i,int flg)
{
        if(flg == 2)
                return (i+1)%(row);
        else if (flg == 8){
                if(i==0)
                        return row - 1;
                else
                        return i-1;
        }
        return i;
}



int jcm(int j,int flg)
{
        if(flg == 6)
                return (j+1)%col;
        else if ( flg == 4){
                if(j == 0)
                        return col-1;
                else
                        return j-1;
        }
        return j;
}
void print()
{
        wait(1);
        system("clear");// for unix
        for(int load = 0;step < Stp && load < Stp && len > 3&&itm != -1; load++){
                if(load < Stp - step )
                        cout<<"#";
                else
                        cout<<".";
        }
        cout<<"\n\r\n\r|";
        for(int i = -1; i < row+1; i++){
                for( int j = 0; j<col; j++){
                        int k = board[i][j];
                        if( i == -1 || i == row)
                                cout<<".";
                        else if( i == ipos && j == jpos)
                                cout<<"0";
                        else if( i == itm && j==jtm){
                                if(step%2 ==0)
                                        cout<<"@";
                                else
                                        cout<<" ";
                        }
                        else if(k != 0)
                                cout<<k;
                        else
                                cout<<" ";
                }
                cout<<"|";
                cout<<"\n\r"<<"|";
        }
        cout<<"Score : "<<score<<"\tLength : "<<len<<"\t\n\r";
}
void *set(void *threadid)
{
        while(flag1){
                while(flag){
                        step++;
                        wait((2*(12.0-speed))/max(row,col));
                        if(step == Stp){
                                itm = -1;
                                jtm = -1;
                        }
                        if(board[ipos][jpos] == 5){
                                egg();
                                len++;
                                score+=speed;
                        }else{
                                if(ipos == itm && jtm == jpos){
                                        score += speed*(Stp-step);
                                        itm = -1;                                                                                         jtm = -1;
                                }else if( board[ipos][jpos] != 0){
                                        cout<<"\r\r\r\t:) Game over (:\r";                                                                flag =0;
                                        flag1 = 0;
                                }
int val = board[itpos][jtpos];
                                int tempi = icm(itpos,val);
                                int tempj= jcm(jtpos,val);
                                board[itpos][jtpos] = 0;
                                itpos = tempi;
                                jtpos = tempj;
                        }
                        board[ipos][jpos]=flag;
                        ipos = icm(ipos,flag);
                        jpos = jcm(jpos,flag);
                }
        }
        pthread_exit(NULL);
}
void *PrintHello(void *threadid) {
        while(flag1){
                while(flag){
                        print();
                        wait(1.0/16);
                }
        }
        cout<<"closing print.";
        pthread_exit(NULL);
}
void *take(void *threadid) {
        int buff = 2;
        char buf = '0';
        //system("stty -icrnl raw");
        system("stty raw");
        while(flag1){
                while(flag){
                        buf = getchar();
                        //cin>>buf;
                        if(//c2i(buf,buff)&&
                                        !valid(buf,buff))
                                cout<<"not ok";
                        if(!((flag == 6 && buff == 4 )||( flag == 4 && buff==6) || (flag == 8 && buff == 2 )||( flag == 2 && buff == 8)) )
                                flag = buff;
                }
                if(flag1){
                cout<<"do you want to close(0)";
                cin>>flag;
                }
                if( !flag && board[ipos][jpos] == 0){
                        flag1 = 0;
                }
        }
        system("stty cooked");
        cout<<"closing...input";
        pthread_exit(NULL);
}
int main () {
//initialise board
        board[row/2][0] = 6;
        board[row/2][1] = 6;
        egg();
        cout<<"\n\n\n\n\t\tWELCOME\n\t\tto\n\n\tMY GAME of SNAKE and EGGS\n";
        cout<<"\n\n\tInstructions : Enter \n\t2.down\t4.left\t6.right\t8.up\n\t0.To PAUSE or CLOSE.";
        cout<<"\n\nTo start game ..\n\n\nEnter speed( 1 to 10 ) : ";
        cin>>speed;
        pthread_t threads[NUM_THREADS];                                                                   int rc=1;
        rc = pthread_create(&threads[0],NULL,set,NULL);
        rc = pthread_create(&threads[1], NULL, PrintHello, NULL);                                         rc = pthread_create(&threads[2], NULL, take, NULL);
        if (rc) {
                cout << "Error:unable to create thread," << rc << endl;
                exit(-1);
        }
        pthread_exit(NULL);
}

