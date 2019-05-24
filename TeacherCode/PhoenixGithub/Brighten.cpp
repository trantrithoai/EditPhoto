//
// Created by WANG Chelsea on 5/19/17.
//

#include "Brighten.h"

void Brighten::run(int pos, Mat& img, Mat& imgFactor) {

    if(pos<=0)
        return;

    img.convertTo(imgFactor, -1, 0.1*pos, pos);

    imshow("Modified",imgFactor);

}


string Brighten::description() {
    return "it will brighten ...";
}