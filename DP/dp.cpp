#include <algorithm>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

map < pair <int,int>, int > m;  //map is used to store result of  (i,k)th recursion step
#define N 100000
//int array[] = {0,7,10,17,37};

int algo(int diff[], int i,int k)
{
	int x=0,y=0,q=0,temp1=0,temp2=0;
	if(m.find(make_pair(i,k))!=m.end())        //Checking whether (i,k) is present in the map 
		return m.at(make_pair(i,k));     //Use of Dynamic programming:- The stored values are being here
	if(k==0)
		return 0;
	if(i==((2*k)-1)) // number of nodes being odd there will be two possibilities                                  
	{
		x=0;
		y=0;
		q=0;
		while(q<i)
		{
			x = x+diff[q];
			y = y+diff[q+1];
			q = q+2;
		}
		if(x<y) return x;
		else return y;
	}
	if(i==((2*k)-2)) // number of nodes being even there is only one possibility
	{
		x = 0;
		q = 0;
		while(q<i)
		{
			x = x+diff[q];
			q = q+2;
		}
		return x;
	}


	temp1 = algo(diff,i-1,k);   //Recursion relation:- not considering the weight of the last edge
	temp2 = algo(diff,i-2,k-1) + diff[i];  //Recursion relation :- considering the weight of the last edge
	if(temp1<temp2) m[make_pair(i,k)] = temp1; //Comparing the values obtained by two recurrence relations
	else m[make_pair(i,k)] = temp2; // storing the value
	if(temp1<temp2) return temp1;
	else return temp2;
		
}

int main()
{
	int n;
	int k;
	int array[N];
	cin >> n >> k;
	for(int i=0;i<n;i++)
	{
		cin>>array[i];   //Scanning the input into the array
	}


	int result;
	int diff[n-1];
	for(int i=0;i<n-1;i++) 
	{
		diff[i]=0;          //Initializing the difference array diff with 0

	}
	
	for(int i=0;i<n-1;i++)
	{
		diff[i] = array[i+1] - array[i];  //diff array is calculating the difference between two offices
	}
	result = algo(diff,n-2,k); //Output is being calculated recursively in the algo function and stored in result
	cout <<"Answer: " << result << "\n";

}
	