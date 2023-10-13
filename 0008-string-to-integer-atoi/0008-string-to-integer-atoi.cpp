class Solution {
public:
    int myAtoi(string str) {
        if(str.empty())
            return 0;
        int len = str.length(),i=0,sign = 1;

        //Check for white spaces and remove
        while(i<len && str[i] == ' '){
            i++;
        }
        //Only whitespace characters
        if(i==len)  return 0;

        //Any signed character
        if(str[i] == '-'){
            sign = 0;
            i++;
        }

        //if no sign character
        else if(str[i] == '+')
            i++;

        long int out = 0;

        while(str[i] >= '0' && str[i] <='9'){
            out = out * 10;
            if(out<INT_MIN || out>INT_MAX)
                break;
            out = out + (str[i]-'0');
            i++;
        }
        if(sign == 0)
            out = -1 * out;
        if(out<INT_MIN) return INT_MIN;
        if(out>INT_MAX) return INT_MAX;
        return (int)out;
    }
};