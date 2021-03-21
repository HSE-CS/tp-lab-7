#include "common.h"

class QWE {
public:
    int v;
    std::string s;
    QWE(int vv, std::string ss) : v(vv), s(ss) {};
    QWE() : v(0), s("") {};
};

int main() {
    srand(time(nullptr));
    std::list<QWE *> lst;
    QWE *h = nullptr;
    for (int i = 0; i < 10; ++i) {
        QWE *tmp = new QWE(i, "qwe");
        if (i == 5)
            h = tmp;
        lst.push_back(tmp);
    }
    lst.remove(h);
    for (auto &x : lst) {
        std::cout << x->v << " " << x->s << "\n";
    }
}
