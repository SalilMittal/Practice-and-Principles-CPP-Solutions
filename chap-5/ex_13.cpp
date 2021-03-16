/* The program is a bit tedious because the answer is hard-coded into
the program. Make a version where the user can play repeatedly
(without stopping and restarting the program) and each game has a
new set of four digits. You can get four random digits by calling the
random number generator randint(10) from std_lib_facilities.h
four times. You will note that if you run that program repeatedly, it
will pick the same sequence of four digits each time you start the
program. To avoid that, ask the user to enter a number (any number)
and call srand(n) where n is the number the user entered before
calling randint(10). Such an n is called a seed, and different seeds
give different sequences of random numbers. */


#include "../std_lib_facilities.h"

vector<char> gen_vector() {
    std::cout << "Enter Seed: ";
    int n;
    std::cin >> n;
    srand(n);
    vector<int> v = {randint(10), randint(10), randint(10), randint(10)};
    
    vector<char> vs;
    for(int x : v) vs.push_back(char('0'+ x));
    for(char x : vs) cout << x << " "; 
    return vs;
}

int main() {
    vector<char> vs = gen_vector();

    std::cout << "Enter your number: ";
    for(std::string x; std::cin >> x;) {
        int bull_count = 0;
        if(x.size() == 4) {
            vector<char> unique;
            for(int i = 0; i < x.size(); i++) {
                if(std::find(vs.begin(), vs.end(), x[i]) != vs.end()) {
                    if(x[i] == vs[i]) {
                        std::cout << "Bull(" << x[i] << ")\n";
                        unique.push_back(x[i]);
                        bull_count++;
                    } else {
                        if(std::find(unique.begin(), unique.end(), x[i]) == unique.end()) { 
                            std::cout << "Cow(" << x[i] << ")\n";
                            unique.push_back(x[i]);
                        }
                    }
                }
            }

            if(bull_count == 4) {
                std::cout << "You won! New Game: \n";
                vs = gen_vector();
            }
        } else {
            std::cout << "Enter 4 digit number\n";
        }
        std::cout << "Enter your number: ";
    }
}