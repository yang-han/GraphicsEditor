#ifndef PARAMETERS_H
#define PARAMETERS_H

#include <string>

class Parameters
{
private:
    std::string path;
public:
    Parameters();
    void set_path(std::string path);
    std::string get_path();
};

#endif // PARAMETERS_H
