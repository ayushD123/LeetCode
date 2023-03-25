class DataStream {
public:
    int val;
    int k;
    int cnt;
    DataStream(int value, int k) {
        val=value;
        this->k=k;
        cnt=0;
    }
    
    bool consec(int num) {
        if(num==val){
            cnt++;
        }else{
            cnt=0;
        }
        if(cnt>=k){
            return true;
        }else{
            return false;
        }
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */