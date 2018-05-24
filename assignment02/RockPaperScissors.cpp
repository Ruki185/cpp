#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

/*
 * Determines if choice1 beats choice2.
 *
 * Valid values for both parameters are:
 * 1: Rock
 * 2: Paper
 * 3: Scissors
 *
 * Rock beats Scissors, Paper beats Rock, Scissors beat Paper.
 *
 * Returns true if choice1 beats choice2
 */

//draws don't need to be implemented here
//draw magic happens in play()
bool beats(int choice1, int choice2)  {
    switch (choice1)  {
      case 1: if (choice2 == 2)
                return false;
              else
                return true;
      case 2: if (choice2 == 3)
                return false;
              else
                return true;
      case 3: if (choice2 == 1)
                return false;
              else
                return true;
      default: return -1;
    }
}

//based on choiceToString to print out the player's choice for each game
const char* choiceToString(int choice)  {
     switch(choice)  {
         case 1:
             return "Rock";
         case 2:
             return "Paper";
         case 3:
             return "Scissors";
         //hopefully unreachable
         default:
             return "invalid";
     }
}

/*
 * Performs a game of Rock-Paper-Scissors.
 *
 * Prompts the player for a choice of Rock, Paper or Scissors (1, 2 or 3)
 * and chooses a second choice to play against.
 *
 * Displays the choice of the player and computer.
 *
 * Returns true if the player wins, false if the player loses.
 * Repeats the game in case of a draw.
 */

//invalid choices might not be needed for the task, but apparently I can't read so it's there anyway
bool play() {
  while(true) {
    int choice1 = 0;
    cout << "1 = Rock, 2 = Paper, 3 = Scissors\n";

    while(true) {
      cin >> choice1;
      if(choice1 < 1 || choice1 > 3)  {
          cout << "Invalid choice, do it again.\n";
          continue;
      }
      break;
    }

    int choice2 = 1+(rand()%3);

    cout << "You chose " << choiceToString(choice1) << '\n';
    cout << "The other player chose " << choiceToString(choice2) << '\n';

    //check whether it ends in a draw or not, if yes, repeat the choice
    if (choice1 == choice2) {
      cout << "It's a draw! Choose again!\n\n";
      continue;
    }
    else
      return beats(choice1, choice2);
  }
}

//n can only be 3 or 5, depending on which game mode the player chose
/* Bonus Implementation
 * If a player has 3 points in a Best of Five and the other has zero, for example:
 * The game ends, because one of the players has no chance of winning anymore.
 * It was unclear whether this should be implemented or not.
 */
bool bestOf(int n)  {
  int player1 = 0;
  int player2 = 0;

  for (int i = 0; i < n; i++) {
    if (play() == true) {
      player1++;
      cout << "Point for you! " << player1 << ":" << player2 << "!\n\n";
    }
    else  {
      player2++;
      cout << "Point for your foe! " << player1 << " : " << player2 << "!\n\n";
    }
    if ((n == 3 && player1 == 2 && player2 != 1) || (n == 5 && player1 == 3 && player2 != 2))  {
      cout << "Your foe has no chance of winning." << '\n';
      break;
    }
    if ((n == 3 && player2 == 2 && player1 != 1) || (n == 5 && player2 == 3 && player1 != 2))  {
      cout << "You have no chance of winning.\n";
      break;
    }
  }

  if (player1 > player2)
    return true;
  else
    return false;
}

// since bestOf3() and bestOf5() have pretty much the same code, the magic happens in bestOf() with an int for counting played games

/*
 * Performs three games of Rock-Paper-Scissors and returns true if the player
 * wins at least two of them.
 */
bool bestOf3()  {
    return bestOf(3);
}

/*
 * Performs five games of Rock-Paper-Scissors and returns true if the player
 * wins at least three of them.
 */
bool bestOf5()  {
  return bestOf(5);
}


/******************************************************************************/
// Template code starts here. Please do not edit beyond this point.
/******************************************************************************/

/*
 * Converts a game mode choice into the game mode's name for display purposes.
 *
 * Note: we can only return a raw pointer here because string literals have
 * static storage duration i.e. they survive for the whole run time of the
 * program. Returning a pointer to something that is not a string literal
 * would be dangerous!
 */
const char* gameModeToString(int mode)  {
    switch(mode)  {
        case 1:
            return "Single";
        case 2:
            return "Best of Three";
        case 3:
            return "Best of Five";
        default:
            return "invalid";
    }
}


int main()  {
    // Initialize random seed
    srand(time(nullptr));

    int mode = 0;
    while(true) {
        cout << "Choose a game mode: \n"
             << "1: " << gameModeToString(1) << "\n"
             << "2: " << gameModeToString(2) << "\n"
             << "3: " << gameModeToString(3)  << "\n"
             << "0: exit\n";
        cout << "Your choice: ";
        cin >> mode;
        if(mode == 0) return 0;
        if(mode < 1 || mode > 3)  {
            cout << "Invalid choice\n";
            continue;
        }
        break;
    }

    bool won = false;
    switch(mode)  {
        case 1:
            won = play();
            break;
        case 2:
            won = bestOf3();
            break;
        case 3:
            won = bestOf5();
            break;
        default:
            // unreachable code
            return -1;
    }

    if(won) {
        cout << "Congratulations! You win the game!\n";
    }
    else  {
        cout << "Unfortunate! You lose the game.\n";
    }
    return 0;
}
