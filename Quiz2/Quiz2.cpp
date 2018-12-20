#include <iostream>
#include <vector>

using namespace std;

vector<int> merge(vector<int> list1, vector<int> list2);

int main() {

	vector<int> list1 = {0,3,5,6};
	vector<int> list2 = {1,2,3,4};

	vector<int> mergedList = merge(list1, list2);
	// Cannot use a new vector merge as a variable here.
	// vector<int> merge = merge(list1, list2) is wrong as merge is a function name

	for(unsigned int i=0; i<mergedList.size(); i++) cout << mergedList[i] << " ";

}
vector<int> merge(vector<int> list1, vector<int> list2) {

	vector<int> list3;
	unsigned int m=0, n=0;
	bool listOneRemains = false, listTwoRemains = false;
	//bool equal = list1.size()==list2.size()?true:false;
	//Remember the this trick of assigning a variable and checking a condition simultaneously

	if(list2[m]<list1[n]) list3.push_back(list2[m++]);
	else list3.push_back(list1[n++]);

	for(unsigned int i=1; i<list1.size()+list2.size(); i++) {

		if(list1[n]>=list2[m]) {

			list3.push_back(list2[m++]);

			if(list2[m-1]<list3[i-1]) {
				//swap
				iter_swap(list3.begin() + i-1, list3.begin() + i);
			}
		}
		else {
			list3.push_back(list1[n++]);

			if(list1[n-1]<list3[i-1]) {
				iter_swap(list3.begin() + i-1, list3.begin() + i);
			}
		}
		if(m==list2.size()) {
			listOneRemains = true;
			break;
		}

		else if(n==list1.size()) {
			listTwoRemains = true;
			break;
		}
	}
	if(listOneRemains == true) {

		list3.insert(list3.end(), list1.begin()+n, list1.end());

	}
	else if(listTwoRemains == true) {

		list3.insert(list3.end(), list2.begin()+m, list2.end());

	}
	return list3;
}
