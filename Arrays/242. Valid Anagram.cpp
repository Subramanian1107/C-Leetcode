class SolutionSort {
public:
    bool isAnagram(string s, string t) {
        int n = s.length();
        if(s.length()!=t.length())
            return false;
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        if(s == t)
            return true;
        return false;
    }
};

class SolutionMap {
public:
    bool isAnagram(string s, string t) {
        int n = s.size();
        int m = t.size();
        if(n!=m)
            return false;
        map<char,int>mpS;
        map<char,int>mpT;
        for(char c:s){
            mpS[c]++;
        }
        for(char c:t){
            mpT[c]++;
        }
        for(char c:t){
            if(mpT[c] != mpS[c])
                return false;
        }
        return true;
    }
};