#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Name_Pairs {
    public:
        std::vector<std::string> names;
        std::vector<double> ages;
        void read_names();
        void read_ages();
        void print();
        void sort();
};

void Name_Pairs::read_names() {
    std::cout << "Enter names: \n";
    for(std::string s; std::cin >> s;) names.push_back(s);
    std::cout << "\n";
}

void Name_Pairs::read_ages() {
    for (double i = 0, d; i < names.size(); i++)
    {
        std::cout << "Enter " << names[i] << "'s age: ";
        std::cin >> d;
        ages.push_back(d);
    }    
    std::cout << "\n";
}

void Name_Pairs::sort() {
    std::vector<std::string> names2 = names;
    std::vector<double> ages2;

    std::sort(names.begin(), names.end());
    for(int i = 0; i < names.size(); i++) {
        std::string name_tmp = names[i];
        for(int j = 0; j < names2.size(); j++) {
            if(name_tmp == names2[j]) {
                ages2[i] = ages[j];
                break;
            }
        }
    }
    ages = ages2;
}

std::ostream& operator<<(std::ostream& os, const Name_Pairs& obj) {
    for(int i = 0; i < obj.names.size(); i++) std::cout << obj.names[i] << ": " << obj.ages[i] << "\n";
}

bool operator==(const Name_Pairs& a, const Name_Pairs& b) {
    if(a.names.size() != b.names.size() || a.ages.size() != b.ages.size()) return false;

    for(int i = 0; i < a.names.size(); i++) if(a.names[i] != b.names[i]) return false;
    for(int i = 0; i < a.ages.size(); i++) if(a.ages[i] != b.ages[i]) return false;

    return true;
}

bool operator!=(const Name_Pairs& a, const Name_Pairs& b) {
    return !(a==b);
}

int main() {
    Name_Pairs pairs;
    pairs.read_names();
    pairs.read_ages();
    pairs.sort();
    pairs.print();
}