//Critter
#include <iostream>
#include <vector>
#include <locale.h>

using namespace std;

void Pointers();
void Calculate(vector<int>* listNumbers);
void CritterGame();

class Critter
{
public:
    Critter(int hunger = 0, int boredom = 0, int thirst = 0);
    void Talk();
    void Eat(int food = 4);
    void Play(int fun = 4);
    void Drink(int drink = 4);

private:
    int m_Hunger;
    int m_Boredom;
    int m_Thirst;
    void PassTime(int time = 1);
};

Critter::Critter(int hunger, int boredom, int thirst) :
    m_Hunger(hunger),
    m_Boredom(boredom),
    m_Thirst(thirst)
{}


void Critter::PassTime(int time)
{
    m_Hunger += time;
    m_Boredom += time;
    m_Thirst += time;
}

void Critter::Talk()
{
    cout << "\nNecesidades\n";
    cout << "Hambre - " << m_Hunger << endl;
    cout << "Aburrimiento - " << m_Boredom << endl;
    cout << "Sed - " << m_Thirst << endl;

    if (m_Hunger >= 0 && m_Hunger < 3 || m_Boredom >= 0 && m_Boredom < 3 || m_Thirst >= 0 && m_Thirst < 3)
    {
        cout << "Estoy feliz!!\n";
    }

    if (m_Hunger >= 3 && m_Hunger < 5)
    {
        cout << "Tengo hambre!   Nivel de hambre - " << m_Hunger << endl;
    }
    if (m_Boredom >= 3 && m_Boredom < 5)
    {
        cout << "Estoy aburrido!   Nivel de aburrimiento - " << m_Boredom << endl;
    }
    if (m_Thirst >= 3 && m_Thirst < 5)
    {
        cout << "Tengo sed!   Nivel de sed - " << m_Thirst << endl;
    }

    if (m_Hunger >= 5 && m_Hunger < 8)
    {
        cout << "Tengo mucha hambre! Alimentame!!   Nivel de hambre - " << m_Hunger << endl;
    }
    if (m_Boredom >= 5 && m_Boredom < 8)
    {
        cout << "Estoy muy aburrido... Juega conmigo!!   Nivel de aburrimiento - " << m_Boredom << endl;
    }
    if (m_Thirst >= 5 && m_Thirst < 8)
    {
        cout << "Tengo mucha sed! Tienes alguna bebida?   Nivel de sed - " << m_Thirst << endl;
    }

    if (m_Hunger >= 8 && m_Hunger < 10)
    {
        cout << "ME MUERO DE HAMBRE!!! ALIMENTAME   Nivel de hambre - " << m_Hunger << endl;
    }
    if (m_Boredom >= 8 && m_Boredom < 10)
    {
        cout << "QUIERO JUGAR!!!   Nivel de aburrimiento - " << m_Boredom << endl;
    }
    if (m_Thirst >= 8 && m_Thirst < 10)
    {
        cout << "DAME AGUA!!!   Nivel de sed - " << m_Thirst << endl;
    }

    if (m_Hunger >= 10 || m_Boredom >= 10 || m_Thirst >= 10)
    {
        cout << "me mori";
        exit(0);
    }

    PassTime();
}

void Critter::Eat(int food)
{
    cout << "\nBrrupp. \n";
    m_Hunger -= food;
    if (m_Hunger < 0)
    {
        m_Hunger = 0;
    }
    PassTime();
}

void Critter::Play(int fun)
{
    cout << "\nWheee!\n";
    m_Boredom -= fun;
    if (m_Boredom < 0)
    {
        m_Boredom = 0;
    }
    PassTime();
}

void Critter::Drink(int drink)
{
    cout << "\nGulp!\n";
    m_Thirst -= drink;
    if (m_Thirst < 0)
    {
        m_Thirst = 0;
    }
    PassTime();
}

int main()
{
    int choice;
    cout << "Cual opcion desea checar?\n1 - Punteros          2 - Objetos\n";
    cin >> choice;
    switch (choice)
    {
    case 1:
        Pointers();
        break;
    case 2:
        CritterGame();
    default:
        break;
    }
}

void Pointers()
{
    vector<int> listNumbers{ 111, 223412, 5423, 775684, 234 };
    vector<int>* pListNumbers = &listNumbers;
    //Calculate(pListNumbers);
    cout << pListNumbers->at(1);
}

//int Calculate(vector<int>* listNumbers)
//{
//    int x = 0;
//    int counter = 0;
//    do
//    {
//        do
//        {
//            counter++;
//        } while (listNumbers->size() % 2 == 0);
//        x++;
//    } while (x < listNumbers->size());
//
//    return counter;
//}

void CritterGame()
{
    Critter crit;
    crit.Talk();
    int choice;
    setlocale(LC_ALL, "spanish");
    do
    {
        cout << "\n Mascotas Virtuales\n\n";
        cout << "0 - Salir.\n";
        cout << "1 - Escucha a tu mascota.\n";
        cout << "2 - Alimentar.\n";
        cout << "3 - Jugar con tu mascota.\n";
        cout << "4 - Hidratar\n";
        cout << "Elige una opción: ";
        cin >> choice;
        switch (choice)
        {
        case 0:
            cout << "Vuelve pronto!.\n";
            break;
        case 1:
            crit.Talk();
            break;
        case 2:
            crit.Eat();
            break;
        case 3:
            crit.Play();
            break;
        case 4:
            crit.Drink();
            break;
        default:
            cout << "\n Tu elección es inválida. \n";
        }
    } while (choice != 0);
}