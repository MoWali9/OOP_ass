// FCAI – OOP Programming – 2023 - Assignment 1
// Program Name:				Filters.cpp
// Last Modification Date:	    19/10/2023
// Author1 and ID and Group:	Mohamed Talaat Hassan 20220710
// Author2 and ID and Group:	Eslam abdelmksoud salah 20210065
// Author3 and ID and Group:	mehad fath alrhaman mohamed 20220716
// Teaching Assistant:		    xxxxx xxxxx
// Purpose:                     A program that takes a photo from the user
//                              and gives him a number of filters, so he can
//                              choose which one to apply to it

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
void rotate_image();
void Detect_Image_Edges();
void Enlarge_Image();
void Shrink_Image();
void Mirror_Image();
void Shuffle_Image();
void Blur_Image();
void Crop_Image();
void Skew_Image_Right();
void Skew_Image_Up();
void out();
void saveImage ();


int  main()
{
  char n;
  cout<<"Ahlan ya user ya habibi :) \n";
  loadImage();
  while (n != '0') {
      cout << "Please select a filter to apply or 0 to exit:\n"
              "1- Black & White Filter\n"
              "2- Invert Filter\n"
              "3- Merge Filter \n"
              "4- Flip Image\n"
              "5- Darken and Lighten Image \n"
              "6- Rotate Image\n"
              "7- Detect Image Edges \n"
              "8- Enlarge Image\n"
              "9- Shrink Image\n"
              "a- Mirror 1/2 Image\n"
              "b- Shuffle Image\n"
              "c- Blur Image\n"
              "d- Crop Image\n"
              "e- Skew Image Right  \n"
              "f- Skew Image Up\n"
              "0- Exit\n";
      cin >> n;
      switch (n) {
          case '1':
              black_White();
              break;
          case '2':
              invert_filter();
              break;
          case '3':
              merge_filter();
              break;
          case '4':
              flip_image();
              break;
          case '5':
              darken_lighten();
              break;
          case '6':
              rotate_image();
              break;
          case '7':
              Detect_Image_Edges();
              break;
          case '8':
              Enlarge_Image();
              break;
          case '9':
               Shrink_Image();
               break;
          case 'a':
              Mirror_Image();
              break;
          case 'b':
              Shuffle_Image();
              break;
          case 'c':
              Blur_Image();
              break;
          case 'd':
              Crop_Image();
              break;
//          case 'e':
//              Skew_Image_Right();
//              break;
//          case 'f':
//              Skew_Image_Up();
//              break;
          case 0:
              out();
      }
  }
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

// black and white filter by Mohamed Talaat Hassan 20220710

void black_White() {
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) {

        if (image[i][j] > 127)
            image[i][j] = 255 ;
        else
            image[i][j] = 0  ;

    }
  }
    saveImage();
}

//_________________________________________

// invert filter by Eslam abdelmksoud salah 20210065

void invert_filter() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {

            image[i][j] = 255- image[i][j] ;
        }
    }
    saveImage();
}


//_________________________________________

// marge filter by mehad fath alrhaman mohamed 20220716

void merge_filter() {
    char imageFileName[100];

    // Get gray scale image file name
    cout << "Please enter name of the second image : ";
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

// flip filter by Mohamed Talaat Hassan 20220710

void flip_image() {
    char x;
    unsigned char n ;
    cout<<"Flip (h)orizontally or (v)ertically ?";
    cin>>x;
    if (x =='h'){
        for (int i = 0; i < SIZE ; i++) {
            for (int j = 0; j < SIZE / 2; j++) {
                n = image[i][j];
                image[i][j] = image[i][SIZE - j - 1];
                image[i][SIZE - j - 1] = n;
            }
        }
    }
    else if (x == 'v'){
        for (int i = 0; i < SIZE /2; i++) {
            for (int j = 0; j < SIZE; j++) {
                n = image[i][j];
                image[i][j] = image[SIZE - i - 1][j];
                image[SIZE - i - 1][j] = n;
            }
        }
    }
    saveImage();
}

//_________________________________________
// darken lighten filter by mehad fath alrhaman mohamed 20220716
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
            else if (x == 'd') {
                image[i][j] = (image[i][j]) / 2;
            }
        }
    }
    saveImage();
}

//_________________________________________

// rotate filter by Eslam abdelmksoud salah 20210065

void rotate_image(){
        int n;
        cout<<"Choose the degree of rotation";
        cin>>n;
        if(n==270){
            int matrix[SIZE][SIZE];
            for (int i = 0; i < SIZE; i++) {

                for (int j = 0; j < SIZE; j++) {

                    matrix[SIZE - 1 - j][i] = image[i][j];

                }
            }
            for (int i = 0; i < SIZE; i++) {

                for (int j = 0; j < SIZE; j++) {
                    image[i][j] = matrix[i][j];
                }
            }
        }
        else if(n==90){
            int matrix[SIZE][SIZE];
            for (int i = 0; i < SIZE; i++) {

                for (int j = 0; j < SIZE; j++) {

                    matrix[j][SIZE - 1 - i] = image[i][j];

                }
            }
            for (int i = 0; i < SIZE; i++) {

                for (int j = 0; j < SIZE; j++) {
                    image[i][j] = matrix[i][j];
                }
            }
        }
        else if(n==180){
            int matrix[SIZE][SIZE];
            for (int i = 0; i < SIZE; i++) {

                for (int j = 0; j < SIZE; j++) {

                    matrix[SIZE-i-1][SIZE - 1 - j] = image[i][j];


                }
            }
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    image[i][j] = matrix[i][j];
                }
            }
        }
    saveImage();
    }
//_________________________________________
void Detect_Image_Edges() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {

            if (image[i][j] > 127)
                image[i][j] = 255;
            else
                image[i][j] = 0;
        }
    }
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {

            if (image[i][j] == image[1 + i][j] )
                image[i][j] = 255;
            else
                image[i][j] = 0;
        }
    }
    saveImage();
}

//_________________________________________
void Enlarge_Image(){
    int mat[SIZE][SIZE];
    int n;
    cout<<"choose quarter to enlarge it ";
    cin>>n;
    if(n==1){
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                mat[i][j] = image[i / 2][j/2];
            }}
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                image[i][j]=mat[i][(j)];
            }}}
    else if (n==3) {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                mat[i][j] = image[(i/2)+127][j/2];
            }}
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                image[i][j]=mat[i][j];
            }}}
    else if (n==2) {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                mat[i][j] = image[i/2][(j/2)+127];
            }}
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                image[i][j]=mat[i][j];
            }}}
    else if (n==4) {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                mat[i][j] = image[(i/2)+127][(j/2)+127];
            }}
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                image[i][j]=mat[i][j];
            }
        }
    }
    saveImage();
}

//_________________________________________
    void Shrink_Image() {
        int mat[SIZE][SIZE];
        float n;
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {

                mat[i][j] = 255;
            }
        }
        cout << "do you want to shrink the image dimensions to 1/2, 1/3 or 1/4 ?";
        cin >> n;
        if (n == 1) {
            for (int i = 0; i < SIZE / 2; i++) {
                for (int j = 0; j < SIZE / 2; j++) {
                    mat[i][j] = image[2 * i][2 * j];
                }
            }
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {

                    image[i][j] = mat[i][j];
                }
            }
        } else if (n == 2) {
            for (int i = 0; i < SIZE / 3; i++) {
                for (int j = 0; j < SIZE / 3; j++) {
                    mat[i][j] = image[3 * i][3 * j];
                }
            }
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {

                    image[i][j] = mat[i][j];
                }
            }
        } else if (n == 3) {
            for (int i = 0; i < SIZE / 4; i++) {
                for (int j = 0; j < SIZE / 4; j++) {
                    mat[i][j] = image[4 * i][4 * j];
                }
            }
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {

                    image[i][j] = mat[i][j];
                }
            }
        }
    saveImage();
    }
//_________________________________________
    void Mirror_Image() {
        char x;
        cout << "Mirror (l)eft, (r)ight, (u)pper, (d)own side?";
        cin >> x;
        switch (x) {
            case 'r' :
                for (int i = 0; i < SIZE; i++) {
                    for (int j = 0; j < SIZE; j++) {
                        image[i][j] = image[i][255 - j];
                    }
                }
            case 'd' :
                for (int i = 0; i < SIZE; i++) {
                    for (int j = 0; j < SIZE; j++) {
                        image[i][j] = image[255 - i][j];
                    }
                }
            case 'l' :
                for (int i = 0; i < SIZE; i++) {
                    for (int j = 0; j < SIZE; j++) {
                        image[i][255 - j] = image[i][j];
                    }
                }
            case 'u':
                for (int i = 0; i < SIZE; i++) {
                    for (int j = 0; j < SIZE; j++) {
                        image[255 - i][j] = image[i][j];
                    }
                }
        }
    saveImage();
    }


//_________________________________________
    void Shuffle_Image() {
        int temp[SIZE][SIZE];
        int mat[SIZE][SIZE];
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                temp[i][j] = image[i][j];
            }
        }
        int a, b, c, d;

        cout << "choose the order you want";
        // الربع الاول
        cin >> a;
        switch (a) {
            case 4:

                for (int i = 128; i < SIZE; i++) {
                    for (int j = 128; j < SIZE; j++) {
                        image[i - (SIZE / 2)][j - (SIZE / 2)] = temp[i][j];
                    }
                }
                break;
            case 3:
                for (int i = 128; i < SIZE; i++) {
                    for (int j = 0; j < 128; j++) {
                        image[i - (SIZE / 2)][j] = temp[i][j];
                    }
                }
                break;
            case 2:
                for (int i = 0; i < 128; i++) {
                    for (int j = 128; j < SIZE; j++) {
                        image[i][j - (SIZE / 2)] = temp[i][j];
                    }
                }
                break;
            case 1:
                for (int i = 0; i < 128; i++) {
                    for (int j = 0; j < 128; j++) {
                        image[i][j] = temp[i][j];
                    }
                }
                break;
        }


// الربع التانى
        cin >> b;
        switch (b) {
            case 3:
                for (int i = 128; i < SIZE; i++) {
                    for (int j = 0; j < 128; j++) {
                        image[i - (SIZE / 2)][j + (SIZE / 2)] = temp[i][j];
                    }
                }
                break;
            case 1:
                for (int i = 0; i < 128; i++) {
                    for (int j = 0; j < 128; j++) {
                        image[i][j + (SIZE / 2)] = temp[i][j];
                    }
                }
                break;
            case 4:
                for (int i = 128; i < SIZE; i++) {
                    for (int j = 128; j < SIZE; j++) {
                        image[i - (SIZE / 2)][j] = temp[i][j];
                    }
                }
                break;
            case 2:
                for (int i = 0; i < 128; i++) {
                    for (int j = 128; j < SIZE; j++) {
                        image[i][j] = temp[i][j];
                    }
                }
                break;
        }
        //الربع التالت
        cin >> c;
        switch (c) {
            case 2:
                for (int i = 0; i < 128; i++) {
                    for (int j = 128; j < SIZE; j++) {
                        image[i + (SIZE / 2)][j - (SIZE / 2)] = temp[i][j];
                    }
                }
                break;
            case 4:
                for (int i = 128; i < SIZE; i++) {
                    for (int j = 128; j < SIZE; j++) {
                        image[i][j - (SIZE / 2)] = temp[i][j];
                    }
                }
                break;
            case 1:
                for (int i = 0; i < 128; i++) {
                    for (int j = 0; j < 128; j++) {
                        image[i + (SIZE / 2)][j] = temp[i][j];
                    }
                }
                break;
            case 3:
                for (int i = 128; i < SIZE; i++) {
                    for (int j = 0; j < 128; j++) {
                        image[i][j] = temp[i][j];
                    }
                }
                break;
        }
//الربع الرابع
        cin >> d;
        switch (d) {
            case 1:
                for (int i = 0; i < 128; i++) {
                    for (int j = 0; j < 128; j++) {
                        image[i + (SIZE / 2)][j + (SIZE / 2)] = temp[i][j];
                    }
                }
                break;
            case 2:
                for (int i = 0; i < 128; i++) {
                    for (int j = 128; j < SIZE; j++) {
                        image[i + (SIZE / 2)][j] = temp[i][j];
                    }
                }
                break;
            case 3:
                for (int i = 128; i < SIZE; i++) {
                    for (int j = 0; j < 128; j++) {
                        image[i][j + (SIZE / 2)] = temp[i][j];
                    }
                }
                break;
            case 4:
                for (int i = 128; i < SIZE; i++) {
                    for (int j = 128; j < SIZE; j++) {
                        image[i][j] = temp[i][j];
                    }
                }
                break;

        }

    saveImage();
    }
//_________________________________________
    void Blur_Image() {
        int mat[SIZE][SIZE];

        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {

                mat[i][j] =
                        (image[i - 1][j - 1] + image[i - 1][j] + image[i - 1][j + 1] + image[i][j - 1] + image[i][j] +
                         image[i][j + 1] + image[i + 1][j - 1] + image[i + 1][j] + image[i + 1][j + 1]) / 9;
            }
        }

        for (int i = 1; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                image[i][j] = mat[i][j];
            }
        }
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {

                mat[i][j] =
                        (image[i - 1][j - 1] + image[i - 1][j] + image[i - 1][j + 1] + image[i][j - 1] + image[i][j] +
                         image[i][j + 1] + image[i + 1][j - 1] + image[i + 1][j] + image[i + 1][j + 1]) / 9;
            }
        }

        for (int i = 1; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                image[i][j] = mat[i][j];
            }
        }
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {

                mat[i][j] =
                        (image[i - 1][j - 1] + image[i - 1][j] + image[i - 1][j + 1] + image[i][j - 1] + image[i][j] +
                         image[i][j + 1] + image[i + 1][j - 1] + image[i + 1][j] + image[i + 1][j + 1]) / 9;
            }
        }

        for (int i = 1; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                image[i][j] = mat[i][j];
            }
        }
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {

                mat[i][j] =
                        (image[i - 1][j - 1] + image[i - 1][j] + image[i - 1][j + 1] + image[i][j - 1] + image[i][j] +
                         image[i][j + 1] + image[i + 1][j - 1] + image[i + 1][j] + image[i + 1][j + 1]) / 9;
            }
        }

        for (int i = 1; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                image[i][j] = mat[i][j];
            }
        }
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {

                mat[i][j] =
                        (image[i - 1][j - 1] + image[i - 1][j] + image[i - 1][j + 1] + image[i][j - 1] + image[i][j] +
                         image[i][j + 1] + image[i + 1][j - 1] + image[i + 1][j] + image[i + 1][j + 1]) / 9;
            }
        }

        for (int i = 1; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                image[i][j] = mat[i][j];
            }
        }
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {

                mat[i][j] =
                        (image[i - 1][j - 1] + image[i - 1][j] + image[i - 1][j + 1] + image[i][j - 1] + image[i][j] +
                         image[i][j + 1] + image[i + 1][j - 1] + image[i + 1][j] + image[i + 1][j + 1]) / 9;
            }
        }

        for (int i = 1; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                image[i][j] = mat[i][j];
            }
        }
    saveImage();
    }
//_________________________________________
    void Crop_Image() {
        int x, y, l, w;
        cout << "please enter x and y positions\n";
        cin >> x >> y;
        cout << "please enter length and width\n";
        cin >> l >> w;
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                image2[i][j] = 255;
            }
        }
        for (int i = x; i < l + x; i++) {
            for (int j = y; j < w + y; j++) {
                image2[i][j] = image[i][j];
            }
        }
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                image[i][j] = image2[i][j];
            }
        }
    saveImage();
    }

//_________________________________________
    void Skew_Image_Right();
//saveImage();
//_________________________________________
    void Skew_Image_Up();
    //saveImage();
//_________________________________________
    void out() {
        exit(0);
    }

//_________________________________________

    void saveImage() {
        char imageFileName[100];

        // Get gray scale image target file name
        cout << "Enter the target image file name: ";
        cin >> imageFileName;

        // Add to it .bmp extension and load image
        strcat(imageFileName, ".bmp");
        writeGSBMP(imageFileName, image);
    }
