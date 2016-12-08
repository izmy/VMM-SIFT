//
//  CCluster.cpp
//  SIFT
//
//  Created by Jaroslav Hrách on 08.12.16.
//  Copyright © 2016 Jaroslav Hrách. All rights reserved.
//

#include "CCluster.hpp"
#include "CPoint.hpp"


CCluster::CCluster() {};
CCluster::~CCluster() {};
bool CCluster::isClose(CPoint p, double epsilon){
    for (unsigned int i = 0; i < points.size(); ++i){
        if(points[i].isClose(p, epsilon))
            return true;
    }
    return false;
}
void CCluster::addPoint (CPoint p){
    points.insert(points.end() ,p);
}
void CCluster::findCentral(){
    double * length = new double[points.size()];
    for (unsigned int i = 0; i < points.size(); ++i)
        length[i] = 0;
    for (unsigned int i = 0; i < points.size(); ++i){
        for (unsigned int j = i+1; j < points.size(); ++j){
            double dist = points[i].distance(points[j]);
            length[i] += dist;
            length[j] += dist;
        }
    }
    int min = 0;
    for (unsigned int i = 0; i < points.size(); ++i){
        if(length[i]<length[min])
            min = i;
    }
    std::cout<<points[min].getX()<<" "<<points[min].getY() << " "<< points.size() << std::endl;
    cnt = (int)points.size();
    points.clear();
}
