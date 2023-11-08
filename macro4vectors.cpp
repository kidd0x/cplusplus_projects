#include <iostream>
#include <vector>

using namespace std;

#define ADD_VECTORS(c, a, b) \
    do { \
        if ((a).size() != (b).size()) { \
            cerr << "Eroare: Vectorii nu au aceeasi marime !" << endl; \
        } else { \
            (c).resize((a).size()); \
            for (size_t i = 0; i < (a).size(); ++i) { \
                (c)[i] = (a)[i] + (b)[i]; \
            } \
        } \
    } while(0)

int main()
{
    vector<int> a {1, 2, 3};
    vector<int> b {1, 2, 3};
    vector<int> c;

    ADD_VECTORS(c, a, b);

    for(int value : c)
        cout << value << " ";

    return 0;
}
