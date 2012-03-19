#include<iostream>
#include<map>

using namespace std;

int main()
{
	string s;
	cin >> s;
	string arr[] = {"0","10","110","111"};
	string val[] = {"a","t","g","c"};
	string tmp;
	int i = 0;
	while(i<s.length()){
		int k = 0;
		while(k<4){
			if(s.substr(i,arr[k].length()) == arr[k]){
				tmp.append(val[k]);
				break;
			}
			k++;
		}
		i += arr[k].length();
	}
	cout << tmp << endl;

	return 0;
}
