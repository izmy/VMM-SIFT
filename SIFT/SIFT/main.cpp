//
//  main.cpp
//  SIFT
//
//  Created by Jaroslav Hrách on 15.11.16.
//  Copyright © 2016 Jaroslav Hrách. All rights reserved.
//

#include "cluster.hpp"

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;


int main(int argc, const char * argv[]) {
    
    double epsilon = 1.9;
    int n, m;
    cin >> n >> m;
    vector<cluster> clusters;
    cluster tmpCluster;
    for (int i = 0; i < n; ++i){
        
        
        //	nacteni dat
        double x, y, scale, rotation;
        int * descriptors = new int [m];
        cin >> x >> y >> scale >> rotation;
        for (int j = 0; j < m; ++j)
            cin >> descriptors[j];
        //	zarazeni bodu do clusteru
        point tmpPoint(x,y,scale,rotation,descriptors);
        unsigned int j;
        for (j = 0; j < clusters.size(); ++j){
            if(clusters[j].isClose(tmpPoint, epsilon)){
                clusters[j].addPoint(tmpPoint);
                break;
            }
        }
        if(j == clusters.size()){
            tmpCluster.addPoint(tmpPoint);
            clusters.insert(clusters.end(), tmpCluster);
        }
        
    }
    
    
    //	hledani prostredniho prvku
    for (unsigned int i = 0; i < clusters.size(); ++i){
        cout<<"CLUSTER "<< i <<endl;
        clusters[i].findCentral();
    }
    
    
    
    return 0;
    
}
