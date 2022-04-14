#include <iostream>
#include <string>

#include "Oferta.h"
#include "wishlist_Repo.h"
#include "UI.h"
#include "Service.h"
#include "Repo.h"
#include "Validators.h"

#include <stdlib.h>
#include <crtdbg.h>

#include <vector>
using namespace std;

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
    wish_list wish;
    Service service(repo, wish, valid);
    test_service(service);
    tests_validators(valid);
}

void start()
{
    vector<Oferta> Lista_oferte;
    Valid valid;
    Repo repo(Lista_oferte);
    wish_list wish;
    Service service(repo, wish, valid);
    console consola(service);
    consola.run();
}