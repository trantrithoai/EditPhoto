//
// Created by chelseaw on 01/05/17.
//

#include "Blur.h"

void Blur::run(int pos, Mat& img, Mat& imgFactor){
    //pos_=pos;
    //userInput_=userInput;
    if(pos <= 0)
        return;

    // result
    //namedWindow("Modified", WINDOW_AUTOSIZE);//create window for blur image

    // casting the input user img to

    // Mat element = getStructuringElement( MORPH_RECT, Size(2*pos+1,2*pos+1), Point(pos,pos));

    // Apply a filter
    //pos = 2*(pos/2) + 1;

    blur(img, imgFactor, Size(pos, pos));
  //  std::cerr << "Modified size " << imgFactor.rows << " X " << imgFactor.cols << std::endl;
    // Show the result
  //  std::cerr << "Showing modified :" << std::endl;
    imshow("Modified", imgFactor);

    //Mat element = getStructuringElement( MORPH_RECT, Size(2*pos+1,2*pos+1), Point(pos,pos));

}

string Blur::description() {
    return "it will blur ...";
}