#include<iostream>
#include<climits>
#include<ctime>

//#define k 10000

using namespace std;


void counting(int * a,int * b,int * c,int n)
{
	int i;
	
	for(i = 0;i < n;i++){
		c[i] = 0;
	}

	for(i = 0;i<n;i++){
		c[a[i]] = c[a[i]]+1;
	}

	for(i = 1;i<n;i++){
		c[i] = c[i]+c[i-1];
	}

	for(i = n-1;i>=0;i--){
		b[c[a[i]]] = a[i];
		c[a[i]] = c[a[i]]-1;
	}
}

void show(int * arr,int n)
{
	for(int i = 0;i<n;i++){
		cout << arr[i] << endl;
	}
}

int main(int argc,char ** argv)
{
	int n = atoi(argv[1]);
	int * a = new int[n];
	int * b = new int[n];
	int * c = new int[n];

	int i = 0;
	while(i<n){
		a[i] = rand()%n;
		i++;
	}
	clock_t start = clock();	
//	show(a,n);
	counting(a,b,c,n);
	clock_t end = clock();
//	show(b,n);
	printf("%d %.4f\n",n,(double)(end-start)/CLOCKS_PER_SEC);

	return 0;
}
