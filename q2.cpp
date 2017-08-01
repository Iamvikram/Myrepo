#include <bits/stdc++.h>
using namespace std;
#define ll long long
int res[1000001];
vector<int>v;
bool check1(int x){
      int rev=0,n=x;
      while(n){
            rev=rev*10+n%10;
            n/=10;
      }
      return (x==rev);
}
bool check2(int x){
      v.clear();
      while(x){
        v.push_back(x%2);
        x/=2;
      }
      reverse(v.begin(),v.end());
      bool f=true;
      int n=v.size();
      for(int i=0;i<n/2;i++){
            if(v[i]!=v[n-i-1]){
                  f=false;
                  break;
            }
      }
      if(f){
            return true;
      }
      else{
            return false;
      }
}
void pre(){
      int i;
      memset(res,0,sizeof(res));
      for(i=1;i<1000001;i++){
            res[i]=res[i-1];
            if(check1(i) && check2(i)){
                  res[i]++;
            }
      }
}
int main() {
	// your code goes here
	int q,n;
	pre();
	cin>>q;
	while(q--){
	      cin>>n;
	      cout << res[n] << endl;
	}
	
	return 0;
}
