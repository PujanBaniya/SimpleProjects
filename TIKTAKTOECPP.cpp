#include<iostream>
#include<conio.h>
using namespace std;
int player=1;
int input;

char a[10]={'0','1','2','3','4','5','6','7','8','9'};
int board()
{	
	cout<<a[1]<<"|"<<a[2]<<"|"<<a[3]<<endl;
	cout<<"--------"<<endl;
	cout<<a[4]<<"|"<<a[5]<<"|"<<a[6]<<endl;
	cout<<"--------"<<endl;
	cout<<a[7]<<"|"<<a[8]<<"|"<<a[9]<<endl;	
	
}

int choiceAndswap()
{
	int value;
	player=(player%2==0)? 2:1;
	char choice=(player==1)? 'X':'O';//if player one then his/her sign is X
	cout<<"Player"<<player<<"  choose box:"<<endl;
	cin>>input;
//	cantReplace();//check either violation of rule or not
	if(a[input]=='X'|| a[input]=='O')
	{
		cout<<"\nCant replacce\n";
		exit(1);//ends game due to violation of rule
	}


	if(input <1 || input>9)
	{
	cout<<"Invalid choice";
	}
	a[input]= choice;//take to address not in value 	
	player++;// to change player
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
int main()
{
	int condition,result,value;
	cout<<"Lets play tiktactoe\n\n"<<endl;
	for(condition=1;condition<=9;condition++)
	{
	board();//to print the board after each iterations(choice)
	choiceAndswap();//takes input and check if the input is repeated or not if repeted=>exit(1); if not repetated then swap the player
	result= win();//catches the result
	
	if(result==1)
	{
		cout<<"Winner is player is"<<player-1;
		condition=99;
		board();
		cout<<"Winner is player is"<<player-1<<endl;
	}
}
	if(condition==10)
	cout<<"DRAW";
	getch();
	return 0;
}

