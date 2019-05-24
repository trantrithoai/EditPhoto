//
// Created by WANG Chelsea on 5/19/17.
//

#include "Erode.h"

void Erode::run(int pos, Mat& img, Mat& imgFactor) {

    if(pos<=0)
        return;


    Mat element = getStructuringElement( MORPH_RECT, Size(2*pos+1,2*pos+1), Point(pos,pos));

    erode(img, imgFactor, element);

    imshow("Modified",imgFactor);

}

string Erode::description() {

    return "it will erode ...";

}