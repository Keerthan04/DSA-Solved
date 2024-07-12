class TimeMap {
private:
    unordered_map<string,vector<pair<int,string>>> keyStore;
public:
    TimeMap() {
    }

    void set(string key, string value, int timestamp) {
        keyStore[key].emplace_back(timestamp,value);        
    }
    string get(string key, int timestamp) {
     auto& values = keyStore[key];//getting the vector
     int l=0,r=values.size()-1;
     string res = "";
     while(l<=r){
        int mid = l+ ((r-l)/2);
        if(values[mid].first <=timestamp){
            res=values[mid].second;//got the value but most recent still so right go
            l=mid+1;
        }else{
            //is greater so left
            r= mid-1;
        }
     }
     return res;
    }
};
