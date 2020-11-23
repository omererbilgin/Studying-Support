//libs
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <unistd.h>
#include <stdbool.h>
#include <time.h>
/////
void intro();
char* readFile(char*);
bool check();
void first(bool);
bool chkroot();
int randoment(int);
void options();
void renstal();
void secset();
void subset();
void infoset();
void infoset2(bool);
void settingsubjects();
void openplan();
void opensections();
void openlinks(char*, int);
void showinf();
void writeinf();
void help();
/////

int main(){

system("clear");

system("sudo touch test");
system("sudo rm test");


system("clear");

bool root;

root = chkroot();

if(root == true){
printf("\nI recommend you to continue with 'normal user' privileges instead of root");
printf("\n\n\n[ENTER] to continue [CTRL + C] to quit");
getchar();
}
system("clear");

bool firstbool;
firstbool = check();
system("clear");
if(firstbool == false){
first(true);
}

intro();

return 0;
}



//main page

void intro(){

start:
// config date opt

system("clear");

char *user = getenv("HOME");



char *date = malloc(40);
date = readFile("date +%F");
int lengt9 = strlen(date);
date[lengt9 - 1] = '\0';

char *writedate = malloc(100);
snprintf(writedate, 100, "sed -i '9i date=%s' %s/.studying/opts",date,user);
system(writedate);
free(writedate);
free(date);

char *deletedate = malloc(100);
snprintf(deletedate, 100, "sed -i '10d' %s/.studying/opts",user);
system(deletedate);
free(deletedate);



system("clear");
int randomnum = randoment(10);

switch(randomnum){
case 0:
printf("Don't forget, 10 questions a day!");
break;
case 1:
printf("If you're tired try giving a break for while. That's no harm");
break;
case 2:
printf("How may I help you sir?");
break;
case 3:
printf("Don't know what to do? Press '6' for help and information of the program");
break;
case 4:
printf("Beep Bop Beep");
break;
case 5:
printf("No pain no gain");
break;
case 6:
printf("Don't forget that group work has an efficacy on your achievements");
break;
case 7:
printf("What a lovely day to be a computer");
break;
case 8:
printf("After studying do not forget to enlist your accomplishments");
break;
case 9:
printf("Maybe it's time to talk about my genius?");
break;
case 10:
printf("Beep Beep Bop Bap!!");
break;
default:
printf("Undefined Behavior");
}

printf("\n\n\nI am done studying        (1)");
printf("\nCheck Accomplishments     (2)");
printf("\nWeekly Plan               (3)");
printf("\nOpen Sections             (4)");
printf("\nOptions                   (5)");
printf("\nHelp me!                  (6)");
printf("\n\n\n");
system("/bin/stty raw");

char a1 = getchar();
system("/bin/stty cooked");
if(a1 == 49){ // 1 WRITE

writeinf();


}
else if(a1 == 50){ // 2 DIARY

showinf();

}
else if(a1 == 51){ // 3 WEEKLY PLAN

openplan();

goto start;

}
else if(a1 == 52){ // 4 SECTIONS

    opensections();

}
else if(a1 == 53){ // 5 OPTIONS
options();
goto start;
}
else if(a1 == 54){ // 6 HELP

    help();
}
else if(a1 == 3){ // INTERRUPT
system("clear");
printf("\nInterrupted... Have a nice day sir!\n\n");
exit(0);    
}
else{
goto start;
}

goto start;
}

//check root

bool chkroot(){

char *root = getenv("HOME");

if(strcmp(root, "/root") == 0)
return true;
else
return false;

}




//readfile

char *readFile(char cmd[200]) {

   char cmd1[99999] = {0};
   system("touch cmd");  
   snprintf(cmd1, 99999, "%s >> cmd", cmd);
   system(cmd1); 
    
    FILE *f = fopen("cmd", "rt");
    assert(f);
    fseek(f, 0, SEEK_END);
    long length = ftell(f);
    fseek(f, 0, SEEK_SET);
    char *buffer = (char *) malloc(length + 1);
    buffer[length] = '\0';
    fread(buffer, 1, length, f);
    fclose(f);
    system("rm cmd");
    return buffer;
}

//checks if the program is opened for the first time or not
bool check(){

char *user = getenv("HOME");
char *cmd = malloc(200);
char *check = malloc(100);

strcat(check, "check\n");

snprintf(cmd, 200, "ls %s/.studying/.check",user);

char *buffer = readFile(cmd);

if(strcmp(buffer, check) == 0){
free(cmd);
free(check);
return true;
}
else{
free(cmd);
free(check);
return false;
}


}


// In case that the user is openning the program for the first time
void first(bool frst){

char *user = getenv("HOME");

if(frst == true){

printf("\nI see this is your first time. Would you like to configure 'Studying Support'?");

printf("\n\n\n");
printf("[ENTER] to continue [CTRL + C] to quit");
getchar();
}
else if(frst == false){

char *rm1 = malloc(100);
snprintf(rm1, 100, "rm -r %s/.studying",user);
system(rm1);
free(rm1);

getchar();

}

//file config

char *s1 = malloc(100);
char *s2 = malloc(100);
char *s3 = malloc(100);
char *s4 = malloc(100);
char *s5 = malloc(100);
char *s6 = malloc(100);
char *s7 = malloc(100);


snprintf(s1, 100, "mkdir %s/.studying",user);
system(s1);

free(s1);

snprintf(s2, 100, "touch %s/.studying/inf",user);
system(s2);

free(s2);

snprintf(s3, 100, "mkdir %s/.studying/.check",user);
system(s3);

free(s3);

snprintf(s4, 100, "touch %s/.studying/.check/check",user);
system(s4);

free(s4);

snprintf(s5, 100, "touch %s/.studying/subinf",user);
system(s5);

free(s5);

snprintf(s6, 100, "touch %s/.studying/opts",user);
system(s6);

free(s6);

snprintf(s7, 100, "touch %s/.studying/pages",user);
system(s7);

free(s7);

char *s11 = malloc(100);
char *s22 = malloc(100);
char *s33 = malloc(100);
char *s44 = malloc(100);
char *s55 = malloc(100);

snprintf(s11, 100, "echo '' >> %s/.studying/inf",user);

for(int i = 0;i <= 8; i++){
system(s11);
}
free(s11);

snprintf(s22, 100, "echo '' >> %s/.studying/subinf",user);

for(int i = 0;i <= 8; i++){
system(s22);
}
free(s22);

snprintf(s33, 100, "echo '' >> %s/.studying/opts",user);


for(int i = 0;i <= 8; i++){
system(s33);
}
free(s3);

snprintf(s44, 100, "echo '' >> %s/.studying/pages",user);

for(int i = 0;i <= 8; i++){
system(s44);
}
free(s4);

// setting 1
system("clear");
printf("First Setting: Subjects");
printf("\n\n\n");
printf("I'd like to learn which subject you're going to study");
printf("\n\n> ");
char *subject = malloc(50);
char *subcmd = malloc(100);
char *subjectcmd = malloc(100);
fgets(subject, 50, stdin);
fflush(stdout);
snprintf(subcmd, 100, "sed -i '1i subjectnum=1' %s/.studying/opts",user);
snprintf(subjectcmd, 100, "sed -i '1i -)%s' %s/.studying/subinf",subject,user);

system(subjectcmd);
system(subcmd);


system("clear");

printf("\nLovely! Your subject has been successfully enlisted.\nRemember that you can add any subject you're studying later");
printf("\n\n\n[ENTER]");
getchar();
system("clear");
free(subcmd);
free(subjectcmd);
free(subject);

//setting 2
printf("Second Setting: Links for Studying");
printf("\n\n\n");
printf("You can create sections and attach links to them \nso you can open your regular links faster and easier");
printf(".\nDo you want to create a section and enlist some links? [Y]/[n] ");
char yesno;
scanf("%c",&yesno);
if(yesno == 'y' || yesno == 'Y'){

system("clear");
getchar();
fflush(stdout);
printf("\nSection name: ");
char *secname = malloc(100);
char *seccmd = malloc(150);
fgets(secname, 100, stdin);

snprintf(seccmd, 150, "touch %s/.studying/%s",user,secname);
system(seccmd);

system("clear");

printf("\nThe number of links that are going to be enlisted: ");
int nummm;
scanf("%d",&nummm);

char *numcmd = malloc(100);


char *spacecmd = malloc(100);
snprintf(spacecmd, 100, "echo '' >> %s/.studying/%s",user,secname);
for(int i = 0; i < nummm; i++){
system(spacecmd);
}
char *seccmdd = malloc(100);
char *seccmdd2 = malloc(100);
snprintf(seccmdd, 100, "sed -i '1i sectionnum=1' %s/.studying/pages",user);
system(seccmdd);
snprintf(seccmdd2, 100, "sed -i '2i -)%s' %s/.studying/pages",secname,user);
system(seccmdd2);
snprintf(numcmd, 100, "sed -i '1i num=%d' %s/.studying/%s",nummm,user,secname);
system(numcmd);
system("clear");
getchar();
for(int i = 1; i <= nummm; i++){
    char *link = malloc(150);
    char *linkcmd = malloc(200);
    printf("%d. Link: ",i);
    fgets(link, 150, stdin);
    snprintf(linkcmd, 200, "sed -i '%di -)%s' %s/.studying/%s",i + 1,link,user,secname);
    system(linkcmd);
    free(link);
    free(linkcmd);
}
system("clear");
printf("\nExcellent! You have created a new section");
printf(" attached %d link(s) to it.",nummm);
printf("\n\n\n[ENTER]");
getchar();
}
else{
system("clear");
printf("\nOK! Continuing without any links. Do not forget you can add them whenever you want.");
printf("\n\n\n[ENTER]");
getchar();
getchar();
}

system("clear");

// setting 3
bool xyy;
printf("Third Setting: Personal Information");

printf("\n\n\nWould you want to let the program know more about you?\nThis will only be stored on your computer [Y]/[n] ");
char yesnoo;
scanf("%c",&yesnoo);
if(yesnoo == 'y' || yesnoo == 'Y'){

xyy = true;
char *simppcmd = malloc(100);
snprintf(simppcmd, 150, "sed -i '2i ncheck=1' %s/.studying/opts",user);
system(simppcmd);
char *fname = malloc(100);
char *namecmd = malloc(150);
system("clear");
getchar();
printf("Full Name: ");
fgets(fname, 100, stdin);
snprintf(namecmd, 150, "sed -i '3i name=%s' %s/.studying/opts",fname,user);
system(namecmd);
free(fname);
free(namecmd);
start:

system("clear");
printf("Date of Birth\n\n");

// day
printf("Day: ");
char day[2];
system("/bin/stty raw");
char a = getchar();
if(a == 48 || a == 49 || a == 50 || a == 51 || a == 52 || a == 53 || a == 54 || a == 55 || a == 56 || a == 57){
day[0] = a;
system("/bin/stty cooked");    
}
else
{
system("/bin/stty cooked");    
goto start;
}
system("/bin/stty raw");
char a1 = getchar();
if(a1 == 48 || a1 == 49 || a1 == 50 || a1 == 51 || a1 == 52 || a1 == 53 || a1 == 54 || a1 == 55 || a1 == 56 || a1 == 57){
day[1] = a1;
system("/bin/stty cooked");    
}
else
{
system("/bin/stty cooked");    
goto start;
}
char *daycmd = malloc(50);
snprintf(daycmd, 50, "sed -i '4i day=%c%c' %s/.studying/opts",day[0],day[1],user);

system(daycmd);
free(daycmd);

// month
printf("\nMonth: ");
char month[2];
system("/bin/stty raw");
char a12 = getchar();
if(a12 == 48 || a12 == 49 || a12 == 50 || a12 == 51 || a12 == 52 || a12 == 53 || a12 == 54 || a12 == 55 || a12 == 56 || a12 == 57){
month[0] = a12;
system("/bin/stty cooked");    
}
else
{
system("/bin/stty cooked");    
goto start;
}
system("/bin/stty raw");
char a13 = getchar();
if(a13 == 48 || a13 == 49 || a13 == 50 || a13 == 51 || a13 == 52 || a13 == 53 || a13 == 54 || a13 == 55 || a13 == 56 || a13 == 57){
month[1] = a13;
system("/bin/stty cooked");    
}
else
{
system("/bin/stty cooked");    
goto start;
}
char *monthcmd = malloc(50);
snprintf(monthcmd, 50, "sed -i '5i month=%c%c' %s/.studying/opts",month[0],month[1],user);

system(monthcmd);
free(monthcmd);

//year

printf("\nYear: ");
char year[5];
system("/bin/stty raw");
char a14 = getchar();
if(a14 == 48 || a14 == 49 || a14 == 50 || a14 == 51 || a14 == 52 || a14 == 53 || a14 == 54 || a14 == 55 || a14 == 56 || a14 == 57){
year[0] = a14;
system("/bin/stty cooked");    
}
else
{
system("/bin/stty cooked");    
goto start;
}
system("/bin/stty raw");
char a15 = getchar();
if(a15 == 48 || a15 == 49 || a15 == 50 || a15 == 51 || a15 == 52 || a15 == 53 || a15 == 54 || a15 == 55 || a15 == 56 || a15 == 57){
year[1] = a15;
system("/bin/stty cooked");    
}
else
{
system("/bin/stty cooked");    
goto start;
}
system("/bin/stty raw");
char a16 = getchar();
if(a16 == 48 || a16 == 49 || a16 == 50 || a16 == 51 || a16 == 52 || a16 == 53 || a16 == 54 || a16 == 55 || a16 == 56 || a16 == 57){
year[2] = a16;
system("/bin/stty cooked");    
}
else
{
system("/bin/stty cooked");    
goto start;
}
system("/bin/stty raw");
char a17 = getchar();
if(a17 == 48 || a17 == 49 || a17 == 50 || a17 == 51 || a17 == 52 || a17 == 53 || a17 == 54 || a17 == 55 || a17 == 56 || a17 == 57){
year[3] = a17;
system("/bin/stty cooked");    
}
else
{
system("/bin/stty cooked");    
goto start;
}
char *yearcmd = malloc(50);
snprintf(yearcmd, 50, "sed -i '6i year=%c%c%c%c' %s/.studying/opts",year[0],year[1],year[2],year[3],user);
int birth = atoi(year);
int curyear = atoi(readFile("date +%Y"));
int age = curyear - birth;
char *agecmd = malloc(50);
snprintf(agecmd, 50, "sed -i '7i age=%d' %s/.studying/opts",age,user);
system(yearcmd);
system(agecmd);

free(yearcmd);
free(agecmd);
system("clear");

char *school = malloc(50);
char *sccmd = malloc(200);

printf("Alma mater: ");
fgets(school, 50, stdin);

snprintf(sccmd, 200, "sed -i '8i school=%s' %s/.studying/opts",school,user);
system(sccmd);
free(sccmd);
free(school);

system("clear");

printf("\nGreat! Your personal information has been stored\non your computer succesfully.");
printf("\n\n\n[ENTER]");
getchar();



}
else{

    xyy = false;
char *simppcmd = malloc(100);
snprintf(simppcmd, 150, "sed -i '2i ncheck=0' %s/.studying/opts",user);
system("clear");
getchar();
printf("\nOK! Continuing without any personal information.\nRemember that you can configure it whenever you want");
printf("\n\n\n[ENTER]");
getchar();
}

//config inf
char *echoo = malloc(200);
snprintf(echoo, 200, "sed -i '5i --------------------------------------------' %s/.studying/inf",user);

if(xyy == true){

char *naem = malloc(30);
char *naemcmd = malloc(100);
snprintf(naemcmd, 100, "sed -n 3p %s/.studying/opts | cut -f 2 -d '='",user);
naem = readFile(naemcmd);
free(naemcmd);
int length = strlen(naem);
naem[length - 1] = '\0';

char *day = malloc(30);
char *daycmd = malloc(100);
snprintf(daycmd, 100, "sed -n 4p %s/.studying/opts | cut -f 2 -d '='",user);
day = readFile(daycmd);
free(daycmd);
int lengthh = strlen(day);
day[lengthh - 1] = '\0';

char *month = malloc(30);
char *monthcmd = malloc(100);
snprintf(monthcmd, 100, "sed -n 5p %s/.studying/opts | cut -f 2 -d '='",user);
month = readFile(monthcmd);
free(monthcmd);
int lengthhh = strlen(month);
month[lengthhh - 1] = '\0';

char *year = malloc(30);
char *yearcmd = malloc(100);
snprintf(yearcmd, 100, "sed -n 6p %s/.studying/opts | cut -f 2 -d '='",user);
year = readFile(yearcmd);
free(yearcmd);
int length1 = strlen(year);
year[length1 - 1] = '\0';

char *age = malloc(30);
char *agecmd = malloc(100);
snprintf(agecmd, 100, "sed -n 7p %s/.studying/opts | cut -f 2 -d '='",user);
age = readFile(agecmd);
free(agecmd);
int length11 = strlen(age);
age[length11 - 1] = '\0';

char *school = malloc(30);
char *schoolcmd = malloc(100);
snprintf(schoolcmd, 100, "sed -n 8p %s/.studying/opts | cut -f 2 -d '='",user);
school = readFile(schoolcmd);
free(schoolcmd);
int length21 = strlen(school);
school[length21 - 1] = '\0';

char *write1 = malloc(100);
snprintf(write1, 100, "sed -i '1i Students Name: %s' %s/.studying/inf",naem,user);


char *write2 = malloc(100);
snprintf(write2, 100, "sed -i '1i Students Age: %s' %s/.studying/inf",age,user);


char *write3 = malloc(100);
snprintf(write3, 100, "sed -i '1i Students Date of Birth: %s/%s/%s' %s/.studying/inf",month,day,year,user);


char *write4 = malloc(100);
snprintf(write4, 100, "sed -i '1i Students School: %s' %s/.studying/inf",school,user);



system(write4);
free(write4);
system(write3);
free(write3);
system(write2);
free(write2);
system(write1);
free(write1);

system(echoo);

char *deletespace = malloc(100);

for(int i = 14; i >= 7; i--){

char *deletespace = malloc(100);
snprintf(deletespace, 100, "sed -i '%dd' %s/.studying/inf",i,user);
system(deletespace);

}


char *date = readFile("date +%F");
int length5 = strlen(date);
date[length5 - 1] = '\0';

char *writedate = malloc(100);
snprintf(writedate, 100, "sed -i '6i                                      Date: %s' %s/.studying/inf",date,user);
system(writedate);

char *echoooo = malloc(200);
snprintf(echoooo, 200, "sed -i '7i --------------------------------------------' %s/.studying/inf",user);
system(echoooo);


char *linenum = malloc(100);
snprintf(linenum, 100, "sed -i '10i linenum=8' %s/.studying/opts",user);
system(linenum);

}
else if(xyy == false){

char *echo1 = malloc(100);
snprintf(echo1, 200, "sed -i '1i --------------------------------------------' %s/.studying/inf",user);
system(echo1);

char *deletespace = malloc(100);

for(int i = 14; i >= 3; i--){

char *deletespace = malloc(100);
snprintf(deletespace, 100, "sed -i '%dd' %s/.studying/inf",i,user);
system(deletespace);

}

char *linenum = malloc(100);
snprintf(linenum, 100, "sed -i '10i linenum=2' %s/.studying/opts",user);
system(linenum);

}

// config date opt

char *date = malloc(30);
date = readFile("date +%F");
int lengt9 = strlen(date);
date[lengt9 - 1] = '\0';

char *writedate = malloc(100);
snprintf(writedate, 100, "sed -i '9i date=%s' %s/.studying/",date,user);
system(writedate);

// conclusion
system("clear");
printf("\nWell Done! You have successfully completed configuring 'Studying Support'.");
printf("\n\n\n[ENTER] to start");
getchar();


}

int randoment(int b1){ 
   time_t t;
   srand((unsigned) time(&t));
   int x = rand() % b1;
   return x;
}

void options(){

start:
system("clear");
printf("Options:");
printf("\n\n");
printf("\nReconfigure Your Information     (1)");
printf("\nSubjects                         (2)");
printf("\nSections                         (3)");
printf("\nReset                            (4)");
printf("\nBack                             (9)\n\n\n\n");

system("/bin/stty raw");

char a1 = getchar();
system("/bin/stty cooked");
if(a1 == 49){ // ascii dec 49 = 1
infoset();
goto start;
}
else if(a1 == 50){ // = 2
settingsubjects();
goto start;
} 
else if(a1 == 51){ // = 3
secset();
goto start;
}
else if(a1 == 52){ // = 4
renstal();
}
else if(a1 == 57){
// blank
return;
}
else if(a1 == 3){
system("clear");
printf("\nInterrupted... Have a nice day sir!\n\n");
exit(0);
}
else{
goto start;
}

}

void infoset(){

system("clear");

char *simmcmd = malloc(100);
char *user = getenv("HOME");


snprintf(simmcmd, 100, "sed -n 2p %s/.studying/opts | cut -f 2 -d '='",user);

char *check = readFile(simmcmd);
free(simmcmd);

if(strcmp(check, "1\n") == 0){



char *namecmd = malloc(100);
snprintf(namecmd, 100, "sed -n 3p %s/.studying/opts | cut -f 2 -d '='",user);
char *name = readFile(namecmd);
free(namecmd);

char *agecmd = malloc(100);
snprintf(agecmd, 100, "sed -n 7p %s/.studying/opts | cut -f 2 -d '='",user);
char *age = readFile(agecmd);
free(agecmd);

char *daycmd = malloc(100);
snprintf(daycmd, 100, "sed -n 4p %s/.studying/opts | cut -f 2 -d '='",user);
char *day = readFile(daycmd);
free(daycmd);

char *monthcmd = malloc(100);
snprintf(monthcmd, 100, "sed -n 5p %s/.studying/opts | cut -f 2 -d '='",user);
char *month = readFile(monthcmd);
free(monthcmd);

char *yearcmd = malloc(100);
snprintf(yearcmd, 100, "sed -n 6p %s/.studying/opts | cut -f 2 -d '='",user);
char *year = readFile(yearcmd);
free(yearcmd);

char *schoolcmd = malloc(100);
snprintf(schoolcmd, 100, "sed -n 8p %s/.studying/opts | cut -f 2 -d '='",user);
char *school = readFile(schoolcmd);
free(yearcmd);

int namelength = strlen(name);
name[namelength - 1] = '\0';

int daylength = strlen(day);
day[daylength - 1] = '\0';

int monthlength = strlen(month);
month[monthlength - 1] = '\0';

int yearlength = strlen(year);
year[yearlength - 1] = '\0';

int agelength = strlen(age);
age[agelength - 1] = '\0';

int schoollength = strlen(school);
age[schoollength - 1] = '\0';


start2:
system("clear");

printf("Your current information:");
printf("\n\n");
printf("\nFull Name:       %s",name);
printf("\nDate of Birth:   %s",month);
printf("/%s",day);
printf("/%s",year);
printf("\nAge:             %s",age);
printf("\nSchool:          %s",school);
printf("\n\n\n\n");

printf("Do you want to reconfigure your information? [Y]/[n] ");

char a9 = getchar();
if(a9 == 'y' || a9 == 'Y'){
infoset2(false);
}
else if(a9 == 'n' || a9 == 'N'){
return;
}
else if(a9 == 3){
system("clear");
printf("\nInterrupted... Have a nice day sir!\n\n");
exit(0);
}
else{
fflush(stdout);
system("clear");

goto start2;
}


}
else{

start1:
system("clear");
printf("\nIt seems like you haven't set your personal information.");
printf("\nAll your information is stored in your own computer.\nNo one else can reach it.");
printf("\n\n\nDo you want to configure your information? [Y]/[n] ");
char a = getchar();

if(a == 'y' || a == 'Y')
infoset2(true);
else if(a == 'n' || a == 'N'){
    return;
    }//blank
else{
    system("clear");
    goto start1;
}


}

}

void infoset2(bool xyy){

char *user = getenv("HOME");

char *del = malloc(70);

snprintf(del, 70, "sed -i '2d' %s/.studying/opts",user);

for(int i = 0; i < 7; i++){

system(del);

}

char *simppcmd = malloc(100);
snprintf(simppcmd, 150, "sed -i '2i ncheck=1' %s/.studying/opts",user);
system(simppcmd);
char *fname = malloc(100);
char *namecmd = malloc(150);
system("clear");

getchar();
printf("Full Name: ");
fgets(fname, 100, stdin);
snprintf(namecmd, 150, "sed -i '3i name=%s' %s/.studying/opts",fname,user);
system(namecmd);
free(fname);
free(namecmd);
start:

system("clear");
printf("Date of Birth\n\n");

// day
printf("Day: ");
char day[2];
system("/bin/stty raw");
char a = getchar();
if(a == 48 || a == 49 || a == 50 || a == 51 || a == 52 || a == 53 || a == 54 || a == 55 || a == 56 || a == 57){
day[0] = a;
system("/bin/stty cooked");    
}
else
{
system("/bin/stty cooked");    
goto start;
}
system("/bin/stty raw");
char a1 = getchar();
if(a1 == 48 || a1 == 49 || a1 == 50 || a1 == 51 || a1 == 52 || a1 == 53 || a1 == 54 || a1 == 55 || a1 == 56 || a1 == 57){
day[1] = a1;
system("/bin/stty cooked");    
}
else
{
system("/bin/stty cooked");    
goto start;
}
char *daycmd = malloc(50);
snprintf(daycmd, 50, "sed -i '4i day=%c%c' %s/.studying/opts",day[0],day[1],user);

system(daycmd);
free(daycmd);

// month
printf("\nMonth: ");
char month[2];
system("/bin/stty raw");
char a12 = getchar();
if(a12 == 48 || a12 == 49 || a12 == 50 || a12 == 51 || a12 == 52 || a12 == 53 || a12 == 54 || a12 == 55 || a12 == 56 || a12 == 57){
month[0] = a12;
system("/bin/stty cooked");    
}
else
{
system("/bin/stty cooked");    
goto start;
}
system("/bin/stty raw");
char a13 = getchar();
if(a13 == 48 || a13 == 49 || a13 == 50 || a13 == 51 || a13 == 52 || a13 == 53 || a13 == 54 || a13 == 55 || a13 == 56 || a13 == 57){
month[1] = a13;
system("/bin/stty cooked");    
}
else
{
system("/bin/stty cooked");    
goto start;
}
char *monthcmd = malloc(50);
snprintf(monthcmd, 50, "sed -i '5i month=%c%c' %s/.studying/opts",month[0],month[1],user);

system(monthcmd);
free(monthcmd);

//year

printf("\nYear: ");
char year[5];
system("/bin/stty raw");
char a14 = getchar();
if(a14 == 48 || a14 == 49 || a14 == 50 || a14 == 51 || a14 == 52 || a14 == 53 || a14 == 54 || a14 == 55 || a14 == 56 || a14 == 57){
year[0] = a14;
system("/bin/stty cooked");    
}
else
{
system("/bin/stty cooked");    
goto start;
}
system("/bin/stty raw");
char a15 = getchar();
if(a15 == 48 || a15 == 49 || a15 == 50 || a15 == 51 || a15 == 52 || a15 == 53 || a15 == 54 || a15 == 55 || a15 == 56 || a15 == 57){
year[1] = a15;
system("/bin/stty cooked");    
}
else
{
system("/bin/stty cooked");    
goto start;
}
system("/bin/stty raw");
char a16 = getchar();
if(a16 == 48 || a16 == 49 || a16 == 50 || a16 == 51 || a16 == 52 || a16 == 53 || a16 == 54 || a16 == 55 || a16 == 56 || a16 == 57){
year[2] = a16;
system("/bin/stty cooked");    
}
else
{
system("/bin/stty cooked");    
goto start;
}
system("/bin/stty raw");
char a17 = getchar();
if(a17 == 48 || a17 == 49 || a17 == 50 || a17 == 51 || a17 == 52 || a17 == 53 || a17 == 54 || a17 == 55 || a17 == 56 || a17 == 57){
year[3] = a17;
system("/bin/stty cooked");    
}
else
{
system("/bin/stty cooked");    
goto start;
}
char *yearcmd = malloc(50);
snprintf(yearcmd, 50, "sed -i '6i year=%c%c%c%c' %s/.studying/opts",year[0],year[1],year[2],year[3],user);
int birth = atoi(year);
int curyear = atoi(readFile("date +%Y"));
int age = curyear - birth;
char *agecmd = malloc(50);
snprintf(agecmd, 50, "sed -i '7i age=%d' %s/.studying/opts",age,user);
system(yearcmd);
system(agecmd);

free(yearcmd);
free(agecmd);
system("clear");

char *school = malloc(50);
char *sccmd = malloc(200);

printf("Alma mater: ");
fgets(school, 50, stdin);

snprintf(sccmd, 200, "sed -i '8i school=%s' %s/.studying/opts",school,user);
system(sccmd);
free(sccmd);
free(school);


if(xyy == true){

char *naem = malloc(30);
char *naemcmd = malloc(100);
snprintf(naemcmd, 100, "sed -n 3p %s/.studying/opts | cut -f 2 -d '='",user);
naem = readFile(naemcmd);
free(naemcmd);
int length = strlen(naem);
naem[length - 1] = '\0';

char *dayy = malloc(30);
char *dayycmd = malloc(100);
snprintf(dayycmd, 100, "sed -n 4p %s/.studying/opts | cut -f 2 -d '='",user);
dayy = readFile(dayycmd);
free(dayycmd);
int lengthh = strlen(dayy);
dayy[lengthh - 1] = '\0';

char *monthh = malloc(30);
char *monthhcmd = malloc(100);
snprintf(monthhcmd, 100, "sed -n 5p %s/.studying/opts | cut -f 2 -d '='",user);
monthh = readFile(monthhcmd);
free(monthhcmd);
int lengthhh = strlen(monthh);
monthh[lengthhh - 1] = '\0';

char *yearr = malloc(30);
char *yearrcmd = malloc(100);
snprintf(yearrcmd, 100, "sed -n 6p %s/.studying/opts | cut -f 2 -d '='",user);
yearr = readFile(yearrcmd);
free(yearrcmd);
int length1 = strlen(yearr);
yearr[length1 - 1] = '\0';

char *agee = malloc(30);
char *ageecmd = malloc(100);
snprintf(ageecmd, 100, "sed -n 7p %s/.studying/opts | cut -f 2 -d '='",user);
agee = readFile(ageecmd);
free(ageecmd);
int length11 = strlen(agee);
agee[length11 - 1] = '\0';

char *schooll = malloc(30);
char *schoollcmd = malloc(100);
snprintf(schoollcmd, 100, "sed -n 8p %s/.studying/opts | cut -f 2 -d '='",user);
schooll = readFile(schoollcmd);
free(schoollcmd);
int length212 = strlen(schooll);
schooll[length212 - 1] = '\0';

char *write1 = malloc(100);
snprintf(write1, 100, "sed -i '1i Students Name: %s' %s/.studying/inf",naem,user);


char *write2 = malloc(100);
snprintf(write2, 100, "sed -i '1i Students Age: %s' %s/.studying/inf",agee,user);


char *write3 = malloc(100);
snprintf(write3, 100, "sed -i '1i Students Date of Birth: %s/%s/%s' %s/.studying/inf",monthh,dayy,yearr,user);


char *write4 = malloc(100);
snprintf(write4, 100, "sed -i '1i Students School: %s' %s/.studying/inf",schooll,user);

system(write4);
free(write4);
system(write3);
free(write3);
system(write2);
free(write2);
system(write1);
free(write1);

for(int i = 14; i >= 8; i--){

char *deletespace = malloc(100);
snprintf(deletespace, 100, "sed -i '%dd' %s/.studying/inf",i,user);
system(deletespace);

}

char *linenum = malloc(10);
char *linenumcmd = malloc(100);
snprintf(linenumcmd, 100, "sed -n 10p %s/.studying/opts | cut -f 2 -d '='",user);
linenum = readFile(linenumcmd);
int length5 = strlen(linenum);
linenum[length5 - 1] = '\0';
int linenumm = atoi(linenum);

int newlinenum = linenumm + 4;

char *writelinenum = malloc(100);
snprintf(writelinenum, 100, "sed -i '10i linenum=%d' %s/.studying/opts",newlinenum,user);
system(writelinenum);

char *deleteoldnum = malloc(100);
snprintf(deleteoldnum, 100, "sed -i '11d' %s/.studying/opts",user);
system(deleteoldnum);

}
else if(xyy == false){

for(int i = 1; i <= 4; i++){

char *deletespace = malloc(100);
snprintf(deletespace, 100, "sed -i '1d' %s/.studying/inf",user);
system(deletespace);

free(deletespace);

}



char *naem = malloc(30);
char *naemcmd = malloc(100);
snprintf(naemcmd, 100, "sed -n 3p %s/.studying/opts | cut -f 2 -d '='",user);
naem = readFile(naemcmd);
free(naemcmd);
int length = strlen(naem);
naem[length - 1] = '\0';

char *dayy = malloc(30);
char *dayycmd = malloc(100);
snprintf(dayycmd, 100, "sed -n 4p %s/.studying/opts | cut -f 2 -d '='",user);
dayy = readFile(dayycmd);
free(dayycmd);
int lengthh = strlen(dayy);
dayy[lengthh - 1] = '\0';

char *monthh = malloc(30);
char *monthhcmd = malloc(100);
snprintf(monthhcmd, 100, "sed -n 5p %s/.studying/opts | cut -f 2 -d '='",user);
monthh = readFile(monthhcmd);
free(monthhcmd);
int lengthhh = strlen(monthh);
monthh[lengthhh - 1] = '\0';

char *yearr = malloc(30);
char *yearrcmd = malloc(100);
snprintf(yearrcmd, 100, "sed -n 6p %s/.studying/opts | cut -f 2 -d '='",user);
yearr = readFile(yearrcmd);
free(yearrcmd);
int length1 = strlen(yearr);
yearr[length1 - 1] = '\0';

char *agee = malloc(30);
char *ageecmd = malloc(100);
snprintf(ageecmd, 100, "sed -n 7p %s/.studying/opts | cut -f 2 -d '='",user);
agee = readFile(ageecmd);
free(ageecmd);
int length11 = strlen(agee);
agee[length11 - 1] = '\0';

char *schooll = malloc(30);
char *schoollcmd = malloc(100);
snprintf(schoollcmd, 100, "sed -n 8p %s/.studying/opts | cut -f 2 -d '='",user);
schooll = readFile(schoollcmd);
free(schoollcmd);
int length212 = strlen(schooll);
schooll[length212 - 1] = '\0';

char *write1 = malloc(100);
snprintf(write1, 100, "sed -i '1i Students Name: %s' %s/.studying/inf",naem,user);


char *write2 = malloc(100);
snprintf(write2, 100, "sed -i '1i Students Age: %s' %s/.studying/inf",agee,user);


char *write3 = malloc(100);
snprintf(write3, 100, "sed -i '1i Students Date of Birth: %s/%s/%s' %s/.studying/inf",monthh,dayy,yearr,user);


char *write4 = malloc(100);
snprintf(write4, 100, "sed -i '1i Students School: %s' %s/.studying/inf",schooll,user);

system(write4);
free(write4);
system(write3);
free(write3);
system(write2);
free(write2);
system(write1);
free(write1);

}



}

void settingsubjects(){

char a;
char *user = getenv("HOME");

start:
system("clear");

printf("Options for Subjects:\n\n");

printf("\nDisplay Subjects        (1)");
printf("\nAdd a Subject           (2)");
printf("\nReset all Subjects      (3)");
printf("\nBack                    (9)");
printf("\n\n\n\n\n");
system("/bin/stty raw");

a = getchar();

if(a == 49){
    system("/bin/stty cooked");
    subset();
    goto start;
}
else if(a == 50){
    system("/bin/stty cooked");

    char *subname = malloc(30);
    system("clear");
    printf("\nSubject Name: ");
    fgets(subname, 30, stdin);

    char *subnumcmd = malloc(100);
    snprintf(subnumcmd, 100, "sed -n 1p %s/.studying/opts | cut -f 2 -d '='",user);
    char *subnum = readFile(subnumcmd);
    
    int length = strlen(subnum);

    subnum[length - 1] = '\0';

    int subnumm = atoi(subnum);

    int lengthhh = strlen(subname);
    subname[lengthhh - 1] = '\0';

    char *writecmd = malloc(100);
    snprintf(writecmd, 100, "sed -i '%di -)%s' %s/.studying/subinf",subnumm + 1,subname,user);
    system(writecmd);
    free(writecmd);

    char *writecmd2 = malloc(100);
    snprintf(writecmd2, 100, "sed -i '1i subjectnum=%d' %s/.studying/opts",subnumm + 1,user);
    system(writecmd2);
    free(writecmd2);

    char *deletecmd = malloc(100);
    snprintf(deletecmd, 100, "sed -i '2d' %s/.studying/opts",user);
    system(deletecmd);
    free(deletecmd);

system("clear");

    printf("Your new subject has been successfully enlisted\n\n\n[ENTER]");

getchar();

    goto start;
}
else if(a == 51){
    system("/bin/stty cooked");

    start10:
    system("clear");

    printf("\nAre you sure you want to reset your subjects? [Y]/[n] ");
    char a = getchar();
    if(a == 'Y' || a == 'y'){

        char *rmcmd = malloc(100);
        snprintf(rmcmd, 100, "rm %s/.studying/subinf",user);
        system(rmcmd);
        free(rmcmd);

        char *touchcmd = malloc(100);
        snprintf(touchcmd, 100, "touch %s/.studying/subinf",user);
        system(touchcmd);
        free(touchcmd);

        char *writecmd = malloc(100);
        snprintf(writecmd, 100, "sed -i '1i subjectnum=0' %s/.studying/opts",user);
        system(writecmd);
        free(writecmd);

        char *deletecmd = malloc(100);
        snprintf(deletecmd, 100, "sed -i '2d' %s/.studying/opts",user);
        system(deletecmd);
        free(deletecmd);
        system("clear");

        char *spacecmd = malloc(100);
        snprintf(spacecmd, 100, "echo '' >> %s/.studying/subinf",user);
        for(int i = 0;i < 9;i++){
system(spacecmd);

        }
        free(spacecmd);

        printf("\nYour subjects has been reset succesfully\n\n\n[ENTER]");
        getchar();
        getchar();
        system("clear");

    }
    else{

        system("clear");
        goto start10;
    }

    goto start;
}
else if(a == 3){
    system("/bin/stty cooked");
    system("clear");
    printf("\nInterrupted... Have a nice day sir!\n\n");
    exit(0);
}
else if(a == 57){
system("/bin/stty cooked");
system("clear");
return;

}
else{
    system("/bin/stty cooked");
goto start;
}



}

void subset(){

char *user = getenv("HOME");

char *subcmd = malloc(100);
snprintf(subcmd, 100, "sed -n 1p %s/.studying/opts | cut -f 2 -d '='",user);
char *simppll = readFile(subcmd);
int lengthh = strlen(simppll);

simppll[lengthh - 1] = '\0';

int subnum = atoi(simppll);

system("clear");

printf("Your current enlisted subjects:\n");

for(int i = 1; i <= subnum; i++){

char *subject = malloc(20);
char *subjectcmd = malloc(100);
snprintf(subjectcmd, 100, "sed -n %dp %s/.studying/subinf | cut -f 2 -d ')'",i,user);
subject = readFile(subjectcmd);
int length = strlen(subject);
subject[length - 1] = '\0';
printf("\n(%s)",subject);

free(subject);
free(subjectcmd);

}

printf("\n\n\n");

getchar();

}

void secset(){

char *user = getenv("HOME");

start99:



system("clear");

printf("Options for Sections: ");
printf("\n\n");
printf("\nDisplay Sections           (1)");
printf("\nAdd a Section              (2)");
printf("\nManage Links               (3)");
printf("\nReset Sections             (4)");
printf("\nBack                       (9)");
printf("\n\n\n\n");
system("/bin/stty raw");

char a99 = getchar();

if(a99 == 49){ // 1
system("clear");
system("/bin/stty cooked");

printf("Your current sections:\n\n");
char *secnum = malloc(10);
char *secnumcmd = malloc(100);
snprintf(secnumcmd, 100, "sed -n 1p %s/.studying/pages | cut -f 2 -d '='",user);
secnum = readFile(secnumcmd);
int length = strlen(secnum);
secnum[length - 1] = '\0';

int secnumm = atoi(secnum);

for(int i = 1;i <= secnumm; i++){

char *secnamecmd = malloc(100);
char *secname = malloc(30);

snprintf(secnamecmd, 100, "sed -n %dp %s/.studying/pages | cut -f 2 -d ')'",i + 1,user);
secname = readFile(secnamecmd);
int lengthh = strlen(secname);
secname[lengthh - 1] = '\0';

printf("\n(%s)",secname);

free(secname);
free(secnamecmd);

}
printf("\n\n\n\n");
getchar();

goto start99;

}
else if(a99 == 50){ // 2
system("clear");
system("/bin/stty cooked");

char *user = getenv("HOME");

system("clear");

fflush(stdout);
printf("\nSection name: ");
char *secname = malloc(100);
char *seccmd = malloc(150);
fgets(secname, 100, stdin);

snprintf(seccmd, 150, "touch %s/.studying/%s",user,secname);
system(seccmd);

system("clear");

printf("\nThe number of links that are going to be enlisted: ");
int nummm;
scanf("%d",&nummm);

char *numcmd = malloc(100);

char *secnum = malloc(10);
char *secnumcmd = malloc(100);
snprintf(secnumcmd, 100, "sed -n 1p %s/.studying/pages | cut -f 2 -d '='",user);

secnum = readFile(secnumcmd);

int length1 = strlen(secnum);

secnum[length1 - 1] = '\0';

int secnumm1 = atoi(secnum);

char *spacecmd = malloc(100);
snprintf(spacecmd, 100, "echo '' >> %s/.studying/%s",user,secname);
for(int i = 0; i < nummm; i++){
system(spacecmd);
}
char *seccmdd = malloc(100);
char *seccmdd2 = malloc(100);
char *delseccmd = malloc(100);
snprintf(seccmdd, 100, "sed -i '1i sectionnum=%d' %s/.studying/pages",secnumm1 + 1,user);
system(seccmdd);
snprintf(delseccmd, 100, "sed -i '2d' %s/.studying/pages",user);
system(delseccmd);
snprintf(seccmdd2, 100, "sed -i '%di -)%s' %s/.studying/pages",secnumm1 + 2,secname,user);
system(seccmdd2);
snprintf(numcmd, 100, "sed -i '1i num=%d' %s/.studying/%s",nummm,user,secname);
system(numcmd);
system("clear");
getchar();
for(int i = 1; i <= nummm; i++){
    char *link = malloc(150);
    char *linkcmd = malloc(200);
    printf("%d. Link: ",i);
    fgets(link, 150, stdin);
    snprintf(linkcmd, 200, "sed -i '%di -)%s' %s/.studying/%s",i + 1,link,user,secname);
    system(linkcmd);
    free(link);
    free(linkcmd);
}
system("clear");
printf("\nExcellent! You have created a new section");
printf(" attached %d link(s) to it.",nummm);
printf("\n\n\n[ENTER]");
getchar();


goto start99;
}
else if(a99 == 51){ // 3
    system("clear");

char*secnumcmd = malloc(100);
snprintf(secnumcmd, 100, "sed -n 1p %s/.studying/pages | cut -f 2 -d '='",user);
char *secnum = malloc(20);
secnum = readFile(secnumcmd);
int length = strlen(secnum);
secnum[length - 1] = '\0';
int secnumm = atoi(secnum);

free(secnum);
free(secnumcmd);

if(secnumm == 0){
system("clear");
system("/bin/stty cooked");
printf("There isn't any sections to manage. You can create one if you want.");
getchar();
goto start99;
}

system("/bin/stty cooked");

printf("Select a section:\n\n");



for(int i = 1; i < secnumm + 1;i++){

char *secnamecmd = malloc(100);
char *secname = malloc(30);

snprintf(secnamecmd, 100, "sed -n %dp %s/.studying/pages | cut -f 2 -d ')'",i + 1,user);
secname = readFile(secnamecmd);
int lengthh = strlen(secname);
secname[lengthh - 1] = '\0';

printf("\n(%d)         -%s",i,secname);

}
printf("\n\n\n");

system("/bin/stty raw");

char a = getchar();

char *selectedseccmd = malloc(100);
char *selectedsec = malloc(30);

if(a == 3){
system("/bin/stty cooked");
system("clear");
printf("\nInterrupted... Have a nice day sir!\n\n");
exit(0);
}
system("/bin/stty cooked");
for(int i = 49; i < secnumm + 49; i++){
if(a == i){
snprintf(selectedseccmd, 100, "sed -n %dp %s/.studying/pages | cut -f 2 -d ')'",i - 47, user);
selectedsec = readFile(selectedseccmd);
}
}

star:

system("clear");

printf("Link Options: ");
printf("\n\n\n");
printf("\nChange links manually                               (1)");
printf("\nAdd a declared amount of links to this section      (2)");
printf("\nBack                                                (9)");

system("/bin/stty raw");
char ans = getchar();
system("/bin/stty cooked");

if(ans == 49){ // 11

system("clear");
system("zenity --info --text='Change the links without damaging the format [CTRL + X] to exit the editor'");
system("clear");

char *nanocmd = malloc(100);
snprintf(nanocmd, 100, "nano %s/.studying/%s",user,selectedsec);
system(nanocmd);
system("clear");
goto star;

}
else if(ans == 50){ // 22

st:

system("clear");
int linknum;

int lengthhh = strlen(selectedsec);
selectedsec[lengthhh - 1] = '\0';

char *numlink = malloc(10);
char *numlinkcmd = malloc(100);
snprintf(numlinkcmd, 100, "sed -n 1p %s/.studying/%s | cut -f 2 -d '='",user,selectedsec);

numlink = readFile(numlinkcmd);
free(numlinkcmd);

int length = strlen(numlink);

numlink[length - 1] = '\0';

int numlinkk = atoi(numlink);


printf("Enter the amount of links to add: ");
scanf("%d",&linknum);

getchar();

if(linknum > 0){
    system("clear");
for(int i = 1; i < linknum + 1; i++){
char *url = malloc(100);
char *linkcmd = malloc(200);
printf("\n%d. Link: ",i);
fgets(url, 100, stdin);
fflush(stdout);
snprintf(linkcmd, 200, "sed -i '%di -)%s' %s/.studying/%s",numlinkk + (i + 1), url,user,selectedsec);
system(linkcmd);

free(linkcmd);
free(url);

}

int newnum = numlinkk + linknum;

char *newnumm = malloc(100);
snprintf(newnumm, 100, "sed -i '1i num=%d' %s/.studying/%s",newnum,user,selectedsec);
system(newnumm);

char *delold = malloc(100);
snprintf(delold, 100, "sed -i '2d' %s/.studying/%s",user,selectedsec);
system(delold);

goto start99;
}
else if(linknum <= 0){
system("clear");
printf("Why are you making me program this path");
getchar();
goto start99;
}
else{
system("clear");
printf("Not possible");
getchar();
goto start99;
}



}
else if(ans == 57){

system("clear");
goto start99;
}
else if(ans == 3){ 
system("/bin/stty cooked");
system("clear");
printf("\nInterrupted... Have a nice day sir!\n\n");
exit(0);
}
else{
system("clear");
goto star;

}

goto start99;
}
else if(a99 == 52){ // 4
    system("clear");
system("/bin/stty cooked");

printf("\nAre you sure you want to delete your sections? [Y]/[n] ");
char a = getchar();

if(a == 'y' || a == 'Y'){

char *numm = malloc(10);
char *nummcmd = malloc(100);

snprintf(nummcmd, 100, "sed -n 1p %s/.studying/pages | cut -f 2 -d '='",user);
numm = readFile(nummcmd);

int length = strlen(numm);
numm[length - 1] = '\0';

int nummm = atoi(numm);

free(numm);
free(nummcmd);

for(int i = 2; i < nummm + 2; i++){

char *rmsec = malloc(400);
char *secnaemcmd = malloc(100);
snprintf(secnaemcmd, 100, "sed -n %dp %s/.studying/pages | cut -f 2 -d ')'",i,user);
char *secnaem = malloc(50);
secnaem = readFile(secnaemcmd);
free(secnaemcmd);
snprintf(rmsec, 400, "rm %s/.studying/%s",user,secnaem);
system(rmsec);
printf("%s\n",secnaem);
printf("\n%s",rmsec);

}

char *rmpages = malloc(100);
snprintf(rmpages, 100, "rm %s/.studying/pages",user);
system(rmpages);

free(rmpages);

char *makepages = malloc(100);
snprintf(makepages, 100, "touch %s/.studying/pages",user);
system(makepages);

free(makepages);

char *spacecmd = malloc(100);

snprintf(spacecmd, 100, "echo '' >> %s/.studying/pages",user);

for(int i = 0; i < 9; i++){

    system(spacecmd);
}

free(spacecmd);

char *writenum = malloc(100);
snprintf(writenum, 100, "sed -i '1i sectionnum=0' %s/.studying/pages",user);
system(writenum);

free(writenum);


system("clear");

printf("\nSections has been reset successfully.\n\n\n");

getchar();

}
else{
system("clear");
goto start99;
}


goto start99;
}
else if(a99 == 57){ // back
    system("clear");
system("/bin/stty cooked");
return;
}
else if(a99 == 3){ // interrupt
system("/bin/stty cooked");
system("clear");
printf("\nInterrupted... Have a nice day sir!\n\n");
exit(0);
}
else{ 
    system("clear");
system("/bin/stty cooked");
return;
}






}

void renstal(){

system("clear");

printf("Are you sure that you want to restart the whole program?");
printf("\nThis will delete all of your recorded work permanently. [Y]/[n] ");
char a = getchar();

if(a == 'y' || a == 'Y'){
    first(false);
}
else{
    //blank
}

}


void openplan(){

system("clear");
system("zenity --info --text='You can edit your weekly plan with libreoffice! Just don't forget to save before you close libreoffice'");
char *user = getenv("HOME");
char *opencmd = malloc(100);
snprintf(opencmd, 100, "sudo --background libreoffice --show weeklyplan.odt");
system(opencmd);

system("clear");
return;


}

void opensections(){

start:

system("clear");

char *user = getenv("HOME");

char *secnumcmd = malloc(100);
char *secnum = malloc(10);

snprintf(secnumcmd, 100, "sed -n 1p %s/.studying/pages | cut -f 2 -d '='",user);
secnum = readFile(secnumcmd);

int length = strlen(secnum);
secnum[length - 1] = '\0';

int secnumm = atoi(secnum);

if(secnumm == 0){

system("clear");
printf("There isn't any sections to open... If you want you can create one from options");
getchar();

return;

}

free(secnum);
free(secnumcmd);

system("clear");
printf("Select the section to open: ");

printf("\n\n");

for(int i = 1; i <= secnumm; i++){

char *secnamecmd = malloc(100);
char *secname = malloc(30);
snprintf(secnamecmd, 100, "sed -n %dp %s/.studying/pages | cut -f 2 -d ')'",i + 1, user);
secname = readFile(secnamecmd);

printf("\n(%d)        -%s",i,secname);

}
printf("\n\n\n");
system("/bin/stty raw");
char ans[2];

ans[0] = getchar();

int selectednum = atoi(ans);
int j;
for(int i = 1; i <= secnumm; i++){

if(i != selectednum){
j++;
}

}

if(j == secnumm){

system("clear");
system("/bin/stty cooked");
goto start;

}


system("/bin/stty cooked");
for(int i = 1; i <= secnumm; i++){
if(i == selectednum){
char *secnamecmd = malloc(100);
char *secname = malloc(30);
snprintf(secnamecmd, 100, "sed -n %dp %s/.studying/pages | cut -f 2 -d ')'",i+1,user);
secname = readFile(secnamecmd);
int lengthh = strlen(secname);
secname[lengthh - 1] = '\0';
free(secnamecmd);
char *linknumm = malloc(30);
char *linknummcmd = malloc(100);
snprintf(linknummcmd, 100, "sed -n 1p %s/.studying/%s | cut -f 2 -d '='",user,secname);
linknumm = readFile(linknummcmd);
free(linknummcmd);
int lengthhh = strlen(linknumm);
linknumm[lengthhh - 1] = '\0';
int linknum = atoi(linknumm);
free(linknumm);
system("clear");
openlinks(secname, linknum);
free(secname);
return;
}

}

}

void openlinks(char *secname, int linknum){

char *user = getenv("HOME");

for(int i = 2; i <= linknum + 1; i++){

char *url = malloc(30);
char *urlcmd = malloc(100);

snprintf(urlcmd, 100, "sed -n %dp %s/.studying/%s | cut -f 2 -d ')'",i,user,secname);
url = readFile(urlcmd);

char *opencmd = malloc(100);
snprintf(opencmd, 100, "firefox %s",url);
system(opencmd);
free(opencmd);

free(urlcmd);
free(url);

}
return;

}


void showinf(){
system("clear");
char *user = getenv("HOME");
char *shwo = malloc(100);
snprintf(shwo, 100, "cat %s/.studying/inf",user);
system("clear");
system(shwo);
getchar();
return;
}


void writeinf(){

start:
system("clear");

char *user = getenv("HOME");

// config date opt

char *date = malloc(30);
date = readFile("date +%F");
int lengt9 = strlen(date);
date[lengt9 - 1] = '\0';

char *olddate = malloc(30);
char *olddatecmd = malloc(100);
snprintf(olddatecmd, 100, "sed -n 9p %s/.studying/opts | cut -f 2 -d '='",user);
olddate = readFile(olddatecmd);
int length = strlen(olddate);
olddate[length - 1] = '\0';


if(strcmp(date, olddate) == 0){

char *subnum = malloc(10);
char *subnumcmd = malloc(100);
snprintf(subnumcmd, 100, "sed -n 1p %s/.studying/opts | cut -f 2 -d '='",user);
subnum = readFile(subnumcmd);
int lengthhh = strlen(subnum);
subnum[lengthhh - 1] = '\0';
int subnumm = atoi(subnum);

system("clear");

printf("What did you study??? :");
printf("\n\n");

for(int i = 1; i < (subnumm + 1); i++){
char *subname = malloc(30);
char *subnamecmd = malloc(100);
snprintf(subnamecmd, 100, "sed -n %dp %s/.studying/subinf | cut -f 2 -d ')'",i,user);
subname = readFile(subnamecmd);
int length7 = strlen(subname);
subname[length7 - 1] = '\0';

printf("\n(%d)         -%s",i, subname);

free(subname);
free(subnamecmd);

}
printf("\n\n\n\n");

system("/bin/stty raw");

char ans[2];
ans[0] = getchar();
system("/bin/stty cooked");
system("clear");
int j;
for(int i = 49; i < subnumm + 49; i++){
if(ans[0] != i){
j++;
}
}
if(j == subnumm){
    system("clear");
goto start;
}

char *selectedsub = malloc(30);

for(int i = 1; i < subnumm + 1; i++){

if((i+48) == ans[0]){
char *subname = malloc(30);
char *subnamecmd = malloc(100);
snprintf(subnamecmd, 100, "sed -n %dp %s/.studying/subinf | cut -f 2 -d ')'",i,user);
subname = readFile(subnamecmd);
int length3 = strlen(subname);
subname[length3 - 1] = '\0';

selectedsub = subname;


free(subnamecmd);

}
}


char *getlinenum = malloc(100);
char *linenumm = malloc(30);
snprintf(getlinenum, 100, "sed -n 10p %s/.studying/opts | cut -f 2 -d '='",user);
linenumm = readFile(getlinenum);
int length0 = strlen(linenumm);
linenumm[length0 - 1] = '\0';
int linenum = atoi(linenumm);

int questnum;
system("clear");
printf("How many questions have you solved?");
printf("\n\n>");
scanf("%d",&questnum);

system("clear");
int minnum;
printf("How many minutes have you been studying for?\n\n>");
scanf("%d",&minnum);


char *writesub = malloc(100);
snprintf(writesub, 100, "sed -i '%di (%s):  %d questions | %d minutes' %s/.studying/inf",linenum,selectedsub,questnum,minnum,user);
system(writesub);
linenum++;

char *replacelinenum = malloc(100);
snprintf(replacelinenum, 100, "sed -i '10i linenum=%d' %s/.studying/opts",linenum,user);

getchar();
fflush(stdout);
system(replacelinenum);


char *deleteoldlinenum = malloc(100);
snprintf(deleteoldlinenum, 100, "sed -i '11d' %s/.studying/opts",user);
system(deleteoldlinenum);
free(deleteoldlinenum);


}
else{ ////////////

char *subnum = malloc(10);
char *subnumcmd = malloc(100);
snprintf(subnumcmd, 100, "sed -n 1p %s/.studying/opts | cut -f 2 -d '='",user);
subnum = readFile(subnumcmd);
int lengthhh = strlen(subnum);
subnum[lengthhh - 1] = '\0';
int subnumm = atoi(subnum);

system("clear");

printf("What did you study? :");
printf("\n\n");

for(int i = 1; i < subnumm + 1; i++){
char *subname = malloc(30);
char *subnamecmd = malloc(100);
snprintf(subnamecmd, 100, "sed -n %dp %s/.studying/subinf | cut -f 2 -d ')'",i,user);
subname = readFile(subnamecmd);
int length7 = strlen(subname);
subname[length7 - 1] = '\0';

printf("\n(%d)         -%s",i, subname);

free(subname);
free(subnamecmd);

}
printf("\n\n\n\n");
system("/bin/stty raw");

char ans[2];
ans[0] = getchar();
system("/bin/stty cooked");
system("clear");
int j;
for(int i = 49; i < subnumm + 49; i++){
if(ans[0] != i){
j++;
}
}
if(j == subnumm){
    system("clear");
goto start;
}

char *selectedsub = malloc(30);


for(int i = 1; i < subnumm + 1; i++){

if((i+48) == ans[0]){
char *subname = malloc(30);
char *subnamecmd = malloc(100);
snprintf(subnamecmd, 100, "sed -n %dp %s/.studying/subinf | cut -f 2 -d ')'",i,user);
subname = readFile(subnamecmd);
int length3 = strlen(subname);
subname[length3 - 1] = '\0';

selectedsub = subname;

free(subnamecmd);

}
}

char *getlinenum = malloc(100);
char *linenumm = malloc(30);
snprintf(getlinenum, 100, "sed -n 10p %s/.studying/opts | cut -f 2 -d '='",user);
linenumm = readFile(getlinenum);
int length0 = strlen(linenumm);
linenumm[length0 - 1] = '\0';
int linenum = atoi(linenumm);

int questnum;
system("clear");
printf("How many questions have you solved?");
printf("\n\n>");
scanf("%d",&questnum);

system("clear");
int minnum;
printf("How many minutes have you been studying for?\n\n>");
scanf("%d",&minnum);

char *echo3 = malloc(100);
snprintf(echo3, 100, "echo '' >> %s/.studying/inf",user);
system(echo3);
linenum++;

char *echo1 = malloc(100);
snprintf(echo1, 200, "sed -i '%di --------------------------------------------' %s/.studying/inf",linenum,user);
system(echo1);
linenum++;


char *writedate = malloc(200);
snprintf(writedate, 200, "sed -i '%di                                           Date: %s' %s/.studying/inf",linenum,date,user);

system(writedate);
linenum++;

char *echo2 = malloc(100);
snprintf(echo2, 200, "sed -i '%di --------------------------------------------' %s/.studying/inf",linenum,user);
system(echo2);
linenum++;

char *writesub = malloc(100);
snprintf(writesub, 100, "sed -i '%di (%s):  %d questions | %d minutes' %s/.studying/inf",linenum,selectedsub,questnum,minnum,user);
system(writesub);
linenum++;
getchar();
fflush(stdout);
char *replacelinenum = malloc(100);
snprintf(replacelinenum, 100, "sed -i '10i linenum=%d' %s/.studying/opts",linenum,user);
system(replacelinenum);
free(replacelinenum);

char *deleteoldlinenum = malloc(100);
snprintf(deleteoldlinenum, 100, "sed -i '11d' %s/.studying/opts",user);
system(deleteoldlinenum);
free(deleteoldlinenum);


}

}


void help(){

system("clear");
char *user = getenv("HOME");
char *name = malloc(30);
char *namecmd = malloc(100);
snprintf(namecmd, 100, "sed -n 3p %s/.studying/opts | cut -f 2 -d '=' | cut -f 1 -d ' '",user);
name = readFile("name");

printf("Hi %s",name);

printf("\n\n\nI don't really know or I can't presume what can be the problem");
printf("\nThe most I can do is let you know there is a source code you can check...");
printf("\nFor other issues, you're all alone. Sorry! X)");

getchar();
system("clear");

}