#include <iostream.h >

#include <conio.h>

#include <fstream.h>

class player {
    private:
    int hp;
    int maxhp;
    int attack;
    int defence;
    int exp;
    int maxexp;
    int gold;
    char Job;
    public:
        player() {
            hp = 0;
            maxhp = 0;
            attack = 0;
            defence = 0;
            exp = 0;
            maxexp = 0;
            gold = 0;
            Job = 'q';
        }
    int returnhp() {
        return hp;
    }
    int returnattack() {
        return attack;
    }
    int returndefence() {
        return defence;
    }
    int returnexp() {
        return exp;
    }
    int returngold() {
        return gold;
    }
    int returnmaxhp() {
        return maxhp;
    }
    int returnmaxexp() {
        return maxexp;
    }
    char returnJob() {
        return Job;
    }
    int changehp(int h) {
        hp = h;
    }
    int changeattack(int h) {
        attack = h;
    }
    int changedefence(int h) {
        defence = h;
    }
    int changeexp(int h) {
        exp = h;
    }
    int changegold(int h) {
        gold = h;
    }
    int changemaxhp(int h) {
        maxhp = h;
    }
    int changemaxexp(int h) {
        maxexp = h;
    }
    char changeJob(char h) {
        Job = h;
    }
    void displaydata() {
        cout << "\nAttack:" << attack << "\nDefence:" << defence << "\nHitPoints:" << hp << "/" << maxhp << "\nGold:" << gold << "\nExperiance:" << exp << "/" << maxexp << "\n" << endl;
    }
};
player Player;
int Eatk;
int EDef;
int EMaxHp;
int EHp = EMaxHp;
int EGold;
int EExp;
int Batk;
int BDef;
int BMaxHp = 1;
int BHp = 1;
int BExp;
int BGold;
int Boss = 1;
void welcome();
void prestory();
void choice();
void stats();
void Fight();
void FightLaunch();
void FightProcess();
void Outside();
void Inn();
void Temple();
void Forest();
void Boss1();
void BossFight();
void BossLaunch();
void BossProcess();
void Victory();
void Displayscore();
void Putscore();
int main() {
    welcome();
    prestory();
    choice();
    stats();
    Inn();
}
void Putscore() {
    fstream filout;
    filout.open("score.dat", ios::out | ios::binary);
    filout.write((char * ) & Player, sizeof(Player));
    filout.close();
}
void Displayscore() {
    cout << "----------SAVED STATS--------------" << endl;
    ifstream fin;
    fin.open("score.dat", ios:: in );
    if (!fin) {
        cout << "Cannot Open File!!\n";
    }
    while (fin) {
        fin.read((char * ) & Player, sizeof(Player));
        Player.displaydata();
    }
    fin.close();
}
void Victory() {
    char in ;
    cout << "\n You Slowly Step Out From The Temple, Battered And Bruised..." << "\n To Your Surprise Hundreds Of People Stand Before You Cheering You On... " << "\n You Have Defeated The Great Demon! Thank You For Playing! " << endl;
    cout << "GAME OVER" << endl;
    cout << " " << endl;
    cout << "Want to save Your Satats? Y/N" << endl;
    cin >> in ;
    if ( in == 'Y') {
        Putscore();
        Displayscore();
    }
    cout << "Thank You For Playing My Game......" << endl;
    cout << "Created By Mayank Jha" << endl;
    getch();
}
void welcome() {
    cout << "--------------------------------- " << endl;
    cout << "\n| The Mist | " << endl;
    cout << "\n--------------------------------- " << endl;
    cout << "\n Welcome To the Unknown " << endl;
    getch();
    clrscr();
}
void prestory() {
    cout << "--------------------------------------------------- " << endl;
    cout << "\n PLEASE USE CAPITAL LETTERS TO PLAY THE GAME " << endl;
    cout << "\n-------------------------------------------------- " << endl;
    cout << "\n" << "\n" << endl;
    getch();
    cout << "\nA long time ago, in a realm of medieval magic, weapons and warriors... " << endl;
    getch();
    cout << "\nA great demon was summoned from hell to bring ruin to the kingdom of Mist... " << endl;
    getch();
    cout << "\nMany brave knights rose to banish this demon..." << endl;
    getch();
    cout << "\nBut all have failed..." << endl;
    getch();
    clrscr();
}
void choice() {
    char Pick;
    cout << "You Awaken Very Slowly, You Begin Cursing Hangovers And Every Form Of Booze..." << endl;
    getch();
    cout << "Your Head Is Splitting And You Can Remember A Thing, Where Or Who You Are." << endl;
    getch();
    cout << "As You Climb To You Feet You Realize Your Staying At The Old Overnighter. An Inn For Local Drifters " << endl;
    getch();
    cout << "\nYou Pat Down Your Clothes And Reconize What Your Wearing..... You Are A... " << endl;
    getch();
    cout << "\n" << "\n<W>arrior" << "\n<M>age" << "\n<P>riest" << endl;
    cin >> Pick;
    if (Pick == 'W') {
        cout << "\n Thats Right You Are A Warrior! Bravest Of The Brave!" << endl;
        Player.changeJob('W');
    }
    if (Pick == 'M') {
        cout << "\n Thats Right You Are A Mage! May The Elements Bring Great Power To You!" << endl;
        Player.changeJob('M');
    }
    if (Pick == 'P') {
        cout << "\n Thats Right You Are A Priest! Maybe Not The Holiest But Hey!" << endl;
        Player.changeJob('P');
    }
    cout << " After Getting Cleaned Up You Head Downstairs Into The Bar " << endl;
    if (Player.returnJob() == 'W') {
        Player.changeattack(10);
        Player.changedefence(5);
        Player.changemaxhp(20);
        Player.changehp(Player.returnmaxhp());
        Player.changegold(10);
        Player.changeexp(0);
        Player.changemaxexp(30);
    }
    if (Player.returnJob() == 'M') {
        Player.changeattack(5);
        Player.changedefence(10);
        Player.changemaxhp(20);
        Player.changehp(Player.returnmaxhp());
        Player.changegold(10);
        Player.changeexp(0);
        Player.changemaxexp(30);
    }
    if (Player.returnJob() == 'P') {
        Player.changeattack(5);
        Player.changedefence(5);
        Player.changemaxhp(30);
        Player.changehp(Player.returnmaxhp());
        Player.changegold(10);
        Player.changeexp(0);
        Player.changemaxexp(30);
    }
}
void stats() {
    cout << " *-----[ Your Stats ]-----*" << "\n" << endl;
    cout << "\nAttack:" << Player.returnattack() << "\nDefence:" << Player.returndefence() << "\nHitPoints:" << Player.returnhp() << "/" << Player.returnmaxhp() << "\nGold:" << Player.returngold() << "\nExperiance:" << Player.returnexp() << "/" << Player.returnmaxexp() << "\n" << endl;
    getch();
}
void Inn() {
    char Pick;
    cout << "\nYou Look Around The Bar And See A Bunch Of Drunks, A Bartender, And A Staircase." << endl;
    cout << "\n" << "\n<D>runks" << "\n<B>artender" << "\n<U>pstairs" << "\n < V>iew Your Stats" << "\n < L>eave Bar And Go Outside" << "\n" << endl;
    cin >> Pick;
    if (Pick == 'D') {
        cout << "\nA Drunk Screams At You.... GO AWAY!!!!" << endl;
        Inn();
    }
    if (Pick == 'B') {
        cout << "\n What Would You Like To Order?" << endl;
        cout << "\n " << "<F>ighting Fury - 10 Gold " << "\n < R>hunestone Water - 10 Gold" << "\n < M>oonShine - 20 Gold" << "\n < L>eave Bar" << endl;
        cin >> Pick;
        if (Pick == 'F') {
            if (Player.returngold() < 10) {
                cout << "\n Sorry Not Enough Gold!" << endl;
            } else {
                Player.changegold(Player.returngold() - 10);
                Player.changeattack(Player.returnattack() + 1);
                cout << "\n Gained 1 Attack!" << endl;
            }
        }
        if (Pick == 'R') {
            if (Player.returngold() < 10) {
                cout << "\n Sorry Not Enough Gold!" << endl;
            } else {
                Player.changegold(Player.returngold() - 10);
                Player.changedefence(Player.returndefence() + 1);
                cout << "\n Gained 1 Defence!" << endl;
            }
        }
        if (Pick == 'M') {
            if (Player.returngold() < 20) {
                cout << "Sorry Not Enough Gold!" << endl;
            } else {
                Player.changegold(Player.returngold() - 20);
                Player.changemaxhp(Player.returnhp() + 5);
                cout << "\n Gained 5 Max Hitpoints!" << endl;
            }
        }
        if (Pick == 'B') {
            Inn();
        }
        Inn();
    }
    if (Pick == 'U') {
        cout << " You Run Back To Your Room And Take A Quick Nap... You Awaken Feeling Refreshed!" << endl;
        Player.changehp(Player.returnmaxhp());
        Inn();
    }
    if (Pick == 'V') {
        stats();
    }
    if (Pick == 'L') {
        cout << "\nYou Gather Your Things And Start Your Journey!";
        Outside();
    } else {
        Inn();
    }
}
void Outside() {
    char Pick;
    cout << "\n You Journey Outside And Look Around. You Feel Cheery Since It Is Such A Beautiful Day..." << endl;
    cout << "\n Then You Remember The Horror Begining Caused By The Demon! It Must Be Stopped!" << endl;
    cout << "\n" << "\n<F>orest" << "\n<I>nn" << "\n<T>emple" << "\n < V>iew Your Stats" << endl;
    cin >> Pick;
    if (Pick == 'F') {
        Forest();
    }
    if (Pick == 'I') {
        Inn();
    }
    if (Pick == 'T') {
        Temple();
    }
    if (Pick == 'V') {
        stats();
    }
}
void Forest() {
    cout << "\n You Look Around And Suddenly You Are Attacked By " << endl;
    if (Boss == 1) {
        cout << "An Ape" << endl;
    }
    if (Boss == 2) {
        cout << "A Witch" << endl;
    }
    if (Boss == 3) {
        cout << "A Dragon" << endl;
    }
    if (Boss == 1) {
        Eatk = 5;
        EDef = 4;
        EMaxHp = 15;
        EHp = EMaxHp;
        EGold = 4;
        EExp = 5;
        Fight();
    }
    if (Boss == 2) {
        Eatk = 9;
        EDef = 8;
        EMaxHp = 30;
        EHp = EMaxHp;
        EGold = 8;
        EExp = 8;
        Fight();
    }
    if (Boss == 3) {
        Eatk = 13;
        EDef = 12;
        EMaxHp = 50;
        EHp = EMaxHp;
        EGold = 12;
        EExp = 12;
        Fight();
    }
}
void FightLaunch() {
    if (EHp < 0) {
        cout << "\n You Have Slain The Creature!" << "\n Gained" << EGold << "Gold!" << "\n Gained" << EExp << "Experiance!" << endl;
        Player.changegold(Player.returngold() + EGold);
        Player.changeexp(Player.returnexp() + EExp);
        EHp = EMaxHp;
        Outside();
    }
    if (Player.returnhp() < 0) {
        cout << "\n You Have Been Killed In Action!" << "\n Lost Half Your Gold" << "\n Lost Half Your Experiance" << endl;
        Player.changegold(Player.returngold() / 2);
        Player.changeexp(Player.returnexp() / 2);
        Player.changehp(Player.returnmaxhp());
        Inn();
    }
    Fight();
}
void FightProcess() {
    EHp = EHp + (EDef / 2 - Player.returnattack());
    cout << "\nCreature took " << (EDef / 2 - Player.returnattack()) <<
        " Damage" << endl;
    Player.changehp(Player.returnhp() + (Player.returndefence() / 2 - Eatk));
    cout << "\nYou Have Taken " << (Player.returndefence() / 2 - Eatk) <<
        " Damage" << endl;
    FightLaunch();
}
void Fight() {
    char Pick;
    cout << "\n *------------[ FIGHT ]------------*" << "\n" <<
        " Enemy Hp :" << EHp << " / " << EMaxHp << "\n" << " Your HP :" << Player.returnhp() << "/" << Player.returnmaxhp() <<
        "\n" << "<A>ttack" << "\n < R>un Away" << endl;
    cin >> Pick;
    if (Pick == 'R') {
        Outside();
    }
    if (Pick == 'A') {
        FightProcess();
    }
}
void Temple() {
    if (Player.returnexp() >= Player.returnmaxexp()) {
        cout << "\n The Monks Feel Your Strength As You Walk The Stone HallWays" <<
            "\n If You Defeat The Awaiting Beast, You Will Be 1 Step Closer To The Demon" << endl;
        Boss1();
    } else {
        cout << "\n The Monks Will Not Allow You Inside, You Are Not Yet Ready!" << endl;
        Outside();
    }
}
void Boss1() {
    if (Boss == 1) {
        BMaxHp = 30;
        BHp = BMaxHp;
        Batk = 10;
        BDef = 8;
        BGold = 15;
        BExp = 5;
        BossFight();
    }
    if (Boss == 2) {
        BMaxHp = 60;
        BHp = BMaxHp;
        Batk = 14;
        BDef = 14;
        BGold = 20;
        BExp = 10;
        BossFight();
    }
    if (Boss == 3) {
        BMaxHp = 90;
        BHp = BMaxHp;
        Batk = 22;
        BDef = 22;
        BGold = 20;
        BExp = 15;
        BossFight();
    }
}
void BossFight() {
    char Pick;
    cout << "\n *------------[ BOSS ]------------*" << "\n" << " Enemy Hp :" << BHp << " / " << BMaxHp <<
        "\n" << " Your HP :" << Player.returnhp() << "/" << Player.returnmaxhp() <<
        "\n" << "<A>ttack" << "\n < R>un Away" << endl;
    cin >> Pick;
    if (Pick == 'R') {
        Outside();
    }
    if (Pick == 'A') {
        BossProcess();
    }
}
void BossProcess() {
    BHp = BHp + (BDef / 2 - Player.returnattack());
    cout << "\nCreature took " << (BDef / 2 - Player.returnattack()) <<
        " Damage" << endl;
    Player.changehp(Player.returnhp() + (Player.returndefence() / 2 - Batk));
    cout << "\nYou Have Taken " << (Player.returndefence() / 2 - Batk) <<
        " Damage" << endl;
    BossLaunch();
}
void BossLaunch() {
    if (BHp < 0) {
        cout << "\n You Have Defeated A Boss! " << "\n Stats Have Increased! " << "\n Gained" << EGold << "Gold!" << "\n Gained" << EExp << "Experiance!" << endl;
        Player.changegold(Player.returngold() + BGold);
        Player.changeexp(Player.returnexp() + BExp);
        BHp = BMaxHp;
        Player.changemaxhp(Player.returnmaxhp() + 15);
        Boss++;
        Player.changemaxexp(Player.returnmaxexp() * 2);
        Player.changeattack(Player.returnattack() + 5);
        Player.changedefence(Player.returndefence() + 5);
        if (Boss == 4) {
            Victory();
        }
        Outside();
    }
    if (Player.returnhp() < 0) {
        cout << "\n You Have Been Killed In Action!" << "\n Lost Half Your Gold" << "\n Lost Half Your Experiance" << endl;
        Player.changegold(Player.returngold() / 2);
        Player.changeexp(Player.returnexp() / 2);
        Player.changehp(Player.returnmaxhp());
        Inn();
    }
    BossFight();
}