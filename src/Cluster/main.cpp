//
//  main.cpp
//  SIFT
//

#include "CCluster.hpp"

#include <fstream>
#include <sstream>

using namespace std;


int main(int argc, const char * argv[]) {

    if ((argc != 3) && (argc != 4)) {
        std::cerr << "Usage: " << argv[0] << " keys1.txt keys1-clustered.txt [epsilon: double]" << std::endl
                  << "- keys1.txt: ASIFT keypoints" << std::endl
                  << "- keys1-clustered.txt: clustered ASIFT keypoints" << std::endl
                  << "- [epsilon optional: double number] (default: 3)" << std::endl;
        return 1;
    }

    double epsilon = 3;

    if (argc == 4) {
        sscanf(argv[3],"%lf",&epsilon);
    }

    ifstream inputFile;
    ofstream outputFile;
    string fileIn;
    string fileOut;
    fileIn = (string)argv[1];
    fileOut = (string)argv[2];
    string line;

    vector<CCluster> clusters;

    int n, m;

    //	nacteni dat
    inputFile.open( fileIn.c_str() );
    getline(inputFile, line);
    istringstream ss(line);
    ss >> n >> m;
    
    for (int i = 0; i < n; ++i) {
        double x, y, scale, rotation;
        int * descriptors = new int [m];

        getline(inputFile, line);
        istringstream ss(line);

        ss >> x >> y >> scale >> rotation;

        for (int j = 0; j < m; ++j) {
            ss >> descriptors[j];
        }

        //	zarazeni bodu do clusteru
        CPoint tmpPoint(x, y, scale, rotation, descriptors, m);

        unsigned int j;

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

    inputFile.close();

    outputFile.open( fileOut.c_str() );
    
    //	hledani prostredniho prvku
    outputFile << clusters.size() << " " << n << endl;
    for (unsigned int i = 0; i < clusters.size(); ++i){
        outputFile << clusters[i].findCentral() << endl;
    }

    outputFile.close();
    
    return 0;
    
}
