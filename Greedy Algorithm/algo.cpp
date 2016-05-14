#include<bits/stdc++.h>
using namespace std;

#define mp make_pair

const int N = 100100;

int arr[N];  // input array
int a[N];  // diffrence array

set<pair<long long, pair<int, int> > > minHeap; //implementing heap
map<pair<int, int>, long long> edges; //storing all edges.

long long lft[N];  // to maintain office numbers to the left of an office
long long rgt[N];  // to maintain office numbers to the right of an office

long long total; //Total Cost

int main()
{

	int n, k; // n = number of offices and k = number of cables
	cin >> n >> k;
	for(int i = 0; i < n; i++) cin >> arr[i]; 
 	for(int i = 0; i < n-1; i++) a[i] = arr[i+1] - arr[i];//cin >> a[i];
	
	for(int i = 0; i < n-1; i++){
		minHeap.insert(mp(a[i], mp(i, i+1)));
		edges[mp(i,i+1)] = a[i];
		rgt[i] = i+1;
		lft[i+1] = i;
	}
	
	rgt[n-1] = -1;
	lft[0] = -1;
	
	while(k--){
		pair<long long, pair<int, int> > top = *minHeap.begin();
		minHeap.erase(top);
		
		if(!edges.count(top.second)){
			k++;
			continue;
		}
		
		edges.erase(top.second);
		
		long long cost = top.first;
		int x = top.second.first, y = top.second.second; // edge from x to y
		
		long long lx = lft[x];
		long long ry = rgt[y];
		
		total += cost;
		
		if(edges.count(mp(lx,x)) and edges.count(mp(y,ry))){
			
			lft[ry] = lx;
			rgt[lx] = ry;
			//Considering the other possible case that if an edge is minimum but not in the final solution 
 			//then its adjacent edges are in the final solutopn for sure 

			cost = edges[mp(lx,x)] + edges[mp(y,ry)] - cost;
			
			edges.erase(mp(lx,x));
			edges.erase(mp(y,ry));
			
			minHeap.insert(mp(cost, mp(lx,ry)));
			edges[mp(lx,ry)] = cost;
		}
		
		if(edges.count(mp(lx,x))) edges.erase(mp(lx,x));
		if(edges.count(mp(y,ry))) edges.erase(mp(y,ry));
		
	}
	
	edges.clear();
	minHeap.clear();
	memset(lft,0,sizeof(lft));
	memset(rgt,0,sizeof(rgt));
	memset(arr,0,sizeof(arr));
	memset(a,0,sizeof(a));
		
	cout << total << endl; // answer
	return 0;

}
