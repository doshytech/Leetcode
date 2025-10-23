class LRUCache {
public:
    set<pair<int,int>> s;
    map<int,pair<int,int>> mp;
    int n, ct = 0;
    LRUCache(int capacity) {
        n = capacity;
    }
    int get(int key){
        if(mp.find(key)!=mp.end()){
            int i = mp[key].first;
            mp[key].first = ct;
            ct++;
            s.erase({i,key});
            s.insert({mp[key].first,key});
            return mp[key].second;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)==mp.end()){
            s.insert({ct,key});
            mp[key]={ct,value};
            }
        else{
            int i = mp[key].first;
            mp[key] = {ct,value};
            s.erase({i,key});
            s.insert({mp[key].first,key});
        }
        if(s.size()>n){
            pair<int,int> p = *s.begin();
            s.erase(s.begin());
            mp.erase(p.second);
        }
        ct++;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
//  auto init = atexit([]() { ofstream("display_runtime.txt") << "0";});
