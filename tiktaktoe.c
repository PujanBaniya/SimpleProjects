#include<stdio.h>
#include<stdlib.h>//just to use exit() function
int board();
int cantReplace();
int win();
int input;
char a[10]={'0','1','2','3','4','5','6','7','8','9'};
int player=1;
int choiceAndswap();
void main()
{
	int condition,result,value;
	printf("Lets play tiktactoe\n\n");
	for(condition=1;condition<=9;condition++)
	{
	board();//to print the board after each iterations(choice)
	choiceAndswap();//takes input and check if the input is repeated or not if repeted=>exit(1); if not repetated then swap the player
	result= win();//catches the result
	
	if(result==1)
	{
		printf("Winner is player %d\n",player-1);
		condition=99;
		board();
		printf("Winner is player %d\n",player-1);
	}
}
	if(condition==10)
	printf("DRAW");
}

int choiceAndswap()
{
	int value;
	player=(player%2==0)? 2:1;
	char choice=(player==1)? 'X':'O';//if player one then his/her sign is X
	printf("Player %d choose box:",player);
	scanf("%d",&input);
	cantReplace();//check either violation of rule or not
	if(input <1 || input>9)
	{
	printf("Invalid choice");
	}
	a[input]= choice;//take to address not in value 	
	player++;// to change player
}


int board()
{	
	printf("%c|%c|%c\n",a[1],a[2],a[3]);
	printf("--------\n");
	printf("%c|%c|%c\n",a[4],a[5],a[6]);
	printf("--------\n");
	printf("%c|%c|%c\n",a[7],a[8],a[9]);
	
	
}
int cantReplace()
{
	if(a[input]=='X'|| a[input]=='O')
	{
		printf("\nCant replacce\n");
		exit(1);//ends game due to violation of rule
	}
	
}

int win()
{	
//all the conditions for winning
	if(a[1]==a[2]&&a[2]==a[3])
	return 1;
	else if(a[1]==a[4]&&a[4]==a[7])
	return 1;
	else if(a[1]==a[5]&&a[5]==a[9])
	return 1;
	else if(a[2]==a[5]&&a[5]==a[8])
	return 1;
	else if(a[3]==a[6]&&a[6]==a[9])
	return 1;
	else if(a[4]==a[5]&&a[5]==a[6])
	return 1;
	else if(a[7]==a[8]&&a[8]==a[9])
	return 1;
	else if(a[3]==a[5]&&a[5]==a[7])
	return 1;
	else
	return 0;
}


