#include <iostream>
#include <cmath>
#include <fstream>
#include <sstream>

#include "CPoint.h"

using namespace std;

typedef struct {
    string fileName;
    double ratio;
} IMAGES;

int compare(const void * a, const void * b) {
    IMAGES *imageA = (IMAGES *)a;
    IMAGES *imageB = (IMAGES *)b;

    if( imageA->ratio < imageB->ratio ) {
        return -1;
    } else if (imageA->ratio == imageB->ratio ) {
        return 0;
    } else {
        return 1;
    }
}

double SQFD (string file1, string file2){

	ifstream infile1(file1);
	ifstream infile2(file2);
	double x, y;
	int cnt, n, m, nn, mm;
	infile1>>n>>nn;
	infile2>>m>>mm;
	CPoint * WqWo = new CPoint[n+m];
	for (int i = 0; i < n; ++i){
		infile1 >> x >> y >> cnt;
		WqWo[i].x = x;
		WqWo[i].y = y;
		WqWo[i].ratio = cnt/(double)nn;
	}
	for (int i = 0; i < m; ++i){
		infile2 >> x >> y >> cnt;
		WqWo[n+i].x = x;
		WqWo[n+i].y = y;
		WqWo[n+i].ratio = -1*cnt/(double)mm;
	}
	double ** matrixA = new double * [n+m];
	for (int i = 0; i < n+m; ++i)
	{
		matrixA[i] = new double[n+m];
	}
	for (int i = 0; i < n+m; ++i)
	{
		for (int j = 0; j < n+m; ++j)
		{
			matrixA[i][j] = 1/(1+sqrt(pow(WqWo[i].x-WqWo[j].x, 2)+pow(WqWo[i].y-WqWo[j].y, 2)));
		}
	}

	double * matrixB = new double[n+m];
    for(int j = 0; j < n+m; ++j){
    	matrixB[j] = 0;
        for(int k = 0; k < n+m; ++k){
                matrixB[j] += WqWo[k].ratio * matrixA[j][k];
        }
    }

    double res = 0;
    for (int i = 0; i < n+m; ++i)
    {
    	res += matrixB[i]  * WqWo[i].ratio;
    }
    return sqrt(abs(res));
}

int main(int argc, char **argv)
{
    if ( argc != 3 ) {
        std::cerr << "Usage: " << argv[0] << " keys-clustered.txt db.txt" << std::endl
                  << "- keys-clustered.txt: clustered ASIFT keypoints" << std::endl
                  << "- db.txt: database of all images (clustered ASIDT keypoints)" << std::endl;
        return 1;
    }

    ifstream inputFile;
    string fileDB = argv[2];
    string line;
    int fileTotal = 0;

    inputFile.open( fileDB );

    while ( getline(inputFile, line) ) {
        ++fileTotal;
    }

    //cout << fileTotal << endl;

    inputFile.clear();
    inputFile.seekg(0, ios::beg);

    IMAGES * images = new IMAGES[fileTotal];

    for (int i = 0; i < fileTotal; ++i) {
        getline(inputFile, line);
        istringstream ss(line);
        ss >> images[i].fileName;
    }

    for (int i = 0; i < fileTotal; ++i) {
        images[i].ratio = SQFD(argv[1], images[i].fileName);
    }

    qsort(images, fileTotal, sizeof(IMAGES), compare);

    for (int i = 0; i < fileTotal; ++i) {
        istringstream ss(images[i].fileName);
        string fileName;
        getline(ss,fileName,'.');
        cout << fileName << ".png";
        printf (";%12.10f", images[i].ratio );
        if (i < fileTotal - 1) cout << endl;
    }

    delete [] images;

	return 0;
}