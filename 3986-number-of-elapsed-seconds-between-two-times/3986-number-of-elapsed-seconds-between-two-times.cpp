class Solution {
public:
    int secondsBetweenTimes(string startTime, string endTime) {
        int hr=0,min=0,sec=0;
        int a=stoi(startTime.substr(0,2));
        int b=stoi(endTime.substr(0,2));
        hr=b-a;

        a=stoi(startTime.substr(3,2));
        b=stoi(endTime.substr(3,2));
        min=b-a;

        a=stoi(startTime.substr(6,2));
        b=stoi(endTime.substr(6,2));
        sec=b-a;

        return hr*60*60 + min*60 + sec;

    }
};