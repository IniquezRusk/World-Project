#include <iostream>
#include <string>
#include "read_words.h"

using namespace std;

// You may optionally implement and use this helper method.

void printGuessColors(string guess, string answer) {
    for (int i = 0; i < guess.length(); i++) {
             bool isRed = true;
            // For green letters - If it is in the exact place
                if ( guess.at(i) == answer.at(i) ) {
                    cout << guess.at(i) << " - Green" << endl;
                    isRed = false;
                }          
    
            // For yellow letters - If it is contained in the string, and not in the correct place  
                for (int j = 0; j < answer.length(); j++) {
                    if ( guess.at(i) == answer.at(j) && isRed ) {
                        cout << guess.at(i) << " - Yellow" << endl;
                        isRed = false;
                    } 
                }         

            // For red letters - Incorrect letter and placement
                if (isRed) {
                cout << guess.at(i) << " - Red" << endl;
                }        
    } 
}   

// Automatically converts all letters to lowercase to fit the lowercase guesses
string getLowerString(string str) {
  int ascii;
  char ch;
  string ret = "";
  
// For statement to convert the lowercase letters
  for ( int i = 0; i < str.length(); i++ ) {
    ch = str.at(i);
      if (ch >= 'A' && ch <= 'Z') {
        ascii = ch;
        ascii = ascii + 32;
        ch = ascii;
      }
      ret += ch;
  }
  return ret;


}

int main(int argc, char *argv[]) {
    // Gets a random word from a file.
    string answer = GetRandomWord(argc, argv);

    int index = 0;
    string userGuess = "";

    // While loop, set with a limit of 6 guesses til game loss.
    while ( userGuess != answer && index <= 6) {
        userGuess = "";  

        // If the user inputs the guess thats greater than 5 letters it will keep asking to put in a guess.
        while (userGuess.length() != 5 && index < 6) {
            // Asks user to guess a random word to start the game
            cout << "Enter a 5 letter guess?" << endl;
            cin >> userGuess;


        // If the user inputs capital letter it'll convert it to lower letter
        userGuess = getLowerString(userGuess);
        printGuessColors(userGuess, answer);
 

        // Will update every time the guess is wrong.
        index = index + 1;
        }

        // Statement for losing conditions
        if (index >= 6) {
            cout << "You lost. The answer was " << answer << "." << endl;
            return 0;
        }    

        // Statement for winning conditions 
    }
    cout << "You Won! That took " << index << " guess(es)." << endl;
    
    return 0;
}
