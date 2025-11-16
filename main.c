#include <stdio.h>
#include <stdlib.h>

#define WIDTH 4
#define HEIGHT 4

void loadImage(int image[HEIGHT][WIDTH]);
void displayImage(int image[HEIGHT][WIDTH]);
void adjustBrightness(int image[HEIGHT][WIDTH], int value);
void negativeTransform(int image[HEIGHT][WIDTH]);
void blurImage(int image[HEIGHT][WIDTH]);
void edgeDetection(int image[HEIGHT][WIDTH]);

int main() {
    int image[HEIGHT][WIDTH];

    loadImage(image);
    printf("Original Image:\n");
    displayImage(image);

    adjustBrightness(image, 50);
    printf("After Brightness Adjustment (+50):\n");
    displayImage(image);

    negativeTransform(image);
    printf("After Negative Transformation:\n");
    displayImage(image);

    blurImage(image);
    printf("After Blurring:\n");
    displayImage(image);

    edgeDetection(image);
    printf("After Edge Detection:\n");
    displayImage(image);

    return 0;
}

void loadImage(int image[HEIGHT][WIDTH]) {
    int sample[HEIGHT][WIDTH] = {
        {255,255,255,255},
        {255,100,100,255},
        {255,100,100,255},
        {255,255,255,255}
    };
    for(int i=0;i<HEIGHT;i++)
        for(int j=0;j<WIDTH;j++)
            image[i][j] = sample[i][j];
}

void displayImage(int image[HEIGHT][WIDTH]) {
    for(int i=0;i<HEIGHT;i++){
        for(int j=0;j<WIDTH;j++)
            printf("%4d", image[i][j]);
        printf("\n");
    }
}

void adjustBrightness(int image[HEIGHT][WIDTH], int value) {
    for(int i=0;i<HEIGHT;i++)
        for(int j=0;j<WIDTH;j++){
            image[i][j]+=value;
            if(image[i][j]>255) image[i][j]=255;
            if(image[i][j]<0) image[i][j]=0;
        }
}

void negativeTransform(int image[HEIGHT][WIDTH]) {
    for(int i=0;i<HEIGHT;i++)
        for(int j=0;j<WIDTH;j++)
            image[i][j] = 255 - image[i][j];
}

void blurImage(int image[HEIGHT][WIDTH]) {
    int temp[HEIGHT][WIDTH]={0};
    for(int i=1;i<HEIGHT-1;i++)
        for(int j=1;j<WIDTH-1;j++)
            temp[i][j] = (image[i][j] + image[i-1][j] + image[i+1][j] + image[i][j-1] + image[i][j+1]) / 5;

    for(int i=1;i<HEIGHT-1;i++)
        for(int j=1;j<WIDTH-1;j++)
            image[i][j] = temp[i][j];
}

void edgeDetection(int image[HEIGHT][WIDTH]) {
    int temp[HEIGHT][WIDTH]={0};
    for(int i=1;i<HEIGHT-1;i++)
        for(int j=1;j<WIDTH-1;j++){
            int gx = abs(image[i][j] - image[i][j+1]);
            int gy = abs(image[i][j] - image[i+1][j]);
            int s = gx+gy;
            temp[i][j] = s>255 ? 255 : s;
        }
    for(int i=1;i<HEIGHT-1;i++)
        for(int j=1;j<WIDTH-1;j++)
            image[i][j] = temp[i][j];
}
