#include <graphics.h>
#include <stdlib.h>
{
          int surucu = DETECT, grmod, hata_kodu; /* DETECT grafik sürücüsünü otomatik seçer */

          initgraph(&surucu, &grmod, "");       /* grafik ekranýný baþlat */

          hata_kodu = graphresult();            /* hata_kodu al  */
          if (hata_kodu != grOk)                /* hata_kodu 0 dan farklý ise baþlatma */
          {
            puts("Hata olustu.");
            puts("Grafik ekrani baslatilamiyor.");
            exit(1);
          }
          cicle(320,120,10);
          closegraph();
          getch();
}
