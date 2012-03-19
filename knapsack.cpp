#include<iostream>
#include<vector>

using namespace std;

int main()
{
	vector<int> weight,val;
	vector<float> val_w;
	int load;
	int n;
	cout << "Enter total no of items : ";
	cin >> n;
	cout << "Enter size of Knapsack : ";
	cin >> load;

	int tmp;
	cout << "Enter weights and values...\n";
	for(int i = 0; i < n; i++){
		cin >> tmp;
		weight.push_back(tmp);
		cin >> tmp;
		val.push_back(tmp);
	}
	for(int i = 0; i < n; i++){
		val_w.push_back((float)(val[i]/weight[i]));
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(val_w[j] < val_w[i]){
				float t1 = val_w[j];
				int t2 = weight[j];
				int t3 = val[j];
				val_w[j] = val_w[i];
				weight[j] = weight[i];
				val[j] = val[i];
				val_w[i] = t1;
				weight[i] = t2;
				val[i] = t3;
			}
		}
	}
	//	for(int i = 0; i < n; i++)
	//		cout << val_w[i] << endl;

	tmp = 0;
	int value = 0;
	int count = 0;
	while( tmp <= load ){
		tmp += 	weight[count];
		if(tmp > load){
			tmp -= weight[count];
			while(tmp < load){
				int t = tmp;
				tmp += load-tmp;
				if(tmp > load)break;
				value += ((float)(load-t)/(float)weight[count])*val[count];
				cout << "Item worth " << ((float)(load-t)/(float)weight[count])*val[count] << " have been entered of weight " << weight[count] << endl;
				count++;
			}
			break;
		}
		cout << "Item worth " << val[count] << " have been entered of weight " << weight[count] << endl;
		value += val[count];
		count++;
	}


	cout << "Value of Items in Knapsack : " << value << endl;
	return 0;
}
