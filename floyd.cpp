#include <iostream>
#include <cstdio>
#include <climits>

using namespace std;

void print_path(int *pi[],int i,int j)
{
	if(i == j){
		cout << i << endl;
		return;
	}
	else{
	       	if(pi[i][j] == -1)
			cout << "No Path from "<< i << " to " << j << " exists" << endl;
		else{
			print_path(pi,i,pi[i][j]);
			cout << j << endl;
		}
	}
}

void floyd(int *g[],int n)
{
	int tmp[n][n];
	int *pi[n];
	for(int i = 0;i<n;i++){
		pi[i] = new int[n];
		for(int j = 0;j<n;j++){
			tmp[i][j] = g[i][j];
			if(i == j || g[i][j] == INT_MAX)
				pi[i][j] = -1;
			else if( i != j && g[i][j] < INT_MAX)
				pi[i][j] = i;
		}
	}

	for(int k = 0;k<n;k++){
		for(int i = 0;i<n;i++){
			for(int j = 0;j<n;j++){
				int a = tmp[i][k] + tmp[k][j];
				if(tmp[i][k] == INT_MAX || tmp[k][j] == INT_MAX)
					a = INT_MAX;
				pi[i][j] = tmp[i][j] <= a ? pi[i][j] : pi[k][j];
				tmp[i][j] = tmp[i][j] < a ? tmp[i][j] : a;
			}
		}
	}

	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			if(tmp[i][j] == INT_MAX){
				char t[] = "INF";
				printf("%5s",t);
			}
			else
				printf("%5d",tmp[i][j]);
		}
		cout << endl;
	}
	cout << "Predecessor Mat..." << endl;
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			printf("%5d",pi[i][j]);
		}
		cout << endl;
	}
	int i,j;
	cout << "Enter source and destination vetices .. \n";
	cin >> i >> j;
	print_path(pi,i,j);
	cout << endl;
}

int main()
{
	int n;
	cin >> n;
	int *graph[n];
	int a,b;
	int value;

	for(int i = 0;i<n;i++){
		graph[i] = new int[n];
		for(int j = 0;j<n;j++){
			graph[i][j] = INT_MAX;
		}
		graph[i][i] = 0;
	}

	while(1)
	{
		cin >> a;
		cin >> b;
		if(a == -1 && b == -1)break;
		cin >> value;
		graph[a][b] = value;
	}

	floyd(graph,n);
	return 0;
}
