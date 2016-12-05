//
//  cluster.cpp
//  SIFT
//
//  Created by Jaroslav Hrách on 29.11.16.
//  Copyright © 2016 Jaroslav Hrách. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <vector>

#include "cluster.hpp"

using namespace std;

point::point(){}
point::~point(){}

point::point(double x, double y, double scale, double rotation, int * descriptors){
        this->x = x;
        this->y = y;
        this->scale = scale;
        this->rotation = rotation;
        this->descriptors = descriptors;
    }
void point::print(){
        cout<<x<<"   "<< y <<endl;
    }
    double point::getX(){
        return x;
    }
    double point::getY(){
        return y;
    }
double point::distance(point p){
        return sqrt(pow(x - p.getX(), 2) + pow(y - p.getY(), 2));
    }
bool point::isClose(point p, double epsilon){
        return epsilon > abs(this->distance(p)) ? true : false;
    }

bool cluster::isClose(point p, double epsilon){
    for (unsigned int i = 0; i < points.size(); ++i){
        if(points[i].isClose(p, epsilon))
            return true;
    }
    return false;
}

cluster::cluster(){}
cluster::~cluster(){}

void cluster::addPoint (point p){
    points.insert(points.end() ,p);
}

void cluster::print (){
    for (unsigned int i = 0; i < points.size(); ++i)
    {
        cout<<"\t\t";
        points[i].print();
    }
}

void cluster::findCentral(){
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
    points[min].print();
    cnt = points.size();
    points.clear();
}
