#include<bits/stdc++.h>

#define F first
#define S second

const double PI = acos(-1.0);

double toRad(double deg){
	return (deg * PI/180.0);
}

double toDeg(double rad){
	return (rad * 180.0 / PI);
}

template<class T>
struct Triangle{
	double Area(T b, T h){
		return ( (long long)b * h)/2.0;
	}
	
	double Area(T a, T b, double theta) { // SAS
		return ( (long long)a * b * sin(theta))/2.0;
	}
	
	double Area(T a, T b, T c){
		double s = (a + b + c)/2.0;
		return sqrt(s * (s - a) * (s - b) * (s - c));
	}
	
	
};
