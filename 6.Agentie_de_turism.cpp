#include <iostream>
#include <string>

#include "Oferta.h"
#include "UI.h"
#include "Service.h"
#include "Repo.h"
#include "Validators.h"
#include "Vector.h"

#include <stdlib.h>
#include <crtdbg.h>

using namespace std;

void test_iterator();
void all_tests();
void start();

int main()
{
    all_tests();

    start();

    _CrtDumpMemoryLeaks();

    return 0;
}

void all_tests()
{
    my_vector<Oferta> Lista_oferte;
    Valid valid;
    Repo repo(Lista_oferte);
    Service service(repo, valid);
    test_service(service);
    tests_validators(valid);
    test_iterator();
}


void test_iterator()
{
    my_vector<int> my_vect;
    for (int i = 0; i < 10; i++)
        my_vect.push_back(1);

    Iterator<int> itr(my_vect);
    int i;
    for (itr.prim(), i = 0; itr.valid(), i < 10; itr.urmator(), i++)
        assert(itr.element() == my_vect.at(i));
}

void start()
{
    my_vector<Oferta> Lista_oferte;
    Valid valid;
    Repo repo(Lista_oferte);
    Service service(repo, valid);
    console consola(service);
    consola.run();
}