//
//  CCluster.hpp
//  SIFT
//

#ifndef CCluster_hpp
#define CCluster_hpp

#include <iostream>
#include <cmath>
#include <vector>
#include <stdio.h>
#include <string>

#include "CPoint.hpp"

class CCluster
{
private:
    std::vector<CPoint> points;
    CPoint central;
    unsigned int cnt;
public:
    CCluster();
    ~CCluster();
    bool isClose(CPoint p, double epsilon);
    void addPoint (CPoint p);
    void print ();
    std::string findCentral();
};

#endif /* CCluster_hpp */
