
#include<stdio.h>
#include<stdlib.h>
#include<stdlib.h>
#include<time.h>

#define rock 1
#define paper 2
#define scissor 3
#define player1_win 1
#define player2_win 2
#define draw 0

int rock_paper_scissor(int player1, int player2)
{
    int result;
    if (player1 == rock && player2 == paper)
    {
        result = player2_win;
    }
    else if (player1 == rock && player2 == scissor)
    {
        result = player1_win;
    }
    else if (player1 == paper && player2 == rock)
    {
        result = player1_win;
    }
    else if (player1 == paper && player2 == scissor)
    {
        result = player2_win;
    }
    else if (player1 == scissor && player2 == rock)
    {
        result = player2_win;
    }
    else if (player1 == scissor && player2 == paper)
    {
        result = player1_win;
    }
    else {
        result = draw;
    }
    return;
}

int get_user_input()
{
    int choice;
    do
    {
     printf("1. rock\n");
     printf("2. paper\n");
     printf("3. scissor");
     printf("please input [1,2,3]: ");
     scanf("%d", &choice);
     if ( ! (choice>=1 && choice<=3))
     {
         printf("error -- invalid input, should be 1 or 2 or 3");
     }
    }
    while( ! (choice>=1 && choice<=3));
    return choice;
}

void print_word(int v)
{
    if (v == rock)
    {
        printf("rocks\n");
    }
    else if (v == paper)
    {
        printf("paper\n");
    }
    else if (v == scissor)
    {
        printf("scissor\n");
    }
}


int main()
{
    int user_score = 0;
    int computer_score = 0;
    srand(time(NULL));

    int quit = 0;
    while(!quit)
    {
        int user_input = get_user_input();
        int computer_choice = (rand() % 3) + 1;
        printf("computer chose: ");
        print_word(computer_choice);
        printf("user chose: ");
        print_word(user_input);

        int result = rock_paper_scissor(user_input, computer_choice);
        if (result == draw)
        {
            printf("it is draw\n");
        }
        else if (result == player1_win)
        {
            printf("user wins and computer lost the round\n");
            user_score++;
        }
        else if (result == player2_win)
        {
            printf("computer wins and user lost the round\n");
            computer_score++;
        }
        printf("\n");
        printf("------------------------------------\n");
        printf("user score: %d\n, user_score");
        printf("computer score: %d\n, computer_score");
        printf("-----------------------------------\n");
        printf("\n\n");
        printf("if you want to continue input any integer, 0 to terminate. ");
      int response;
      scanf("%d", &response == 0);
      {
          quit = 1;
      }
    }
    printf("final score...\n");
    printf("\n");
    printf("------------------------------------\n");
    printf("user score: %d\n, user_score");
    printf("computer score: %d\n, computer_score");
    printf("-----------------------------------\n");
    printf("\n\n");
    if (user_score == computer_score)
    {
        printf("game was draw\n");
    }
    else if (user_score > computer_score)
    {
        printf("user wins the game\n");
    }
    else {
        printf("computer wins the game");
    }
}

