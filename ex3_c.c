#include <stdio.h>
#include <string.h>

#define TXT 1024
#define WORD 30
////////////////////////////////
int gimtria_c(char word ){
int count =0;

    if(word>=65 && word<=90){
        count+= word-64;
    }
    if(word>=97 && word<=122){
        count+= word-96;
}

return count;}
//////////////////////////////////////
int gimtria(char *word , int len){
int count =0;

for(int i=0;i<len;i++){
    if(word[i]>=65 && word[i]<=90){
        count+= word[i]-64;
    }
    if(word[i]>=97 && word[i]<=122){
        count+= word[i]-96;
}}
return count;}
////////////////////////////////
void atbashReverse(char *word ,int len , char *temp2){

int j=len-1;
char a;
for(int i=0;i<len;i++){
    temp2[j]=word[i];
    j--;
}
}
/////////////////////////////////////
void atbash(char *word ,int len , char *tempF){
int j=0;
char a;
int i;
for(i=0;i<len;i++){
    //if this is capital leter 
    if(word[i]>=65 && word[i]<=90){
        
        a=90-(word[i] -65);
    }
    //if this is small leter 
    if(word[i]>=97 && word[i]<=122){
        a=122-(word[i] -97);
    }
   
    tempF[j]=a;
    j++;
    
}

}
/////////////////////////////////
int main (){

char word [WORD];
char txt [TXT+1];

char ch;
int i ;
//get the word
for (i=0; i<WORD; i++){
	scanf("%c" , &ch);
	if(ch == ' ' || ch == '\t' || ch == '\n') break;
	word[i] = ch;
	}
    word[i]='\0';

//get the text
for (i=0; i<TXT; i++){
	scanf("%c" , &ch);
	if(ch == '~') break;
	txt[i] = ch;	
	}
  txt[i]='\0';
  scanf("%c" , &ch);
 
///////////////////////////
printf("Gematria Sequences: ");
char wordPrint [strlen(txt)];
int geo = gimtria(word,strlen(word));
int first=0;
  for(int i=0; i<strlen(txt); i++) {
    int count = 0;
    int k=0;
    int len=strlen(word);
     memset(wordPrint, 0,strlen(txt) );
     
     for(int j=i; count < geo  &&j<j+len &&j<strlen(txt);j++) {
        
            if(gimtria_c(txt[j])==0){
                len++;
            }    
            count += gimtria_c(txt[j]);
            if(count==0){
                break;
            }
            wordPrint[k]=txt[j];
            k++;
            
            if(count == geo){
                if(first==1){
                    printf("~");
                }
                printf("%s",wordPrint);
                first=1;
                break;
            } 
            }
            }
/////////////////////////////////
first=0;
printf("\nAtbash Sequences: ");
char atb [strlen(word)+1];
atb[strlen(word)+1]='\0';
char rev [strlen(word)+1];
rev[strlen(word)+1]='\0';

atbash(word, strlen(word),atb);
atbashReverse(atb, strlen(word) ,rev);

 for(int i=0; i<strlen(txt); i++) {
    
    int br=0;
    int bf=0;
    int r=0;
    int a=0;

    int rw=0;
    int aw=0;

    char wordPrintR [strlen(txt)+1];
    char wordPrintA [strlen(txt)+1];
    memset(wordPrintR, '0', strlen(txt));
    memset(wordPrintA, '0', strlen(txt));
        
    for(int j=i; j<strlen(txt)  &&  (br==0||bf==0); j++) {
        if(txt[j]==32){
            if(br==0){
              
                wordPrintR[rw]=txt[j]; 
                rw++;
                continue;}
            if(bf==0)  {
                wordPrintA[aw]=atb[a];
                aw++; 
                continue;}
              }
        if(txt[j]== rev[r] && br==0 ){   
            wordPrintR[rw]=rev[r];
            rw++;
            r++;
        }
        else{
            br=1;
        }
        if(txt[j]== atb[a] && bf==0 ){
            wordPrintA[aw]=atb[a];
            aw++;
             a++;     
        }
        else{
            bf=1;
        }
        if(r==strlen(word)){
            wordPrintR[rw]='\0';
            if(first==1){
                    printf("~");}
                first=1;
            printf("%s" , wordPrintR);
           r=0;
         
        }
        
        if(a==strlen(word)){
            wordPrintA[aw]='\0';
            if(first==1){
                    printf("~");
                }
                first=1;
            printf("%s" ,wordPrintA);
            a=0;
         
        }
    }
}
printf("\n");
//////////////////////////////////////////
first=0;
printf("Anagram Sequences: ");
char printWord [strlen(word)+1];
printWord[strlen(word)+1]='\0';
int p=0;
char temp[strlen(word)];
int numOfDig=strlen(word);
strcpy(temp,word);
int find=0;
int out =0;
// int path=0;
for(int i=0; i<strlen(txt); i++) {
    if(txt[i]==32){
        continue;
    }
    out=0;
    strcpy(temp,word);
    numOfDig=strlen(word);
    p=0;
      for(int j=i; j<strlen(txt)&& out==0 ; j++) {
         if(txt[j]==32){
                 printWord[p]=txt[j]; 
                 p++;
                  continue;
              }
          for (int k = 0; k < strlen(word) ; k++){
            
                if(txt[j]==temp[k]){
                    find=1;
                    printWord[p]=txt[j];
                    temp[k]= '~';
                    break;}
      }
   
      if(find==1){

            numOfDig=numOfDig-1;
            p++;
            find=0;
      }
      else{
            out=1;
            strcpy(temp,word);
            numOfDig=strlen(word);
            p=0;

      }
      
      if(numOfDig==0){
           printWord[strlen(word)]='\0';
          if(first==1){
                    printf("~");
                }
                first=1;
        printf("%s",printWord);
        numOfDig=strlen(word);
      }
        
}
}
return 0;
}