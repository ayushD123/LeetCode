class SmallestInfiniteSet {
public:
      priority_queue <int, vector<int>, greater<int> > pq; 
    int arr[1001]={0};
    int index;
    SmallestInfiniteSet() {
index=1;
    }
    
    int popSmallest() {
        while(arr[index]!=0){
            index++;
        }
        arr[index]=1;
        return index;
    }
    
    void addBack(int num) {
        arr[num]=0;
        index=1;
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */