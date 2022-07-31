#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int x = 5;
int y = 5;

struct wall
{
    char xwalls[32];
};

wall walls[16];

// I will make some software that does this automatically in the future
void wallsInit()
{
    for(int i = 0; i < 32; i++)
        walls[0].xwalls[i] = '#';

    for(int i = 1; i < 15; i++)
        for(int k = 0; k < 16; k++)
        {
            walls[i].xwalls[0] = '#';
            for(int j = 1; j < 31; j++)
               walls[i].xwalls[j] = ' ';
            walls[i].xwalls[31] = '#'; 
        }
    
    for(int i = 0; i < 32; i++)
        walls[15].xwalls[i] = '#';
}

void drawWalls()
{
    for(int i = 0; i < 16; i++)
    {
        for(int k = 0; k < 32; k++)
            cout << walls[i].xwalls[k];
        cout << "\n";
    }
}

int main()
{
    system("clear");
    char c;

    //cout << "\033[0;37mTerminal\033[1;31Dungeon\033[0;37m v0.01\033[0m\n";

    // Hide the cursor
    printf("\e[?25l");

    while(1) {
        
        // Set the terminal to raw mode
        system("stty raw");
        c = getchar(); 
        // terminate when "." is pressed
        system("stty cooked");
        system("clear");

        wallsInit();
        drawWalls();
        cout << "\033[0;37mTerminal\033[1;31mDungeon\033[0;37m v0.01\033[0m\n";
        cout << "Press '.' to quit, use arrow keys to move\n\n";
        //cout << "\033[1;32m[DEBUG] X:" << x << ", Y:" << y << "\n\033[0m";
        //cout << "\033[" << y << ";" << x << "f";

        
        if(x > 31)
            x = 31;
        
        if(y < 1)
            y = 1;

        if(c == 'C')
        {
            if(walls[y - 1].xwalls[x] != '#')
            {
                x++;
                cout << "\033[" << y << ";" << x << "f";
                std::cout << "\033[1;32m$" << std::endl;
            }
            else
            {
                
                cout << "\033[" << y << ";" << x << "f";
                std::cout << "\033[1;32m$" << std::endl;
            }

        }
        else if(c == 'D')
        {
            if(walls[y - 1].xwalls[x - 2] != '#')
            {
                x--;
                cout << "\033[" << y << ";" << x << "f";
                std::cout << "\033[1;32m$" << std::endl;
            }
            else
            {
                
                cout << "\033[" << y << ";" << x << "f";
                std::cout << "\033[1;32m$" << std::endl;
            }

        }
        else if(c == 'A')
        {
            if(walls[y + 13].xwalls[x - 1] != '#')
            {
                y--;
                cout << "\033[" << y << ";" << x << "f";
                std::cout << "\033[1;32m$" << std::endl;
            }
            else
            {
                
                cout << "\033[" << y << ";" << x << "f";
                std::cout << "\033[1;32m$" << std::endl;
            }

        }
        else if(c == 'B')
        {
            if(walls[y - 15].xwalls[x - 1] != '#')
            {
                y++;
                cout << "\033[" << y << ";" << x << "f";
                std::cout << "\033[1;32m$" << std::endl;
            }
            else
            {
                
                cout << "\033[" << y << ";" << x << "f";
                std::cout << "\033[1;32m$" << std::endl;
            }

        }
        else
        


        if(c == '.') {
            system("stty cooked");
            system("clear");
            // Show cursor
            cout << "\033[1;31mThanks \033[0mfor playing!\n";
            cout << "\033[0mCheck out the repository at \033[1;32mhttps://github.com/PancakeHat/terminaldungeon/ \n";
            printf("\e[?25h");
            exit(0);
        }  
    
    }
    return 0;
}

// < D ^A >c *B