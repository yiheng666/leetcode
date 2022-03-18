class Bank {
public:
    vector<long long> bankAccount;
    int n;
    Bank(vector<long long>& balance) {
        bankAccount = balance;
        n = balance.size();
    }
    
    bool transfer(int account1, int account2, long long money) {
        if (account1 <= 0 || account1 > n || account2 <= 0 || account2 > n || bankAccount[account1-1] < money) return false;
        bankAccount[account1-1] -= money;
        bankAccount[account2-1] += money;
        return true;
    }
    
    bool deposit(int account, long long money) {
        if (account <= 0 || account > n) return false;
        bankAccount[account-1] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if (account <= 0 || account > n ||  bankAccount[account-1] < money) return false;
        bankAccount[account-1] -= money;
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