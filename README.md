## Filter 

-----

A program that applies filters to BMPs (Bitmap images).

Usage: `$ ./filter -r IMAGE.bmp REFLECTED.bmp`

Where IMAGE.bmp is the name of an image file and REFLECTED.bmp is the name given to an output image file, now reflected.

### Image filtering

-----
What does it even mean to filter an image? You can think of filtering an image as taking the pixels of some original image, and modifying each pixel in such a way that a particular effect is apparent in the resulting image.

#### Grayscale
One common filter is the “grayscale” filter, where we take an image and want to convert it to black-and-white

![Grayscale]()

#### Reflection
Some filters might also move pixels around. Reflecting an image, for example, is a filter where the resulting image is what you would get by placing the original image in front of a mirror. So any pixels on the left side of the image should end up on the right, and vice versa.

![Reflection]()

#### Blur
The effect of blurring or softening an image.

![Blur]()

#### Edges
In artificial intelligence algorithms for image processing, it is often useful to detect edges in an image:Highlights the lines in the image that create a boundary between one object and another.

![Edges]()

### Specifications

----

- The function `grayscale` takes an image and turn it into a black-and-white version of the same image.
- The `reflect` function takes an image and reflect it horizontally.
- The `blur` function takes an image and turn it into a box-blurred version of the same image.
- The `edges` function takes an image and highlight the edges between objects, according to the [Sobel operator](https://en.wikipedia.org/wiki/Sobel_operator).

### Usage

----
The program behaves per the examples below. `INFILE.bmp` is the name of the input image and `OUTFILE.bmp` is the name of the resulting image after a filter has been applied.

First, compile the file using:

`$ make filter`

The following filters can be applied as per below:

`$ ./filter -g INFILE.bmp OUTFILE.bmp`

`$ ./filter -r INFILE.bmp OUTFILE.bmp`

`$ ./filter -b INFILE.bmp OUTFILE.bmp`

`$ ./filter -e INFILE.bmp OUTFILE.bmp`


