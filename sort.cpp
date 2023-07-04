#include <climits>
#include <iostream>
#include<algorithm>
using namespace std;

int partition2(int arr[], int l, int r);
int partition3(int arr[], int l, int r, int k);
int findMedian(int arr[], int n)
{
    sort(arr, arr+n);  
    return arr[n/2];  
}

int Select1_kthSmallest(int arr[], int n, int k)
{
    
    sort(arr, arr + n);
    return arr[k - 1];
}
int Select2_kthSmallest(int arr[], int l, int r, int k)
{
	
	if (k > 0 && k <= r - l + 1) {
		int pos = partition2(arr, l, r);
		if (pos - l == k - 1)
			return arr[pos];
		if (pos - l > k - 1)
			return Select2_kthSmallest(arr, l, pos - 1, k);
		return Select2_kthSmallest(arr, pos + 1, r, k - pos + l - 1);
	}
	return INT_MAX;
}
int Select3_kthSmallest(int arr[], int l, int r, int k)
{
    
    if (k > 0 && k <= r - l + 1)
    {
        int n = r-l+1;
  
        int i, median[(n+4)/5];
        for (i=0; i<n/5; i++)
            median[i] = findMedian(arr+l+i*5, 5);
        if (i*5 < n)
        {
            median[i] = findMedian(arr+l+i*5, n%5); 
            i++;
        }    
        int medOfMed = (i == 1)? median[i-1]:
            Select3_kthSmallest(median, 0, i-1, i/2);
  
        int pos = partition3(arr, l, r, medOfMed);
  
        if (pos-l == k-1)
            return arr[pos];
        if (pos-l > k-1)
            return Select3_kthSmallest(arr, l, pos-1, k);
  
        return Select3_kthSmallest(arr, pos+1, r, k-pos+l-1);
    }

    return INT_MAX;
}

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
int partition2(int arr[], int l, int r)
{
	int x = arr[r], i = l;
	for (int j = l; j <= r - 1; j++) {
		if (arr[j] <= x) {
			swap(&arr[i], &arr[j]);
			i++;
		}
	}
	swap(&arr[i], &arr[r]);
	return i;
}

int partition3(int arr[], int l, int r, int x)
{
   
    int i;
    for (i=l; i<r; i++)
        if (arr[i] == x)
           break;
    swap(&arr[i], &arr[r]);
  
    i = l;
    for (int j = l; j <= r - 1; j++)
    {
        if (arr[j] <= x)
        {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[r]);
    return i;
}

int main()
{
	int arr[] = { 12, 3, 5, 7, 4, 19, 26 , 4};
	int n = sizeof(arr) / sizeof(arr[0]), k = n/2;
	cout << "Algorithm Quicksort: " << Select1_kthSmallest(arr, n, k) << endl;
	cout << "Algorithm Quickselect: " << Select2_kthSmallest(arr, 0, n - 1, k) << endl;
	cout << "Algorithm Selection: " << Select3_kthSmallest(arr, 0, n - 1, k) << endl;
	return 0;
}
