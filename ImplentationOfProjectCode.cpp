#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;


int main() {
    int no_of_users;
    cin>>no_of_users;
    unordered_map<int,int>id_balance;
    vector<string>success_or_failure;
    for(int i=0;i<no_of_users;i++){
        int id,balance;
        cin>>id>>balance;
        id_balance[id]=balance;
        
    }
    int no_of_transactions;cin>>no_of_transactions;
    for(int i=0;i<no_of_transactions;i++){
        int to_id,from_id,amount;
        cin>>from_id>>to_id>>amount;
        
        if(id_balance.find(from_id)!=id_balance.end()&&id_balance.find(to_id)!=id_balance.end()){
            if(id_balance[from_id]>=amount){
                id_balance[from_id]-=amount;
                id_balance[to_id]+=amount;
                success_or_failure.push_back("Success");
                
            }
            else{
                success_or_failure.push_back("Failure");
            }
            
        }
        else{
            success_or_failure.push_back("Failure");
        }
        
    }
    for(int i=0;i<no_of_transactions;i++){
        cout<<success_or_failure[i]<<'\n';
    }
    cout<<'\n';
    vector<pair<int,int>>final_balance(id_balance.begin(),id_balance.end());
    sort(final_balance.begin(),final_balance.end(),[](const pair<int, int>& a, const pair<int, int>& b) {
        if (a.second == b.second) return a.first < b.first;
        return a.second < b.second;});
    for(auto balance:final_balance){
        cout<<balance.first<<" "<<balance.second<<'\n';
    }
    
    return 0;
}