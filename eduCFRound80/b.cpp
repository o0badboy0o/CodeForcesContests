You are given two integers A and B, calculate the number of pairs (a,b) such that 1≤a≤A, 1≤b≤B, and the equation a⋅b+a+b=conc(a,b) is true; conc(a,b) is the concatenation of a and b (for example, conc(12,23)=1223, conc(100,11)=10011). a and b should not contain leading zeroes.

// daridram entante...codeforces lo pow() pancheyyadu. so power ki oka linear function rayali.
 
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
 
ll pow(ll a)
{
	ll res=1;
	for(int i=1;i<=a;i++)
	{
   		res*=10;
  	}
  	return res;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll a,b;
        cin>>a>>b;
        ll d=b;
        int counter=0;
        while(d)
        {
            d/=10;
            counter++;
        }
        if(b==(pow(counter)-1))
        {
            cout<<a*counter<<"\n";
        }
        else 
        {
            cout<<a*(counter-1)<<"\n";
        }
    }
    return 0;
}
