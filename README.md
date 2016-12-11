# VMM-SIFT
Image Retrieval - Podobnost obrázků (SIFT)

Cílem projektu bylo vytvoření aplikace, která měří podobnost vstupního obrázku s databází obrázků na základě analýzy extrahovaných SIFT deskriptorů. 

Z extrahovaných deskriptorů jsme vytvořili clustery pomocí euklidovské vzdálenosti mezi nimi. V těchto clusterech jsme nalezli centrální prvek, který reprezentuje cluster.

Porovnání obrázků bylo řešeno algoritmem SQFD, který porovná clustery dvou obrázků a vypočte podobnostní míru.
Podle podobnostní míry vstupního obrázku oproti obrázkům z databáze seřadíme obrázky v databázi tak, aby nejpodobnější obrázky byli první.

Výsledky, které dostáváme, jsou dobré díky omezení výběru hodnoty ε pouze na (1, 2, 3, 4, 5). Jiné hodnoty ε buď snižují kvalitu výsledku, nebo výrazně prodlužují dobu běhu.

