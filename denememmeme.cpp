#include <graphics.h>
#include <stdlib.h>
{
          int surucu = DETECT, grmod, hata_kodu; /* DETECT grafik s�r�c�s�n� otomatik se�er */

          initgraph(&surucu, &grmod, "");       /* grafik ekran�n� ba�lat */

          hata_kodu = graphresult();            /* hata_kodu al  */
          if (hata_kodu != grOk)                /* hata_kodu 0 dan farkl� ise ba�latma */
          {
            puts("Hata olustu.");
            puts("Grafik ekrani baslatilamiyor.");
            exit(1);
          }
          cicle(320,120,10);
          closegraph();
          getch();
}
