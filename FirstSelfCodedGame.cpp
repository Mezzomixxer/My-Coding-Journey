#include <iostream>

//endtitle
void endtitle();
//admin
void adminpanel();
void adminQuests();
// inventory
void inventory(void (*returnTo)() = nullptr);
namespace gold{
    double gold = 10;
}
namespace key1{
    int key1 = 0;
}
namespace special{
    int specialKey = 0;
}
//shop
void shop(void (*returnTo)() = nullptr);
//first quest
void firstQuest();
void firstRight();
void firstLeft();
//second quest
void secondQuest();
void secondRight();
void secondLeft();
//thirdQuest
void thirdQuest();
void thirdLeft();
void thirdRight();
//firstBoss
void firstBoss();
void firstBossRoom();
//4.Quest

// Adminpanel
void adminpanel(){

    int adminInPut;

    std::cout << "Welcome to the admin panel " << '\n';
    std::cout << "what u wanna do (1)Play (2)give gold (3) give all " << '\n';
    std::cin >> adminInPut;

    if(adminInPut == 1){

        int adminQuests;

        std::cout << "which level? 1, 2, 3, 4(boss1)" << '\n';
        std::cin >> adminQuests;

        if(adminQuests == 1){
            firstQuest();
        }
        else if(adminQuests == 2){
            secondQuest();
        }
        else if(adminQuests == 3){
            thirdQuest();
        }
        else if(adminQuests == 4){
            firstBoss();
        }
        else{
            adminpanel();
        }

    }
    else if(adminInPut == 2){
        double adminGold;

        std::cout << "How much gold u want? " << '\n';
        std::cin >> adminGold;
        gold::gold += adminGold;
        adminpanel();
    }
    else if(adminInPut == 3){
        gold::gold += 99990;
        key1::key1 += 99;
        special::specialKey += 99;
        adminpanel();
    }
    else{
        adminpanel();
    }
}

void inventory(void (*returnTo)()){

    std::cout << "--------------------" << '\n';
    std::cout << "- Gold   " << gold::gold << '\n';
    std::cout << "- Key1   " << key1::key1 << '\n';
    if(special::specialKey >= 1){
        std::cout << "- SpecialKey   " << key1::key1 << '\n';
    }
    std::cout << "--------------------" << '\n';

    int back;

    std::cout << "back(1)" << '\n';
    std::cin >> back;
    if(back == 1){
        if(returnTo) returnTo();
        return;
    }
    else{
        if(returnTo) returnTo();
        return;
    }
}

void shop(void (*returnTo)()){
    std::cout << "--------------------" << '\n';
    std::cout << "- key1 50 Gold(1) go back(0)" << '\n';
    std::cout << "--------------------" << '\n';

    int choice = 0;
    std::cin >> choice;

    if(choice == 1){
        if(gold::gold >= 50){
            gold::gold -= 50;
            key1::key1++;
            std::cout << "success! " << '\n';
            if(returnTo) returnTo();
            return;

        }
        else{
            std::cout << "not enough gold " << '\n';
            if(returnTo) returnTo();
            return;
        }
    }
    else{
        if(returnTo) returnTo();
        return;
    }
}

//firstQuest
void firstQuest(){

    int firstQuestion;

    // First quest
    std::cout << "Where do u wanna go, left(1) or right(2)? " << '\n';
    std::cout << "Inventory (9) Shop(0)" << '\n';
    std::cin >> firstQuestion;

    if(firstQuestion == 1){
        firstLeft();
    }
    else if(firstQuestion == 2){
        firstRight();
    }
    else if(firstQuestion == 9){
        inventory(firstQuest);
    }
    else if(firstQuestion == 0){
        shop(firstQuest);
    }
    else{
        std::cout << "wrong input" << '\n';
        firstQuest();
    }
}

// firstRight
void firstRight(){
    std::cout << "going to the left..." << '\n';
    std::cout << "you got 5 gold" << '\n';

    gold::gold+=5;
    secondQuest();
}

// firstLeft
void firstLeft(){
   std::cout << "going to the right..." << '\n';
   std::cout << "you got 10 gold" << '\n';

   gold::gold+=10;
   secondQuest();
}

//secondQuest
void secondQuest(){
    
    int secondQuestion;

    std::cout << "Where do u wanna go, Castle(1) or Village(2)? " << '\n';
    std::cout << "Inventory (9) Shop(0)" << '\n';
    std::cin >> secondQuestion;

    if(secondQuestion == 1){
        secondLeft();
    }
    else if(secondQuestion == 2){
        secondRight();
    }
    else if(secondQuestion == 9){
        inventory(secondQuest);
    }
    else if(secondQuestion == 0){
        shop(secondQuest);
    }
    else{
        std::cout << "wrong input" << '\n';
        secondQuest();
    }
}

//secondLeft
void secondLeft(){
    std::cout << "going in the Castle... " << '\n';
    std::cout << "you lost 15 gold" << '\n';
    gold::gold-=15;
    thirdQuest();
}

//secondRight
void secondRight(){
    std::cout << "going in the village... " << '\n';
    std::cout << "you got twice the gold u have" << '\n';
    gold::gold*=2;
    thirdQuest();
}

//thirdQuest
void thirdQuest(){

    int thirdQuestion;

    std::cout << "Where do u wanna go, left(1) or right(2)? " << '\n';
    std::cout << "Inventory (9) Shop(0)" << '\n';
    std::cin >> thirdQuestion;

    if(thirdQuestion == 1){
        thirdLeft();
    }
    else if(thirdQuestion == 2){
        thirdRight();
    }
    else if(thirdQuestion == 9){
        inventory(thirdQuest);
    }
    else if(thirdQuestion == 0){
        shop(thirdQuest);
    }
    else{
        std::cout << "wrong input" << '\n';
        thirdQuest();
    }
}

//thirdLeft
void thirdLeft(){
    std::cout << "You explore the area and find nothing." << '\n';
    firstBoss();
}

//thirdRight
void thirdRight(){
    std::cout << "You find a small chest and gain 3 gold." << '\n';
    gold::gold += 3;
    firstBoss();
}

//firstBoss
void firstBoss(){
    int firstBossQuestion;

    std::cout << "Here is the first boss but u need an key! Enter(1) Go away(2) " << '\n';
    std::cout << "Inventory (9) Shop(0)" << '\n';
    std::cin >> firstBossQuestion;

    if(firstBossQuestion == 1){
        if(key1::key1 >= 1){
            std::cout << "Enter the Boss room!\n";
            firstBossRoom();
        }
        else{
            std::cout << "You dont have the key bought on the shop!\n";
            firstBoss();
        }
    }
    else if(firstBossQuestion == 2){
        std::cout << "going to the next quest...\n";
        return;
    }
    else if(firstBossQuestion == 9){
        inventory(firstBoss);
    }
    else if(firstBossQuestion == 0){
        shop(firstBoss);
    }
    else{
        std::cout << "wrong input" << '\n';
        firstBoss();
    }
}
//firstBossRoom
void firstBossRoom(){
    int firstBossQuestion;

    std::cout << "~~~~~~~~~~MEET THE BOSS~~~~~~~~~~\n";
    std::cout << "              ______             \n";
    std::cout << "             /      |            \n";
    std::cout << "            / x   x |            \n";
    std::cout << "           |   ~~~  |            \n";
    std::cout << "           |  _____ |            \n";
    std::cout << "           / /    / /            \n";
    std::cout << "        ###############          \n";

    std::cout << "fight(1) or hide(2)\n";
    std::cin >> firstBossQuestion;

    if(firstBossQuestion == 1){
        std::cout << "u run at him and dealt him 10 dammage\n"; //richtig

        int secondBossQuestion;
        std::cout << "strike him down(1) or run behind him(2)\n";
        std::cin >> secondBossQuestion;
        if(secondBossQuestion == 1){
            std::cout << "while u strike him, u get hit by his fist and die\n"; //falsch
            endtitle();
        }
        else if(secondBossQuestion == 2){
            std::cout << "u run behind him and strike him from behind and dealt 20 dammage\n"; //richtig

            int thirdBossQuestion;
            std::cout << "u can strike him down(1) or run for the chest(2)\n";
            std::cin >> thirdBossQuestion;
            if(thirdBossQuestion == 1){
                std::cout << "u strike him down and win, u got an special key\n";
                special::specialKey++;
                //eqweqeq
            }
            else if(thirdBossQuestion == 2){
                std::cout << "u open the chest and got 1000 gold\n";
                gold::gold += 1000;
                //ewqeqweq
            }
            else{
                std::cout << "wrong input" << '\n';
                firstBossRoom();
            }
        }
        else{
            std::cout << "wrong input" << '\n';
            firstBossRoom();    
        }
    }
    else if(firstBossQuestion == 2){
        std::cout << "u run, the boss strikes u down with an rock, u die...\n"; //falsch
        endtitle();
    }
    else{
       std::cout << "wrong input" << '\n';
        firstBossRoom(); 
    }
}
//endtitle
void endtitle(){
    return;
}
//main funktion
int main(){

    // User name
    std::string name;
    
    std::cout << "Whats ur name nigger?" << '\n';
    std::cin >> name;

    if(name.empty()){
        std::cout << "u didnt enter your name\n";
    }

    if(name == "admin"){
        std::cout << "Admin grantet " << '\n';
        adminpanel();
    }
    else{
    std::cout << "Hello " << name << '\n';
    firstQuest();
    }

    return 0;
}

