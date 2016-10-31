# VMM-SIFT
Image Retrieval - Podobnost obrázků (SIFT)

Instalace, pokud nechcete řešit knihovnu libpng:

1. otevřít demo_ASIFT_src/io_png/libs/makefile.libpng
2. upravit URL ke knihovně (LIBPNG_URL = http://downloads.sourceforge.net/project/libpng/libpng14/older-releases/1.4.3/libpng-1.4.3.tar.xz)
3. make LOCAL_LIBS=1
4. profit!

Příkaz pro porovnání:

./demo_ASIFT_src/demo_ASIFT input/adam1.png input/adam2.png output/adamImgOutVert.png output/adamImgOutHori.png output/adamMatching.txt output/adamKeys1.txt output/adamKeys2.txt
