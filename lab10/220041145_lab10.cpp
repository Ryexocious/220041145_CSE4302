#include<iostream>
using namespace std;
class CharacterActions {
private:
public:
    virtual void attack()=0;
    virtual void defence()=0;
    virtual void usespecialability()=0;
    virtual void display()=0;

};
class BaseCharacter : public CharacterActions {
protected:
    string name;
    int atkpow;
    string specialabi;
    int spabpow;
    int health;
    int mana;

public:
    BaseCharacter(string n, int atk, string s, int sa, int h, int m = 0)
        : name(n), atkpow(atk), specialabi(s), spabpow(sa), health(h), mana(m) {}

    void attack() override {
        cout << name << " attacks with power " << atkpow << "!\n";
        mana += 50;
    }

    void defence() override {
        cout << name << " health now: " << health << "\n";
    }

    void usespecialability() override {
        if (mana >= 100) {
            cout << name << " uses " << specialabi << " with power " << spabpow << "!\n";
            mana = 0;
        }
    }

    void display() override {
        cout << name << " Health now: " << health <<"\n";
    }

    string getname() { 
        return name; 
    }
    int getatk() { 
        return atkpow; 
    }
    int gethealth() { 
        return health; 
    }
    int getspecialpower() { 
        return spabpow; 
    }
    int getmana() { 
        return mana; 
    }
    void reduceHealth(int dmg) {
        health = health - dmg; 
    }
    bool isAlive() { 
        return health > 0; 
    }
};


class Warrior : public BaseCharacter{
public:
    Warrior():BaseCharacter("Warrior",25,"Berserk Rage",35,100,0) {}
    
};
class Mage : public BaseCharacter{
public:
    Mage():BaseCharacter("Mage",20,"Arcane Blash",30,120,0) {}
    
};
class Archer : public BaseCharacter{
public:
    Archer():BaseCharacter("Archer",20,"Fire Arrow",35,90,0) {}
    
};
class BossEnemy{
protected:
    string name;
    int atkpow;
    int health;
public:
    BossEnemy(string s="boss",int h=150,int atk=30) : name(s),health(h),atkpow(atk){}
    void attack(BaseCharacter &target) {
        cout << name << " attacks " << target.getname() << " with power " << atkpow << "!\n";
        target.reduceHealth(atkpow);
    }

    void takeDamage(int dmg) {
        health = health - dmg;
        cout << name << " takes " << dmg << " damage! Health now: " << health << "\n";
    }

    int gethealth() { 
        return health; 
    }
    bool isAlive() { 
        return health > 0; 
    }
};
class GameEngine{
private:
    Warrior w;
    Mage m;
    Archer a;
    BossEnemy b;

public:
    GameEngine() : w(), m(), a(), b() {}

    void playGame() {
        cout << "Game begins! Players vs. Boss\n";
        while (b.isAlive() && (w.isAlive() || m.isAlive() || a.isAlive())) {
            if (w.isAlive() && b.isAlive()) {
                if (w.getmana() >= 100 && b.isAlive()) {
                    w.usespecialability();
                    b.takeDamage(w.getspecialpower());
                }
                else{
                    w.attack();
                    b.takeDamage(w.getatk());
                }
            }
            if (m.isAlive()&& b.isAlive()) {
                if (m.getmana() >= 100 && b.isAlive()) {
                    m.usespecialability();
                    b.takeDamage(m.getspecialpower());
                }
                else{
                    m.attack();
                    b.takeDamage(m.getatk());
                }
            }
            if (a.isAlive()&& b.isAlive()) {
                if (a.getmana() >= 100 && b.isAlive()) {
                    a.usespecialability();
                    b.takeDamage(a.getspecialpower());
                }
                else{
                    a.attack();
                    b.takeDamage(a.getatk());
                }
            }
            if (b.isAlive()) {
                if (w.isAlive()){
                    b.attack(w);
                    w.display();
                }
                if (m.isAlive()){
                    b.attack(m);
                    m.display();
                }    
                if (a.isAlive()){
                    b.attack(a);
                    a.display();
                }
            }
        
        }
        if (!b.isAlive()) {
            cout << "Boss defeated! Players win!\n";
        } 
        else {
            cout << "Players defeated! Boss wins!\n";
        }
    }
};
int main() {
    GameEngine game;
    game.playGame();

}