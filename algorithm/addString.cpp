
//大数相加
string addStrings(string num1, string num2) {
    int i = num1.size() - 1;
    int j = num2.size() - 1;
    int carry = 0;
    string res = "";
    while(i>=0 || j>=0 || carry){
        long sum = 0;
        if(i >= 0){sum += (num1[i] - '0');i--;}
        if(j >= 0){sum += (num2[j] - '0');j--;}
        sum += carry; 
        carry = sum / 10;
        sum = sum % 10;
        res =  res + to_string(sum);
    }
    reverse(res.begin(), res.end());
    return res;
}

//大数相乘
 string multiply(string num1, string num2) {
        string rst;
        if(num1.size()==0||num2.size()==0)
            return rst;
        int len1=num1.size();
        int len2=num2.size();
        vector<int> tmp(len1+len2-1,0);
        for(int i=0;i<len1;++i){
            int a=num1[i]-'0';
            for(int j=0;j<len2;++j){
                int b=num2[j]-'0';
                tmp[i+j]+=a*b;
            }
        }
        int carry=0;
        for(int i=tmp.size()-1;i>=0;--i){
            int val=tmp[i]+carry;
            tmp[i]=val%10;
            carry=val/10;
        }
        while(carry){
            int val=carry%10;
            tmp.insert(tmp.begin(),val);
            carry=carry/10;
        }
        for(auto ele:tmp){
            char c='0'+ele;
            rst=rst+c;
        }
        if(rst.size()>0&&rst[0]=='0')
            return string("0");
        return rst;
        
        
    }
