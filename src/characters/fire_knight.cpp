#include "fire_knight.h"


FireKnight::FireKnight()
{
    const char* file = "assets/FireKnight/idle";
    SetTexture(file);
    SetXPos(-80);
    SetYPos(20);

    SetPath("assets/FireKnight/idle");
    SetFrames(8);
    SetSpeed(20);
    SetCount(1);

    SetName("Unknown");
    SetLevel(1);
    SetHealth(100);

    stamina = 100;
}

FireKnight::FireKnight(bool isEnemy, string name)
{   
    if (isEnemy) {
        SetEnemy(isEnemy);
        const char* file = "assets/FireKnight/idle";
        SetTexture(file);
        SetXPos(200);
        SetYPos(20);

        SetPath("assets/FireKnight/idle");
        SetFrames(8);
        SetSpeed(100);
        SetCount(1);

        SetName(name);
        SetLevel(1);
        SetHealth(100);

        stamina = 100;
    }
    else {
        SetPath("assets/FireKnight/idle");
        SetFrames(8);
        SetSpeed(100);
        SetCount(1);
        SetXPos(-80); 
        SetYPos(20); 

        SetName(name);
        SetLevel(1);
        SetHealth(100);
        stamina = 100;

        string filename = path+"/"+"1.png";
        const char* file = filename.c_str();
        SetTexture(file);
    }
}
FireKnight::FireKnight(bool isEnemy, string name, int level, int health, int _stamina)
{
    if (isEnemy) {
        SetEnemy(isEnemy);
        const char* file = "assets/FireKnight/idle";
        SetTexture(file);
        SetXPos(200);
        SetYPos(20);

        SetPath("assets/FireKnight/idle");
        SetFrames(8);
        SetSpeed(100);
        SetCount(1);

        SetName(name);
        SetLevel(level);
        SetHealth(health);
        stamina = _stamina;
    }
    else {
        SetPath("assets/FireKnight/idle");
        SetFrames(8);
        SetSpeed(100);
        SetCount(1);
        SetXPos(-80); 
        SetYPos(20); 

        SetName(name);
        SetLevel(level);
        SetHealth(health);
        stamina = _stamina;

        string filename = path+"/"+"1.png";
        const char* file = filename.c_str();
        SetTexture(file);
    }
}

void FireKnight::Attack1() 
{
    string filename = "assets/FireKnight/1_atk";
    const char* file = filename.c_str();
    SetTexture(file);
    SetPath("assets/FireKnight/1_atk");
    SetFrames(11);
    SetCount(1);
    SetSpeed(100);
}

void FireKnight::Attack2() 
{
    string filename = "assets/FireKnight/2_atk";
    const char* file = filename.c_str();
    SetTexture(file);
    SetPath("assets/FireKnight/2_atk");
    SetFrames(19);
    SetCount(1);
    SetSpeed(100);
}

void FireKnight::Attack3() 
{
    string filename = "assets/FireKnight/3_atk";
    const char* file = filename.c_str();
    SetTexture(file);
    SetPath("assets/FireKnight/3_atk");
    SetFrames(29); // added image 29 from idle (1)
    SetCount(1);
    SetSpeed(100);
}

void FireKnight::Attack4() 
{
    string filename = "assets/FireKnight/4_sp_atk";
    const char* file = filename.c_str();
    SetTexture(file);
    SetPath("assets/FireKnight/4_sp_atk");
    SetFrames(18);
    SetCount(1);
    SetSpeed(100);
}

void FireKnight::Death()
{
    string filename = "assets/FireKnight/death";
    const char* file = filename.c_str();
    SetTexture(file);
    SetPath("assets/FireKnight/death");
    SetFrames(13);
    SetCount(1);
    SetSpeed(100);
}
void FireKnight::Defend()
{
    string filename = "assets/FireKnight/defend";
    const char* file = filename.c_str();
    SetTexture(file);
    SetPath("assets/FireKnight/defend");
    SetFrames(10);
    SetCount(1);
    SetSpeed(100);
}
void FireKnight::Idle()
{
    string filename = "assets/FireKnight/idle";
    const char* file = filename.c_str();
    SetTexture(file);
    SetPath("assets/FireKnight/idle");
    SetFrames(8);
    SetCount(1);
    SetSpeed(100);
}
void FireKnight::TakeDamage(int damage) 
{
    string filename = "assets/FireKnight/take_hit";
    const char* file = filename.c_str();
    SetTexture(file);
    SetPath("assets/FireKnight/take_hit");
    SetFrames(6);
    SetCount(1);
    SetSpeed(100);
    SetHealth(health - damage);
}


void FireKnight::SetEnergy(int _stamina)
{
    stamina = _stamina;
}

int FireKnight::GetEnergy()
{
    return stamina;
}
void FireKnight::PrintStats() 
{
    cout << "Character Stats:" << endl 
        <<  "> Name: " << name << endl
        <<  "> Level: " << level << endl
        <<  "> Health: " << health << endl
        <<  "> Stamina: " << stamina << endl;
}