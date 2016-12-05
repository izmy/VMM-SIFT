//
//  cluster.hpp
//  SIFT
//
//  Created by Jaroslav Hrách on 29.11.16.
//  Copyright © 2016 Jaroslav Hrách. All rights reserved.
//

#ifndef cluster_hpp
#define cluster_hpp

#include <iostream>
#include <cmath>
#include <vector>
#include <stdio.h>

class point {
private:
    double x, y, scale, rotation;
    int * descriptors;
    
public:
    point();
    ~point();
    point(double x, double y, double scale, double rotation, int * descriptors);
    void print();
    double getX();
    double getY();
    double distance(point p);
    bool isClose(point p, double epsilon);
};

class cluster
{
private:
    std::vector<point> points;
    point central;
    int cnt;
public:
    cluster();
    ~cluster();
    bool isClose(point p, double epsilon);
    void addPoint (point p);
    void print ();
    void findCentral();
};

#endif /* cluster_hpp */
