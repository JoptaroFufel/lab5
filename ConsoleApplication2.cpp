#include <iostream>
#include <string>
using namespace std;

//class cooking {
//protected:
//    string name;
//public:
//    cooking() {};
//
//    cooking(string meal) {
//        name = meal;
//    }
//    virtual ~cooking() {};
//    void virtual output() = 0;
//    void virtual count() = 0;
//};
//
//class dish_meat :public cooking {
//protected:
//    int spices;
//    int grams;
//    int choice;
//public:
//    dish_meat() {
//        grams = 200;
//        spices = 1;
//        choice = 1;
//    };
//    dish_meat(string meal, int number) :cooking(meal) {
//        choice = number;
//        grams = 200;
//        spices = 1;
//    }
//    void virtual count() {
//        cout << "You need " << choice * spices << " spoon of spices and " << choice * grams << "g of meat to make " << choice << " portions of steak\n\n\n";
//    }
//    void virtual output() {
//        cout << "Ingridients of " << name << ": " << spices << " spoons of spices and " << grams << "g of meat for one portion\n";
//    }
//    virtual ~dish_meat() {};
//};
//
//class desert :public cooking {
//protected:
//    int cream;
//    int cookies;
//    int num;
//public:
//    desert() {
//        cream = 250;
//        cookies = 15;
//        num = 1;
//    };
//    desert(string meal, int quantity) : cooking(meal) {
//        num = quantity;
//        cream = 250;
//        cookies = 15;
//    };
//    void virtual count() {
//        cout << "You need " << num * cream << "g of cream and " << num * cookies << " cookies to make " << num << " portions of " << name << "\n\n\n";
//    }
//    void virtual output() {
//        cout << "Ingridients of " << name << ": " << cream << "g of cream and " << cookies << " cookies for one portion\n";
//    }
//    virtual ~desert() {};
//};
//
//class dish_garnish :public dish_meat {
//protected:
//    int water;
//    int salt;
//public:
//    dish_garnish() {
//        water = 1;
//        salt = 10;
//    }
//    dish_garnish(string meal, int number) :dish_meat(meal, number) {
//        water = 1;
//        salt = 10;
//    }
//    void virtual count() {
//        cout << "You need " << choice * water << "L of water and " << choice * salt << "g of salt for " << choice << " portions\n\n\n";
//    }
//    void virtual output() {
//        cout << "Ingridients of " << name << ": " << water << "L of water and " << salt << "g of salt for one portion\n";
//    }
//    virtual ~dish_garnish() {};
//};

void Input(string& str) {
    while (true) {
        rewind(stdin);
        cout << "Input string" << endl;
        getline(cin, str);
        if (str.length() < 2) {
            cout << "\nPlease, describe this topic in more details" << endl;
            continue;
        }
        else break;
    }
}

int Input() {
    int i;
    bool fail = true;
    cout << "\nInput:";
    do
    {
        cin >> i;
        if (cin.fail() || cin.rdbuf()->in_avail() > 1)
            cout << "\nError" << endl;
        else
            if (i > 0)
                fail = false;
        cin.clear();
        cin.ignore(cin.rdbuf()->in_avail());
    } while (fail);
    return i;
}

float Input(int q) {
    float i;
    bool fail = true;
    cout << "\nInput:";
    do
    {
        cin >> i;
        if (cin.fail() || cin.rdbuf()->in_avail() > 1)
            cout << "\nError" << endl;
        else
            if (i > 0)
                fail = false;
        cin.clear();
        cin.ignore(cin.rdbuf()->in_avail());
    } while (fail);
    return i;
}

class prods {
protected:
    string name;
public:
    prods() :name(">_empty") { cout << ">_construct000;\n"; }
    prods(string _name) :name(_name) { cout << ">_construct001;\n"; }
    virtual ~prods() {};

    virtual void input() = 0;
    virtual void out() = 0;
};

class meat :virtual public prods {
protected:
    float prc;
    float weight;
public:
    meat() :prc(0), weight(0) { cout << ">_construct010;\n"; };
    meat(string _name, float _prc, float _weight) :prc(_prc), weight(_weight), prods(_name) { cout << ">_construct011;\n"; }
    ~meat() {};

    void input() {
        cout << "Input name:"<<endl;
        Input(name);
        cout << "Input price:"<<endl;
        prc = Input(0);
        cout << "Input weight:" << endl;
        weight = Input(0);
    }
    void out() {
        cout << "\nName: " << name << endl;
        cout << "Price: " << prc << endl;
        cout << "Weight: " << weight << endl;
        cout << "Summary cost: " << prc * weight << endl;
    }
};

class fastfood :virtual public prods {
protected:
    int portions;
    float price;
public:
    fastfood() :portions(0), price(0) { cout << ">_construct020;\n"; };
    fastfood(string _name, float _prc, float _portions) : price(_prc), portions(_portions), prods(_name) { cout << ">_construct021;\n"; }
    ~fastfood() {};

    void input() {
        cout << "Input name:" << endl;
        Input(name);
        cout << "Input price:" << endl;
        price = Input(0);
        cout << "Input portions:" << endl;
        portions= Input();
    }
    void out() {
        cout << "\nName: " << name << endl;
        cout << "Price: " << price << endl;
        cout << "Amount of portions: " << portions << endl;
        cout << "Summary cost: " << price * portions << endl;
    }
};

class veget :public meat {
protected:
    int num;
public:
    veget() :num(0) { cout << ">_construct110;\n"; };
    veget(string _name, float _prc,float _weight, int _num) : num(_num), meat(_name, _prc, _weight), prods(_name) { cout << ">_construct111;\n"; }
    ~veget() {};

    void input() {
        cout << "Input name:" << endl;
        Input(name);
        cout << "Input price:" << endl;
        prc = Input(0);
        cout << "Input weight:" << endl;
        weight = Input(0);
        cout << "Input amount:" << endl;
        num = Input();
    }
    void out() {
        cout << "\nName: " << name << endl;
        cout << "Price: " << prc << endl;
        cout << "Weight: " << weight << endl;
        cout << "Amount of pieces:" << num << endl;
        cout << "Summary cost: " << prc * weight << endl;
    }
};

int main()
{
    prods* mas[3];
    mas[0] = new fastfood();
    mas[1] = new meat();
    mas[2] = new veget();

    for (int i = 0; i < 3; i++) {
        mas[i]->input();
        mas[i]->out();
        cout << endl;
    }
    for (int i = 0; i < 3; i++) {
        delete mas[i];
    }

    return 0;
}