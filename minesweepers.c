#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FLUSH fflush(stdin)

void difficulty( void );
void beginner( void );
void intermediate( void );
void expert( void );
void minefield_generator( void );
void print_minefield( void );
void guess( void );
void boom( void );
void print_final_minefield( void );
void win( void );
void play_again( void );
void game_over( void );

int x, y;
int M, N;
float diff;
int total_mines = 0;
int mines = 0;
int minefield[30][30];                                      //contains all of the mines, numbers and blank spaces
int blank_minefield[30][30];                                //contains the minefield full of '|-|' characters
int final_minefield[30][30];

int main()
{
    printf("\t\tWelcome to Minesweeper\n");
    difficulty();
    return 0;
}

void difficulty( void )                                     //difficulty level
{
    diff = 0;
    while( (diff != 1) && (diff != 2) && (diff != 3) && (diff != 4))
    {
        printf("\t\tChoose a difficulty level(1-4):");
        scanf("%f", &diff);
        FLUSH;
        if( (diff != 1) && (diff != 2) && (diff != 3) && (diff != 4))
        {
            printf("\t\tPlease enter either 1, 2, 3 or 4\n");
        }
    }

    if( diff == 1 )
    {
        beginner();
    }
    else if( diff == 2 )
    {
        intermediate();
    }
    else if( diff == 3 )
    {
        expert();
    }
    else if(diff == 4)
    {
        custom();
    }
}
void beginner( void )                                      //4X4 grid
{
    M = 4;
    N = 4;
    total_mines = 4;
    minefield_generator();
    guess();
}

void intermediate( void )                                  // 6X6 grid
{
    M = 6;
    N = 6;
    total_mines = 6;
    minefield_generator();
    guess();
}

void expert( void )                                        //10X10 grid
{
    M = 10;
    N = 10;
    total_mines = 99;
    minefield_generator();
    guess();
}

void custom ( void )
{
    M = 0;
    N = 0;
    total_mines = 0;
    printf("\t\tEnter no. of rows: ");
    scanf("%d", &M);
    printf("\t\tEnter no. of columns: ");
    scanf("%d", &N);
    printf("\t\tEnter no. of mines: ");
    scanf("%d", &total_mines);
    minefield_generator();
    guess();
}

void minefield_generator( void )                            //generates the minefield
{
    int i = 0, j = 0;

    srand( time( NULL ) );                                  //random no. generator

    while( j < N )                                          //Nested loop for making the blank minefield and final minefield
    {
        while( i < M)
        {
            minefield[i][j] = '-';
            blank_minefield[i][j] = minefield[i][j];
            final_minefield[i][j] = minefield[i][j];
            i++;
        }
        i = 0;
        j++;
    }
    mines = 0;
    while( mines < total_mines )                            //Randomly generates mines
    {
        i = rand()%(M);
        j = rand()%(N);
        if( minefield[i][j] != '*')                         //Checks for mine
        {
            minefield[i][j] = '*';
            final_minefield[i][j] = minefield[i][j];
            mines++;
        }
    }
    i = 0;
    j = 0;

    while( j < N )                                          //While loop that generates the numbers for any adjacent mines
    {
        while( i < M)
        {
            if( minefield[i][j] != '*')
            {
                minefield[i][j] = 0;
            }
            if((minefield[i-1][j-1] == '*') && (minefield[i][j] != '*'))
            {
                minefield[i][j]++;
            }
            if((minefield[i-1][j] == '*') && (minefield[i][j] != '*'))
            {
                minefield[i][j]++;
            }
            if((minefield[i][j-1] == '*') && (minefield[i][j] != '*'))
            {
                minefield[i][j]++;
            }
            if((minefield[i-1][j+1] == '*') && (minefield[i][j] != '*'))
            {
                minefield[i][j]++;
            }
            if((minefield[i+1][j-1] == '*') && (minefield[i][j] != '*'))
            {
                minefield[i][j]++;
            }
            if((minefield[i+1][j] == '*') && (minefield[i][j] != '*'))
            {
                minefield[i][j]++;
            }
            if((minefield[i][j+1] == '*') && (minefield[i][j] != '*'))
            {
                minefield[i][j]++;
            }
            if((minefield[i+1][j+1] == '*') && (minefield[i][j] != '*'))
            {
                minefield[i][j]++;
            }
            i++;
        }
        i = 0;
        j++;
    }
    i = 0;
    j = 0;
}

void print_minefield(void)                                  // This function prints the minefield
{
    int i = 0, j = 0, z = 0;
    while( z < M )                                          // prints co-ordinates along the x axis
    {
        if( z == 0 )
        {
            printf("\t");
        }
        printf("|%d|\t", z);
        z++;
    }
    printf("\n\n");

    while( j < N )                                          // Loop that prints out each character in the minefield
    {
        printf("|%d|\t", j);
        while( i < M)
        {
            if( blank_minefield[i][j] == '-')
            {
                printf("|%c|\t", blank_minefield[i][j]);

            }
            else if( minefield[i][j] == 0 )                 // Change null values to letter 'B'
            {
                blank_minefield[i][j] = 'B';
                printf("|%c|\t", blank_minefield[i][j]);
            }
            else
            {
                printf("|%d|\t", blank_minefield[i][j]);

            }
            i++;
        }
        printf("\n");
        i = 0;
        j++;
    }
}


void guess( void )
{
    int i = 0, j = 0, match=0;
    print_minefield();
    while( i < M )                                          // Checking if the mines are cleared
    {
        while( j < N )
        {
            if(minefield[i][j] == blank_minefield[i][j])
            {
                match++;
            }
            j++;
        }
        j = 0;
        i++;
    }
    if( match == (( M * N ) - total_mines))                 // If mines cleared, player wins
    {
        win();
    }
    printf("\nEnter the x value, then a space, then the y value:");
    scanf("%d %d", &y, &x);                                 // User input for mine
    FLUSH;
    if( (x >= M) || (x < 0) || (y < 0) || (y >= N) )
    {
        printf("\nPlease enter a value inside the grid\n");
        guess();
    }
    if( minefield[x][y] == '*' )
    {
        boom();
    }
    if( blank_minefield[x][y] != '-' )
    {
        printf("\nPlease enter a value that has not already been entered\n");
        guess();
    }

    else                                                // Checks if the adjacent spaces are blank
    {
        blank_minefield[x][y] = minefield[x][y];
        if( minefield[x][y] == 0 )
        {
            if( minefield[x-1][y-1] == 0 )
            {
                blank_minefield[x-1][y] = minefield[x-1][y];
            }
            if( minefield[x-1][y] == 0 )
            {
                blank_minefield[x-1][y] = minefield[x-1][y];
            }
            if( minefield[x][y-1] == 0 )
            {
                blank_minefield[x][y-1] = minefield[x][y-1];
            }
            if( minefield[x-1][y+1] == 0 )
            {
                blank_minefield[x-1][y+1] = minefield[x-1][y+1];
            }
            if( minefield[x+1][y-1] == 0 )
            {
                blank_minefield[x+1][y-1] = minefield[x+1][y-1];
            }
            if( minefield[x+1][y] == 0 )
            {
                blank_minefield[x+1][y] = minefield[x+1][y];
            }
            if( minefield[x][y+1] == 0 )
            {
                blank_minefield[x][y+1] = minefield[x][y+1];
            }
            if( minefield[x+1][y+1] == 0 )
            {
                blank_minefield[x+1][y+1] = minefield[x+1][y+1];
            }
        }
        guess();
    }
}

void boom( void )                                       // Mine explodes
{
    print_final_minefield();
    printf("\n\t\tYou hit a mine at %d,%d\n\t\tYOU LOSE!!!!", x, y);
    play_again();
}

void print_final_minefield( void )                      // Prints minefield
{
    int i = 0, j = 0, z = 0;
    while( z < M )
    {
        if( z == 0 )
        {
            printf("\t");
        }
        printf("|%d|\t", z);
        z++;
    }
    printf("\n\n");

    while( j < N )
    {
        printf("|%d|\t", j);
        while( i < M)
        {
            printf("|%c|\t", final_minefield[i][j]);
            i++;
        }
        printf("\n");
        i = 0;
        j++;
    }
}

void win( void )                                        // Win
{
    printf("\n\n\n\t\t\tYOU WIN!!!!!\n\n\n");
    play_again();
}

void play_again( void )                                 // Play again
{
    char option[2];
    printf("\n\t\tWould you like to play again(Y/N)?:");
    scanf("%c", &option[0]);
    FLUSH;
    if((option[0] == 'Y') || (option[0] == 'y'))        // Restart program
    {
        difficulty();
    }
    else if( (option[0] == 'N') || (option[0] == 'n'))
    {
        game_over();
    }
    else
    {
        printf("Please enter either Y or N");
        play_again();
    }
}

void game_over( void )                                  // End program
{
    printf("\n\n\t\tGame Over");
    exit(1);
}
