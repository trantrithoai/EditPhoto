//
// Created by chelseaw on 18/04/17.
//

#include "Blur.h"
#include "Resize.h"
#include "Erode.h"
#include "Dilate.h"
#include "Brighten.h"

const String keys =
        "{help h usage ?  |      | print this message   }"
// "{@image          |<none>| image to show        }"
;

struct data_input {
    Mat* img;
    Mat* imgFactor;
    Action* action;
};

// store the position of trackbar
int factorAmount=10;
int num;
// call back function to execute every time the trackbar change
static void onChange(int pos, void* userInput);
void call_menu();
// create vector to switch menu
std::vector<Action*> action_vector = { new Blur(), new Resize(),new Erode(), new Dilate(), new Brighten() };

int main( int argc, const char** argv )
{
    CommandLineParser parser(argc, argv, keys);
    parser.about("ISEP C++ 2017");

    if (parser.has("help")) {
        parser.printMessage();
        return 0;
    }

// String img_filename = parser.get<String>(0);

    if (!parser.check()) {
        parser.printErrors();
        return 0;
    }


    do{

        call_menu();

        if(num == 0)
        {
            return 0;
        };

        if (num == 1)
        {

            int number_files;

            std::cout << "How many files you want to read ? "<<std::endl;
            std::cin >> number_files;

            std::vector<string> files(number_files);

            bool try_use_gpu = false;
            Stitcher::Mode mode = Stitcher::PANORAMA;
            std::vector<Mat> imgs;
            string result_name = "result.jpg";

            for(int i =0; i < number_files;++i)
            {
                //read files
                std::cout << "\nPlease input the image file name (for example: joconde.jpg): "<<std::endl;
                std::cin >> files[i];

                Mat img = imread(files[i]);
                imgs.push_back(img);
            }

            //use stitching function
            Mat pano;
            Ptr<Stitcher> stitcher = Stitcher::create(mode, try_use_gpu);
            Stitcher::Status status = stitcher->stitch(imgs, pano);

            if (status != Stitcher::OK)
            {
                std::cout << "Can't stitch images, error code = " << int(status) << std::endl;
                return -1;
            }

            imwrite(result_name, pano);
            imshow(result_name, pano);

            waitKey(0);

            destroyWindow(result_name);

            waitKey(1);
            //return 0;
        }

        else

        {
            string imageName;
            std::cout<<"\n Please tell me which image you like (for example: joconde.jpg): " <<std::endl;
            std::cin >> imageName;

            Mat img = imread(imageName);
            //std::cerr << "Original size " << img.rows << " X " << img.cols << std::endl;
            namedWindow("Original", WINDOW_AUTOSIZE);
            Mat imgFactor = img.clone();
            namedWindow("Modified", WINDOW_AUTOSIZE);

            data_input data;

            data.action = action_vector[num - 2];
            data.img = &img;
            data.imgFactor = &imgFactor;
            // create the Trackbar
            imshow("Original", img);

            imshow("Modified", imgFactor);

            createTrackbar("Factor","Modified", &factorAmount, 20, onChange, &data);

            // Call back to onChange function
            onChange(factorAmount, &data);

            // wait app for a key to exit
            waitKey(0);

            // Destroy the windows

            destroyWindow("Original");
            destroyWindow("Modified");
            waitKey(1);
            //return 0;
        }

    }while(1);

}

static void onChange(int pos , void* userInput)
{
    if(pos <= 0)
        return;

    // result
    namedWindow("Modified", WINDOW_AUTOSIZE);//create window for blur image
    Mat imgFactor;
    // casting the input user img to
    data_input* data = (data_input*)userInput;

    //Mat* img= data->img;
    Action *action = data -> action;

    action -> run(factorAmount, *(data->img), *(data->imgFactor));

    //  Mat element = getStructuringElement( MORPH_RECT, Size(2*pos+1,2*pos+1), Point(pos,pos));

    /* // Apply a filter
     switch (num) {
         case 1:
             blur(*img, imgFactor, Size(pos, pos));
             break;

         case 2:
             resize(*img, imgFactor, Size(63*pos,48*pos));
             break;

         case 3:
             erode(*img, imgFactor, element);
             break;

         case 4:
             dilate(*img, imgFactor, element);
             break;

         case 5:
             img->convertTo(imgFactor, -1, 0.1*pos, pos);
             break;

    }
 */
    // Show the result
    //imshow("Modified", imgFactor);

}

void call_menu()
{
    std::cout <<"Please tell me which option you choose:  " << std::endl;
    std::cout <<"1 -> it will panorama " << std::endl;

    for(int i = 0; i < action_vector.size() ; ++i)
    {

        std::cout << (i+2) << " -> " << action_vector[i]->description() << std::endl;
    }
    /*cout <<" 2 -> resize " << endl;
    cout <<" 3 -> erode " << endl;
    cout <<" 4 -> dilate " << endl;
    cout <<" 5 -> brighten / darken " << endl;
    cout <<" 6 -> panorama \n " << endl;*/

    std::cout <<" Press '0' to quit \n" <<std::endl;
    std::cin >> num;

}
