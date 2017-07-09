#ifndef PARAMETERS_H
#define PARAMETERS_H

#include <string>
class Parameters
{
protected:
    std::string path;

public:
    Parameters();
    void set_path(std::string & path);
};

#endif // PARAMETERS_H
