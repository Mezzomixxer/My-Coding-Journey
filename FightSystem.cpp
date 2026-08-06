#include <iostream>
#include <ctime>

void endTitle();
void getPokemon();
void getComputerDamage();
void playerChoice();

namespace player {
    double health = 0;
    double strength = 0;
    double ultDamage = 0;
}

namespace computer {
    double health = 0;
    double strength = 0;
    double ultDamage = 0;
}

int main() {
    srand(time(0));
    getPokemon();
    playerChoice();
    return 0;
}

void playerChoice() {
    int choice = 0;
    double heal = 0;

    do {
        std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        std::cout << "health: " << player::health << "          | [ ]                 [ ] | " << computer::health << " :health" << '\n';
        std::cout << "angriff 1            | /|\\                 /|\\ | \n";
        std::cout << "special angriff 2    |  |                   |  | \n";
        std::cout << "heilen 3             | / \\                 / \\ | \n";
        std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        std::cin >> choice;

        switch (choice) {
            case 1:
                computer::health -= player::strength;
                std::cout << "Du machst " << player::strength << " Damage\n";
                break;
            case 2:
                computer::health -= player::ultDamage;
                std::cout << "Du machst " << player::ultDamage << " Damage\n";
                break;
                
            case 3:
                heal = (rand() % 100 + 1);
                    if(heal > 60){
                        player::health += 60;
                        std::cout << "Du heilst dich um 40.\n";
                    }
                    else{
                        player::health += 40;
                        std::cout << "Du heilst dich um 20.\n";
                    }
                break;
            default:
                std::cout << "Ungültige Eingabe.\n";
                break;
        }

        if (player::health > 0 && computer::health > 0) {
            getComputerDamage();
        }
    } while (player::health > 0 && computer::health > 0);

    if(player::health <= 0){
        endTitle();
    }
    else{
        std::cout << "Gewonnen \n";
    }
}

void getComputerDamage() {

    if(player::health > computer::health){
        double health = (rand() % 100 + 1);
        if(health > 60){
            computer::health += 30;
            std::cout << "Gegner heilt sich um 30\n\n";
        }
        else{
            computer::health += 10;
            std::cout << "Gegner heilt sich um 10\n\n";
        }
    }
    else{
        double heal;
        double computerChoice;

        computerChoice = (rand() % 100 + 1);
        if(computerChoice < 80){
            player::health -= computer::strength;
            std::cout << "Du bekommst " << computer::strength << " Damage\n";
             
        }
        else{
            player::health -= computer::ultDamage;
            std::cout << "Du bekommst " << computer::ultDamage << " Damage\n";
        }
    }
}

void getPokemon(){

    std::string playerPokemon;
    
    std::string Pokemons[] {"Schwer", "Mittel", "Leicht"};

    int pokemon;

    std::cout << "Welches Pokemon willst du?: schwer 1, mittel 2, leicht 3\n";
    std::cin >> pokemon;

    switch(pokemon){
        case 1:
            playerPokemon = Pokemons[0];
            player::health = 250; 
            player::strength = 20;
            player::ultDamage = 50;
            computer::health = 300;
            computer::strength = 20;
            computer::ultDamage = 50;     
            break;
        case 2:
            playerPokemon = Pokemons[1];
            player::health = 300;
            player::strength = 30;
            player::ultDamage = 70;
            computer::health = 350;
            computer::strength = 30;
            computer::ultDamage = 70; 
            break;
        case 3:
            playerPokemon = Pokemons[2];
            player::health = 350;
            player::strength = 40;
            player::ultDamage = 90;
            computer::health = 400;
            computer::strength = 40;
            computer::ultDamage = 90; 
            break;
        default:
            std::cout << "Wrong input\n";
            break;
    }
    std::cout << playerPokemon << '\n';
}
void endTitle(){
    std::cout << "Du bist tot lol xD \n";
}
