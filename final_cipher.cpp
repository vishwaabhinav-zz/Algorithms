#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>

using namespace std;

struct node{
	int freq;
	string val;
	struct node * left;
	struct node * right;
};

vector<string> tmp;
void show(node **,int);
void show_tree(node *);

//int len = 10;
int right(int size)
{
	return size*2+2;
}

int left(int size)
{
	return size*2+1;
}

int parent(int size)
{
	return (size-1)/2;
}

void heapify(node ** arr,int size,int len)
{
	int l = left(size);
	int r = right(size);
	int smallest;
	if ( l < len && arr[ l ]->freq < arr[ size ]->freq ) {
		smallest = l;
	}
	else{
		smallest = size;
	}

	if ( r < len && arr[ r ]->freq < arr[ smallest ]->freq ) {
		smallest = r;
	}


	if(smallest != size){
		int tmp = arr[size]->freq;
		string val = arr[size]->val;
		node * left = arr[size]->left;
		node * right = arr[size]->right;

		arr[size]->freq = arr[smallest]->freq;
		arr[size]->val = arr[smallest]->val;
		arr[size]->left = arr[smallest]->left;
		arr[size]->right = arr[smallest]->right;

		arr[smallest]->freq = tmp;
		arr[smallest]->val = val;
		arr[smallest]->left = left;
		arr[smallest]->right = right;

		heapify(arr,smallest,len);
	}
	
}

void build_heap(node ** arr,int len)
{
	for(int i = len/2;i>=0;i--){
		heapify(arr,i,len);
	}
}

void show(node ** arr,int len)
{
	int i = 0;

	while(i<len){
		printf("%d ",arr[i]->freq);
		i++;
	}
	putchar('\n');
}

int heap_min(node ** arr)
{
	return arr[0]->freq;
}

node * extract_min(node ** arr,int * len)
{
	node * tmp = new node;
	
	tmp->freq = arr[0]->freq;
	tmp->val = arr[0]->val;
	tmp->left = arr[0]->left;
	tmp->right = arr[0]->right;
	
	arr[0]->freq = arr[(*len)-1]->freq;
	arr[0]->val = arr[(*len)-1]->val;
	arr[0]->left = arr[(*len)-1]->left;
	arr[0]->right = arr[(*len)-1]->right;

	*len = *len-1;
	heapify(arr,0,*len);
	return tmp;
}

void decrease_key(node ** arr,int i,node * head)
{
	if(head->freq > arr[i]->freq)
		cout << "new key is bigger than older" << endl;
	else{
		arr[i]->freq = head->freq;
		arr[i]->val = head->val;
		arr[i]->left = head->left;
		arr[i]->right = head->right;
		while( i > 0 && arr[parent(i)]->freq > arr[i]->freq){
			int t = arr[i]->freq;
			string val = arr[i]->val;
			node * tmp = arr[i]->left;
			node * tmp1 = arr[i]->right;

			arr[i]->freq = arr[parent(i)]->freq;
			arr[i]->val = arr[parent(i)]->val;
			arr[i]->left = arr[parent(i)]->left;
			arr[i]->right = arr[parent(i)]->right;

			arr[parent(i)]->freq = t;
			arr[parent(i)]->val = val;
			arr[parent(i)]->left = tmp;
			arr[parent(i)]->right = tmp1;
			
			i = parent(i);
		}
	}
}

node ** insert(node ** arr,node * head,int * len)
{
	arr[*len]->freq = head->freq + 1;
	arr[*len]->val = head->val;
	decrease_key(arr,*len,head);
	*len = *len + 1;
	return arr;
}

int frequency(string s,char key)
{
	int count = 0;
	for(int i = 0;i<s.length();i++){
		if(s[i] == key)
			count++;
	}
	return count;
}

node * huffman(node ** arr,int * len)
{
	int n = *len;
	for(int i = 0;i < n-1;i++){
		node * z = new node;
		
		node * x = extract_min(arr,len);
		z->left = x;
		
		node * y = extract_min(arr,len);
		z->right = y;
		
		z->freq = x->freq + y->freq;
		z->val = x->val;
		(z->val).append(y->val);
		arr = insert(arr,z,len);
/*		for(int j = 0;j<*len;j++){
//			cout << arr[j]->val << " ";
			show_tree(arr[j]);
			cout << endl;
		}
		cout << *len << endl;
		cout << endl;
*/	}
//	show_tree(arr[0]);
	return extract_min(arr,len);
}

void show_tree(node * head)
{
	if(head == NULL)
		return;
	show_tree(head->left);
	cout << head->freq << " " << head->val << endl;
	show_tree(head->right);
}

void search(node * head,int freq,char key){
	if(head == NULL)
		return;
	if(head->left != NULL){
		int found = (head->left->val).find(key);
		if(found != string::npos){
			cout << "0";
			search(head->left,freq,key);
		}
	}
	if(head->right != NULL){
		int found = (head->right->val).find(key);
		if(found != string::npos){
			cout << "1";
			search(head->right,freq,key);
		}
	}
}

int main()
{
	int i = 0,len;
	node ** arr = (node **)malloc(sizeof(node)*100);
	node * t;
	string s;
	bool flag = true;
	getline(cin,s);

	vector<char> ch;
	vector<int> freq;
	int j;
	int k = 0;
	while(i<s.length()){
		j = 0;
		flag = true;
		while(j<ch.size()){
			if(ch[j] == s[i]){
				flag = false;
				break;
			}
			j++;
		}
		
		if(flag == true){
			arr[k] = new node;
			arr[k]->freq = frequency(s,s[i]);
			freq.push_back(arr[k]->freq);
			arr[k]->val = s[i];
			arr[k]->left = NULL;
			arr[k]->right = NULL;
			ch.push_back(s[i]);
			k++;
		}
		i++;
	}
	len = k;
	int n = len;
	build_heap(arr,len);
//	show(arr,len);
	t = huffman(arr,&len);
//	show_tree(t);
//	cout << n << endl;
	cout << "value\tfrequency\tcode\n";
	for(i = 0;i<n;i++){
		cout << ch[i] << "\t" << freq[i] << " \t\t";
		search(t,freq[i],ch[i]);
		cout << endl;
	}

	for(i = 0;i<s.length();i++){
		for(j = 0;j<n;j++){
			if(s[i] == ch[j])
				break;
		}
		search(t,freq[j],s[i]);
	}
	cout << endl;

	return 0;	
}
