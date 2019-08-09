//
// Created by michele on 07/07/19.
//

#include <ros/ros.h>
#include <sensor_msgs/Image.h>
#include <opencv2/core/core.hpp>

using namespace std;
using namespace cv;


#ifndef ROS_CUDA_DOOR_RECOGNIZER_CPU_ALGORITMS_H
#define ROS_CUDA_DOOR_RECOGNIZER_CPU_ALGORITMS_H

// SINGLETON
class CpuAlgorithms {
private:
    CpuAlgorithms();

public:
    static CpuAlgorithms& getInstance();

    void toGrayScale(unsigned char*, int, int);
    void toGrayScale(uint8_t*, const uint8_t*, int, int);
    void copyArrayToImage(sensor_msgs::Image&, uint8_t*);
    void gaussianFilter(unsigned char *destination, unsigned char *source, float *mask, int width, int height, int maskDim);
    void sobel(float *edgeGradient, int *edgeDirection, unsigned char *source, int width, int height);
    void nonMaximumSuppression(unsigned char *destination, float *edgeGradient, int *edgeDirection, int width, int height);
    void harris(unsigned char *destination, unsigned char *source, unsigned char *imageSobel, int width, int height);
    double houghLinesIntersection(vector<Point> &points, Mat &image);
    double findCandidateCorner(vector<Point> &candidateCorners, unsigned char *image, vector<Point>& intersections, int width, int height);
    double candidateGroups(vector<pair<vector<Point>, Mat*>> &groups, vector<Point>& corners, Mat &image, int width, int height);
    double fillRatio(vector<vector<Point>>& matchFillRatio, vector<pair<vector<Point>, Mat*>> &groups, unsigned char *image, int width, int height);

};


#endif //ROS_CUDA_DOOR_RECOGNIZER_CPU_ALGORITMS_H
