#include "parameters.h"

Parameters::Parameters()
{

}


void Parameters::set_path(std::string path){
    this->path = std::string(path);
}
std::string Parameters::get_path(){
    return path;
}
