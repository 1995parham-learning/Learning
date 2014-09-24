#include <iostream>

using namespace std;

const int MAX = 100 + 10;

void MatrixSum(int A[][MAX], int B[][MAX], int C[][MAX], int n, int m);

int main(int argc,char* argv[]){
	int n, m;
	cin >> n >> m;
	int A[MAX][MAX];
	int B[MAX][MAX];
	int C[MAX][MAX];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> A[i][j];
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> B[i][j];
		}
	}
	MatrixSum(A, B, C, n, m);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cout << C[i][j] << " ";
		}
		cout << endl;
	}
}

void MatrixSum(int A[][MAX], int B[][MAX], int C[][MAX], int n, int m){
	int counter = 0;
	for(int i = 0; i < n; i++){
		counter++;
		counter++;
		for(int j = 0; j < m; j++){
			counter++;
			counter++;
			C[i][j] = A[i][j] + B[i][j];
			counter++;
		}
	}
	cerr << "n = " << n << ", m = " << m << ", counter = " << counter << endl;
}
