//
// Created by WANG Chelsea on 5/19/17.
//

#ifndef IMAGE_EDITOR_BRIGHTEN_H_
#define IMAGE_EDITOR_BRIGHTEN_H_

#include "Action.h"

class Brighten: public Action{

public:
    virtual void run(int pos, Mat& img, Mat& imgFactor);
    virtual string description();

};


#endif //IMAGE_EDITOR_BRIGHTEN_H
