#include<stdio.h>
//Board
char board[3][3]={'1','2','3','4','5','6','7','8','9'};
//Drawing the board
void drawboard()
{
    for(int i=0; i<3; i++)  //Here, printing row..if we print row automatically column will also print..
    {
        printf("%c  |  %c  |  %c\n",board[i][0],board[i][1],board[i][2]);
        if(i!=2)
        {
            printf("---|-----|---\n");
        }
    }
}
//For checking game status i.e., return 1 for win and return 2 for draw
int check()
{
    //Checking row
    for(int i=0; i<3; i++)
    {
        if(board[i][0]==board[i][1] && board[i][1]==board[i][2])
        {
            return 1;
        }
    }
    //Checking column
    for(int i=0; i<3; i++)
    {
        if(board[0][i]==board[1][i] && board[1][i]==board[2][i])
        {
            return 1;
        }
    }
    //Checking diagonal
    if(board[0][0]==board[1][1] && board[1][1]==board[2][2])
    {
        return 1;
    }
    //Checking diagonal
    if(board[2][0]==board[1][1] && board[1][1]==board[0][2])
    {
        return 1;
    }
    //Checking for draw i.e., If all cells are filled up and still there is no winner we will call this has a draw...
    int count=0;
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(board[i][j]!='X' && board[i][j]!='O')
            {
                count++;
            }
        }
    }
    if(count==0)
    {
        //Draw
        return 2;
    }
    return 0;
}
int main(void)
{
    int row,column,move,gamestatus;
    int player=1;
    while(1)
    //Running an infinite loop
    {
        drawboard();
        //Using ternary operator
        player=(player%2)?(1):(2);
        printf("Player %i move : ",player);
        scanf("%i",&move);
        //Defining row
        row=(move-1)/3;
        //Defining column
        column=(move-1)%3;
        if(board[row][column]!='X' && board[row][column]!='O')
        //Checking valid input
        {
            if(player==1)
            //Using Nested if
            {
                board[row][column]='X';
            }
            else
            {
                board[row][column]='O';
            }
        }
        else
        {
            printf("This cell is already filled!!Please try unfilled cell!!\n");
            player--;
        }
        gamestatus=check();
        if(gamestatus==1)
        {
            drawboard();
            printf("Player %i win\n",player);
            break;
        }
        if(gamestatus==2)
        {
            drawboard();
            printf("Draw");
            break;
        }
        player++;
    }
    return 0;
}