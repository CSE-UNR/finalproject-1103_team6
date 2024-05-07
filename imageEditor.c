//Name: Brody Mingo & Natalie Jimenez
//Date: 5/3/24
//Purpose: Editing Grayscale Images

#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

void displayMenu();
void loadImage(int image[MAX_SIZE][MAX_SIZE], int *rows, int *cols);
void displayImage(int image[MAX_SIZE][MAX_SIZE], int rows, int cols);
void editImage(int image[MAX_SIZE][MAX_SIZE], int rows, int cols);
void cropImage(int image[MAX_SIZE][MAX_SIZE], int *rows, int *cols);
void dimImage(int image[MAX_SIZE][MAX_SIZE], int rows, int cols);
void brightenImage(int image[MAX_SIZE][MAX_SIZE], int rows, int cols);
void saveImage(int image[MAX_SIZE][MAX_SIZE], int rows, int cols);

int main() {
    int image[MAX_SIZE][MAX_SIZE];
    int rows, cols;
    int choice;

    do {
        displayMenu();
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                loadImage(image, &rows, &cols);
                break;
            case 2:
                displayImage(image, rows, cols);
                break;
            case 3:
                editImage(image, rows, cols);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 4);

    return 0;
}

void displayMenu() {
    printf("Erinstagram\n");
    printf("1. Load a new image\n");
    printf("2. Display the current image\n");
    printf("3. Edit the current image\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}

void loadImage(int image[MAX_SIZE][MAX_SIZE], int *rows, int *cols) {
}

void displayImage(int image[MAX_SIZE][MAX_SIZE], int rows, int cols) {
}

void editImage(int image[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    int editChoice;

    do {
        printf("\nEdit Menu\n");
        printf("1. Crop\n");
        printf("2. Dim\n");
        printf("3. Brighten\n");
        printf("4. Save edited image\n");
        printf("5. Back to main menu\n");
        printf("Enter your choice: ");
        scanf("%d", &editChoice);

        switch(editChoice) {
            case 1:
                cropImage(image, &rows, &cols);
                break;
            case 2:
                dimImage(image, rows, cols);
                break;
            case 3:
                brightenImage(image, rows, cols);
                break;
            case 4:
                saveImage(image, rows, cols);
                break;
            case 5:
                printf("Returning to main menu.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (editChoice != 5);
}

void cropImage(int image[MAX_SIZE][MAX_SIZE], int *rows, int *cols) {
    printf("Enter an a row to crop \n");
    scanf(" ", );
    printf("Enter a column to crop \n");
    scanf(" ", );
}

void dimImage(int image[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    printf("How much would you like to dim the current image? \n");
    scanf(" ", );
}

void brightenImage(int image[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    printf("How much would you like to brighten the current image? \n");
    scanf(" ", );
}

void saveImage(int image[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    printf("Would you like to save the edited image? \n");
    	if( ){
    	
    	}else{
    	
    	}
}

