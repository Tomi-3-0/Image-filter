#include "helpers.h"
#include "math.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    //loop through each row of the image
    for (int i = 0; i < height; i++)
    {
        //loop through each column of the image
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE pixel = image[i][j];

            //Get the average hex values
            int R = pixel.rgbtRed;
            int B = pixel.rgbtBlue;
            int G = pixel.rgbtGreen;

            //calculate the average hex value and round it up
            int average = round(((float) R + (float) B + (float) G) / 3);

            //set the new value for each pixel
            image[i][j].rgbtRed = image[i][j].rgbtBlue = image[i][j].rgbtGreen = average;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    //loop through each row
    for (int i = 0; i < height; i++)
    {
        //loop through each column
        int x = width / 2;
        for (int j = 0; j < x; j++)
        {
            //swap values: by swapping each pixel with total - (j + 1)
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - (j + 1)] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //create a temporary array to hold values
    RGBTRIPLE temp[height][width];

    //copy image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }

     // Loop through pixel rows
    for (int i = 0; i < height; i++)
    {
        // Loop through pixel columns
        for (int j = 0; j < width; j++)
        {
            // Initialise values
            float R = 0;
            float B = 0;
            float G = 0;
            float total_count = 0;


             // For each pixel, loop vertical and horizontal
            for (int x = -1; x < 2; x++)
            {
                for (int y = -1; y < 2; y++)
                {
                    int row = i + x;
                    int col = j + y;
                    // Check for corner and side pixels
                    if (row < 0 || row >= height || col < 0 || col >= width)
                    {
                        continue;
                    }
                    // add to the sums
                    R += temp[row][col].rgbtRed;
                    B += temp[row][col].rgbtBlue;
                    G += temp[row][col].rgbtGreen;
                    total_count++;
                }
            }
            // Compute the average and set to original image
            image[i][j].rgbtRed = round(R / total_count);
            image[i][j].rgbtGreen = round(G / total_count);
            image[i][j].rgbtBlue = round(B / total_count);
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    // Create a temp array to hold worxing values
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }
    // Sobel arrays
    int Gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int Gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    // Loop through rows and columns
    for (int i = 0; i < height; i++)
    {

        for (int j = 0; j < width; j++)
        {
            // Initialise ints
            float GxRed = 0;
            float GxBlue = 0;
            float GxGreen = 0;
            float GyRed = 0;
            float GyBlue = 0;
            float GyGreen = 0;

            // For each pixel, loop vertical and horizontal
            for (int x = -1; x < 2; x++)
            {
                for (int y = -1; y < 2; y++)
                {
                    int row = i + x;
                    int col = j + y;
                    // Checx for corner  and side pixels
                    if (row < 0 || row >= height || col < 0 || col >= width)
                    {
                        continue;
                    }

                    // Add to sums for initialised variable Gx and Gy of respective colours
                    GxRed += temp[row][col].rgbtRed * Gx[x + 1][y + 1];
                    GxGreen += temp[row][col].rgbtGreen * Gx[x + 1][y + 1];
                    GxBlue += temp[row][col].rgbtBlue * Gx[x + 1][y + 1];

                    GyRed += temp[row][col].rgbtRed * Gy[x + 1][y + 1];
                    GyGreen += temp[row][col].rgbtGreen * Gy[x + 1][y + 1];
                    GyBlue += temp[row][col].rgbtBlue * Gy[x + 1][y + 1];
                }
            }
             // find the square root of the sum of the squares
            int R = round(sqrt(GxRed * GxRed + GyRed * GyRed));
            int G = round(sqrt(GxGreen * GxGreen + GyGreen * GyGreen));
            int B = round(sqrt(GxBlue * GxBlue + GyBlue * GyBlue));

            //checx for values that are more than 255
            int Red = (R > 255) ? 255 : R;
            int Green = (G > 255) ? 255 : G;
            int Blue = (B > 255) ? 255 : B;

            // Assign new values to pixels
            image[i][j].rgbtRed = Red;
            image[i][j].rgbtGreen = Green;
            image[i][j].rgbtBlue = Blue;
        }
    }

    return;
}
