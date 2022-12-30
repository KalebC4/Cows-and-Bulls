/* Kaleb Calverley Oct 25, 2020
This program is a game of guessing digits called Cows and Bulls
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

int main() {

  int g1, g2, g3, g4, a1, a2, a3, a4, cows, bulls, attempts;
  bool replay = false;
  char playAgain;

  bulls = 0;
  attempts = 0;

  srand (time(0));

  do {

    a1 = rand() % 10;
    do {
      a2 = rand() % 10;
    } while (a2 == a1);
    do {
      a3 = rand() % 10;
    } while (a3 == a2 || a3 == a1);
    do {
      a4 = rand() % 10;
    } while (a4 == a3 || a4 == a2 || a4 == a1);

    cout << endl << "Welcome to Cows and Bulls! Your goal" <<
    " is to obtain four bulls by correctly guessing" <<
    " four numbers less than ten in their correct spot. " << endl << endl
    << "Bull: correct number in correct spot. " << endl
    << "Cow: correct number in incorrect spot. " << endl
    << endl << "You have 10 attempts." << endl;

    while (bulls != 4 && attempts <= 9) {

      cows = 0;
      bulls = 0;

      cout << endl << "Enter four digits separated by spaces (no two digits will be the same): ";
      cin >> g1 >> g2 >> g3 >> g4;

      while(1) {
        if (cin.fail()) {
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
          cout << "\nPlease enter single digit integers only.\n \n";
          cout << "Enter four digits separated by spaces (no two digits will be the same): ";
          cin >> g1 >> g2 >> g3 >> g4;
        } else {
          break;
        }
      }

      while (g1 >= 10 || g2 >= 10 || g3 >= 10 || g4 >= 10) {
        cout << endl << "Each digit must be less than 10." << endl << endl;
        cout << "Enter four digits separated by spaces (no two digits will be the same): ";
        cin >> g1 >> g2 >> g3 >> g4;
      }

      if (g1 == a1) {
        bulls++;
      }
      if (g1 != g2 && g1 != g3 && g1 != g4) {
        if (g1 == a2 || g1 == a3 || g1 == a4) {
          cows++;
        }
      }
      if (g2 == a2) {
        bulls++;
      }
      if (g2 != g1 && g2 != g3 && g2 != g4){
        if (g2 == a1 || g2 == a3 || g2 == a4) {
          cows++;
        }
      }
      if (g3 == a3) {
        bulls++;
      }
      if (g3 != g1 && g3 != g2 && g3 != g4) {
        if (g3 == a1 || g3 == a2 || g3 == a4) {
          cows++;
        }
      }
      if (g4 == a4) {
        bulls++;
      }
      if (g4 != g1 && g4 != g2 && g4 != g3) {
        if (g4 == a1 || g4 == a2 || g4 == a3) {
          cows++;
        }
      }

      attempts++;

      cout << endl << "Cows: " << cows << endl << "Bulls: " << bulls << endl << "Attempts left: " << 10 - attempts << endl;

    }

    if (attempts >= 9) {
      cout << "\nNo attempts left! You lose!\n" << "\nThe answer was: " << a1 << " " << a2 << " " << a3 << " " << a4 << endl;
    } else {
      cout << "\nYou win!\n";
    }

    bulls = 0;
    attempts = 0;

    while (true) {
      cout << "\nWould you like to play again? (Y/N): ";
      cin >> playAgain;

      if (playAgain == 'Y') {
        replay = true;
        break;
      } else if (playAgain == 'N') {
        replay = false;
        break;
      } else
        cout << "Please enter Y or N \n";
    }

  } while (replay);

  return 0;
}
