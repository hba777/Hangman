#include<iostream>
using namespace std;
#include<cstring>
#include<iomanip>

//Output based on guesses
int Guesses(int guesses, string word, char guess_word)

{	
    while(guesses >= 0)
    {
        cout<<"\nYou have "<<guesses<<" left";
        if(guesses == 7)
        {
            cout<<endl<<"_______"<<endl;
            cout<<"|"<<endl;
            cout<<"|"<<endl;
            cout<<"|"<<endl;
            cout<<"|"<<endl;
            cout<<"|______";
            break;
        }
        else if(guesses == 6)
        {
            cout<<endl<<"_______"<<endl;
            cout<<"|     O"<<endl;
            cout<<"|"<<endl;
            cout<<"|"<<endl;
            cout<<"|"<<endl;
            cout<<"|______"<<endl;
            break;
        }
        else if(guesses == 5)
        {
            cout<<endl<<"_______"<<endl;
            cout<<"|     O"<<endl;
            cout<<"|     |"<<endl;
            cout<<"|"<<endl;
            cout<<"|"<<endl;
            cout<<"|______"<<endl;
            break;
        }
        else if(guesses == 4)
        {
            cout<<endl<<"_______"<<endl;
            cout<<"|     O"<<endl;
            cout<<"|    /|"<<endl;
            cout<<"|"<<endl;
            cout<<"|"<<endl;
            cout<<"|______"<<endl;
            break;
        }
        else if(guesses == 3)
        {
            cout<<endl<<"_______"<<endl;
            cout<<"|     O"<<endl;
            cout<<"|    /|\\"<<endl;
            cout<<"|"<<endl;
            cout<<"|"<<endl;
            cout<<"|______"<<endl;
            break;
        }
        else if(guesses == 2)
        {
            cout<<endl<<"_______"<<endl;
            cout<<"|     O"<<endl;
            cout<<"|    /|\\"<<endl;
            cout<<"|     |"<<endl;
            cout<<"|"<<endl;
            cout<<"|______"<<endl;
            break;
        }
        else if(guesses == 1)
        {
            cout<<endl<<"_______"<<endl;
            cout<<"|     O"<<endl;
            cout<<"|    /|\\"<<endl;
            cout<<"|     |"<<endl;
            cout<<"|    /"<<endl;
            cout<<"|______"<<endl;
            break;
        }
        else if(guesses == 0)
        {
            cout<<endl<<"_______"<<endl;
            cout<<"|     O"<<endl;
            cout<<"|    /|\\"<<endl;
            cout<<"|     |"<<endl;
            cout<<"|    / \\"<<endl;
            cout<<"|______"<<endl;
            cout<<"You lost"<<endl;
            cout<<"The word was "<<word;
            exit(0);
        }
    }
    return 0;
}

//Display guessed words
void DisplayGuesses(string words_guessed[], char guess_word, int check)
{
	cout<<"\nYou have guessed:"<<setw(2);
	for(int i=0;i<=check;i++)
		{
		cout<<words_guessed[i]<<" ";
		}
}

int main()
{
	//Word and empty space initialization
    string word="charming";

    string empty_spaces;
    
    string words_guessed[25];
    
    //Assign emptyspaces = word length
    for(int i=0;i<word.length();i++)
    {
    	empty_spaces.append("_");
	}
	
    int guesses=7,i=0,check=0;

//Wrong guess check
	bool fail=false;
	
    char guess_word;

//Display Hangman Board once
    Guesses(guesses,word,guess_word);
    cout<<endl<<empty_spaces;
    
    //Checking if empty spaces are filled
    while(empty_spaces != word)
    {
    cout<<"\nYour guess:";	
    cin>>guess_word;
    words_guessed[check]=guess_word;
    
    fail = false;
    	for(i=0;i<word.length();i++)
		{	    
    	    if(guess_word == word[i]) 
        	{
           		empty_spaces[i]=word[i];
            	Guesses(guesses,word,guess_word);
            	cout<<endl<<empty_spaces;
            	check++;
				fail=true;	
    		}
        
    	}
    
        if(fail==false)
		{
			check++;
			guesses--;
			Guesses(guesses,word,guess_word);
			cout<<endl<<empty_spaces;
		}

		DisplayGuesses(words_guessed, guess_word,check);    
    }
    cout<<"\nYou Won !!!";

}
