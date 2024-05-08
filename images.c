//Name: Brody Mingo & Natalie Jimenez
//Date: 5/3/24
//Purpose: Editing Grayscale Images

#include <stdio.h>

#define MAX_SIZE 100 
#define BRIGHTNESS_STEP 1 

void loadNewImage(int image[MAX_SIZE][MAX_SIZE], int *rows, int *cols);
void displayImage(int image[MAX_SIZE][MAX_SIZE], int rows, int cols);
void editImage(int image[MAX_SIZE][MAX_SIZE], int *rows, int *cols);
void cropImage(int image[MAX_SIZE][MAX_SIZE], int *rows, int *cols);
void dimImage(int image[MAX_SIZE][MAX_SIZE], int rows, int cols);
void brightenImage(int image[MAX_SIZE][MAX_SIZE], int rows, int cols);
void saveImage(int image[MAX_SIZE][MAX_SIZE], int rows, int cols);

int main() {
    int image[MAX_SIZE][MAX_SIZE];
    int rows = 0, cols = 0;
    int choice;

    do {
        printf("\nMenu:\n");
        printf("1. Load a new image\n");
        printf("2. Display the current image\n");
        printf("3. Edit the current image\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                loadNewImage(image, &rows, &cols);
                break;
            case 2:
                displayImage(image, rows, cols);
                break;
            case 3:
                editImage(image, &rows, &cols);
                break;
            case 4:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

void loadNewImage(int image[MAX_SIZE][MAX_SIZE], int *rows, int *cols) {
    char filename[100];
    printf("Enter the filename to load the image from: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error: Unable to open file.\n");
        return;
    }

    fscanf(file, "%d %d", rows, cols);
    for (int i = 0; i < *rows; ++i) {
        for (int j = 0; j < *cols; ++j) {
            fscanf(file, "%d", &image[i][j]);
        }
    }

    fclose(file);
    printf("Image loaded successfully.\n");
}

void displayImage(int image[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    printf("Displaying the current image:\n");
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("%c ", image[i][j] >= 128 ? '#' : '.');
        }
        printf("\n");
    }
}

void editImage(int image[MAX_SIZE][MAX_SIZE], int *rows, int *cols) {
    int choice;
    do {
        printf("\nEdit Menu:\n");
        printf("1. Crop\n");
        printf("2. Dim\n");
        printf("3. Brighten\n");
        printf("4. Back to main menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                cropImage(image, rows, cols);
                break;
            case 2:
                dimImage(image, *rows, *cols);
                break;
            case 3:
                brightenImage(image, *rows, *cols);
                break;
            case 4:
                printf("Returning to the main menu...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

        if (choice != 4) {
            displayImage(image, *rows, *cols);
        }
    } while (choice != 4);
}

void cropImage(int image[MAX_SIZE][MAX_SIZE], int *rows, int *cols) {
    int startX, startY, width, height;
    printf("Enter the starting X coordinate for cropping: ");
    scanf("%d", &startX);
    printf("Enter the starting Y coordinate for cropping: ");
    scanf("%d", &startY);
    printf("Enter the width for cropping: ");
    scanf("%d", &width);
    printf("Enter the height for cropping: ");
    scanf("%d", &height);

    if (startX < 0 || startY < 0 || startX + width > *cols || startY + height > *rows) {
        printf("Invalid crop coordinates.\n");
        return;
    }

    int croppedImage[MAX_SIZE][MAX_SIZE];
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            croppedImage[i][j] = image[startY + i][startX + j];
        }
    }

    *rows = height;
    *cols = width;
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            image[i][j] = croppedImage[i][j];
        }
    }

    printf("Image cropped successfully.\n");
}

void dimImage(int image[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            image[i][j] -= BRIGHTNESS_STEP;
            if (image[i][j] < 0) {
                image[i][j] = 0;
            }
        }
    }
    printf("Image dimmed successfully.\n");
}

void brightenImage(int image[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            image[i][j] += BRIGHTNESS_STEP;
            if (image[i][j] > 255) {
                image[i][j] = 255;
            }
        }
    }
    printf("Image brightened successfully.\n");
}

void saveImage(int image[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    char filename[100];
    printf("Enter the filename to save the image to: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Error: Unable to create file.\n");
        return;
    }

    fprintf(file, "%d %d\n", rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            fprintf(file, "%d ", image[i][j]);
        }
        fprintf(file, "\n");
    }

    fclose(file);
    printf("Image saved successfully.\n");
}

