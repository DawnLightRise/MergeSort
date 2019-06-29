#include <iostream>

using namespace std;

int mergeTwoParts(float *a, int idx_low, int idx_mid, int idx_high)
{
	int n = idx_high - idx_low + 1;

	float *tmp = NULL;
	tmp = new float[n];
	fill_n(tmp, n, 0);

	int i, j, k;
	i = idx_low;
	j = idx_mid+1;
	k = 0; 
	
	while(i<=idx_mid && j<=idx_high)
		if(a[i]<a[j])
			tmp[k++] = a[i++];
		else
			tmp[k++] = a[j++];
			
	while(i<=idx_mid)
		tmp[k++] = a[i++];
		
	while(j<=idx_high)
		tmp[k++] = a[j++];
		
	for(k=0; k<n; k++)
		a[k+idx_low] = tmp[k];

	delete[] tmp;

	return 0;
}

int mergeSortKernel(float *a, int idx_low, int idx_high)
{
	int idx_mid;
	
	if(idx_low<idx_high)
	{
		idx_mid = (idx_low + idx_high)/2;
		
		mergeSortKernel(a, idx_low, idx_mid);
		mergeSortKernel(a, idx_mid+1, idx_high);
		
		mergeTwoParts(a, idx_low, idx_mid, idx_high);
	}
	
	return 0;
}

int mergeSort(float *a, int n)
{	
	if(n<1)
		;
	else
		mergeSortKernel(a, 0, n-1);
		
	return 0;
}

int main(void)
{
	int n=400;

	float *a = NULL; 
	a = new float[n];
	fill_n(a, n, 0);
	
	int i=0; 
	
	for(i=0; i<n; i++)
		a[i] = (float)(n-i);
		
	mergeSort(a, n);
	
	for(i=0; i<n; i++)
		cout << a[i] << endl;
		
	delete[] a;
	
	return 0;
}
