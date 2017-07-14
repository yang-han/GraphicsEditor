#include "model.h"
#include <opencv2/opencv.hpp>
#include <opencv2/face.hpp>
#include <vector>
#include "viewmodel.h"
#include "notification.h"
#include <QDebug>
#include <iostream>
#include <QDir>

void Model::open_file(std::string path){

//    std::cout << path << std::endl;
    image = cv::imread(path);
    if(image.empty()){
        qInfo() << "false";
    }else{
        image.copyTo(originImg);
        image.copyTo(interImg);
        notify();
    }
}

cv::Mat& Model::get(){
    return image;
}

cv::Mat& Model::getOrigin(){
    return originImg;
}

//void Model::bind(std::shared_ptr<ViewModel> viewmodel){
//    this->viewmodel = viewmodel;
//}

void Model::set_update_display_data_notification(std::shared_ptr<Notification> notification){
    this->update_display_data_notification = notification;
}

void Model::notify(){
    update_display_data_notification->exec();
}

void Model::alterBrightAndContrast(int nbright, int nContrast){
//    image = originImg;
    cv::Mat tmpImg = cv::Mat::zeros(image.size(), image.type());
    if(tmpImg.empty() == true){
        qInfo() << "false";
        return ;
    }
    for(int y = 0; y<interImg.rows; y++){
        for(int x = 0; x<interImg.cols;x++){
            for(int c = 0;c<3;c++){
                tmpImg.at<cv::Vec3b>(y,x)[c] = cv::saturate_cast<uchar>((nContrast*0.01)*(interImg.at<cv::Vec3b>(y,x)[c]+nbright));
            }
        }
    }
    image = tmpImg;
    if(image.empty()){
        qInfo() << "false";
    }else{
        notify();
    }
}
void Model::filterReminiscence(){
    cv::Mat tmpImg(image.size(),CV_8UC3);
    if(tmpImg.empty() == true){
        std::cout<<"Can not create tmpImg! "<<std::endl;
        return ;
    }
    for (int y=0; y<image.rows; y++)
    {
        uchar* P0  = image.ptr<uchar>(y);
        uchar* P1  = tmpImg.ptr<uchar>(y);
        for (int x=0; x<image.cols; x++)
        {
            float B=P0[3*x];
            float G=P0[3*x+1];
            float R=P0[3*x+2];
            float newB=0.272*R+0.534*G+0.131*B;
            float newG=0.349*R+0.686*G+0.168*B;
            float newR=0.393*R+0.769*G+0.189*B;
            if(newB<0)newB=0;
            if(newB>255)newB=255;
            if(newG<0)newG=0;
            if(newG>255)newG=255;
            if(newR<0)newR=0;
            if(newR>255)newR=255;
            P1[3*x] = (uchar)newB;
            P1[3*x+1] = (uchar)newG;
            P1[3*x+2] = (uchar)newR;
        }
    }
    interImg = tmpImg;
    image = tmpImg;
    if(image.empty()){
        qInfo() << "false";
    }else{
        notify();
    }
}



void Model::AeroGlassscence(){
    using namespace cv;


        cv::Mat imageResult = image.clone();
        RNG rng;
        int randomNum;
        int Number = 5;

        for (int i = 0; i < image.rows - Number; i++){
            for (int j = 0; j < image.cols - Number; j++)
            {
                randomNum = rng.uniform(0, Number);
                imageResult.at<Vec3b>(i, j)[0] = image.at<Vec3b>(i + randomNum, j + randomNum)[0];
                imageResult.at<Vec3b>(i, j)[1] = image.at<Vec3b>(i + randomNum, j + randomNum)[1];
                imageResult.at<Vec3b>(i, j)[2] = image.at<Vec3b>(i + randomNum, j + randomNum)[2];
            }

    }
    interImg=imageResult.clone();
    image=imageResult.clone();
    if(image.empty()){
        qInfo() << "false";
    }else{
        notify();
    }
}


void Model::reset() {
	image = originImg;
    interImg = originImg;
	if (image.empty())
	{
		qInfo() << "false";
	}
	else {
		notify();
	}
}

void Model::save_file(std::string path){
//    std::cout << path << std::endl;
    cv::imwrite(path, image);

}
void Model::save_bmp_file(std::string path){
    cv::imwrite(path, image);
}

void Model::detect_face(){
    cv::Mat gray;
//    std::cout << "debbbbbbbbug" << std::endl;
    cv::CascadeClassifier cascade;
    cascade.load("lbpcascade_frontalface.xml");
    qInfo() << (new QDir)->currentPath();
    cv::Ptr<cv::face::FaceRecognizer> modelPCA = cv::face::createEigenFaceRecognizer();
    modelPCA->load("MyFacePCAModel.xml");

    std::vector<cv::Rect> faces(0);

    cv::cvtColor(image, gray, CV_BGR2GRAY);
    cv::equalizeHist(gray, gray);

    cascade.detectMultiScale(gray, faces,
        1.1, 2, 0
        //|CV_HAAR_FIND_BIGGEST_OBJECT
        //|CV_HAAR_DO_ROUGH_SEARCH
        | CV_HAAR_SCALE_IMAGE,
        cv::Size(30, 30));

    cv::Mat face;
    cv::Point text_lb;

    for (size_t i = 0; i < faces.size(); i++)
    {
        if (faces[i].height > 0 && faces[i].width > 0)
        {
            face = gray(faces[i]);
            text_lb = cv::Point(faces[i].x, faces[i].y);

            rectangle(image, faces[i], cv::Scalar(0, 0, 255), 1, 8, 0);
        }
    }

    notify();
}

void Model::rotate(double angle)
{
    if( image.empty() ) {
        qInfo() << "false";
        return ;
    }

    int width = originImg.cols;
    int height = originImg.rows;

    cv::Point2f center;
    center.x = width / 2.0;
    center.y = height / 2.0;

    double scale = 1.0;
    cv::Mat trans_mat = getRotationMatrix2D( center, -angle, scale );

    double angle1 = angle  * CV_PI / 180.0 ;
    double a = sin(angle1) * scale;
    double b = cos(angle1) * scale;
    double out_width = height * fabs(a) + width * fabs(b);
    double out_height = width * fabs(a) + height * fabs(b);

    trans_mat.at<double>(0, 2) += cvRound( (out_width - width) / 2 );
    trans_mat.at<double>(1, 2) += cvRound( (out_height - height) / 2);

    warpAffine(originImg, image, trans_mat, cvSize(out_width, out_height));
    interImg = image;
    if(image.empty()){
        qInfo() << "false";
    }else{
        notify();
    }
}

void Model::crop(int x1, int y1, int x2, int y2)
{
    cv::Point point1(x1, y1);
    cv::Point point2(x2, y2);
    cv::Rect rect(point1, point2);
	
    //计算剪切区域：剪切Rect与源图像所在Rect的交集
	cv::Rect srcRect;
	srcRect = cv::Rect(0, 0, interImg.cols, interImg.rows);

    rect = rect & srcRect;
    if ( rect.width <= 0  || rect.height <= 0 ){
        qInfo() << "The region is illegal!";
        return;
    }
    //创建结果图像
    interImg.create(cvSize(rect.width, rect.height), interImg.type());
    cv::Mat output = interImg;
    if (output.empty())
        return ;
    //复制源图像的剪切区域到结果图像
    image(rect).copyTo( output );
}
