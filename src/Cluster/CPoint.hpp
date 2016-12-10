//
//  CPoint.hpp
//  SIFT
//

#ifndef CPoint_hpp
#define CPoint_hpp

#include <iostream>
#include <cmath>
#include <vector>
#include <stdio.h>

class CPoint {
private:
    double x, y, scale, rotation;
    int * descriptors, m;
    
public:
    CPoint();
    ~CPoint();
    CPoint(double x, double y, double scale, double rotation, int * descriptors, int m);
    void print();
    double getX();
    double getY();
    double getScale();
    double getRotation();
    int * getDescriptors();
    double distance(CPoint p);
    bool isClose(CPoint p, double epsilon);
};

#endif /* CPoint_hpp */
