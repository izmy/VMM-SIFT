//
//  CCluster.cpp
//  SIFT
//

#include <sstream>
#include "CCluster.hpp"

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

std::string CCluster::findCentral(){
    std::ostringstream ss;
    std::string value;
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

    ss << points[min].getX() << " " << points[min].getY() << " " << points.size();
    value = ss.str();

    cnt = (int)points.size();
    points.clear();

    return value;
}
