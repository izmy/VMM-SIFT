//
//  CPoint.cpp
//  SIFT
//
//  Created by Jaroslav Hrách on 08.12.16.
//  Copyright © 2016 Jaroslav Hrách. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <vector>

#include "CPoint.hpp"

using namespace std;

CPoint::CPoint(){};
CPoint::~CPoint(){};
CPoint::CPoint(double x, double y, double scale, double rotation, int * descriptors, int m){
    this->x = x;
    this->y = y;
    this->scale = scale;
    this->rotation = rotation;
    this->descriptors = descriptors;
    this->m = m;
}
double CPoint::getX(){
    return x;
}
double CPoint::getY(){
    return y;
}
double CPoint::getScale(){
    return scale;
}
double CPoint::getRotation(){
    return rotation;
}
int * CPoint::getDescriptors(){
    return descriptors;
}
double CPoint::distance(CPoint p){
    double tmp = 0;
    
    tmp += pow(x - p.getX(), 2) + pow(y - p.getY(), 2);
    /*+  pow(rotation - p.getRotation(), 2) + pow(scale - p.getScale(), 2);
     
     int * desc = p.getDescriptors();
     for (unsigned int i = 0; i < m; ++i){
     tmp += pow(descriptors[i] - desc[i], 2);
     }*/
    return sqrt(tmp);
}
bool CPoint::isClose(CPoint p, double epsilon){
    return epsilon > abs(this->distance(p)) ? true : false;
}
