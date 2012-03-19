#include<iostream>
#include<cstdio>
#include<ctime>

using namespace std;
void show(int *,int);

inline int partition(int * arr,int p,int r)
{
	int x = arr[r];
	int i = p-1;
	int tmp;
	for(int j = p;j<r;j++){
		if(arr[j]<=x){
			i++;
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
		}
	}
	tmp = arr[i+1];
	arr[i+1] = arr[r];
	arr[r] = tmp;

	return i+1;
}

inline void quick_sort(int * arr,int p,int r)
{
	if(p<r){
		int q = partition(arr,p,r);
		quick_sort(arr,p,q-1);
		quick_sort(arr,q+1,r);
	}
}

void show(int *arr,int size)
{
	for(int i = 0;i<size;i++){
		printf("%d ",arr[i]);
	}
	putchar('\n');
}

int main(int argc,char ** argv)
{
	clock_t start = clock();
	int * arr = new int[1020000010];
	int i = 0,n;
	n = atoi(argv[1]);
	while(i<n){
		arr[i] = rand();
		i++;
	}
	quick_sort(arr,0,n-1);
//	show(arr,n);
	clock_t end = clock();
	double diff = difftime(end,start);
	printf("%d %.4f\n",n,diff/CLOCKS_PER_SEC);
//	cout << n << " " << (double)(end-begin)/CLOCKS_PER_SEC << endl;

	return 0;
}
