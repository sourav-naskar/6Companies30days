class Solution {
public:
    string getHint(string secret, string guess) {
        vector<int> cowsS(10, 0);
        vector<int> cowsG(10, 0);

        int bulls=0, cows=0;
        for (int i{0}; i<secret.size(); ++i) {
            // if the numbers in the positions match then it's a bull
            if (secret[i]==guess[i]) bulls++;
            else {

                cowsS[secret[i]-'0']++;
                cowsG[guess[i]-'0']++;
            }
        }

        for (int i=0; i<cowsG.size(); ++i) {
            // let's day cowsS[4]=5, it means that '4' is present 5 times in secret
            // same goes for cowsS. The minimum of either gives the number of matches (the extra ones can't match)
            cows+=min(cowsG[i], cowsS[i]);
        }

        // to_string converts ascii to integer. (eg., '5' to 5)
        return to_string(bulls)+'A'+to_string(cows)+'B';

    }
};