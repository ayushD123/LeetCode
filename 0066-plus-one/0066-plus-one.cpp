class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(),digits.end());
        int x=digits[0]+1;
        int carry=0;
        if(x==10){
            digits[0]=0;
            carry=1;
        }else{
            digits[0]+=1;
        }
        for(int i=1;i<digits.size();++i){
            int x=digits[i]+carry;
            if(x==10){
                digits[i]=0;
                carry=1;
            }else{
                digits[i]=x;;
                carry=0;
            }
        }
        if(digits[digits.size()-1]==0){
            digits.push_back(1);
        }
        
     reverse(digits.begin(),digits.end());
        return digits;
    }
};