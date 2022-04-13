#include <iostream>
#include <string>

#include "Oferta.h"
#include "UI.h"
#include "Service.h"
#include "Repo.h"
#include "Validators.h"

#include <stdlib.h>
#include <crtdbg.h>

#include <vector>
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
    vector<Oferta> Lista_oferte;
    Valid valid;
    Repo repo(Lista_oferte);
    Service service(repo, valid);
    test_service(service);
    tests_validators(valid);
    test_iterator();
}

void start()
{
    vector<Oferta> Lista_oferte;
    Valid valid;
    Repo repo(Lista_oferte);
    Service service(repo, valid);
    console consola(service);
    consola.run();
}