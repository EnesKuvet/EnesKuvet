#include <stdio.h>
#include <stdlib.h>

char metin[],sifre[],kucukHarf;
	int j,anahtar;
	FILE *dosya;


void alt()
{
	printf("\n");
}

void sifreleYazdir()
{
	               printf("METIN GIR:");
	gets(metin);
	gets(metin);
	               printf("ANAHTAR GIR:");
	               scanf("%d",&anahtar);
	for(j=0;j<strlen(metin);j++)

	{
	            if(isalpha(metin[j]))
	       {
	    	kucukHarf = tolower(metin[j]);
			kucukHarf -= 'a';
			kucukHarf = (kucukHarf + anahtar)%26;
			kucukHarf += 'a';
			sifre[j]=kucukHarf;
	       }

	             else
		   {
			sifre[j]=metin[j];
		   }

	}


    dosya=fopen("sifrelenenkelimeler.rtf","a");
                    fprintf(dosya,"SIFRELI KELIME: %s",sifre);
                    fprintf(dosya,"\n YUKARIDAKI KOD ICIN KAYDIRMA ANAHTARI = ");
                    fprintf(dosya,"%d\n\n\n",anahtar);
    fclose(dosya);

    alt();alt();alt();
}


    void temizle()
{
	int secim,sayac=0;
	char icindekiler;

	   printf("!!! SIFRELER TEMIZLENECEKTIR !!!!\n\n");
	   printf("SILMEK ICIN '1' E BASINIZ:");
	   scanf("%d",&secim);

	        alt();alt();

	if(secim==1)

	{
	dosya=fopen("sifrelenenkelimeler.rtf","w");
	fclose(dosya);

	   printf("'' SIFRELENENKELIMELER '' ADLI WORD DOSYASINDAKI SIFRELER BASARIYLA SILINDI !! TEYIT EDIN !!");
    }

   else
   {

   }

   alt();alt();alt();
}



  void desifre()
{
	char icindekiler;
	char desifre_icin_kelime[10000];
	char desifre[10000];
	dosya = fopen("sifrelenenkelimelr.rtf","r");

	    do
	      {
	       icindekiler=getc(dosya);
	       printf("%c",icindekiler);
	      }


	while(icindekiler!=EOF);
	fclose(dosya);

	                      printf("DESIFRE ETMEK ISTEDIGIN KELIMEYI GIR:");
	gets(desifre_icin_kelime);
    gets(desifre_icin_kelime);
	                      printf("DESIFRE ETMEK ISTEDIGIN KELIMENIN ANAHTARINI GIR:");
                          scanf("%d",&anahtar);


	printf("DESIFRE OLAN KELIME SUDUR: ");

	for(j=0;j<strlen(desifre_icin_kelime);j++)
	{
		if(isalpha(desifre_icin_kelime[j]))
	    {
	    	kucukHarf = tolower(desifre_icin_kelime[j]);
			kucukHarf -= 'a';
			kucukHarf -= anahtar;
			while (kucukHarf < 0)
			{
                kucukHarf += 26;
            }

			kucukHarf = kucukHarf % 26;
			kucukHarf += 'a';
			printf("%c",kucukHarf);

	    }

	    else
		{
			 printf("%c",desifre_icin_kelime[j]);
		}

     }


    alt();alt();alt();



}


int main()
{
	int islem;

	anamenu:
	printf("^^^^^^^^"); alt();
	printf("1. SIFRELE"); alt();
	printf("2. DESIFRE ET "); alt();
	printf("3. DOSYADAKI SIFRELENENLERI SIL"); alt();
	printf("4. CIKIS"); alt();
	printf("^^^^^^^^"); alt();alt();


	printf("YAPCAGIN ISLEMIN SAYISINI GIR:");
	scanf("%d",&islem);

	switch(islem)
	{
		                  case 1:
			              sifreleYazdir();
                          printf("Algoritma Kisa Sinav 1.2 Adli Klasordeki '' Sifrelenenkelimeler '' Adli Word Dosyasina Sifrelendi !! TEYIT EDIN !!\n\n");
			              goto anamenu;
                          break;

		           case 2:
			       desifre();
			       goto anamenu;
			       break;
		                                case 3:
			                            temizle();
			                            goto anamenu;
			                            break;

		                          case 4:
                                  exit(1);
			                      break;
		    default:
			printf("GECERSIZ BIR DEGER GIRDINIZ TEKRAR GIRINIZ:"); alt();alt();alt();
			goto anamenu;
			break;


	}

}

