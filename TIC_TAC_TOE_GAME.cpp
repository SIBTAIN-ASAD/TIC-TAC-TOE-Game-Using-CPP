//This Program is a TIC TAC TOE game

#include<iostream>
#include<string>				 //liberary used for input strings
#include<cstdlib>				 //liberary used for system("pause") and system("cls")

using namespace std;

//GLOBLE constants
const int row = 3;
const int col = 3;


//Function prototypes
void populateArray(char [][col], int);
void displayScreen(char [][col], int, string, string);
void game(char [][col], int, string ,char);
bool check(char [][col], int, char);
void conclude(string);
void tie();



/********************************************************
*														*
*                    main Function                      *
*														*			
********************************************************/
int main()
{
	
	//variable declaration
	string play1;
	string play2;
	
	char ch;
	char again;
	bool result = false;

	//2D array for game
	char arr[row][col];
	
	
	//printing first screen
	cout << "\n\t\t ********************************************\n\n";
	cout <<   "\t\t **   WELCOME TO THE TIC TAC TOE GAME      **\n\n";
	cout <<   "\t\t ********************************************\n\n";

	//input name of player 1
	cout << "\t\t   Enter the player's name for 'X': "      	     ;
	getline(cin, play1);

	//input name of player 2
	cout << "\t\t   Enter the player's name for 'O': "    	         ;
	getline(cin, play2);

	cout << "\n\t\t ********************************************\n\n";

	//pause the screen for a while
	system("pause");


// use the loop to play games again and again   
do{
	
		populateArray(arr, row);                     //calling function to fill array
		
		for (int count = 0; count < 5; count++)      //loop for run game for each player
		{
			
			displayScreen(arr, row, play1, play2);   //calling function to display array
			ch = 'X';								 //using 'X' in char for player one
			game(arr, row, play1, ch);				 //calling function for player one's game
			
			result = check(arr, row, ch);			 //calling function to check weither any of the winner
			
			if(result)								 //checking and printing output in case of winnig player one
			{
				conclude(play1);					 //calling output function
				break;
			}
			
			if(count == 4)							// check in case of match tie
			{
				tie();							    //calling tie output function
				break;
			}
		
			displayScreen(arr, row, play1, play2);				//calling function to display array
			
			ch = 'O';								//using 'O' in char for player one
			game(arr, row, play2, ch);				//calling function for player two's game
			
			result = check(arr, row, ch);			//calling function to check weither any of the winner
			
			if(result)								//checking and printing output in case of winnig player two
			{
				conclude(play2);					//calling output function
				break;
			}
			
			displayScreen(arr, row, play1, play2);				//calling function to display array
		}
		
			//asking user to play again
			cout << " Want to play again? (Y/N)... ";
			cin  >> again;
				//checking input validation
				while(again !='y' && again !='Y' && again !='n' && again !='N' ) 
				{
					cout << "Please just press 'Y' or 'N'... ";
					cin  >> again ;
				}	
				
				system("cls");
}
while(again == 'Y' || again =='y' );

	return 0;
}




/********************************************************
*														*
*  //Function for populating 2D array with '*'          *
*														*			
********************************************************/
void populateArray(char arr[][col], int row)
{
	
	for(int j = 0; j < col; j++)
	{
		for(int i = 0; i<row; i++)
		{
			arr[i][j] = '*';
		}
	}

}


 
/********************************************************
*														*
*         Function for displaying 2D array              *
*														*			
********************************************************/
void displayScreen(char arr[][col], int row, string play1, string play2)
{
	system("cls");  	  //clearing screen

	cout << "\n\n";
	cout << "     *******************************\n";
	cout << "     *                             *\n";
	cout << "     *     TIC TAC TOE GAME        *\n";
	cout << "     *                             *\n";
	cout << "     *******************************\n";
	cout << "\n\n";

	cout << "     " << play1 << " <X>   -   " << play2 << " <O> \n\n"; 	
	for(int i = 0; i < row; i++)
	{
		cout << endl << "       ";
		for(int j = 0; j<col; j++)
		{
			cout << "   " << arr[i][j] << "  " ;
		} 
		cout << endl ;
	}
	
}



/********************************************************
*														*
*    Function for user input row and colum              *
*														*			
********************************************************/
void game(char arr[][col], int row, string player, char ch)
{
	
	int i; //variable for row
	int j; //variable for colum
	
	cout << "\n   " << player << "'s turn: \n";
	
	cout << "\n   Select the row: ";
	cin  >> i;

	//input validation for number of rows
	while(i < 1 || i > 3)     
	{
		cout <<  "\n\n   ************** ERROR **************\n";
		cout <<      "   Please select a valid number of row\n";
		cout <<      "   (1 to 3)\n";
		
		cout << "\n   Select the row: ";
		cin  >> i;
	}

	cout << "   Select the colum: ";
	cin  >> j;

	//input validation for number of colums	
	while(j < 1 || j > 3)
	{
		cout <<  "\n\n   ************ ERROR *************\n";
		cout << "   Please select a valid number of colum\n";
		cout << "   (1 to 3)\n";
		
		cout << "\n   Select the colum: ";
		cin  >> j;
	}
	
	
	//input validation for not to rewrite at the already selected space
	while(arr[i-1][j-1] == 'X' || arr[i-1][j-1] == 'O')
	{
			cout << "\n\n   ************ ERROR *********\n";
			cout <<     "   Please select an empty space\n";
	
			cout << "\n   Select the row: ";
			cin  >> i;
			
				//input validation for number of rows
				while(i < 1 || i > 3)
				{
					cout <<  "\n\n   ************ ERROR ***********\n";
					cout << "   Please select a valid number of row\n";
					cout << "   (1 to 3)\n";
					
					cout << "\n   Select the row: ";
					cin  >> i;
				}

			
			cout << "   Select the colum: ";
			cin  >> j;
			
				//input validation for number of colums
				while(j < 1 || j > 3)
				{
					cout <<  "\n\n   ************** ERROR **************\n";
					cout <<      "   Please select a valid number of colum\n";
					cout <<      "   (1 to 3)\n";
					
					cout << "\n   Select the colum: ";
					cin  >> j;
				}			
	}
	
	//selecting the place of user input with respected character ('X' or 'O')
	arr[i-1][j-1] = ch;
		
	
}



/********************************************************
*														*
* Function for checking is there the player win or not  *
*														*			
********************************************************/
bool check(char arr[][col], int row, char ch)
{
	//variable for check
	bool flag = false;
	
	//checking colums 
	for(int j = 0; j < 3; j++)
	{	
		if(arr[0][j] == ch && arr[1][j] == ch && arr[2][j] == ch)
		{
			flag = true;
		}
	}

	//checking rows
	for(int i = 0; i < 3; i++)
	{	
		if(arr[i][0] == ch && arr[i][1] == ch && arr[i][2] == ch)
		{
			flag = true;
		}
	}
	
	//checking diagonal from left to right
	if(arr[0][0] == ch && arr[1][1] == ch && arr[2][2] == ch)
	{
		flag = true;
	}
	
	//checking diagonal from right to left
	if(arr[0][2] == ch && arr[1][1] == ch && arr[2][0] == ch)
	{
		flag = true;
	}

	return flag;
}



/********************************************************
*														*
*  Function for displaying output if any player wins    *
*														*			
********************************************************/
void conclude(string player)
{
	system("cls");
	cout << "\n\n \t\t **********************************************\n";
	cout << " \t\t    Congratulations " << player << " . "    << endl   ;
	cout << " \t\t     You WON the game!!!  \n";
	cout << " \t\t **********************************************\n\n\n";
}




/********************************************************
*														*
*  Function for displaying output in case of tie        *
*														*			
********************************************************/
void tie()
{
	system("cls");
	cout << "\n\n \t\t *******************************\n";
	cout << " \t\t    The match is TIE !!! " << endl ;
	cout << " \t\t *******************************\n\n\n";
	
}


