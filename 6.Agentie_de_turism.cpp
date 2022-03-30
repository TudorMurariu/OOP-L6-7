#include <iostream>
#include <string>
#include <vector>

#include "Oferta.h"
#include "UI.h"
#include "Service.h"
#include "Repo.h"
using namespace std;

void all_tests();

vector<Oferta> Lista_oferte;

int main()
{
    all_tests();
    Repo repo(Lista_oferte);
    Service service(repo);
    console consola(service);
    consola.run();
    return 0;
}

void all_tests()
{
    Repo repo(Lista_oferte);
    Service service(repo);
    test_service(service);
}