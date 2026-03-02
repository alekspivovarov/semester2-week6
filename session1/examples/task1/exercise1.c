#include <stdio.h>
#include <stdlib.h>

int calculate_fine(int speed_limit, int driver_speed) {
  // Determine if the driver is speeding
  int fine = 0; // local variable
  if (driver_speed > speed_limit) {
    int excess_speed = driver_speed - speed_limit;


    // Calculate fine based on how much over the limit
    if (excess_speed <= 10) {
      fine = 50;
    } else if (excess_speed <= 20) {
      fine = 100;
    } else {
      fine = 200;
    }

    printf("Fine: $%d\n", fine);
  } else {
    printf("No fine needed.\n");
  }
}


int get_valid_speed(const char *prompt) {

  char input[20]; //local buffer to store the raw text the user types
  int speed;
  printf("%s", prompt); //prints whatever prompt was passed in

  if (fgets(input, sizeof(input), stdin)) { // reads a line of text from keyboard
    sscanf(input, "%d", &speed); // converts that text to an integer, stores in speed
  }
  return speed;
}




int main() {
  int speed_limit = get_valid_speed("Enter the speed limit: ");
  int driver_speed = get_valid_speed("Enter driver's speed: ");
  calculate_fine(speed_limit, driver_speed);





  return 0;
}