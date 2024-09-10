#include <iostream>
using namespace std;
int numberguessing()
{
  int number = rand() % 100 + 1;
  int guess = 0;
  int c=0;
  do
  {
    cout << "Guess a number between 1 and 100: ";
    cin >> guess;

    if (guess > number)
    {
      cout << "Too high.\n"
           << endl;
           c++;
    }
    else if (guess < number)
    {
      cout << "Too low.\n"
           << endl;
           c++;
    }
    else
    {
      cout << "That's right!\n"
           << endl;
      if(c==0)
      {
        return 1;
      }
      exit(0);
    }
  } while (number != guess);
  return 0;
}