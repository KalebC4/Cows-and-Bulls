/*
Purpose -- Recreated cowsandbulls.cc using new understanding of structs
Author -- Kaleb Calverley
Date -- March 2021
*/

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <limits>a
#include <string>

using namespace std;

// Struct Definitions
struct NumberNumbers {
  string numbers;
  int a, b, c, d;
};

// Function Prototypes
void startMessage();
NumberNumbers generateAnswer();
NumberNumbers guesstimate();
NumberNumbers convertDigits(NumberNumbers);
void check4CBT(int&, int&, NumberNumbers, NumberNumbers);
bool replayceMe();

// Const Declarations

int main() {
  bool replay = false;
  NumberNumbers answer, guess;
  int bulls, cows, attempts = 0, wins = 0, rounds = 0;

  startMessage();

  do {
    answer = generateAnswer();

    do {
      cows = 0;
      bulls = 0;
      guess = guesstimate();
      check4CBT(cows, bulls, guess, answer);

      attempts++;
      cout << "\nCows: " << cows << "\nBulls: " << bulls << "\nGuesses left: " << 10 - attempts << endl;
    } while (bulls != 4 && attempts < 10);

    if (attempts >= 11) {
      cout << "\nNo attempts left! You lose!\n" << "\nThe answer was: " << answer.a << answer.b << answer.c << answer.d << endl;
    } else {
      wins++;
      cout << "\nYou win!\n";
    }

    bulls = 0;
    attempts = 0;

    replay = replayceMe();

    rounds++;

  } while(replay);

  cout << "\nThanks for playing! You won " << wins << " out of " << rounds << " rounds!\n\n";

  return 0;
}

// Function Definitons

void startMessage() {
  cout << "\nWelcome to Cows and Bulls! Your goal is to get four bulls by correctly"
  << " guessing four digits, each in their correct spot. No two digits will be the"
  << " same.\n\nWARNING: if you put in a number with less than four digits the "
  << "program puts enough 0s at the front to make the number four digits long. "
  << "\n\nBull: correct digit in correct position\nCow: correct digit in "
  << "incorrect position\n\nYou have 10 guesses.\n";
}

NumberNumbers generateAnswer() {
  srand (time(0));
  NumberNumbers number;

  number.a = rand() % 10;
  do {
    number.b = rand() % 10;
  } while (number.b == number.a);
  do {
    number.c = rand() % 10;
  } while (number.c == number.a || number.c == number.b);
  do {
    number.d = rand() % 10;
  } while (number.d == number.a || number.d == number.b || number.d == number.c);

  return number;
}

NumberNumbers guesstimate() {
  NumberNumbers number;
  int tempGuess;
  stringstream ss;

  cout << "\nPlease enter your four digit guess: ";
  cin >> tempGuess;

  while (1) {
    if (cin.fail() || tempGuess > 9999 || tempGuess < 0) {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "\nPlease only enter four digits.\n \n";
      cout << "Please enter your four digit guess: ";
      cin >> tempGuess;
    } else
      break;
  }

  ss << tempGuess;
  ss >> number.numbers;

  while (number.numbers.length() < 4) {
    number.numbers = '0' + number.numbers;
  }

  number = convertDigits(number);

  return number;
}

NumberNumbers convertDigits(NumberNumbers number) {
  char val;

  val = number.numbers[0];
  number.a = static_cast <int> (val) - static_cast <int> ('0');
  val = number.numbers[1];
  number.b = static_cast <int> (val) - static_cast <int> ('0');
  val = number.numbers[2];
  number.c = static_cast <int> (val) - static_cast <int> ('0');
  val = number.numbers[3];
  number.d = static_cast <int> (val) - static_cast <int> ('0');

  return number;
}

void check4CBT(int& cownter, int& totbull, NumberNumbers g, NumberNumbers a) {
  if (g.a == a.a)
    totbull++;
  if (g.a != g.b && g.a != g.c && g.a != g.d)
    if (g.a == a.b || g.a == a.c || g.a == a.d)
      cownter++;
  if (g.b == a.b)
    totbull++;
  if (g.b != g.a && g.b != g.c && g.b != g.d)
    if (g.b == a.a || g.b == a.c || g.b == a.d)
      cownter++;
  if (g.c == a.c)
    totbull++;
  if (g.c != g.a && g.c != g.b && g.c != g.d)
    if (g.c == a.a || g.c == a.b || g.c == a.d)
      cownter++;
  if (g.d == a.d)
    totbull++;
  if (g.d != g.a && g.d != g.b && g.d != g.c)
    if (g.d == a.a || g.d == a.b || g.d == a.c)
      cownter++;
}

bool replayceMe() {
  char playAgain = ' ';
  while (true) {
    cout << "\nWould you like to play again? (Y/N): ";
    cin >> playAgain;

    if (playAgain == 'Y' || playAgain == 'y') {
      return true;
    } else if (playAgain == 'N' || playAgain == 'n') {
      return false;
    } else
      cout << "Please enter Y or N \n";
  }
}
