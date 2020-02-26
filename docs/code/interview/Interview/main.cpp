#include <iostream>
#include <sstream>
#include<bits/stdc++.h>

/*
 *
 *  Given a 32-bit signed integer, reverse digits of an integer.
 *
 * Example 1:
 *
 * Input: 123
 * Output: 321
 * Example 2:
 *
 * Input: -123
 * Output: -321
 * Example 3:
 *
 * Input: 120
 * Output: 21
 * Note:
 * Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−2^31,  2^31 − 1].
 * For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
 *
 */
std::string timeConversion(std::string s) {
    size_t length = s.size();

    std::string am = s.substr(length - 2, 2);
    bool is_AM = (am.compare("AM") == 0);
    //"07:34:23AM"
    std::string hours = s.substr(0, 2);
    std::string minutes = s.substr(3, 2);
    std::string seconds = s.substr(6, 2);

    int converted_hours;
    std::istringstream input(hours);
    input >> converted_hours;

    bool need_attention = (converted_hours == 0 || converted_hours == 12);

    if ((!is_AM && !need_attention) || (is_AM && need_attention)) {
        converted_hours += 12;
    }

    converted_hours %= 24;

    char final_hours[] = "XX";
    sprintf(final_hours, "%02d", converted_hours);

    std::ostringstream output;
    output << final_hours << ":" << minutes << ":" << seconds;

    return output.str();
}

class Solution {
public:
    int reverse(int x) {
        /* first we get the string representation */
        std::ostringstream os;
        os << x;
        std::string repr = os.str();

        /* then we calculate the edge of the string where the digits are */
        size_t start = (repr[0] == '-') ? 1 : 0; /* take into account the sign */
        size_t end = repr.size() - 1;

        /* here we swap the char at the edge moving to the center */
        size_t left, right;
        for (left = start, right = end ; left < right ; left++, right--) {
            auto tmp = repr[left];
            repr[left] = repr[right];
            repr[right] = tmp;
        }

        /* now we can reconvert the string to a number */
        long result;
        std::stringstream(repr) >> result;

        return ((result < INT_MAX) && (result > INT_MIN)) ? result : 0;
    }
};

void test_reverse() {
    Solution s;

    int a[] = {
        123,
        -123,
        1234567890,
        -2147483647,
        10,
    };

    for (size_t idx = 0 ; idx < sizeof(a)/sizeof (int) ; idx++) {
        std::cout << a[idx] << ": " << s.reverse(a[idx]) << std::endl;
    }
}

void test_convert_time() {
    /*
     * Note:
     *  - Midnight is 12:00:00AM on a 12-hour clock, and 00:00:00 on a 24-hour clock.
     *  - Noon is 12:00:00PM on a 12-hour clock, and 12:00:00 on a 24-hour clock.
     */
    std::cout << timeConversion("12:00:00AM") << std::endl; /* 00:00:00 */
    std::cout << timeConversion("12:00:00PM") << std::endl; /* 12:00:00 */
    std::cout << timeConversion("00:00:00AM") << std::endl; /* 12:00:00 */
    std::cout << timeConversion("00:00:00PM") << std::endl; /* 00:00:00 */
    std::cout << timeConversion("07:05:45PM") << std::endl;
    std::cout << timeConversion("06:05:45AM") << std::endl;
}

int main()
{
    test_convert_time();
}
