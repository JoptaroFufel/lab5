#include <iostream>
#include <string>
using namespace std;


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