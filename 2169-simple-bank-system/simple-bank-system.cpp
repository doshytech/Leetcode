map<int,long long> mp;
int n;
class Bank {
public:
    
    Bank(vector<long long>& balance) {
        n=balance.size();
        for(int i=0;i<n;i++){
            mp[i]=balance[i];
        }
    }
    
    bool transfer(int account1, int account2, long long money) {
        if(withdraw(account1,money)){
            if(deposit(account2,money)) return true;
            deposit(account1,money);
            return false;
            //  return true;
        }
        else return false;
    }
    
    bool deposit(int account, long long money) {
        if(account>n)return false;
        mp[account-1]+=money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if(account>n||mp[account-1]<money) return false;
        mp[account-1]-=money;
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */