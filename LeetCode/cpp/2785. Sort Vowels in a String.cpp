class Solution {
public:
    string sortVowels(string s) {
        map<int,int> m;
        for(int i = 0 ; i < s.length() ; i++){
            switch(s[i]){
                case 'a': case 'A':
                case 'e': case 'E':
                case 'i': case 'I':
                case 'o': case 'O':
                case 'u': case 'U':
                    m[s[i]-'a']++;
                    s[i] = '-';
                    break;
                default:
                    break;
            }
        }
        for(int i = 0 ; i < s.length() ; i++){
            if(s[i] == '-'){
                s[i] = m.begin()->first + 'a';
                if(--m.begin()->second == 0) m.erase(m.begin());
            }
        }
        return s;
    }
};