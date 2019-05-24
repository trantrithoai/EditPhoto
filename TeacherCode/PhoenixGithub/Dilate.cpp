//
// Created by WANG Chelsea on 5/19/17.
//

#include "Dilate.h"

void Dilate::run(int pos, Mat& img, Mat& imgFactor) {

    if(pos<=0)
        return;

    Mat element = getStructuringElement( MORPH_RECT, Size(2*pos+1,2*pos+1), Point(pos,pos));

    dilate(img, imgFactor, element);

    imshow("Modified", imgFactor);

}

string Dilate::description() {
    return "it will dilate ...";
}