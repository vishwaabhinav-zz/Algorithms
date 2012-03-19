#include<cstdio>
#include<ctime>

using namespace std;

void show(int *,int);

//int len = 10;
int right(int size)
{
	return size*2+2;
}

int left(int size)
{
	return size*2+1;
}

void heapify(int * arr,int size,int len)
{
	int l = left(size);
	int r = right(size);
	int largest;
	if(l<len && arr[l]>arr[size]){
		largest = l;
	}
	else{
		largest = size;
	}

	if(r<len && arr[r]>arr[largest]){
		largest = r;
	}


	if(largest != size){
		int tmp = arr[size];
		arr[size] = arr[largest];
		arr[largest] = tmp;

		heapify(arr,largest,len);
	}
}

void build_heap(int * arr,int len)
{
	for(int i = len/2;i>=0;i--){
		heapify(arr,i,len);
	}
}

void show(int * arr,int len)
{
	int i = 0;

	while(i<len){
		printf("%d\n",arr[i]);
		i++;
	}
	putchar('\n');
}

void heap_sort(int * arr,int len){
	build_heap(arr,len);
	int t = len-1;
	for(int i = len-1;i>=1;i--){
		int tmp = arr[0];
		arr[0] = arr[i];
		arr[i] = tmp;
		
		t--;
		heapify(arr,0,t+1);
	}
}

int main(int argc,char ** argv)
{
	clock_t start = clock();
	int i = 0;
	int * arr = new int[10000000];
	int len = atoi(argv[1]);
	while(i<len){
		arr[i] = rand();
		i++;
	}

	heap_sort(arr,len);
//	show(arr,len);
	clock_t end = clock();

	double diff = difftime(end,start);
	printf("%d %.4f\n",len,diff/CLOCKS_PER_SEC);
	
	return 0;
}
