#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

int fact(int n){
    if(n==0) return 1;
    if (n>0) return n*fact(n-1);
};

int NCR(int n,int r){
    if(n==r) return 1;
    if (r==0&&n!=0) return 1;
    else return (n*fact(n-1))/fact(n-1)*fact(n-r);
};


class point
{
public:
	int x , y; 
	double ratio;
	void print(){
		cout<<"("<<x<<", "<<y<<") ["<<ratio<<"]"<<endl;
	}
};	
int main(int argc,char **argv)
{
	if(argc<2)
		return 1;
	cout<<argv[0]<<endl;
	ifstream infile1(argv[1]);
	ifstream infile2(argv[2]);

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
    cout<<sqrt(abs(res))<<endl;

	return 0;
}