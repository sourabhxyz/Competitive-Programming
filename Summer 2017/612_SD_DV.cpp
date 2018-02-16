#include<bits/stdc++.h>
unsigned long long swaps[102];
using namespace std;
#define FileIn(file) freopen(file".txt", "r", stdin)
#define FileOut(file) freopen(file".txt", "w", stdout)
int g;
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else///i.e we need to swap
        {
            arr[k] = R[j];
            swaps[g]+=n1-i;//Most important line. basically once we are doing arr[k]=R[j] that means we are
            ///putting R[j] before each of n1-i elements thus there are that many swaps.
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}
struct stringData{
	string a;
	int swap,originalIndex;
};
bool cmp(stringData x,stringData y)
{
    if(x.swap==y.swap)  return x.originalIndex<y.originalIndex;
    else    return x.swap<y.swap;
}
int main()
{
    //FileIn("in");
    //FileOut("out");
	int t;
	cin>>t;
	while(t--)
	{
		memset(swaps, 0 , sizeof swaps);
		int n,m;
		cin>>n>>m;
		vector<stringData> sd;
		sd.resize(m);
		int a[n];
		for(g = 0;g<m;g++)
		{
			cin>>sd[g].a;
			for(int i =0;i<n;i++)
			{
				a[i] = sd[g].a[i]-65;
			}
			mergeSort(a,0,n-1);
			sd[g].swap=swaps[g];
			sd[g].originalIndex=g;
		}
		sort(sd.begin(),sd.end(),cmp);
		for(int i = 0;i<m;i++)
		{
			cout<<sd[i].a<<"\n";
		}
		if(t>0) cout<<"\n";
	}
	return 0;
}

