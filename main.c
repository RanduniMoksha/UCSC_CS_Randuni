#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int i=0;
struct getRollNumbers s1;

struct Piece {
    char name[3];
};
struct Player {
    char *color;
    struct Piece pieces[4]; 
};
struct Player players[4] = {
        {"Red", {{"R1"}, {"R2"}, {"R3"}, {"R4"}}},
        {"Green", {{"G1"}, {"G2"}, {"G3"}, {"G4"}}},
        {"Yellow", {{"Y1"}, {"Y2"}, {"Y3"}, {"Y4"}}},
        {"Blue", {{"B1"}, {"B2"}, {"B3"}, {"B4"}}}
    };
struct getRollNumbers
{
    int getRollNum[4];
};
int getRandomNum(){
    return (rand()%6)+1;
}
void getRollNumber(){
    for(i=0;i<4;i++){
        s1.getRollNum[i]=getRandomNum();
        printf("%s rolls %d\n",players[i].color,s1.getRollNum[i]);
    }
}
int getFristPlayer(){

    int lagerNumIndex=0;
    for(int j=0;j<4;j++){
        if(s1.getRollNum[lagerNumIndex]<s1.getRollNum[j]){
            lagerNumIndex=j;
        }    
    }
    return lagerNumIndex;
}
void setPatten(){
    i=getFristPlayer();
    int a=-1;
    while (i<4)
    {
        a++;
        if(a==4){
            break;
        }
        players[a].color=players[i].color;
        for(int j=0;j<4;j++){
             players[a].color[j]=players[i].color[j];
        }
        if(i==3){
            i=-1;
        }
        i++;
    } 
    printf("%s,%s,%s and %s",players[0].color,players[1].color,players[2].color,players[3].color);      
}
int setStartBase(){
    for(int k=0;k<4;k++){
        int diceValue = getRandomNum();
        printf("\n%s rolls %d",players[k].color,diceValue);
        if(diceValue ==6){
            return k;
            break;
        }
        if(k==3){
            k=-1;
        }
    }
}
int main(){
    srand(time(0));
    getRollNumber();
    printf("%s player has the highest roll and will begin the game\n",players[getFristPlayer()].color); 
    setPatten();
    setStartBase();
    printf("\n%s ", players[0].pieces[0].name);
    return 0;
}