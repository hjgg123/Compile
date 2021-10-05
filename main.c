#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isLetter(char ch){
    return ((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z'));
}

int isDigit(char ch){
    return (ch>='0'&&ch<='9');
}

void analyze(char* tmp){
    char out[1000],ch;
    int i,j;
    for(i=0;i<1000;i++){
        ch=tmp[i];
        if(ch==' '||ch=='\n'||ch=='\t'){
            continue;
        } else if(ch==';')
            printf("Semicolon\n");
        else if(ch=='(')
            printf("LPar\n");
        else if(ch==')')
            printf("RPar\n");
        else if(ch=='{')
            printf("LBrace\n");
        else if(ch=='}')
            printf("RBrace\n");
        else if(ch=='+')
            printf("Plus\n");
        else if(ch=='*')
            printf("Mult\n");
        else if(ch=='/')
            printf("Div\n");
        else if(ch=='<')
            printf("Lt\n");
        else if(ch=='>')
            printf("Gt\n");
        else if(ch=='='){
            if(tmp[i+1]=='='){
                printf("Eq\n");
                i++;
            } else
                printf("Assign\n");
        } else if(isDigit(ch)){
            out[0]=ch;
            j=1;
            while(isDigit(tmp[i+1])){
               out[j++]=tmp[i+1];
               i++;
            }
            out[j]='\0';
            printf("Number(%s)\n",out);
        } else if(ch=='_'||isLetter(ch)){
            out[0]=ch;
            j=1;
            while(isDigit(tmp[i+1])||tmp[i+1]=='_'||isLetter(tmp[i+1])){
               out[j++]=tmp[i+1];
               i++;
            }
            out[j]='\0';
            if(strlen(out)==2&&strcmp(out,"if")==0)
                printf("If\n");
            else if(strlen(out)==4&&strcmp(out,"else")==0)
                printf("Else\n");
            else if(strlen(out)==5&&strcmp(out,"while")==0)
                printf("While\n");
            else if(strlen(out)==5&&strcmp(out,"break")==0)
                printf("Break\n");
            else if(strlen(out)==6&&strcmp(out,"return")==0)
                printf("Return\n");
            else if(strlen(out)==8&&strcmp(out,"continue")==0)
                printf("Continue\n");
            else
                printf("Ident(%s)\n",out);
        } else if(ch=='\0'){
            return;
        } else {
            printf("Err\n");
            exit(0);
        }
    }
}

int main()
{
    FILE *f;
    char file[100],tmp[1000];
    scanf("%s",file);
    f=fopen(file,"r");
    while(fgets(tmp,sizeof(tmp),f)!=NULL){
        analyze(tmp);
    }
    return 0;
}
