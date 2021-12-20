#include <stdio.h>
#include <string.h>

#define TXT 1024
#define WORD 30
////////////////////////////////
int gimtria_c(char w ){
int count =0;

    if(w>=65 && w<=90){
        count+= w-64;
    }
    if(w>=97 && w<=122){
        count+= w-96;
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
void atbashReverse(char *word ,int len , char *t1){
int j=len-1;
for(int i=0;i<len;i++)
{
    t1[j]=word[i];
    j--;
}
}
/////////////////////////////////////
void atbash(char *word ,int len , char *t2){
int j=0;
char c;
int i;
for(i=0;i<len;i++){
    
    if(word[i]>=65 && word[i]<=90){
        
        c=90-(word[i] -65);
    }
    
    if(word[i]>=97 && word[i]<=122){
        c=122-(word[i] -97);
    }
    t2[j]=c;
    j++;
    
}
}
/////////////////////////////////
int main ()
{

char word [WORD];
char text [TXT+1];
char c;
int i ;

for (i=0; i<WORD; i++){
	scanf("%c" , &c);
	if(c == ' ' || c == '\t' || c == '\n') 
    break;
	word[i] = c;
	}
    word[i]='\0';
for (i=0; i<TXT; i++){
	scanf("%c" , &c);
	if(c == '~') break;
	text[i] = c;	
	}
  text[i]='\0';
  scanf("%c" , &c);
///////////////////////////
printf("Gematria Sequences: ");
char wordPrint [strlen(text)];
int geo = gimtria(word,strlen(word));
int f=0;
  for(int i=0; i<strlen(text); i++) {
    int count = 0;
    int k=0;
    int len=strlen(word);
     memset(wordPrint, 0,strlen(text) );
     for(int j=i; count < geo  &&j<j+len &&j<strlen(text);j++) {
        
            if(gimtria_c(text[j])==0){
                len++;
            }    
            count += gimtria_c(text[j]);
            if(count==0){
                break;
            }
            wordPrint[k]=text[j];
            k++;
            
            if(count == geo){
                if(f==1){
                    printf("~");
                }
                printf("%s",wordPrint);
                f=1;
                break;
            } 
            }
            }
/////////////////////////////////
f=0;
printf("\nAtbash Sequences: ");
char atb [strlen(word)+1];
atb[strlen(word)+1]='\0';
char rev [strlen(word)+1];
rev[strlen(word)+1]='\0';

atbash(word, strlen(word),atb);
atbashReverse(atb, strlen(word) ,rev);

 for(int i=0; i<strlen(text); i++) {
    int b1=0;
    int b2=0;
    int r=0;
    int a=0;
    int rw=0;
    int aw=0;
    char w1 [strlen(text)+1];
    char w2 [strlen(text)+1];
    memset(w1, '0', strlen(text));
    memset(w2, '0', strlen(text));
        
    for(int j=i; j<strlen(text)  &&  (b1==0||b2==0); j++) {
        if(text[j]==32){
            if(b1==0){
              
               w1[rw]=text[j]; 
                rw++;
                continue;}
            if(b2==0)  {
                w2[aw]=atb[a];
                aw++; 
                continue;}
              }
        if(text[j]== rev[r] && b1==0 ){   
            w1[rw]=rev[r];
            rw++;
            r++;
        }
        else{
            b1=1;
        }
        if(text[j]== atb[a] && b2==0 ){
            w2[aw]=atb[a];
            aw++;
             a++;     
        }
        else{
            b2=1;
        }
        if(r==strlen(word)){
            w1[rw]='\0';
            if(f==1){
                    printf("~");}
                f=1;
            printf("%s" , w1);
           r=0;
         
        }
        
        if(a==strlen(word)){
            w2[aw]='\0';
            if(f==1){
                    printf("~");
                }
                f=1;
            printf("%s" ,w2);
            a=0;
         
        }
    }
}

//////////////////////////////////////////
f=0;
printf("\nAnagram Sequences: ");
char ans [strlen(word)+1];
ans[strlen(word)+1]='\0';
int p=0;
char temp[strlen(word)];
int numOfDigit=strlen(word);
strcpy(temp,word);
int x=0;
int y =0;

for(int i=0; i<strlen(text); i++) {
    if(text[i]==32){
        continue;
    }
     y=0;
    strcpy(temp,word);
    numOfDigit=strlen(word);
    p=0;
      for(int j=i; j<strlen(text)&&  y==0 ; j++) {
         if(text[j]==32){
                 ans[p]=text[j]; 
                 p++;
                  continue;
              }
          for (int k = 0; k < strlen(word) ; k++){
            
                if(text[j]==temp[k]){
                    x=1;
                   ans[p]=text[j];
                    temp[k]= '~';
                    break;}
      }
   
      if(x==1){

            numOfDigit=numOfDigit-1;
            p++;
           x=0;
      }
      else{
             y=1;
            strcpy(temp,word);
            numOfDigit=strlen(word);
            p=0;

      }
      
      if(numOfDigit==0){
           ans[strlen(word)]='\0';
          if(f==1){
                    printf("~");
                }
                f=1;
        printf("%s",ans);
        numOfDigit=strlen(word);
      }
        
}
}
return 0;
}