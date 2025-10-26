vector<long long> p;
int n;
class Bank {
public:
    Bank(vector<long long>& balance) {
        p = balance;
        n = p.size();
    }
    bool transfer(int account1, int account2, long long money) {
        bool tk = withdraw(account1,money);
        if(tk){
            if(deposit(account2,money))return true;
            else{
                deposit(account1,money);
                return false;
            }
            // return true;
        }
        else return false;
    }
    
    bool deposit(int account, long long money) {
        if(account<1||account>n)return false;
        p[account-1]+=money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        // if(account>p.size())return false;
        if(account<1||account>n||p[account-1]<money)return false;
        p[account-1]-=money;
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