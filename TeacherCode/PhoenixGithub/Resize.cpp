//
// Created by WANG Chelsea on 5/19/17.
//

#include "Resize.h"

void Resize::run(int pos, Mat& img, Mat& imgFactor){

    if(pos <= 0)
        return;

    resize(img, imgFactor, Size(63*pos,48*pos));

  //  std::cerr << "Modified size " << imgFactor.rows << " X " << imgFactor.cols << std::endl;
    // Show the result
  //  std::cerr << "Showing modified :" << std::endl;
    imshow("Modified", imgFactor);

}


string Resize::description() {
    return "it will resize ...";
}
