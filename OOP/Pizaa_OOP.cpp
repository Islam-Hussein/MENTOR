#include <iostream>
using namespace std;

// --> Making Dough
// --> Add Topping 
// -- Baking Pizza
// -- Pizza Ready

/*
void  Make_Mozerella_Pizza()
{
    cout << "Making Dough...\n";
    cout << "Add Mozarella Tpping...\n";
    cout << "Baking Pizza...\n";
    cout << "Pizza Ready...\n";
    cout << "Verpackung...\n";
}

void  Make_Chicken_Pizza()
{
    cout << "Making Dough...\n";
    cout << "Add Chicken Tpping...\n";
    cout << "Baking Pizza...\n";
    cout << "Pizza Ready...\n";
    cout << "Verpackung...\n";
}

void  Make_Salami_Pizza()
{
    cout << "Making Dough...\n";
    cout << "Add Salami Tpping...\n";
    cout << "Baking Pizza...\n";
    cout << "Pizza Ready...\n";
    cout << "Verpackung...\n";
}
*/

class Pizza
{
public:
    void Make_Dough()
    {
        cout << "Making Dough...\n";
    }

    virtual void Add_Topping()
    {
        cout << "Add Shit Topping..\n";
    }

    void Bake_Pizza()
    {
        cout << "Baking Pizza...\n";
        cout << "Pizza Ready...\n";
    }

    
    void Verpackung()
    {
        cout << "Verpacken.....\n";
    }
    

    void MakePizza()
    {
        Make_Dough();
        Add_Topping();
        Bake_Pizza();
        Verpackung();
    }


};

class Chicken_Pizza : public Pizza
{
    void Add_Topping()
    {
        cout << "Add Chicken Topping..\n";
    }

};

class Salami_Pizza : public Pizza
{
    void Add_Topping()
    {
        cout << "Add Salami Topping..\n";
    }

};


class Mozarella_Pizza : public Pizza
{
    void Add_Topping()
    {
        cout << "Add Mozarella Topping..\n";
    }

};


void Make_Pizza(Pizza* pizza)
{
    pizza->MakePizza();
}



int main()
{
    int choice;
    cout << "Enter 1 for Mozarella 2 for Chicken 3 for Salami...\n";
    cin >> choice;
   

      
    switch(choice)
    {
        case 1:
        Make_Pizza(new Mozarella_Pizza());
        break;

        case 2:
        Make_Pizza(new Chicken_Pizza());
        break;

        case 3:
        Make_Pizza(new Salami_Pizza());
        break;



        default:
        break;
    }
    


    return 0;
}