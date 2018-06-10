#include <ncurses.h>//nucrses library
#include <stdlib.h>//used for random
#include <iostream>//useid for output
#include <vector>//used for  letter vector
using namespace std;
void printLetters (vector<char> &letters, int x[], int y[], int &score){
    for(int i =0; i<letters.size(); i++){
        mvaddch(y[i], x[i], letters[i]);//print letters in x y cordinates
    }
    mvprintw(23, 0, "Current score is: %d. Press ESC to exit", score );//print score
    for(int i=0; i<100000; i++)
        refresh();//refrehh 1000000 times
}
void moveLetters (vector<char> &letters, int x[], int y[]){
    for (int i =0; i<10; i++){
        y[i]++;//changes the t cordinate up and down
    }
}
void findLetter (vector<char> &letters, char userInput, int &score){
    for(int i=0; i <letters.size(); i++){
        if(letters[i]==userInput){
            letters[i]='*';//changes the letter to star if user hits letter
            score++;//adds score
        }
    }
}
void destroyLetter(vector<char> &letters, int x[], int y[], int &missed){
    for(int i=0; i <letters.size(); i++){
        if(letters[i]=='*'){//finds stars and replaces with a space
            letters[i]=' ';
            x[i]=rand()%80;//new x cordinate
            y[i]=0;//starts the letter back to y cordinate 0
            letters[i] = rand()%26+'a';//new letter
        }
    }
    for (int i =0; i < letters.size();i++){
        if (y[i]==24){//resets letter if it goes off the window
            x[i]=rand()%80;
            y[i]=0;
            letters[i] = rand()%26+'a';//new letter
            missed++;//adds to missed
        }
    }
}
int main(void){
    srand (time(NULL));//random generator
	initscr();//initilize screen
    nodelay(stdscr,TRUE);//for no inpt delay
    noecho();//no output of input
    char userInput;//user Input
    vector <char>  letters(10);//vector for all letters
    int x[10], y[10];//x and y
    int score=0, missed=0;//score and missed gernatror
    for (int i=0; i<10; i++){//new letter and cordinate
        letters[i] = (rand()%26+'a');
        x[i] = rand()%80;
        y[i] = 0;
    }
    while(userInput !=27){//loop until user hits esc
        clear();//clear screeen
        findLetter(letters, userInput, score);//find letter
        printLetters (letters,x,y, score);//print everything
        moveLetters (letters,x,y);//move letters
        destroyLetter(letters, x,y,missed);//destroy and add new letters if missed
        userInput =getch();//user Input
    }
	endwin();//end ncurese
    cout<< "Total Score: " << score << endl;//total score output after game ends
    cout<< "Total Missed: " << missed << endl;//total missed output after game ends
    return 0;
}
