#include<iostream>
#include<cstdio>
#include<ctime>

using namespace std;

void show(int * ,int);
//int c = 1;
void merge(int * arr,int p,int q,int r)
{
	int n2 = r-q;
	int n1 = q-p+1;

	int left[n1];
	int right[n2];
	int i;
	for(i = 0;i<n1;i++){
		left[i] = arr[p+i-1];
	}
	for(i = 0;i<n2;i++){
		right[i] = arr[q+i];
	}
	i = 0;
	int j = 0;

	for(int k = p-1;k<r-1;k++){
		if(i==n1){
			while(j<n2){
				arr[k++] = right[j++];
			}
			break;
		}

		else if(j==n2){
			while(i<n1){
				arr[k++] = left[i++];
			}
			break;
		}

		if(left[i] <= right[j]){
			arr[k] = left[i];
			i++;
		}
		else{
			arr[k] = right[j];
			j++;
		}
	}
	
}

void merge_sort(int * arr,int p,int r)
{
	if(p<r){
		int q = (p+r)/2;
		merge_sort(arr,p,q);
		merge_sort(arr,q+1,r);
		merge(arr,p,q,r);
//		cout << c++ << endl;
	}
}

void show(int * arr,int size)
{
	for(int i = 0;i<size;i++){
		printf("%d\n",arr[i]);
	}
	putchar('\n');
}

int main(int argc,char ** argv)
{
	int * arr = new int[15000000];
	int i = 0,n;
	n = atoi(argv[1]);
	clock_t start = clock();
	while(i<n){
		arr[i] = rand();
		i++;
	}
	merge_sort(arr,1,n);
//	show(arr,n);
	clock_t end = clock();

	double diff = difftime(end,start);
	printf("%d %.4f\n",n,diff/CLOCKS_PER_SEC);
	//cout << n << " " << (double)(end-begin)/CLOCKS_PER_SEC << endl;
	return 0;
}
