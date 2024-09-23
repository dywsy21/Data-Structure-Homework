//HEREBY NOTED:This program is inspired by XuZhaokai's idea
#include<bits/stdc++.h>
#define MAXN 200010
using namespace std;
int weight[MAXN]={},prefix_hash[27][MAXN];
long long p1=43,p2=1e9+7;

long long substringHash(int letter, int left, int right) {
    return ((prefix_hash[letter][right] - (long long)prefix_hash[letter][left - 1] * weight[right - left + 1] % p2 + p2) % p2);
}

bool letter_isomorphic(int letter1, int letter2, int l1, int r1, int l2, int r2) {
    return substringHash(letter1, l1, r1) == substringHash(letter2, l2, r2);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int prefix_frequency[27][MAXN]={},index[27][MAXN]={};
    int cnt[27]={};
    
    
    string s;
    int m,l1,r1,l2,r2;
    cin >> s >> m;
	s = "0"+s;

    weight[0] = 1;
    for(size_t i=1;i<s.size();i++){
        weight[i] = weight[i-1]*p1 % p2;
    }
    
	for(size_t i=1;i<s.size()+1;i++){
        cnt[s[i]-'a'+1]++;
        index[s[i]-'a'+1][cnt[s[i]-'a'+1]] = i;
        for(int j=1;j<27;j++){
            prefix_frequency[j][i] = cnt[j];
        }
    }

    for(size_t i=1;i<s.size();i++){
        for(int j=1;j<27;j++){
            prefix_hash[j][i] = (prefix_hash[j][i-1]*p1 % p2 + prefix_frequency[j][i]-prefix_frequency[j][i-1]) % p2;  
        }
    }



    while(m--){
        int s1_prefix_frequency[27],s2_prefix_frequency[27];
        bool flag=1;
        cin >> l1 >> r1 >> l2 >> r2;
        if(r2-l2 != r1-l1){
            cout << "No\n";
            continue;
        }
        for(int i=1;i<27;i++){
            s1_prefix_frequency[i] = prefix_frequency[i][r1]-prefix_frequency[i][l1-1];
            s2_prefix_frequency[i] = prefix_frequency[i][r2]-prefix_frequency[i][l2-1];
            if((s1_prefix_frequency[i]!=0)!=(s2_prefix_frequency[i]!=0)){
                flag = 0;
            }
        }
        sort(s1_prefix_frequency+1,s1_prefix_frequency+27);
        sort(s2_prefix_frequency+1,s2_prefix_frequency+27);
        for(int i=1;i<27;i++){
            if(s1_prefix_frequency[i]!=s2_prefix_frequency[i]){
                flag = 0;
            }
        }
        if(!flag){
            cout << "No\n";
            continue;
        }
        for(int i=1;i<27;i++){
            if(prefix_frequency[i][l1-1]==prefix_frequency[i][r1]){
                continue;
            }
            int i_times = prefix_frequency[i][l1-1];
            int i_index = index[i][i_times+1];
            int i_counterpart = s[l2+i_index-l1] - 'a' + 1 ;
            if(!letter_isomorphic(i,i_counterpart,l1,r1,l2,r2)){
                flag = 0;
                break;
            }
        }
        if(flag){
            cout << "Yes\n";
        }
        else{
            cout << "No\n";
        }
    }

    return 0;
}