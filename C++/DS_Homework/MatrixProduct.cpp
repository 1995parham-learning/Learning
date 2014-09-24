#include <iostream>

using namespace std;

const int MAX = 100 + 10;

void matrixProduct(int A[][MAX], int B[][MAX], int C[][MAX], int n, int m, int k);

int main(int argc,char* argv[]){
	int n, m, k;
	cin >> n >> m >> k;
	int A[MAX][MAX];
	int B[MAX][MAX];
	int C[MAX][MAX];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> A[i][j];
		}
	}
	for(int i = 0; i < m; i++){
		for(int j = 0; j < k; j++){
			cin >> B[i][j];
		}
	}
	matrixProduct(A, B, C, n, m, k);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < k; j++){
			cout << C[i][j] << " ";
		}
		cout << endl;
	}
}

void matrixProduct(int A[][MAX], int B[][MAX], int C[][MAX], int n, int m, int k){
	int counter = 0;
	for(int i = 0; i < n; i++){
		counter++;
		counter++;
		for(int j = 0; j < k; j++){
			counter++;
			counter++;
			int sum = 0;
			counter++;
			for(int l = 0; l < m; l++){
				counter++;
				counter++;
				sum += A[i][l] * B[l][j];
				counter++;
			}
			C[i][j] = sum;
			counter++;
		}
	}
	cerr <<"n = " << n << ", m = " << m << ", k = " << k << ", counter = " << counter << endl;
}
