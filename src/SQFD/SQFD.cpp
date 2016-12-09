#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

class point
{
public:
	int x , y; 
	double ratio;
};	

double SQFD (char * file1, char * file2){

	ifstream infile1(file1);
	ifstream infile2(file2);
	double x, y;
	int cnt, n, m, nn, mm;
	infile1>>n>>nn;
	infile2>>m>>mm;
	point * WqWo = new point[n+m];
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
/**
 * Bublinkove razeni (od nejmensiho)
 * @param array pole k serazeni
 * @param size velikost pole
 */
void bubbleSort(double * array, int size, int * zobrazeni){
    for(int i = 0; i < size - 1; i++){
        for(int j = 0; j < size - i - 1; j++){
            if(array[j+1] < array[j]){
                double tmp = array[j + 1];
                array[j + 1] = array[j];
                array[j] = tmp;
                int tmp2 = zobrazeni[j + 1];
                zobrazeni[j + 1] = zobrazeni[j];
                zobrazeni[j] = tmp2	;
            }   
        }   
    }   
}    
            
int main(int argc,char **argv)
{
	if(argc<1)
		return 1;

	int imageCnt = 8;
	string images[] = {"img-01.txt", "img-02.txt", "img-03.txt", "img-04.txt",
		"img-05.txt", "img-06.txt", "img-07.txt", "img-08.txt"};
	double res [imageCnt];
	for (int i = 0; i < imageCnt; ++i){
			char * cstr = new char [images[i].length()+1]; 	// Cecko zase neumi totalni picovinu
  			strcpy (cstr, images[i].c_str());				// proto tahle prasarna
		
		res[i] = SQFD(argv[1], cstr);
	}
	int zobrazeni[] = {1,2,3,4,5,6,7,8};
	bubbleSort(res,imageCnt, zobrazeni);

	for (int i = 0; i < imageCnt; ++i)
	{
		cout << images[zobrazeni[i]] <<endl;
	}



	return 0;
}


