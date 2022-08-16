#include "helpers.h"
#include <math.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width]) {
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      int avg = round(image[i][j].rgbtBlue + image[i][j].rgbtGreen +
                      image[i][j].rgbtRed) /
                3;
      image[i][j].rgbtGreen = avg;
      image[i][j].rgbtRed = avg;
      image[i][j].rgbtBlue = avg;
    }
  }
  return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width]) {
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      float sepiaRed =
          round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen +
                .189 * image[i][j].rgbtBlue);
      float sepiaGreen =
          round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen +
                .168 * image[i][j].rgbtBlue);
      float sepiaBlue =
          round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen +
                .131 * image[i][j].rgbtBlue);

      if (sepiaRed > 255) {
        sepiaRed = 255;
      }
      if (sepiaBlue > 255) {
        sepiaBlue = 255;
      }
      if (sepiaGreen > 255) {
        sepiaGreen = 255;
      }

      image[i][j].rgbtBlue = sepiaBlue;
      image[i][j].rgbtRed = sepiaRed;
      image[i][j].rgbtGreen = sepiaGreen;
    }
  }
  return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width]) {
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width / 2; j++) {
      RGBTRIPLE tmp = image[i][j];
      image[i][j] = image[i][width - j - 1];
      image[i][width - j - 1] = tmp;
    }
  }
  return;
}

// Blur image
// https://www.youtube.com/watch?v=ZvjpllMmUzM great resource for this problem
void blur(int height, int width, RGBTRIPLE image[height][width]) {
    int offsety[] = {0, -1, -1, 0, 1, 1, 1, 0, -1};
    int offsetx[] = {0, 0, 1, 1, 1, 0, -1, -1, -1};
    int rgbtBlueSum, rgbtGreenSum, rgbtRedSum;
    int y, x, xO, yO = 0;
    float count = 0;
    RGBTRIPLE tempImage[height][width];

    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            // reset the sum values before doing next set
            rgbtBlueSum = 0;
            rgbtGreenSum = 0;
            rgbtRedSum = 0;
            count = 0;
            for (int i = 0; i < 9; i++) {
                // get array offset pos
                yO = y + offsety[i];
                xO = x + offsetx[i];
                // bound checking for the 2d array of pixels if out of bounds
                // skip the rest of the loop
                if (xO > width || xO < 0 || yO < 0 || yO > height) {
                    continue;
                } else {
                    // add all surrounding pixles including center together
                    rgbtBlueSum += (image[yO][xO].rgbtBlue);
                    rgbtGreenSum += (image[yO][xO].rgbtGreen);
                    rgbtRedSum += (image[yO][xO].rgbtRed);
                }
                    count++;
            }
            //get average of the sums
            tempImage[y][x].rgbtBlue = round(rgbtBlueSum / count);
            tempImage[y][x].rgbtGreen = round(rgbtGreenSum / count);
            tempImage[y][x].rgbtRed = round(rgbtRedSum / count);
        }
    }

    // write tempImage to real image
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            image[i][j].rgbtBlue = tempImage[i][j].rgbtBlue;
            image[i][j].rgbtGreen = tempImage[i][j].rgbtGreen;
            image[i][j].rgbtRed = tempImage[i][j].rgbtRed;
        }
    }
  return;
}
