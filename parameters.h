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
class MouseMoveParameters: public Parameters {
private:
    double x_s;
    double y_s;
    double x_e;
    double y_e;
public:
    MouseMoveParameters() :x_s(0), y_s(0), x_e(0), y_e(0) {}
    void set_start_pnt(double vx_s, double vy_s) { x_s = vx_s; y_s = vy_s; }
    void set_end_pnt(double vx_e, double vy_e) { x_e = vx_e; y_e = vy_e; }
    double getx_s() { return x_s; }
    double gety_s() { return y_s; }
    double getx_e() { return x_e; }
    double gety_e() { return y_e; }

};
#endif // PARAMETERS_H
