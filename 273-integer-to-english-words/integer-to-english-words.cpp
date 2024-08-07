class Solution {
public:
    string numberToWords(int num) {
        if (num == 0)
            return "Zero";

        string big[] = {"Thousand", "Million", "Billion"};
        string result = helper(num % 1000);
        num /= 1000;

        for (int i = 0; i < 3; ++i) {
            if (num % 1000 > 0) {
                result = helper(num % 1000) + big[i] + " " + result;
            }
            num /= 1000;
        }

        while (!result.empty() && result.back() == ' ') {
            result.pop_back();
        }

        return result;
    }

    string helper(int num) {
        string digitString[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
        string teenString[] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        string tenString[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

        string result;
        if (num >= 100) {
            result += digitString[num / 100] + " Hundred ";
            num %= 100;
        }

        if (num >= 20) {
            result += tenString[num / 10] + " ";
            num %= 10;
        } else if (num >= 10) {
            result += teenString[num - 10] + " ";
            num = 0;
        }

        if (num > 0) {
            result += digitString[num] + " ";
        }

        return result;
    }
};