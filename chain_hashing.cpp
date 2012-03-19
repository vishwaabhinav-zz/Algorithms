#include<iostream>
#include<cstdlib>
#include<climits>
#include<cstdio>

using namespace std;

struct node{
	int data;
	node * next;
};

node * insert(node *,float);
void show(int *,int);
node * insertion_sort(node *);
void show_list(node *);

int hash(int key,int n,int k)
{
	return (int)((float)(key-1)/k*n);
}

node * insert(node * head,int data)
{
	node * newnode = new node();
	newnode -> data = data;
	newnode->next = head;
	head = newnode;
	return head;
}

node ** make_list(node ** head,int * arr,int n,int k)
{
	for(int i = 0;i<n;i++){
//		int tmp = (int)((float)(arr[i]-1)/INT_MAX*n);
		int tmp = hash(arr[i],n,k);
//		cout << tmp << " " << endl;
		head[tmp] = insert(head[tmp],arr[i]);
	}
	return head;
}

void merge_buckets(int * arr,node ** b,int n)
{
	int k = 0;
	for(int i = 0;i<n;i++){
		node * temp = b[i];
		while(temp != NULL){
			arr[k] = temp->data;
			k++;
			temp = temp->next;
		}
	}
}

void show(int * arr,int n)
{
	for(int i = 0;i<n;i++){
		cout << arr[i] << endl;
	}
	cout << endl;
}

void show_list(node * head)
{
	node * tmp = head;
	while(tmp != NULL){
		cout << tmp->data << " ";
		tmp = tmp->next;
	}
	cout << endl;
}

node ** hash_delete(node **b,int num,int *n,int k)
{
	int j = hash(num,*n,k);
//	cout << j << " " << num << " " << b[j]->data << endl;
	node * temp = b[j];
	node * temp1 = b[j];
	while(temp != NULL){
		if(temp->data == num){
			if(temp == b[j]){
				b[j] = b[j]->next;
				free(temp);
			}
			else{
				temp1->next = temp->next;
				free(temp);
			}
//			cout << num << endl;
			(*n) = (*n)-1;			
		}
		temp1 = temp;
		temp = temp->next;
	}

	return b;
}

int main(int argc,char **argv)
{
	time_t start;
	time_t end;
	int i;
	
	int n = atoi(argv[1]);
	int k;	
	int tmp;
	int * arr = (int *)malloc(sizeof(int)*n);
	node ** b = (node **)malloc(sizeof(node)*n);

	for (i = 0; i < n; i++ ) {
		b[i] = NULL;
	}
	cout << "Enter range : ";
	cin >> k;
	i = 0;
	while(i<n){
		int tmp = rand()%k;
//		cout << tmp << " ";
		arr[i] = tmp;
		i++;
	}
	cout << endl;
	n = i;

	b = make_list(b,arr,n,k);
	merge_buckets(arr,b,n);

	show(arr,n);
	cout << "Enter Value to delete : ";
	cin >> tmp;
	b = hash_delete(b,tmp,&n,k);
//	cout << n << endl;
	merge_buckets(arr,b,n);
	show(arr,n);

	return 0;
}
