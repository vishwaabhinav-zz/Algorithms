#include<iostream>
#include<vector>
#include<climits>
#include"min_prior.h"

using namespace std;

struct node{
	int data;
	int value;
	node * next;
};

node * insert(node *head,int data,int value)
{
	node *tmp = new node;
	tmp->data = data;
	tmp->value = value;
	tmp->next = head;

	if(head == NULL)
		return tmp;
	head = tmp;
}

void show(node *head)
{
	node *tmp = head;
	while(tmp != NULL){
		cout << tmp->data << "[" << tmp->value << "]  ";
		tmp = tmp->next;
	}
	cout << endl;
}

bool search_list(node * head,int data)
{
	node *tmp = head;
	while(tmp != NULL)
	{
		if(tmp->data == data)
			return true;
		tmp = tmp->next;
	}
	return false;
}

void print_path(node *graph[],int s,int v,int *pre)
{
	if(v == s)
		cout << s << " ";
	else if(pre[v] == -1){
		cout << "No path from " << s << " to " << v << " exist" << endl;
		return;
	}
	else{
		print_path(graph,s,pre[v],pre);
		cout << v << " ";
	}
}

void prim(node *graph[],int n,int s,int *key,int *pre,vector<int> S,que *pq[])
{
	for(int i = 0;i<n;i++){
		key[i] = INT_MAX;
		pre[i] = -1;
	}
	int len = n;
	key[s] = 0;
	for(int i = 0;i<n;i++){
		pq[i] = new que;
		pq[i]->value = key[i];
		pq[i]->key = i;
	}
	build_heap(pq,n);

	int i = 0;
	while(n>0){
		que *u = heap_extract_min(pq,&n);
		node *tmp = graph[u->key]->next;
		while(tmp != NULL){
			int v = tmp->data;
			for(i = 0;i<n;i++){
				if(v == pq[i]->key && u->value < key[v]){
					pre[v] = u->key;
					key[v] = u->value;
					pq[i]->value = key[v];
					break;
				}
			}
			tmp = tmp->next;
		}
		build_heap(pq,n);
	}
	
	cout << "Enter Destination Vertex : ";
	int v;
	cin >> v;
	print_path(graph,s,v,pre);
	cout << endl;
//	for(int i = 0;i<len;i++)
//		cout << i << " " << pre[i] << endl; 
}
	
int main()
{
	int n;
	int a,b;
	int value;
	int source;
	cin >> n;

	node *graph[n];
	int d[n];
	int pre[n];
	que *prior[n];
	vector<int> S;
	
	for(int i = 0;i<n;i++){
		graph[i] = NULL;
	}
	
	while(1){
		cin >> a;
		cin >> b;
		if(a == -1 && b == -1)break;
		
		cin >> value;
		graph[a] = insert(graph[a],b,value);
//		graph[b] = insert(graph[b],a,value);
	}
	
	for(int i = 0;i<n;i++){		
		graph[i] = insert(graph[i],i,0);
	}
	
	for(int i = 0;i<n;i++){
		show(graph[i]);
	}
///////////////////////////////////////////////////////////////
	cout << "Enter source vertex : ";
	cin >> source;
	prim(graph,n,source,d,pre,S,prior);

	return 0;
}
