#include <stdlib.h>
#include <stdio.h>

//function prototypes (telling the compiler these functions exist before main)
int getUserInput(char *message);
void menu(void);
unsigned char **allocateArray(int height, int width);
unsigned char **readPGM(char *fn, int *a, int *b);
void printImage(unsigned char **image, int a, int b);


int main(int argc, char **argv) { // argc = number of arguments, argv = the arguments themseleves
  if (argc != 2) {  // program expects exactly 2 args: ./pgmTools and a filename
    printf("Usage: ./pgmTools image_path\n");
    return 0;       // exit if number of arguments is wrong
  }

  int height, width, maxGray; // will store image height and width
  unsigned char **image;  //2D array to store pixel values
  image = readPGM(argv[1], &height, &width);  // read the image, fill a and b

  int choice = -1;   // store the user's choice, -1 = no choice yet

  do {
    choice = -1;   // reset choice each loop iteration
    menu();   // print the menu options
    while (choice < 1) // keep asking until valid input (>=1)
      choice = getUserInput("Enter choice");

    switch (choice) { //
    case 1:
      printImage(image, height, width); //
      break;
    case 2:
      break;
    case 3:
      break;
    case 4:
      break;
    case 5:
      return 0; // quit the program
    default:
      printf("Bad choice\n"); //everything else is invalid
      break;
    }
  } while (1);
}

int getUserInput(char *message) {
  unsigned char buffer[100];
  int choice;
  printf("%s: ", message);
  fgets(buffer, 100, stdin);
  int check = sscanf(buffer, "%d", &choice);
  if (!check) {
    return -1;
  }
  return choice;
}

void menu(void) {
  printf("1 - View PGM Image\n");
  printf("2 - Invert Image\n");
  printf("3 - Rotate Image\n");
  printf("4 - Scale Image\n");
  printf("5 - quit\n");
}

unsigned char **allocateArray(int height, int width) {
  unsigned char **array = calloc(height, sizeof(unsigned char *));
  for (int i = 0; i < height; i++) {
    array[i] = calloc(width, sizeof(unsigned char));
  }

  return array;
}

unsigned char **readPGM(char *filename, int *a, int *b) {
  unsigned char magicNumber[10]; // temporary buffer to read and discard strings
  int height, width, maxGray; // image heigth and width from file header
  FILE *file = fopen(filename, "r");  // open the image file for reading
  fscanf(file, "%s ", magicNumber);
  fscanf(file, "%d %d", &height, &width);
  fscanf(file, "%d", &maxGray);
  unsigned char **image = allocateArray(height, width); //allocate the 2d pixel array
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      fscanf(file, "%hhd", &image[i][j]);
    }
  }
  *a = height;
  *b = width;
  return image;
}

void printImage(unsigned char **image, int height, int width) {
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      printf("%d%s", image[i][j],
             (image[i][j] < 100) ? (image[i][j] < 10) ? "   " : "  " : " ");
    }
    printf("\n");
  }
}