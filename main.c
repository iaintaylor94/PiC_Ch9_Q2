// This program calculates the number of days between two days
// The example in the textbook is wrong

#include <stdio.h>

// Define Structures
struct date {
int day;
int month;
int year;
};

// Declare Functions
int f (struct date);
int g (struct date);
int dateNumber (struct date);

int main(void) {
  struct date one, two;
  
  // Get input
  printf ("Enter date 1 (mm:dd:yyyy):  ");
  scanf ("%d:%d:%d", &one.month, &one.day, &one.year);

  printf ("Enter date 2 (mm:dd:yyyy):  ");
  scanf ("%d:%d:%d", &two.month, &two.day, &two.year);

  // Calculate date numbers
  int numberOne = dateNumber (one);
  int numberTwo = dateNumber (two);

  printf ("f1: %d\n", f(one));
  printf ("f2: %d\n", f(two));

  printf ("g1: %d\n", g(one));
  printf ("g2: %d\n", g(two));

  printf ("Number 1: %d\n", numberOne);
  printf ("Number 2: %d\n", numberTwo);

  // Calculate number of days between the two dates
  int daysBetween = numberTwo - numberOne;

  // Print number of days between the two dates
  printf ("There are %d days between %.2d:%.2d:%.2d and %.2d:%.2d:%.2d", daysBetween, one.month, one.day, one.year, two.month, two.day, two.year);
  
  return 0;
}

// Define Functions
int f (struct date input) {
  if (input.month <= 2)
    return input.year - 1;
  else
    return input.year;
}
int g (struct date input) {
  if (input.month <= 2) {
    return input.month + 13;
  }
  else {
    return input.month + 1;
  }
}
int dateNumber (struct date input) {
  return (1461 * f (input)) / 4 + (153 * g (input)) / 5 + input.day;
}