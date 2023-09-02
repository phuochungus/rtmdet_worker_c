#include <opencv2/opencv.hpp>
#include "mmdeploy/detector.hpp"
#include <zmq.hpp>

#include <iostream>
#include <cstdlib>
#include <omp.h>
#include <chrono>

using namespace std;
using namespace cv;
using namespace mmdeploy;

const char *model_path = NULL;
const char *device_name = "cpu";

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        cout << "Please provide model path\n";
        return 1;
    }
    model_path = argv[1];
    Model model(model_path);
    Detector detector(model, Device{device_name});
    // VideoCapture videoCapture(video_path);
    // Mat frame;
    // int frameIndex = 0;
    // int frame_width = videoCapture.get(CAP_PROP_FRAME_WIDTH);
    // int frame_height = videoCapture.get(CAP_PROP_FRAME_HEIGHT);
    // int fps = videoCapture.get(CAP_PROP_FPS);

    // VideoWriter video("outcpp.avi", cv::VideoWriter::fourcc('M', 'J', 'P', 'G'), fps, Size(frame_width, frame_height));
    // using namespace std::chrono;
    // uint64_t tmp1 = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();

    // while (true)
    // {
    //     videoCapture >> frame;
    //     if (frame.empty())
    //         break;
    //     auto dets = detector.Apply(frame);
    //     for (int i = 0; i < dets.size(); ++i)
    //     {
    //         const auto &box = dets[i].bbox;
    //         if (dets[i].score < 0.3)
    //         {
    //             continue;
    //         }
    //         rectangle(frame, Point{(int)box.left, (int)box.top},
    //                   Point{(int)box.right, (int)box.bottom}, Scalar{0, 255, 0});
    //     }
    //     video.write(frame);
    // }
    // uint64_t tmp2 = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
    // cout << tmp2 - tmp1 << endl;
    // videoCapture.release();
    // video.release();
    return 0;
}