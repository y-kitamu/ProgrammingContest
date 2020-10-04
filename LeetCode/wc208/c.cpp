#include <bits/stdc++.h>

using namespace std;


struct Person {
    Person(std::string name): name(name) {}
    Person() {}
    Person* parent = nullptr;
    std::string name;
    std::vector<Person*> childs;
    bool is_dead = false;
};


class ThroneInheritance {
  public:
    ThroneInheritance(string kingName) {
        king = kingName;
        person_map[kingName] = Person(kingName);
    }

    void birth(string parentName, string childName) {
        person_map[childName] = Person(childName);
        person_map[childName].parent = &person_map[parentName];
        person_map[parentName].childs.emplace_back(&person_map[childName]);
    }

    void death(string name) {
        person_map[name].is_dead = true;
    }

    vector<string> getInheritanceOrder() {
        curOrder = std::vector<std::string>();
        success(king);
        return curOrder;
    }

    void success(std::string name) {
        if (person_map[name].is_dead == false) {
            curOrder.emplace_back(name);
        }
        for (auto person : person_map[name].childs) {
            success(person->name);
        }
    }

  private:
    std::map<std::string, Person> person_map {};
    std::vector<std::string> curOrder;
    std::string king;
    std::vector<Person*> order;
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */


int main() {
    std::vector<std::string> commands {
        "ThroneInheritance", "birth", "birth", "birth", "birth", "birth", "birth",
        "getInheritanceOrder", "death", "getInheritanceOrder"
    };

    std::vector<std::vector<std::string>> args {
        {"king"},
        {"king", "andy"},
        {"king", "bob"},
        {"king", "catherine"},
        {"andy", "matthew"},
        {"bob", "alex"},
        {"bob", "asha"},
        {},
        {"bob"},
        {}
    };


    ThroneInheritance *obj;
    int n_commands = commands.size();
    for (int i = 0; i < n_commands; i++) {
        auto command = commands[i];
        if (command == "ThroneInheritance") {
            obj = new ThroneInheritance(args[i][0]);
        } else if (command == "birth") {
            obj->birth(args[i][0], args[i][1]);
        } else if (command == "death") {
            obj->death(args[i][0]);
        } else {
            for (auto inh : obj->getInheritanceOrder()) {
                std::cout << inh << std::endl;;
            }
            std::cout << std::endl;
        }
    }

    delete obj;
}
