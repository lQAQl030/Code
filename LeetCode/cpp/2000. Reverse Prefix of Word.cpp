class Solution {
public:
    string reversePrefix(string word, char ch) {
        string head,tail;
        for(int i = 0 ; i < word.size() ; i++){
            if(word[i] == ch){
                head = word.substr(0,i+1);
                tail = word.substr(i+1);
                cout << head << endl << tail;
                break;
            }
        }
        reverse(head.begin(), head.end());

        if(head.empty()) return word;
        else return head + tail;
    }
};