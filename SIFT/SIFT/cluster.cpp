#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

class point
{
private:
	double x, y, scale, rotation;
	int * descriptors;

public:
	~point(){
	 	//delete [] descriptors;
	 }

	point(){};
	point(double x, double y, double scale, double rotation, int * descriptors){
		this->x = x;
		this->y = y;
		this->scale = scale;
		this->rotation = rotation;
		this->descriptors = descriptors;
	}
	void print(){
		cout<<x<<"   "<< y <<endl;
	}
	double getX(){
		return x;
	}
	double getY(){
		return y;
	}
	double distance(point p){
		return sqrt(pow(x - p.getX(), 2) + pow(y - p.getY(), 2));
	}
	bool isClose(point p, double epsilon){
		return epsilon > abs(this->distance(p)) ? true : false;
	}
};
class cluster
{
private:
	vector<point> points;
	point central;
	int cnt;
public:

	bool isClose(point p, double epsilon){
		for (unsigned int i = 0; i < points.size(); ++i){
			if(points[i].isClose(p, epsilon))
				return true;
		}
		return false;
	}
	void addPoint (point p){
		points.insert(points.end() ,p);
	}
	void print (){
		for (unsigned int i = 0; i < points.size(); ++i)
		{	
			cout<<"\t\t";
			points[i].print();
		}
	}
	void findCentral(){
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
};

int main(int argc,char **argv)
{

	double epsilon = 1.9;
	int n, m;
	cin >> n >> m;
	vector<cluster> clusters;
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
			cluster tmpCluster;
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