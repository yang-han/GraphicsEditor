#ifndef MODEL_H
#define MODEL_H

#include "common.h"

Model::Model()
{
private:
    std::shared_ptr<cv::Mat> image;
public:
    Model();
    ~Model();
    std::shared_ptr<cv::Mat> get();

    void load(string file_name);
}

#endif // MODEL_H
