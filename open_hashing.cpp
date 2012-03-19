#include<iostream>

using namespace std;

struct node{
	int value;
	char * flag;
};

int hash1(int k,int n)
{
	return abs(k)%n;
}

int hash2(int k,int n)
{
	return 1+(abs(k)%(n-1));
}

int hash(int k,int i,int n)
{
//	if(k < 0)
//		return 0;
	return ( hash1( k, n ) + i * hash2( k, n ) ) % n;
}

int make_table(node *v,int num,int n)
{
	int i = 0;
	do{
		int j = hash(num,i,n);
//		cout << j << endl;
		if(v[j].flag == NULL){
			v[j].value = num;
			v[j].flag = "NUM";
			return j;
		}
		i = i + 1;
	} while(i < n);
	cout << "hash table overflow" << endl;
	return -1;
}

int search(node *v,int num,int n)
{
	int i = 0,j;
	do{
		j = hash(num,i,n);
		if(v[j].value == num && v[j].flag == "NUM")
			return j;
		i = i + 1;
	} while(v[j].flag != NULL || i < n );
	return -1;
}

int hash_delete(node *arr,int k,int n)
{	
	int j = search(arr,k,n);
	if(j == -1){
		cout << "Not Found" << endl;
		return -1;
	}
	else{
		arr[j].flag = "DEL";
	}
	return arr[j].value;
}

void show(node *arr,int n)
{
	for(int i = 0;i<n;i++){
		if(arr[i].flag == "NUM")
			cout << arr[i].value << " ";
	}
	cout << endl;
}

int main()
{
	int n;
	int tmp;
	int i;
	int j;
	cin >> n;
	node arr[n];
	for(int i = 0;i<n;i++)
		arr[i].flag = NULL;

	i = 0;
	while(i < n){
		cin >> tmp;
		int j = make_table(arr,tmp,n);
//		if(j != -1)
//			cout << j << endl;
		i++;
	}
	show(arr,n);
	cout << "Enter Num To Search : ";
	cin >> tmp;
	cout << "Index of the Num : ";
	cout << search (arr,tmp,n) << endl;
	cout << "Enter Num to delete : ";
	cin >> tmp;
	cout << "deleted Num is : " << hash_delete(arr,tmp,n) << endl;
	show(arr,n);
}
