#include<iostream>
#include<windows.h>
#include<time.h> //using for srand() and rand()
#include<conio.h> //using for getch() 
#include<string> //using for store player name
#define KEY_UP  72
#define KEY_DOWN  80
#define KEY_LEFT  75
#define KEY_RIGHT 77
#define EXIT_TO_GAME 101
#define YOU_ARE_WIN 1 
using namespace std;
class NumShift_Game
{
    private:
        string playerName;
        int matrix[4][4]; //matrix 4*4
    public:
        void insertPlyN();
        void createMatrix(); //create matrix with random number storing 
        void showMatrix();
        void gameRule();
        void play_Game_Or_moveNum();
        bool winOrNot();
};
void NumShift_Game::insertPlyN()
{
    char name[25];
    cin.getline(name,25);
    playerName.append(name);
}
bool NumShift_Game::winOrNot()
{
    int count=0; //for counting how many number is same position
    int temp[4][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,0}}; //store number 1-15 in temp[4][4]
    for(int i=0; i<4; i++)
        for(int j=0; j<4; j++)
            if(matrix[i][j]==temp[i][j]) //compair between matrix and temp 
                count++;
    return count==16; //if matrix and temp is equle So return true or not return false
}
void NumShift_Game::play_Game_Or_moveNum()
{
    int row,column;
    try{
        while(1)
        {
            //searching value of row and column of matrix in which store Zero   
            for(int i=0;i<4;i++){
                for(int j=0;j<4;j++){
                    if(matrix[i][j]==0)
                    {
                        row=i;
                        column=j;
                    }
                }
            }
            if(winOrNot()) //check for wining condition
                throw YOU_ARE_WIN;
            char keyN=getch(); //user input from Arrow key (Up,Down,Left,Right) And for end game E,e
            if(keyN==69)
                keyN=109;
            switch(keyN)
            {
                case KEY_UP: //Up arrow key
                    if(row>0) //Up arrow key is availabe for swaping value
                    {
                        //swaping value(0) to value(Up)
                        matrix[row][column]=matrix[row-1][column]; 
                        matrix[row-1][column]=0;
                        break;
                    }
                    else //Not available Up arrow key for swap
                        break;
                case KEY_DOWN: //Down arrow key
                    if(row<3) //Down arrow key is available for swaping value 
                    {
                        //swaping value(0) to value(Down)
                        matrix[row][column]=matrix[row+1][column];
                        matrix[row+1][column]=0;
                        break;
                    }
                    else //Not available Down arrow key for swap
                        break;
                case KEY_LEFT: //Left arrow key
                    if(column>0) //Left arrow key is available for swaping value
                    {
                        //swaping value(0) to value(Left)
                        matrix[row][column]=matrix[row][column-1];
                        matrix[row][column-1]=0;
                        break;
                    }
                    else //Not available Left arrow key for swap
                        break;
                case KEY_RIGHT: //Right arrow key
                    if(column<3) //Right arrow key is available for swaping value
                    {
                        //swaping value(0) to value(Right)
                        matrix[row][column]=matrix[row][column+1];
                        matrix[row][column+1]=0;
                        break;
                    }
                    else //Not available Right arrow key for swap
                        break;
                case EXIT_TO_GAME:
                    exit(0); //Exit Game
                default: //any another key
                    break; 
            }
            system("cls"); //clear terminal or screen
            //print player Name
            cout<<"\n\t\033[96mPlayer Name : ";
            for(int n=0;n<playerName.size();n++)
                cout<<"\033[96m"<<playerName.at(n)<<"\033[0m";
            showMatrix(); //after swaping show matrix 
        }
    }
    catch(int e)
    {
        if(e==1) //After win Game
        {
            system("cls"); //clear screen or terminal
            //print Player Name
            cout<<"\n\t\033[93mCongratulation: ";
            for(int n=0;n<playerName.size();n++)
                cout<<"\033[96m"<<playerName.at(n)<<"\033[0m";
            cout<<"\n\n\t\t\t\033[1;92mYou Win\033[0m";
            showMatrix(); //After win game show matrix
        }
    }
}
void NumShift_Game::gameRule()
{
    //using escape sequences to change the color of text and formating
    //\033 is the escape character And
    //[1;32m is the code for setting the text color and format
    //\033[0m is used to reset the color back to normal
    cout<<"\n\t\t\t\t\033[1;4;91mRULE OF THIS GAME\033[0m\n"<<endl; //Rule of this Game
    cout<<" \033[91m1. \033[31mYou can move only 1 step at a time by arrow key\033[0m"<<endl; //Rule-1
        cout<<"\t\033[32mMove UP    : \033[3;35mby Up arrow key"<<endl;
        cout<<"\t\033[32mMove Down  : \033[3;35mby Down arrow key"<<endl;
        cout<<"\t\033[32mMove Left  : \033[3;35mby Left arrow key"<<endl;
        cout<<"\t\033[32mMove Right : \033[3;35mby Right arrow key\033[0m"<<endl;
    cout<<" \033[91m2. \033[31mYou can move number at empty position only\033[0m"<<endl; //Rule-2
    cout<<" \033[91m3. \033[31mFor each valid move : \033[3;35myour total number of move will decreased by 1\033[0m"<<endl; //Rule-3
    cout<<" \033[91m4. \033[31mWining situation : \033[3;35mnumber in a 4*4 matrix should be in order from 1 to 15\033[0m"<<endl; //Rule-4
    
    cout<<"\n\t\t\033[1;32m   Wining situation :\033[0m"<<endl; //Wining situation
    //For printing Wining situation So that see user
    int k=1;
    for(int i=0; i<4; i++)
        for(int j=0; j<4; j++,k++)
            matrix[i][j]=k; //storing Number in matrix with k++
    matrix[3][3]=0; //last number is Zero of matrix
    showMatrix(); //call showMatrix

    cout<<" \033[91m5. \033[31mYou can exit the game at any time by pressing '\033[37mE\033[31m' or '\033[37me\033[31m'\033[0m"<<endl; //Rule-5
    cout<<" \033[3;94m  =>So Try to win in minium no. of move\033[0m"<<endl;
    cout<<"\033[1;36m\tHappy gaming , Good Luck\033[0m"<<endl; //Good Luck
}
void NumShift_Game::showMatrix()
{
    cout<<endl;
    cout<<"\033[1;91m\t\t --------------------- \033[0m"<<endl; //lining on up
    for(int i=0; i<4; i++)
    {
        cout<<"\033[1;91m\t\t |\033[0m "; //lining on left side
        for(int j=0; j<4; j++)
        {
            if(matrix[i][j]==0) // if given number is zero(0) in the matrix, So print three blankSpace and Bar |
            {
                cout<<"\033[43m  \033[0m \033[1;91m|\033[0m ";
            }
            else if(matrix[i][j]>=10) //if given number is one digit, So print number with two blankSpace and Bar |
                cout<<"\033[1;93m"<<matrix[i][j]<<" \033[1;91m|\033[0m ";
            else    //if given number is two digit, So print number with one blankSpace and Bar |
                cout<<"\033[1;93m"<<matrix[i][j]<<"  \033[1;91m|\033[0m ";
        }
        cout<<endl;
    }
    cout<<"\033[1;91m\t\t --------------------- \033[0m"<<endl; //lining on down
}
void NumShift_Game::createMatrix()
{
    int n=15,i,j;
    int num[n],index;
    for(i=0; i<15; i++) //These 1-15 number will be in the Matrix
        num[i]=i+1;
    int lastIndex=n-1;

    srand(time(NULL)); /*For Random Number Generator using time (Always different Number generat) */
    
    for(i=0; i<4; i++)
    {
        for(j=0; j<4; j++)
        {
            if(lastIndex>=0)
            {
                index=rand()%(lastIndex+1); // Rendom number generator And % operation (lastIndex+1)
                matrix[i][j]=num[index]; // Will give index, So put that num[index] number in matrix
                num[index]=num[lastIndex--]; // And repalce last number with this indexed position number
            }                                 // and finally lastIndex--
        }
    }
    matrix[i-1][j-1]=0; // last number is Zero 
}
int main()
{
    NumShift_Game Game;
    Game.gameRule();
    cout<<"\n\033[32mEnter any key to start.....\033[0m";
    getch(); //Enter any key for start Game
    system("cls"); //clear terminal/screen
    char name[25];
    cout<<"\n\t\033[36mPlayer Name : \033[0";
    Game.insertPlyN();
    
    Game.createMatrix(); //create matrix And store random number in matrix
    Game.showMatrix(); //show matrix 
    Game.play_Game_Or_moveNum();
    cout<<endl;
}