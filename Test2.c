#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Piece {
    char name[3];
    int location;
};

struct Player {
    char *color;
    struct Piece pieces[4]; 
};

struct Player players[4] = {
    {"Red", {{"R1",0}, {"R2",0}, {"R3",0}, {"R4",0}}},
    {"Green", {{"G1",0}, {"G2",0}, {"G3",0}, {"G4",0}}},
    {"Yellow", {{"Y1",0}, {"Y2",0}, {"Y3",0}, {"Y4",0}}},
    {"Blue", {{"B1",0}, {"B2",0}, {"B3",0}, {"B4",0}}}
};

struct getRollNumbers {
    int getRollNum[4];
};
int setStartBase();

int getRandomNum() {
    return (rand() % 6) + 1;
}

void getRollNumber(struct getRollNumbers *s1) {
    for (int i = 0; i < 4; i++) {
        s1->getRollNum[i] = getRandomNum();
        printf("%s rolls %d\n", players[i].color, s1->getRollNum[i]);
    }
}

int getFirstPlayer(struct getRollNumbers *s1) {
    int largestNumIndex = 0;
    for (int j = 1; j < 4; j++) {
        if (s1->getRollNum[largestNumIndex] < s1->getRollNum[j]) {
            largestNumIndex = j;
        }
    }
    return largestNumIndex;
}

void setPattern(int firstPlayerIndex) {
    struct Player tempPlayers[4];
    int a = 0;
    
    for (int i = firstPlayerIndex; i < firstPlayerIndex + 4; i++) {
        tempPlayers[a] = players[i % 4];
        a++;
    }

    for (int i = 0; i < 4; i++) {
        players[i] = tempPlayers[i];
    }

    printf("%s, %s, %s and %s\n", players[0].color, players[1].color, players[2].color, players[3].color);
}
int rollDice(int p,int k){
    int location1=0,location2=0;
    int diceValue = getRandomNum();
    printf("%s rolls %d\n", players[k].color, diceValue);
    location1 = players[k].pieces[p].location;
    location2 = location1 + diceValue; 
    printf("%s moves piece %s from location L%d to L%d by %d units\n",players[k].color,players[k].pieces[p].name,location1,location2,diceValue);
    k = (k + 1) % 4;
    setStartBase(k);
}        

int setStartBase(int k) {
    while (1) {
        int diceValue = getRandomNum();
        printf("%s rolls %d\n", players[k].color, diceValue);
        if(diceValue == 6){
            int i=0;
            while(i<4){

                if(players[k].color=="Yellow" && players[k].pieces[i].location == 0)
                {
                    players[k].pieces[i].location = 2;
                    break;

                }else if (players[k].color=="Blue" && players[k].pieces[i].location == 0)
                {
                    players[k].pieces[i].location = 15;
                    break;

                }else if (players[k].color=="Red" && players[k].pieces[i].location == 0)
                {
                    players[k].pieces[i].location = 28;
                    break;

                }else if(players[k].color=="Green" && players[k].pieces[i].location == 0){

                    players[k].pieces[i].location = 41;
                    break;
                }
                i++;
            }    
            printf("%s player moves piece %s to the starting point\n", players[k].color,players[k].pieces[i].name);

            rollDice(i,k);
        }
        k = (k + 1) % 4;
    }
}
int main() {
    srand(time(0));

    struct getRollNumbers s1;
    getRollNumber(&s1);

    int firstPlayerIndex = getFirstPlayer(&s1);
    printf("%s player has the highest roll and will begin the game\n", players[firstPlayerIndex].color);

    setPattern(firstPlayerIndex);

    setStartBase(firstPlayerIndex);

 //   printf("%s\n", players[2].pieces[0].name);


    return 0;
}
