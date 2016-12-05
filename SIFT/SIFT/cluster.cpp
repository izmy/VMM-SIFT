#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

class point
{
private:
	double x, y, scale, rotation;
	int * descriptors, m;

public:
	~point(){
	 	//delete [] descriptors;
	 }

	point(){};
	point(double x, double y, double scale, double rotation, int * descriptors, int m){
		this->x = x;
		this->y = y;
		this->scale = scale;
		this->rotation = rotation;
		this->descriptors = descriptors;
		this->m = m;
	}
	double getX(){
		return x;
	}
	double getY(){
		return y;
	}
	double getScale(){
		return scale;
	}
	double getRotation(){
		return rotation;
	}
	int * getDescriptors(){
		return descriptors;
	}
	double distance(point p){
		double tmp = 0;
		
		tmp += pow(x - p.getX(), 2) + pow(y - p.getY(), 2);
		   /*+  pow(rotation - p.getRotation(), 2) + pow(scale - p.getScale(), 2);
			   
		int * desc = p.getDescriptors();
		for (unsigned int i = 0; i < m; ++i){
			tmp += pow(descriptors[i] - desc[i], 2);
		}*/
		return sqrt(tmp);
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
	unsigned int cnt;
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
		cout<<points[min].getX()<<" "<<points[min].getY() << " "<< points.size()<<endl;
		cnt = points.size();
		points.clear();
	}
};

int main(int argc,char **argv)
{

	double epsilon = 5;
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
		point tmpPoint(x,y,scale,rotation,descriptors,m);	
		unsigned int j;
		//cout<<i<<endl;
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
	cout<<clusters.size()<<" "<<n<<endl;
	for (unsigned int i = 0; i < clusters.size(); ++i){
			clusters[i].findCentral();	
	}	


	
	return 0;
}