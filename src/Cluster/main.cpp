//
//  main.cpp
//  SIFT
//
//  Created by Jaroslav Hrách on 15.11.16.
//  Copyright © 2016 Jaroslav Hrách. All rights reserved.
//

#include "CCluster.hpp"
#include "CPoint.hpp"

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;


int main(int argc, const char * argv[]) {
    
    
    double epsilon = 5;
    int n, m;
    cin >> n >> m;
    vector<CCluster> clusters;
    
    for (int i = 0; i < n; ++i){
        
        //	nacteni dat
        double x, y, scale, rotation;
        int * descriptors = new int [m];
        cin >> x >> y >> scale >> rotation;
        for (int j = 0; j < m; ++j)
            cin >> descriptors[j];
        //	zarazeni bodu do clusteru
        CPoint tmpPoint(x,y,scale,rotation,descriptors,m);
        unsigned int j;
        //cout<<i<<endl;
        for (j = 0; j < clusters.size(); ++j){
            if(clusters[j].isClose(tmpPoint, epsilon)){
                clusters[j].addPoint(tmpPoint);
                break;
            }
        }
        if(j == clusters.size()){
            CCluster tmpCluster;
            tmpCluster.addPoint(tmpPoint);
            clusters.insert(clusters.end(), tmpCluster);
        }
        
    }
    
    //	hledani prostredniho prvku
    cout<<clusters.size()<<" "<<n<<endl;
    for (unsigned int i = 0; i < clusters.size(); ++i){
        clusters[i].findCentral();
    }
    
    
    return 0;
    
}
