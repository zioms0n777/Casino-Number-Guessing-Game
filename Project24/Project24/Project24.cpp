#include <cstdlib>
#include <iostream>
#include <ctime>
#include <fstream>
int player_money = 0;

void bank_status()
{
    int bank_money = player_money;
    std::cout << "You have " << bank_money << "$ in your bank account" << std::endl;

    std::ofstream plik("stan_konta1.txt");
    if (plik.is_open())
    {
        plik << bank_money << std::endl;
        plik.close();
    }
    else
        std::cerr << "Nie udalo sie otworzyc pliku do zapisu" << std::endl;
}

void wygrana(int x, int y)
{
  int kwota_wygrana  = x*y;
  player_money = player_money + kwota_wygrana;
  std::cout << "Wygrales " << kwota_wygrana << std::endl;
}

void przegrana(int x)
{
    int kwota_przegrana = x;
    player_money -= kwota_przegrana;
}

void wplacenie()
{
    std::cout << "Podaj kwote wplaty (max 100$): ";
    int z;
    std::cin >> z;
    if (z== 0)
    {
        std::cout << "W sumie to nic nie wplaciles idioto h3h3" << std::endl;
    }
    if (z <= 100)
    {
        player_money += z;
        std::cout << "Prawidlowo wplaciles " << z << " $" << std::endl;
    }
    if (z > 100)
    {
        std::cout << "Za duzo chcialbys wplacic na raz spokojnie mordini" << std::endl;
    }


}


void wyplacenie()
{
    int x;
    std::cout << "1. Wyplac calosc" << std::endl;
    std::cout << "2. Wyplac konkretna liczbe pieniedzy" << std::endl;
    std::cin >> x;
    switch (x) {
    case 1:
    {
        player_money = player_money - player_money;
        std::cout << "Wyplaciles calosc. Bravo!" << std::endl;
        break;
    }
    case 2:
    {
        std::cout << "Podaj ilosc: ";
        int z;
        std::cin >> z;
        if (z > player_money)
        {
            std::cout << "Nie mozesz tego zrobic chyba ze chcesz byc zadluzony cymbale" << std::endl;
        }
        else
        {
            player_money -= z;
            std::cout << "Pomyslnie wyplacono " << z << "$" << std::endl;

        }
        break;
    }
    default:
    {
        std::cout << "Wybierz 1 lub 2 co tu takiego trudnego? " << std::endl;
        break;
    }

    }
}

int level_easy()
{
    int losowa_liczba = std::rand() % 10 + 1;
    return losowa_liczba;
}

int level_medium()
{
    int losowa_liczba = std::rand() % 50 + 1;
    return losowa_liczba;
}

int level_hard()
{
    int losowa_liczba = std::rand() % 100 + 1;
    return losowa_liczba;
}





void Menu()
{
    std::cout << "Welcome to the Casino Number Guessing Game." << std::endl;
    std::cout << "Difficulty" << std::endl;
    std::cout << "1. Easy (1-10) 3 chances (x3)" << std::endl;
    std::cout << "2. Medium (1-50) 5 chances (x7)" << std::endl;
    std::cout << "3. Hard (1-100) 7 chances (x11)" << std::endl;
    std::cout << "4. Check your bank status" << std::endl;
    std::cout << "5. Add balance to your bank account" << std::endl;
    std::cout << "6. Withdraw money from your bank account" << std::endl;
    std::cout << "Game by ziomson777" << std::endl;
}

int main()
{

    std::ifstream plik("stan_konta1.txt");
        if (plik.is_open())
        {
            plik >> player_money;
            plik.close();
        }
    Menu();
    while (true)
    {
        std::srand(static_cast<unsigned int>(std::time(nullptr)));
        int x;
        std::cin >> x;

        {

            switch (x)
            {
            case 1:
            {
                std::cout << "Za ile chcesz zagrac" << std::endl;
                int piniondz;
                std::cin >> piniondz;
                if (piniondz == 0)
                {
                    std::cout << "Nie mozesz grac za 0, kekw" << std::endl;
                    break;
                }
                if (piniondz > player_money)
                {
                    std::cout << "Nie masz tyle na koncie pecik" << std::endl;
                    break;
                }
                if (piniondz <= player_money)
                {
                    player_money -= piniondz;
                    std::cout << "Grasz za " << piniondz << "$" << std::endl;
                }
                int computer_easy = level_easy();
                int y;
                for (int i = 0; i < 3; i++)
                {
                    std::cin >> y;
                    if (y == computer_easy)
                    {
                        
                        std::cout << "Gratulacje wygrales" << std::endl;
                        wygrana(piniondz, 3);
                        break;
                        
                    }
                    if (y > computer_easy)
                    {
                        std::cout << "Za duzo, Sprobuj mniej." << std::endl;
                    }
                    if (y < computer_easy)
                    {
                        std::cout << "Za malo, Sprobuj wiecej." << std::endl;
                    }


                }
                if (y != computer_easy)
                {
                    std::cout << "Przegrales pecikson h3h3" << std::endl;
                }
                break;
            }


            case 2:
            {
                std::cout << "Za ile chcesz zagrac" << std::endl;
                int piniondz;
                std::cin >> piniondz;
                if (piniondz == 0)
                {
                    std::cout << "Nie mozesz grac za 0, kekw" << std::endl;
                    break;
                }
                if (piniondz > player_money)
                {
                    std::cout << "Nie masz tyle na koncie pecik" << std::endl;
                    break;
                }
                if (piniondz <= player_money)
                {
                    player_money -= piniondz;
                    std::cout << "Grasz za " << piniondz << "$" << std::endl;
                }
                int computer_medium = level_medium();
                int y;
                for (int i = 0; i <5 ; i++)
                {
                    std::cin >> y;
                    if (y == computer_medium)
                    {
                        std::cout << "Gratulacje wygrales" << std::endl;
                        wygrana(piniondz, 7);
                        break;

                    }
                    if (y > computer_medium)
                    {
                        std::cout << "Za duzo, Sprobuj mniej." << std::endl;
                    }
                    if (y < computer_medium)
                    {
                        std::cout << "Za malo, Sprobuj wiecej." << std::endl;
                    }

                }

                if (y != computer_medium)
                {
                    std::cout << "Przegrales pecikson h3h3" << std::endl;
                }


                break;
            }


            case 3:
            {

                std::cout << "Za ile chcesz zagrac" << std::endl;
                int piniondz;
                std::cin >> piniondz;
                if (piniondz == 0)
                {
                    std::cout << "Nie mozesz grac za 0, kekw" << std::endl;
                    break;
                }
                if (piniondz > player_money)
                {
                    std::cout << "Nie masz tyle na koncie pecik" << std::endl;
                    break;
                }
                if (piniondz <= player_money)
                {
                    player_money -= piniondz;
                    std::cout << "Grasz za " << piniondz << "$" << std::endl;
                }
                int computer_hard = level_hard();
                int y;
                for (int i = 0; i < 7; i++)
                {

                    std::cin >> y;
                    if (y == computer_hard)
                    {
                        std::cout << "Gratulacje wygrales" << std::endl;
                        wygrana(piniondz, 11);
                        break;
                    }
                    if (y > computer_hard)
                    {
                        std::cout << "Za duzo, Sprobuj mniej." << std::endl;
                    }
                    if (y < computer_hard)
                    {
                        std::cout << "Za malo, Sprobuj wiecej." << std::endl;
                    }
                }
                if (y != computer_hard)
                {
                    std::cout << "Przegrales pecikson h3h3" << std::endl;
                }


                break;
            }

            case 4:
            {
                bank_status();
                break;
            }
            case 5:
            {
                wplacenie();
                break;
            }
            case 6:

            {
                wyplacenie();
                break;
            }
            default:
            {
                std::cout << "Podaj numer z listy" << std::endl;
            }
            }
        }
    }
}