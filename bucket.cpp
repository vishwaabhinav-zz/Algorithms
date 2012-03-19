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

node * insert(node * head,int data)
{
	node * newnode = new node();
	newnode -> data = data;
	newnode->next = head;
	head = newnode;
	return head;
}

node ** make_list(node ** head,int * arr,int n)
{
	for(int i = 0;i<n;i++){
		int tmp = (int)((float)(arr[i]-1)/INT_MAX*n);
//		cout << tmp << " " << endl;
		head[tmp] = insert(head[tmp],arr[i]);
	}
	return head;
}

node ** sort_list(node ** head,int n)
{
	for( int i = 0;i<n;i++){
		node * temp = head[i];
		while( temp != NULL ) {
			node * temp1 = temp->next;
			while(temp1 != NULL){
				if(temp1->data < temp->data){
					int tmp = temp->data;
					temp->data = temp1->data;
					temp1->data = tmp;
				}
				temp1 = temp1->next;
			}
			temp = temp->next;
		}
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

int main(int argc,char **argv)
{
	time_t start;
	time_t end;
	int i;
	
	int n = atoi(argv[1]);
	
	int * arr = (int *)malloc(sizeof(int)*n);
	node ** b = (node **)malloc(sizeof(node)*n);

	for (i = 0; i < n; i++ ) {
		b[i] = NULL;
	}

	i = 0;
	while(i<n){
		int tmp = rand();
//		cout << tmp << " ";
		arr[i] = tmp;
		i++;
	}
	cout << endl;
	n = i;

	start = clock();
	b = make_list(b,arr,n);
	b = sort_list(b,n);
	merge_buckets(arr,b,n);
//	cout << '\v';
//	show(arr,n);
	end = clock();
	double diff = difftime(end,start);

	printf("%.4f\n",diff/CLOCKS_PER_SEC);

	return 0;
}
