#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#define True 1;
#define False 0;
#define true 1;
#define false 0;

int score=0;
int fire=0;
int live=0;
int lives=3;
int x=0;
int y=0;
int z=0;
int w=0;
int h=0;
int ends=False;
int camera=0;
int enemy=0;
int enemycount=3;
int debugsa=true
char *files="log.txt";

#define tsleep 100000
void debugs(char *c){
    FILE *f1;
    if (debugsa){
        f1=fopen(files,"w");
        fprintf(f1,"%s\n",c);
        fclose(f1);
        printf("%s\n",files);
    }else{
        f1=fopen(files,"a");
        fprintf(f1,"%s\n",c);
        fclose(f1);
        //printf("%s\n",files);
    }
    debugsa=false
    usleep(tsleep);
}
void checkgameover(){
    //put you code here
    debugs("checkgameover\n\n");


}
void refreshscreen(){
    //put you code here
    debugs("refreshscreen");



}
void handlescore(){
    //put you code here
    debugs("handlescore");

}
void changenetwork(){
    //put you code here
    debugs("changenetwork");


}
void drawplayers(){
    //put you code here
    debugs("drawplayers");




}
void handlekeymouse(){
    //put you code here
    debugs("drawplayers");



}
void drawenemys(){
    //put you code here
    debugs("drawenemys");

}
void handlenemy(){
    //put you code here
    debugs("handlenemy");

}
void drawmain(){
    //put you code here
    debugs("drawmain");
}

int mainloop(){
    //put you code here
    debugs("mainloop");
    while(1){
        drawmain();
        handlenemy();
        drawenemys();
        handlekeymouse();
        drawplayers();
        changenetwork();
        handlescore();
        refreshscreen();
        checkgameover();
        if (ends)return ends;
    }
    return ends;
}

int setuploop(){
    //put you code here
    debugs("setuploop");
    while(1){
       if (mainloop())return ends;
    }
    return ends;
    
}
int main(int argc,char *argv[]){
    //put you code here
    debugs("main");
    setuploop();

    return 0;
}