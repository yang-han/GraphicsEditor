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

class brightAndContrastParameters: public Parameters{
private:
    int nBright; // may not be 'int'
    int nContrast;
public:
    brightAndContrastParameters(int bright = 0, int contrast = 100):nBright(bright), nContrast(contrast){}

    int get_nBright(){return nBright;}
    int get_nContrast(){return nContrast;}
};

class IntParameters :public Parameters {
private:
    int value;
public:
    IntParameters(int v) :value(v) {}
    void setvalue(int v) { value = v; }
    int getvalue() { return value; }
};

#endif // PARAMETERS_H
