class Solution {
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        string ls="";
        for(auto it:event1[0]){
            if(it!=':')
            ls.push_back(it);
        }
        int low=stoi(ls);
        string hs="";
         for(auto it:event1[1]){
              if(it!=':')
            hs.push_back(it);
        }
           int high=stoi(hs);
        string check="";
        for(auto it:event2[0]){
             if(it!=':')
            check.push_back(it);
        }
        int ch=stoi(check);
         string check2="";
        for(auto it:event2[1]){
             if(it!=':')
            check2.push_back(it);
        }
        int ch2=stoi(check2);
         if(ch2>=low && ch2<=high)
        return 1;
        if(low>=ch && low<=ch2)
        return 1;
        if(high>=ch && high<=ch2)
        return 1;
      //  cout<<low<<" "<<high<<" "<<ch2;
      //  cout<<low<<" "<<high<<" "<<check;
        if(ch>=low && ch<=high)
        return 1;
        return 0;
    }
};