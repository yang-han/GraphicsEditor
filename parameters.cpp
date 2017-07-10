#include "parameters.h"
#include <string>


Parameters::Parameters()
{

}

void Parameters::set_path(std::string path){
    this->path = path;
}

std::string Parameters::get_path(){
    return path;
}
