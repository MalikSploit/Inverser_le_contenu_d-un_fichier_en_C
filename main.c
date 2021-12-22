#include<stdio.h>

int main()
{
  FILE *fp;
  char ch[100]; //La taille du fichier ne doit pas depasser 100 caractères.
  int i,pos;
  fp=fopen("Fichier.txt","r"); //Nom du Fichier
  if(fp==NULL)
  {
    printf("Fichier non existant !!!\n");
    return -1;
  }
  fseek(fp,0,SEEK_END);
  pos=ftell(fp);
  i=0;
  int j=0;
  while(i<pos)
  {
    i++;
    fseek(fp,-i,SEEK_END);
    ch[j]=fgetc(fp);
    printf("%c", ch[j]) ;
    j++;
  }
  fclose(fp);
  fp=fopen("Fichier.txt","w");
  for (i=0; i<pos; i++)
  {
    fputc(ch[i], fp);
  }
  printf("\n");
  return 0;
}
