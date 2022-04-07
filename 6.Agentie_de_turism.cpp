#include <iostream>
#include <string>

#include "Oferta.h"
#include "UI.h"
#include "Service.h"
#include "Repo.h"
#include "Validators.h"
using namespace std;

void all_tests();

vector<Oferta> Lista_oferte;

int main()
{
    all_tests();
    Valid valid;
    Repo repo(Lista_oferte);
    Service service(repo, valid);
    console consola(service);
    consola.run();
    return 0;
}

void all_tests()
{
    Valid valid;
    Repo repo(Lista_oferte);
    Service service(repo,valid);
    test_service(service);
    tests_validators(valid);
}