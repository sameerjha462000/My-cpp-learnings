#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
ostream& operator<<(ostream& os,const pair<int,int>& p)
{
	os << "<" << p.first << ", " << p.second << ">";
	return os;
}
/**
 * "should_i_swap" is a comparator function(custom comparator)
 * 
 * Ascending order on the basis of first elements and descending 
 * order on the basis of second element(obviously in case when first elements are equal)
 */
bool should_i_swap(const pair<int,int>& p1,const pair<int,int>& p2)
{
	if(p1.first < p2.first)
	{
		/**
		 * Yes you should swap in this case
		 */
		return true;
	}else if(p1.first == p2.first){
		/**
		 * Since first elements of both the pairs are same we should compare
		 * by the second elements
		 */

		/**
		 * So we will sorting in decresing order on the basis of second element
		 * For example : <5,5> and <5,3> I want them to be swapped
		 */
		if(p1.second < p2.second)
		{
			return false;
		}else if(p1.second == p2.second){
			/**
			 * Do not swap as the pairs are equal
			 */
			return false;
		}else{
			return true;
		}
	}else{
		/**
		 * No, you should not swap in this case
		 */
		return false;
	}
}
int main()
{
	#ifndef ONLINE_JUDGE
			freopen("input.txt","r",stdin);
			freopen("output.txt","w",stdout);
			freopen("error.txt","w",stderr);
	#endif

	vector<pair<int,int> > v;

	int n;
	cin >> n;

	for(int i=0;i<n;i++)
	{
		int a,b;
		cin >> a >> b;
		v.emplace_back(a,b);
	}

	for(const auto& x : v)
	{
		cout << x << endl;
	}

	// sort(v.begin(),v.end());
	/**
	 * The above function will use the natural ordering for pairs
	 * Let us say we want to compare two pairs p1 and p2
	 * Then if p1.first < p2.first then swapping would happen 
	 * If p1.first > p2.first then no swapping
	 * In case when p1.first == p2.first then we move on to the second element
	 * So if p1.second < p2.second then swapping would happen 
	 * and if p1.second > p2.second then swapping would not happen 
	 * We can also give our custom comparators in the sort function
	 **/

	/**
	 * Now let us use our own comparator function and pass that into the 
	 * sort function
	 **/

	sort(v.begin(), v.end(),should_i_swap);

	cout << "\nafter sorting...\n\n";
	for(const auto& x : v)
	{
		cout << x << endl;
	}

	return 0;
}
