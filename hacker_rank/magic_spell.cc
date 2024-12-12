#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Spell { 
    private:
        string scrollName;
    public:
        Spell(): scrollName("") { }
        Spell(string name): scrollName(name) { }
        virtual ~Spell() { }
        string revealScrollName() {
            return scrollName;
        }
};

class Fireball : public Spell { 
    private: int power;
    public:
        Fireball(int power): power(power) { }
        void revealFirepower(){
            cout << "Fireball: " << power << endl;
        }
};

class Frostbite : public Spell {
    private: int power;
    public:
        Frostbite(int power): power(power) { }
        void revealFrostpower(){
            cout << "Frostbite: " << power << endl;
        }
};

class Thunderstorm : public Spell { 
    private: int power;
    public:
        Thunderstorm(int power): power(power) { }
        void revealThunderpower(){
            cout << "Thunderstorm: " << power << endl;
        }
};

class Waterbolt : public Spell { 
    private: int power;
    public:
        Waterbolt(int power): power(power) { }
        void revealWaterpower(){
            cout << "Waterbolt: " << power << endl;
        }
};

class SpellJournal {
    public:
        static string journal;
        static string read() {
            return journal;
        }
}; 
string SpellJournal::journal = "";

void counterspell(Spell *spell) {
    cout << endl << "==============" << endl;
    if (dynamic_cast<Waterbolt*>(spell))
        dynamic_cast<Waterbolt*>(spell)->revealWaterpower();
    else if (dynamic_cast<Thunderstorm*>(spell))
        dynamic_cast<Thunderstorm*>(spell)->revealThunderpower();
    else if (dynamic_cast<Frostbite*>(spell))
        dynamic_cast<Frostbite*>(spell)->revealFrostpower();
    else if (dynamic_cast<Fireball*>(spell))
        dynamic_cast<Fireball*>(spell)->revealFirepower();
    else {
        // find a subsequence of letters that are contained in *both* the spell name and your spell journal.
        string scrollName = spell->revealScrollName();
        const string& journal = SpellJournal::read();
        //cout << "scroll: " << scrollName << "journal: " << journal << endl;

        // Dynamic programming:
        int n = scrollName.length();
        int m = journal.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                // if the next char of both strings are equal,
                // add 1 to the value of [row-1][col-1].
                if (scrollName[i - 1] == journal[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else {
                    // if the next char is not in both strings,
                    //  carry the max value of the previous row & col
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
                //printf("dp[%d][%d] = %d\n", i, j, dp[i][j]);
            }
        }
        cout << dp[n][m] << endl;
    }
}
#if 0
1
ABCD 12 BACDBDCD
#endif
class Wizard {
    public:
        Spell *cast() {
            Spell *spell;
            string s; cin >> s;
            int power; cin >> power;
            if(s == "fire") {
                spell = new Fireball(power);
            }
            else if(s == "frost") {
                spell = new Frostbite(power);
            }
            else if(s == "water") {
                spell = new Waterbolt(power);
            }
            else if(s == "thunder") {
                spell = new Thunderstorm(power);
            } 
            else {
                spell = new Spell(s);
                cin >> SpellJournal::journal;
            }
            return spell;
        }
};

int main() {
    int T;
    cin >> T;
    Wizard Arawn;
    while(T--) {
        Spell *spell = Arawn.cast();
        counterspell(spell);
    }
    return 0;
}
