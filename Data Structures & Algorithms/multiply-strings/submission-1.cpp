class Solution {
public:
    string add(string num1, string num2){
        int i=num1.size()-1;
        int j=num2.size()-1;
        int carry=0;
        string str_sum;
        while(i>=0 ||j>=0 || carry){
            int a=(i>=0)?num1[i]-'0':0;
            int b=(j>=0)?num2[j]-'0':0;
            int total=a+b+carry;
            int sum=total%10;
            carry=total/10;
            str_sum+=(sum+'0');
            i--;
            j--;
        }
        reverse(str_sum.begin(),str_sum.end());
        return str_sum;
    }
    string mul(string s,char d,int zero_count){
        int i=s.size()-1;
        int digit=d-'0';
        int carry=0;
        string str_mul;
        while(i>=0 || carry){
            int val=(i>=0)?s[i]-'0':0;
            int product=digit*val+carry;
            int curr=product%10;
            carry=product/10;
            str_mul+=(curr+'0');
            i--;
        }
        reverse(str_mul.begin(),str_mul.end());
        for(int i=0;i<zero_count;i++){
            str_mul.push_back('0');
        }
        return str_mul;
    }
    string multiply(string num1, string num2) {
        if(num1=="0"||num2=="0")return "0";
        if(num1.size()<num2.size()){
            string temp;
            temp=num1;
            num1=num2;
            num2=temp;
        }
        int zero_count=0;
        string soln;
        for(int i=num2.size()-1;i>=0;i--){
            string prod=mul(num1,num2[i],zero_count++);
            if(soln=="")soln=prod;
            else soln=add(soln,prod);
        }
        return soln;
    }

};
