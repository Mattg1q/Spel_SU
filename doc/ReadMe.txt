Bygga projektet

Förutsättningar:
C++-kompilator (g++)
SDL2 och SDL2_image installerade
make installerat

Bygginstruktioner:
Stå i projektets rotkatalog (där Makefile ligger) och kör:
make

Det körbara programmet skapas i:
build/debug/

Köra spelet

Windows:
build\debug\game.exe

Linux / macOS:
./build/debug/game

Spelbeskrivning
Spelet är ett 2D-arkadspel som fungerar som en demonstration av spelmotorn.

Spelaren: Grön figur längst ner (player.png).
Fiende: Faller ner från toppen (enemy.png).
Mekanik: När spelaren fångar en fiende, eller när en fiende når botten, spawnas en ny fiende på slumpmässig x-position.

Kontroller
Vänsterpil eller A: Flytta spelaren åt vänster.
Högerpil eller D: Flytta spelaren åt höger.
Stäng fönstret: Avsluta spelet.

Testning
Rörelse: Kontrollera att spelaren reagerar på piltangenterna samt A/D.
Kollision: Fånga ett fallande objekt och verifiera att det ersätts av ett nytt.
Resurser: Verifiera att bilderna laddas från resources/images/.
Avslut: Stäng fönstret och kontrollera att programmet avslutas korrekt.