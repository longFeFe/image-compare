#include "interface.h"
#include "opencv2/opencv.hpp"
#include <iostream>
const int RESULT_RANGE_MAX_VALUE = 100000;
using namespace std;
string ImageHashValue(IplImage *src, int rank) {
    string resStr(rank * rank, '\0');
    IplImage *image = cvCreateImage(cvGetSize(src), src->depth, 1);
    //step one : 灰度化
	if (src->nChannels == 3)
		cvCvtColor(src, image, CV_BGR2GRAY);
	else {
		cout << "src->nChannels = " << src->nChannels;
		cvCvtColor(src, image, CV_BGR2GRAY);
	}
		
    //step two : 缩小尺寸 rank*rank
    IplImage *temp = cvCreateImage(cvSize(rank, rank), image->depth, 1);
    cvResize(image, temp);
    //step three : 简化色彩
    uchar *pData;
    for (int i = 0; i < temp->height; i++) {
        pData = (uchar *)(temp->imageData + i * temp->widthStep);
        for (int j = 0; j < temp->width; j++)
            pData[j] = pData[j] / 4;
    }
    //step four : 计算平均灰度值
    int average = (int)cvAvg(temp).val[0];
    //step five : 计算哈希值
    int index = 0;
    for (int i = 0; i < temp->height; i++) {
        pData = (uchar *)(temp->imageData + i * temp->widthStep);
        for (int j = 0; j < temp->width; j++) {
            if (pData[j] >= average)
                resStr[index++] = '1';
            else
				resStr[index++] = '0';
        }
    }
    cvReleaseImage(&image);
    cvReleaseImage(&temp);
    return resStr;
}

unsigned int ImageSimilarity(const char* sample_path, const char* refer_path, int rank) {
    if (!sample_path || !refer_path || rank < 8) return 0;

    IplImage *image1 = cvLoadImage(sample_path, 1);
    IplImage *image2 = cvLoadImage(refer_path, 1);
    string imgPrint1 = ImageHashValue(image1, rank);
    string imgPrint2 = ImageHashValue(image2, rank);

    double similarity = 1.0;
    for (int i = 0; i < rank * rank; i++) {
        char c1 = imgPrint1[i];
        char c2 = imgPrint2[i];
        if (c1 != c2)
            similarity = similarity - 1.0 / (rank * rank);
    }
	cvReleaseImage(&image1);
	cvReleaseImage(&image2);
    return (unsigned int)(similarity * RESULT_RANGE_MAX_VALUE);
}