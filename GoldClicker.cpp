#include <iostream>
#include <limits>
#include <chrono>
#include <thread>

bool running = true;
bool perseclickrunning = true;
namespace Player{
    double gold = 0;
    double click = 1;
    double persec = 0;
}
void showmenu();
void showshop();
void showstats();
void showshopitems();
void showgoldpersec();

int main(){
    std::thread goldpersecThread(showgoldpersec);
    showmenu();
    return 0;
}
void showmenu(){
    while(running){
        int choice;

        system("cls");
        std::cout << "~~~~~~~~~~~~~~~~~~~~~~\n";
        std::cout << "      Gold Clicker    \n";
        std::cout << "~~~~~~~~~~~~~~~~~~~~~~\n";
        std::cout << "  ________ \n";
        std::cout << " /_______/ \n\n";
        std::cout << "Gold: " << Player::gold << '\n';
        std::cout << "1, Click \n";
        std::cout << "2, Shop\n";
        std::cout << "3, Stats\n";
        std::cout << "0, Beenden \n";
        std::cin >> choice;

        switch(choice){
            case 1: Player::gold += Player::click; 
            break;
            case 2: showshop();
            break;
            case 3: showstats();
            break;
            case 0: running = false;
            break;
            case 9: Player::gold = 99999;
                showmenu();
            break;
            default: std::cout << "Wrong\n";
            break;
        }
    }
}
void showshop(){
    int choice = 0;

    system("cls");
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~\n";
    std::cout << "         Shop         \n";
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~\n";
    std::cout << "Gold: " << Player::gold << '\n';
    std::cout << "1, ShopItems \n";
    std::cout << "0, Beenden \n";
    std::cin >> choice;

    switch(choice){
        case 1:
            showshopitems();
            break;
        case 0:
            showmenu();
            break;
        default:
            std::cout << "Wrong\n";
            showshop();
            break;
    }
}
void showshopitems(){
    std::string Items[] = {"Click Upgrade", "Miner", "Fabric"};
    int item;

    system("cls");
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~\n";
    std::cout << "      Shop Items      \n";
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~\n";
    for(int i = 0; i < sizeof(Items)/sizeof(std::string); i++){
            std::cout << i + 1 << ", " << Items[i] << '\n';
    }
    std::cout << "Welches Item: ";
    if(!(std::cin >> item)){
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Ungültige Eingabe\n";
        return;
    }
    int price = 0;

    switch(item){
        case 1:
            price = 10;
            if(Player::gold >= price){
                Player::gold -= price;
                Player::click++;
            } else {
                std::cout << "Nicht genug Gold\n";
            }
            break;
        case 2:
            price = 100;
            if(Player::gold >= price){
                Player::gold -= price;
                Player::click += 5;
            } else {
                std::cout << "Nicht genug Gold\n";
            }
            break;
        case 3:
            price = 2000;
            if(Player::gold >= price){
                Player::gold -= price;
                Player::persec += 1;
            } else {
                std::cout << "Nicht genung Gold\n";
            }
            break;
        default:
            std::cout << "Wrong\n";
            showshopitems();
            break;
    }
}
void showgoldpersec(){
    while (perseclickrunning)
    {
        Player::gold += Player::persec;

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}
void showstats(){
    int choice = 0;
    system("cls");
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~\n";
    std::cout << "         Stats        \n";
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~\n";
    std::cout << "Gold: " << Player::gold << '\n';
    std::cout << "GPC: " << Player::click << '\n';
    std::cout << "GPS: " << Player::persec << '\n';
    std::cout << "0, Zurück \n";
    std::cin >> choice;
    switch(choice){
        case 0: break;
        default: std::cout << "Wrong\n";
        showstats();
        break;
    } 
}
