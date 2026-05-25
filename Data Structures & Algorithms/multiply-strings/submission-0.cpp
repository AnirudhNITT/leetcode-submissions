class Solution {
public:
    string trim(string s){
        int i=0;
        while(i<s.size()-1 && s[i]=='0')i++;
        return s.substr(i);
    }

    string addStrings(string a,string b){
        string ans="";
        int i=a.size()-1,j=b.size()-1,carry=0;

        while(i>=0 || j>=0 || carry){
            int sum=carry;
            if(i>=0)sum+=a[i--]-'0';
            if(j>=0)sum+=b[j--]-'0';
            ans.push_back((sum%10)+'0');
            carry=sum/10;
        }

        reverse(ans.begin(),ans.end());
        return trim(ans);
    }

    string subStrings(string a,string b){ // assume a>=b
        string ans="";
        int i=a.size()-1,j=b.size()-1,borrow=0;

        while(i>=0){
            int x=(a[i]-'0')-borrow;
            int y=(j>=0?b[j]-'0':0);

            if(x<y){
                x+=10;
                borrow=1;
            }else borrow=0;

            ans.push_back((x-y)+'0');
            i--;j--;
        }

        while(ans.size()>1 && ans.back()=='0')ans.pop_back();
        reverse(ans.begin(),ans.end());
        return ans;
    }

    string shiftLeft(string s,int k){
        if(s=="0")return "0";
        return s+string(k,'0');
    }

    string multiply(string x,string y){
        x=trim(x);
        y=trim(y);

        if(x=="0" || y=="0")return "0";

        if(x.size()==1 && y.size()==1){
            int val=(x[0]-'0')*(y[0]-'0');
            return to_string(val);
        }

        int n=max(x.size(),y.size());
        if(n&1)n++;

        while(x.size()<n)x='0'+x;
        while(y.size()<n)y='0'+y;

        int m=n/2;

        string a=x.substr(0,m);
        string b=x.substr(m);
        string c=y.substr(0,m);
        string d=y.substr(m);

        string ac=multiply(a,c);
        string bd=multiply(b,d);

        string ab=addStrings(a,b);
        string cd=addStrings(c,d);

        string mid=multiply(ab,cd);
        mid=subStrings(mid,ac);
        mid=subStrings(mid,bd);

        string part1=shiftLeft(ac,2*m);
        string part2=shiftLeft(mid,m);

        return trim(addStrings(addStrings(part1,part2),bd));
    }
};