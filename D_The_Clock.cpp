#include <bits/stdc++.h>
using namespace std;
bool isPalindrom(string s1, string s2)
{
    // cout << s1 << " " << s2 << endl;
    if (s1.size() < 2)
        s1 = "0" + s1;
    if (s2.size() < 2)
        s2 = "0" + s2;
    if (s1[0] == s2[1] && s1[1] == s2[0])
        return true;
    return false;
}
void solve(int cases = 1)
{
    // solve the problem here
    const int oneDay = 24 * 60;
    string time;
    string minutesCheck;
    cin >> time >> minutesCheck;
    int hour = stoi(time.substr(0, 2));
    int minute = stoi(time.substr(3, 2));
    int minutesCheckInt = stoi(minutesCheck);
    int palindrom = 0;
    int i = 0;
    while (true)
    {
        int newMinute = (minute + i) % 60;
        int newHour = (hour + (minute + i) / 60) % 24;
        if (i != 0 && minute == newMinute && hour == newHour)
            break;
        if (isPalindrom(to_string(newHour), to_string(newMinute)))
        {
            // cout << newHour << " " << newMinute << endl;
            palindrom++;
        }
        i += minutesCheckInt;
    }
    // cout << hour << " " << minute << " " << minutesCheckInt << endl;
    // cout << time << " " << minutes << endl;
    cout << palindrom << endl;
}

int main()
{
    int cases = 1; // 1 or more cases
    cin >> cases;
    while (cases--)
    {
        solve();
    }
    return 0;
}