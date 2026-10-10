#include<iostream>
#include<vector>

using namespace std;

double f(double x) {
	return sin(x);
}

vector<vector<double>> intervals(double a, double b, int k) {
	int n = 0;
	vector<vector<double>>m;

	double step = (b - a) / k;
	while (a < b) {
		if (f(a) * f(a + step) < 0) {
			m.push_back({ a,a + step });
		}
		a += step;
	}
	return m;
}

vector<double> solution(vector<vector<double>> inter) {
	vector<double>dots;
	
	for (int i = 0; i < inter.size(); i++) {
		double a = inter[i][0];
		double b = inter[i][1];
		
		double c;

		while (b-a > 1e-6){
			c = (a + b) / 2;
			if (f(c) * f(a) < 0) {
				b = c ;
			}
			else if (f(c) * f(b) < 0) {
				a = c;
			}
		}
		dots.push_back(c);
	}
	return dots;
}

int main() {
	vector<vector<double>> a = intervals(0, 10, 20);
	for (int i = 0; i < a.size(); i++) {
		cout << a[i][0] << " " << a[i][1] << endl;
	}
	cout << "\n";

	vector<double>b = solution(a);
	for (int i = 0; i < b.size(); i++) {
		cout << b[i]<< endl;
	}
}
