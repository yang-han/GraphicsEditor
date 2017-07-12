#ifndef PARAMETERS_H
#define PARAMETERS_H

#include <string>

class Parameters
{
public:
    Parameters();
};


class PathParameters: public Parameters{
private:
    std::string path;
public:
    PathParameters(std::string _path):path(_path){
    }
    std::string get_path(){
        return path;
    }
};




#endif // PARAMETERS_H
