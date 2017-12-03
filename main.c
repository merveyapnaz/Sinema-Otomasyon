#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char Red[5][50];
    char Green[5][50];
    char Blue[5][50];
}Salonlar;

typedef enum
{
   ogrenci=1,
   tam
}ucretler;

int main()
{
    Salonlar salon;
    ucretler ucret;
    int hasilat;
    int koltuksayaci=0;

    char sifre[20];
    printf("Menuyu gormek icin sifreyi giriniz.(5idiots)\n");
    gets(sifre);

    FILE *fp1;
    fp1=fopen("Sifre.txt","r");
    int i;
    char b;
    if(sifre[1] == '\0' )
    {
        printf("Sifre girmediniz!");
             exit(0);
    }

    for(i=0;i<strlen(sifre);i++)
    {


         b = (char) (((int) sifre[i]-65+6)%26+65);
         if(b!=getc(fp1))
         {
             printf("Yanlis sifre");
             exit(0);
         }


    }
    fclose(fp1);
    FILE *fp5;
    fp5=fopen("hasilat.txt","r");

            fscanf(fp5,"%d",&hasilat);

    fclose(fp5);

    int menuSecimi;
    printf("SINEMA REZARVASYON SISTEMINE HOSGELDINIZ.\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("Rezervasyon yapmak icin 1'e\n");
    printf("Hasilati ogrenmek icin 2'e\n");
    printf("Izlenme miktarlari icin 3'e basiniz\n");
    scanf("%d",&menuSecimi);
    char salonsecimi;
    int matine;
    Salonlar *psalon;
    psalon = &salon;
    int j,k;
    int koltuknum=0;
    int odemesekli;
    int tutar=0;

    FILE *fp2;
    fp2=fopen("koltukred.txt","r");
    for(j=0;j<5;j++)
    {
        for(k=0;k<50;k++)
        {
            psalon->Red[j][k] = getc(fp2) ;
        }

    }
    fclose(fp2);

    FILE *fp3;
    fp3=fopen("koltukgreen.txt","r");
    for(j=0;j<5;j++)
    {
        for(k=0;k<50;k++)
        {
            psalon->Green[j][k] = getc(fp3) ;
        }

    }
    fclose(fp3);

    FILE *fp4;
    fp4=fopen("koltukblue.txt","r");
    for(j=0;j<5;j++)
    {
        for(k=0;k<50;k++)
        {
            psalon->Blue[j][k] = getc(fp4) ;
        }

    }
    fclose(fp4);

    switch(menuSecimi)
    {
        case 1:
            printf("\nHangi salona rezarvasyon yapmak istersiniz?\n(Red icin R/r\nGreen icin G/g\nBlue icin B/b)\n");
            scanf(" %c",&salonsecimi);
            switch(salonsecimi)
            {
                case 'R':
                case 'r':

                    printf("\n\nKac numarali matinede rezarvasyon yapmak istersiniz?\n(1/2/3/4/5)");
                    scanf("%d",&matine);
                    for(i=matine-1;i<matine;i++)
                    {
                        for(j=0;j<50;j++)
                        {
                            if(psalon->Red[i][j] == '0')
                            {
                                psalon->Red[i][j] = 1;
                                koltuknum = j;
                                break;
                            }
                            else
                                continue;

                        }
                    }

                    printf("\nOdeme sekliniz?\n(Ogrenci icin 1'e Tam icin 2'ye basin)\n");
                    scanf(" %d",&odemesekli);
                    if(odemesekli == ogrenci )
                    {
                        tutar = 20;
                        hasilat+=tutar;
                    }
                    else if(odemesekli == tam)
                    {
                        tutar = 30;
                        hasilat+=tutar;
                    }
                    printf("\nRezarvasyon Bilgileri:\n");
                    printf("\n\n%d numarali koltuga rezerve yapilmistir.\n",koltuknum+1);
                    printf("\nUcretiniz %d liradir.\n",tutar);

                    fp2=fopen("koltukred.txt","w+");
                    for(j=0;j<5;j++)
                    {
                        for(k=0;k<50;k++)
                        {
                            if(psalon->Red[j][k] == '0')
                            fputc('0',fp2);
                        else
                            fputc('1',fp2);
                        }

                    }
                    fclose(fp2);

                    fp5=fopen("hasilat.txt","w+");

                    fprintf(fp5,"%d",hasilat);

                    fclose(fp5);



                break;
                break;

                case 'G':
                case 'g':
                    printf("\n\nKac numarali matinede rezarvasyon yapmak istersiniz?\n(1/2/3/4/5)");
                    scanf("%d",&matine);
                    for(i=matine-1;i<matine;i++)
                    {
                        for(j=0;j<50;j++)
                        {
                            if(psalon->Green[i][j] == '0')
                            {
                                psalon->Green[i][j] = 1;
                                koltuknum = j;
                                break;
                            }
                            else
                                continue;

                        }
                    }

                    printf("\nOdeme sekliniz?\n(Ogrenci icin 1'e Tam icin 2'ye basin)\n");
                    scanf(" %d",&odemesekli);
                    if(odemesekli == ogrenci )
                    {
                        tutar = 20;
                        hasilat+=tutar;
                    }
                    else if(odemesekli == tam)
                    {
                        tutar = 30;
                        hasilat+=tutar;
                    }
                    printf("\nRezarvasyon Bilgileri:\n");
                    printf("\n\n%d numarali koltuga rezerve yapilmistir.\n",koltuknum+1);
                    printf("\nUcretiniz %d liradir.\n",tutar);

                    fp3=fopen("koltukgreen.txt","w+");
                    for(j=0;j<5;j++)
                    {
                        for(k=0;k<50;k++)
                        {
                            if(psalon->Green[j][k] == '0')
                            fputc('0',fp2);
                        else
                            fputc('1',fp2);
                        }

                    }
                    fclose(fp3);
                    fp5=fopen("hasilat.txt","w+");

                    fprintf(fp5,"%d",hasilat);

                    fclose(fp5);


                    break;
                    break;

                case 'B':
                case 'b':
                    printf("\n\nKac numarali matinede rezarvasyon yapmak istersiniz?\n(1/2/3/4/5)");
                    scanf("%d",&matine);
                    for(i=matine-1;i<matine;i++)
                    {
                        for(j=0;j<50;j++)
                        {
                            if(psalon->Blue[i][j] == '0')
                            {
                                psalon->Blue[i][j] = 1;
                                koltuknum = j;
                                break;
                            }
                            else
                                continue;

                        }
                    }

                    printf("\nOdeme sekliniz?\n(Ogrenci icin 1'e Tam icin 2'ye basin)\n");
                    scanf(" %d",&odemesekli);
                    if(odemesekli == ogrenci )
                    {
                        tutar = 20;
                        hasilat+=tutar;
                    }
                    else if(odemesekli == tam)
                    {
                        tutar = 30;
                        hasilat+=tutar;
                    }
                    printf("\nRezarvasyon Bilgileri:\n");
                    printf("\n\n%d numarali koltuga rezerve yapilmistir.\n",koltuknum+1);
                    printf("\nUcretiniz %d liradir.\n",tutar);

                    fp4=fopen("koltukblue.txt","w+");
                    for(j=0;j<5;j++)
                    {
                        for(k=0;k<50;k++)
                        {
                            if(psalon->Blue[j][k] == '0')
                            fputc('0',fp4);
                        else
                            fputc('1',fp4);
                        }

                    }
                    fclose(fp4);
                    fp5=fopen("hasilat.txt","w+");

                    fprintf(fp5,"%d",hasilat);

                    fclose(fp5);

                    break;
                    break;

                default:
                    printf("\nYanlis secim yaptiniz.\n");
                    break;

            }
            break;

        case 2:
            fp5=fopen("hasilat.txt","r");

            fscanf(fp5,"%d",&hasilat);

            fclose(fp5);
            printf("\nToplam hasilat : %d TL.\n",hasilat);

            break;

        case 3:
            printf("\nRed salonu izin izlenme bilgileri,\n");
            for(i=0;i<5;i++)
            {
                for(j=0;j<50;j++)
                {
                    if(psalon->Red[i][j] == '1')
                    {
                        koltuksayaci++;

                    }
                }
                printf("\n%d. Matinede %d izlenme.\n",i+1,koltuksayaci);
                koltuksayaci=0;
            }
            printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");

            printf("\nGreen salonu izin izlenme bilgileri,\n");
            for(i=0;i<5;i++)
            {
                for(j=0;j<50;j++)
                {
                    if(psalon->Green[i][j] == '1')
                    {
                        koltuksayaci++;

                    }
                }
                printf("\n%d. Matinede %d izlenme.\n",i+1,koltuksayaci);
                koltuksayaci=0;
            }

            printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");

            printf("\nBlue salonu izin izlenme bilgileri,\n");
            for(i=0;i<5;i++)
            {
                for(j=0;j<50;j++)
                {
                    if(psalon->Blue[i][j] == '1')
                    {
                        koltuksayaci++;

                    }
                }
                printf("\n%d. Matinede %d izlenme.\n",i+1,koltuksayaci);
                koltuksayaci=0;
            }

            break;

        default:
            break;

    }
    }

