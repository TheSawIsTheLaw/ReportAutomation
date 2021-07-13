#ifndef FACADE_HPP
#define FACADE_HPP

#include "autodocconfiguration.hpp"

// Legendary Facade. RIP CGCoursework.
class Facade
{
public:
    Facade();

    void setSavePathForConfiguration(QString path);
    void setAnalyzeFile(QString filePath);

private:
    AutoDocConfiguration *configuration;
};

#endif // FACADE_HPP
