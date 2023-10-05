#include <iostream>
#include <cstring>
#include "bmplib.cpp"

using namespace std;
unsigned char image[SIZE][SIZE];

void loadImage ();
void black_White();
void invert_filter();
//void merge_filter();
//void flip_image();
//void darken_lighten();
//void rotate_image();
void exitt();
void saveImage ();
int main()
{
  int n;
  cout<<"Ahlan ya user ya habibi\n";
  loadImage();
  cout<<"Please select a filter to apply or 0 to exit:\n"
        "1- Black & White Filter\n"
        "2- Invert Filter\n"
        "3- Merge Filter \n"
        "4- Flip Image\n"
        "5- Darken and Lighten Image \n"
        "6- Rotate Image\n"
        "0- Exit\n";
  cin>>n;
    switch (n) {
        case 1:
            black_White();
        case 2:
            invert_filter();
//        case 3:
//            merge_filter();
//        case 4:
//            flip_image();
//        case 5:
//            darken_lighten();
//        case 6:
//            rotate_image();
        case 0:
            exitt();
    }
  saveImage();
  return 0;
}

//_________________________________________
void loadImage () {
   char imageFileName[100];

   // Get gray scale image file name
   cout << "Enter the source image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   readGSBMP(imageFileName, image);
}

//_________________________________________
void black_White() {
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) {

//code to convert to BW

        if (image[i][j] > 127)
            image[i][j] = 255 ;
        else
            image[i][j] = 0  ;

    }
  }
}
//_________________________________________
void invert_filter() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {

            image[i][j] = 255 - image[i][j] ;
        }
    }
}
//_________________________________________
void exitt(){
    exit(0);
}
//_________________________________________
void saveImage () {
    char imageFileName[100];

    // Get gray scale image target file name
    cout << "Enter the target image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat(imageFileName, ".bmp");
    writeGSBMP(imageFileName, image);
}
