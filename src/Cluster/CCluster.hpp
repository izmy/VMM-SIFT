//
//  CCluster.hpp
//  SIFT
//
//  Created by Jaroslav Hrách on 08.12.16.
//  Copyright © 2016 Jaroslav Hrách. All rights reserved.
//

#ifndef CCluster_hpp
#define CCluster_hpp

#include <iostream>
#include <cmath>
#include <vector>
#include <stdio.h>

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
    void findCentral();
};

#endif /* CCluster_hpp */
