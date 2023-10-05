#include <iostream>
#include <cstring>
#include "bmplib.cpp"

using namespace std;
unsigned char image [SIZE][SIZE];
unsigned char image2[SIZE][SIZE];
unsigned char image3[SIZE][SIZE];

void loadImage ();
void black_White();
void invert_filter();
void merge_filter();
void flip_image();
void darken_lighten();
//void rotate_image();
void exitt();
void saveImage ();
int main()
{
  int n;
  cout<<"Ahlan ya user ya habibi :) \n";
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
            break;
        case 2:
            invert_filter();
            break;
        case 3:
            merge_filter();
            break;
        case 4:
            flip_image();
          break;
        case 5:
            darken_lighten();
          break;
//        case 6:
//            rotate_image();
//          break;
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
void merge_filter() {
    char imageFileName[100];

    // Get gray scale image file name
    cout << "Please enter name of image file to merge with: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    readGSBMP(imageFileName, image2);

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {

            image3[i][j] = (image[i][j] + image2[i][j]) / 2 ;
        }
    }
    char imageFileName2[100];

    // Get gray scale image target file name
    cout << "Enter the target image file name: ";
    cin >> imageFileName2;

    // Add to it .bmp extension and load image
    strcat(imageFileName2, ".bmp");
    writeGSBMP(imageFileName2, image3);
}
//_________________________________________
void flip_image() {
    char x;
    cout<<"Flip (h)orizontally or (v)ertically ?";
    cin>>x;
    if (x =='h'){
        for (int i = 0; i < SIZE ; i++) {
            for (int j = 0; j < SIZE / 2; j++) {
                unsigned char temp = image[i][j];
                image[i][j] = image[i][SIZE - 1 - j];
                image[i][SIZE - 1 - j] = temp;
            }
        }
    }
    else if (x == 'v'){
        for (int i = 0; i < SIZE /2; i++) {
            for (int j = 0; j < SIZE; j++) {
                unsigned char temp = image[i][j];
                image[i][j] = image[SIZE - 1 - i][j];
                image[SIZE - 1 - i][j] = temp;
            }
        }
    }
}
//_________________________________________
void darken_lighten() {
    char x;
    cout<<"Do you want to (d)arken or (l)ighten?";
    cin>>x;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (x == 'l') {
                if (image[i][j] > 127 && image[i][j] < 193) {
                    image[i][j] += 60;
                }
                else if (image[i][j] >= 193) {
                    image[i][j] = 255;
                }
                else image[i][j] += 120;
            }
            else if (x == 'd'){
                if (image[i][j] < 127 && image[i][j] > 60) {
                    image[i][j] -= 60;
                }
                else if (image[i][j] <= 60) {
                    image[i][j] = 0;
                }
                else image[i][j] -= 120;
            }
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
