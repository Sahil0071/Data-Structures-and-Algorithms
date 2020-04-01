// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

string compress(string& s);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        cout<< compress(s) << endl;
    }
    return 1;
}
// } Driver Code Ends
//User function Template for C++

// return a string formed by compressing string s
// do not print anything
vector<int> getlps(string s)
{
	int n=s.length();
	vector<int>lps(n,0);
	int i=1,j=0;
	while(i<n&&j<n)
	{
		if(s[i]==s[j])
		{
			lps[i]=j+1;
			i++,j++;
		}
		else
		{
			if((j-1)<0)
			{
				lps[i]=0;
				i++;
			}
			else
			{
				j=lps[j-1];
			}
		}
	}
	return lps;
}


string compress(string& s)
{
    vector<int>lps=getlps(s);
    string str;
    int n=s.length();
    int ind=n-1;

    string res;
    
    
    while(ind>=0)
    {
        if(ind%2 && lps[ind]>=(ind+1)/2 && (ind+1)%(ind+1-lps[ind])==0 && ((ind+1)/(ind+1-lps[ind]))%2==0 )
        {
            res.push_back('*');
            ind/=2;
            
        }
        else
        {
            res.push_back(s[ind]);
            ind--;
            
        }
        
    }
    
    string ans;
    for(int i=res.size()-1;i>=0;i--)
    ans+=res[i];
    return ans;
}


