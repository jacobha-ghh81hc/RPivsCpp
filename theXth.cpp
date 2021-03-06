#include <iostream>
#include <vector>
// https://www.techiedelight.com/find-kth-largest-element-array/
// https://www.geeksforgeeks.org/k-th-element-two-sorted-arrays/
using namespace std;

ostream& operator<< (ostream& os, const std::vector<int> &v)
{
	for(auto it = v.begin(); it != v.end(); ++it)
	{
		os << *it << ',';
	}
	return os;
}

#define N 10

int main()
{
	int firstArray[N] = {14,24,30,41,56,67,70,83,91,101};
	int secondArray[N] = {1,25,30,41,55,63,70,82,93,106};

	int kRequired = 11;
	int *mergedArray = (int*)calloc(2*N, sizeof(int));

	int i,j,k;
	i = j = k = 0;
	while(i<N && j<N)
	{
		if(*(firstArray+i) < *(secondArray+j))
		{
			*(mergedArray+k) = *(firstArray+i);
			if(k == kRequired) cout << *(firstArray+i) << endl;
			k++;
			i++;
		}
		else
		{
			*(mergedArray+k) = *(secondArray+j);
			if(k == kRequired) cout << *(secondArray+j) << endl;
			k++;
			j++;
		}
	}

	while(i<N)
	{
		*(mergedArray+k) =  *(firstArray+i);
		if(k == kRequired) cout << *(firstArray+i) << endl;
		i++;
		k++;
	}

	while(j<N)
	{
		*(mergedArray+k) =  *(secondArray+j);
		if(k == kRequired) cout << *(secondArray+j) << endl;
		j++;
		k++;
	}

	for(int l = 0; l<2*N; l++)
	{
		cout << *(mergedArray+l) << ',';
	}
	cout << endl;

	return 0;
}