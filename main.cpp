/**
 * @file main.cpp
 * @brief Test per la classe Queue.
 */

 #include <iostream>
 #include "queue.hpp"
 #include <string>
 #include <cassert>
 
 using namespace std;
 
 /**
  * @brief Test dei metodi principlai della coda con tipo int.
  */
 void testPrincipaliInt(){
     cout << "----------------------------------------" << endl;
     cout << "-       TEST METODI PRINCIPALI INT     -" << endl;
     cout << "----------------------------------------" << endl;
 
     cout << "------------------------------" << endl;
     cout << "Test con coda FIFO di tipo Int" << endl;
     cout << "------------------------------" << endl;
 
     cout << "Creazione coda FIFO di tipo Int..." << endl;
     Queue<int> q;
 
     assert(q.isEmpty());
 
     cout << "Inserimento dati..." << endl;
     q.push(1);
     q.push(2);
     q.push(3);
     q.push(4);
     q.push(5);
     q.push(6);
 
     assert(!q.isEmpty());
     assert(q.size() == 6);
     assert(q.front() == 1);
     assert(q.back() == 6);
     assert(q.contains(3));
     assert(!q.contains(9));
 
     cout << "\nSize della coda: " << q.size() << endl;
 
     cout << "Dati Inseriti: " << q << endl;
 
     cout << "\n" << endl;
 
     cout << "--------------------------------------------" << endl;
     cout << "Test front() e back() in scrittura e lettura" << endl;
     cout << "--------------------------------------------" << endl;
 
     cout << "Il front della coda e': " << q.front() << endl;
     int nHead = 10;
     q.front() = nHead;
     cout << "Il front della coda e' cambiato a: " << q.front() << endl;
 
     cout << endl;
 
     cout << "Il back della coda e': " << q.back() << endl;
     int nTail = 60;
     q.back() = nTail;
     cout << "Il back della coda e' cambiato a: " << q.back() << endl;
 
     cout << "\n" << endl;
 
     cout << "----------------------------------" << endl;
     cout << "Test rimozione elementi della coda" << endl;
     cout << "----------------------------------" << endl;
 
     cout << "Rimozione di tre elementi dalla coda..." << endl;
 
     for(int i = 0; i != 3; i++){
         q.pop();
     }
 
     assert(!q.isEmpty());
     assert(q.size() == 3);
     assert(q.front() == 4);
     assert(q.back() == 60);
     assert(q.contains(5));
     assert(!q.contains(3));
 
     cout << "La coda e' vuota? " << (q.isEmpty() ? "Si" : "No") << endl;
 
     cout << "\nSize della coda dopo il ciclo: " << q.size() << endl;
 
     cout << "Dati Rimasti dopo il ciclo:" << endl;
     cout << q << endl;
 
     cout << "\n" << endl;
 
     cout << "----------------------------------" << endl;
     cout << "Test elementi contenuti nella coda" << endl;
     cout << "----------------------------------" << endl;
 
     cout << "La coda contiene l'elemento 2: " << (q.contains(2) ? "Si" : "No") << endl;
     cout << "La coda contiene l'elemento 4: " << (q.contains(4) ? "Si" : "No") << endl;
 
     cout << "\n" << endl;
 
     cout << "----------------------------------" << endl;
     cout << "Test push nella coda già esistente" << endl;
     cout << "----------------------------------" << endl;
 
     cout << "Inserimento dati..." << endl;
     q.push(69);
     q.push(10);
     q.push(21);
 
     assert(!q.isEmpty());
     assert(q.size() == 6);
     assert(q.front() == 4);
     assert(q.back() == 21);
     assert(q.contains(5));
     assert(!q.contains(9));
 
     cout << "\nSize della coda dopo l'aggiunta di nuovi elementi: " << q.size() << endl;
 
     cout << "Dati della coda dopo l'aggiunta di nuovi elementi:" << endl;
     cout << q << endl;
 
     cout << "\n" << endl;
 
     cout << "----------------------------------------" << endl;
     cout << "Test rimozione degli elementi della coda" << endl;
     cout << "----------------------------------------" << endl;
 
     cout << "Rimozione coda..." << endl;
     q.clear();
 
     assert(q.isEmpty());
     assert(q.size() == 0);
 
     cout << "La coda e' vuota? " << (q.isEmpty() ? "Si" : "No") << endl;
 
     cout << "Size coda: " << q.size() << endl;
 
     cout << "\n" << endl;
 
     cout << "----------------------------------------------------" << endl;
     cout << "Test inserimento dati dopo rimozione dati dalla coda" << endl;
     cout << "----------------------------------------------------" << endl;
 
     cout << "Inserimento dati..." << endl;
     q.push(5);
     q.push(10);
     q.push(7);
     q.push(8);
 
     assert(!q.isEmpty());
     assert(q.size() == 4);
     assert(q.front() == 5);
     assert(q.back() == 8);
     assert(q.contains(10));
     assert(!q.contains(9));
 
     cout << "\nSize della coda: " << q.size() << endl;
 
     cout << "Dati Inseriti: " << q << endl;
 
     cout << "\n" << endl;
     
     cout << "------------------------------------" << endl;
     cout << "Test Copy Constructor con nuova coda" << endl;
     cout << "------------------------------------" << endl;
 
     cout << "Creazione nuova coda const utilizzando Copy Constructor..." << endl;
 
     const Queue<int> q2(q);
 
     assert(!q2.isEmpty());
     assert(q2.size() == 4);
     assert(q2.front() == 5);
     assert(q2.back() == 8);
     assert(q2.contains(10));
     assert(!q2.contains(9));
 
     cout << "\nSize della coda: " << q2.size() << endl;
 
     cout << "Dati Inseriti: " << q2 << endl;
 
     cout << "\n" << endl;
 
     cout << "--------------------------------------------" << endl;
     cout << "Test front() e back() in solo lettura" << endl;
     cout << "--------------------------------------------" << endl;
 
     cout << "Il front della coda e': " << q2.front() << endl;
 
     cout << endl;
 
     cout << "Il back della coda e': " << q2.back() << endl;
 
     cout << "\n" << endl;
 
     cout << "---------------------------------------------" << endl;
     cout << "Test Operatore di Assegnamento con nuova coda" << endl;
     cout << "---------------------------------------------" << endl;
 
     Queue<int> q3;
 
     cout << "Inserimento dati..." << endl;
     q3.push(1);
     q3.push(2);
     q3.push(3);
     q3.push(4);
     q3.push(5);
     q3.push(6);
 
     assert(!q3.isEmpty());
     assert(q3.size() == 6);
     assert(q3.front() == 1);
     assert(q3.back() == 6);
     assert(q3.contains(3));
     assert(!q3.contains(9));
 
     cout << "\nSize della coda: " << q3.size() << endl;
 
     cout << "Dati Inseriti: " << q3 << endl;
 
     cout << "Utilizzo dell'operatore di assegnamento su q3..." << endl;
 
     q3 = q;
 
     assert(!q3.isEmpty());
     assert(q3.size() == 4);
     assert(q3.front() == 5);
     assert(q3.back() == 8);
     assert(q3.contains(10));
     assert(!q3.contains(9));
 
     cout << "\nSize della coda: " << q3.size() << endl;
 
     cout << "Dati Inseriti: " << q3 << endl;
 }
 
 /**
  * @brief Test dei metodi principlai della coda con tipo string.
  */
 
 void testPrinciapliString() {
     cout << "-------------------------------------------" << endl;
     cout << "-       TEST METODI PRINCIPALI STRING     -" << endl;
     cout << "-------------------------------------------" << endl;
 
     cout << "---------------------------------" << endl;
     cout << "Test con coda FIFO di tipo String" << endl;
     cout << "---------------------------------" << endl;
 
     cout << "Creazione coda FIFO di tipo String..." << endl;
     Queue<string> q;
 
     assert(q.isEmpty());
 
     cout << "Inserimento dati..." << endl;
     q.push("Ho");
     q.push("Perso");
     q.push("50");
     q.push("Euro");
     q.push("A");
     q.push("Montecarlo");
 
     assert(!q.isEmpty());
     assert(q.size() == 6);
     assert(q.front() == "Ho");
     assert(q.back() == "Montecarlo");
     assert(q.contains("Euro"));
     assert(!q.contains("Vinto"));
 
     cout << "\nSize della coda: " << q.size() << endl;
     cout << "Dati Inseriti: " << q << endl << "\n";
 
     cout << "--------------------------------------------" << endl;
     cout << "Test front() e back() in scrittura e lettura" << endl;
     cout << "--------------------------------------------" << endl;
 
     cout << "Il front della coda e': " << q.front() << endl;
     q.front() = "Ciao";
     cout << "Il front della coda e' cambiato a: " << q.front() << endl;
 
     cout << endl;
 
     cout << "Il back della coda e': " << q.back() << endl;
     q.back() = "Addio";
     cout << "Il back della coda e' cambiato a: " << q.back() << endl;
 
     cout << "\n" << endl;
 
     cout << "----------------------------------" << endl;
     cout << "Test rimozione elementi della coda" << endl;
     cout << "----------------------------------" << endl;
 
     cout << "Rimozione di tre elementi dalla coda..." << endl;
 
     for(int i = 0; i != 3; i++) {
         q.pop();
     }
 
     assert(!q.isEmpty());
     assert(q.size() == 3);
     assert(q.front() == "Euro");
     assert(q.back() == "Addio");
     assert(q.contains("A"));
     assert(!q.contains("Perso"));
 
     cout << "La coda e' vuota? " << (q.isEmpty() ? "Si" : "No") << endl;
     cout << "\nSize della coda dopo il ciclo: " << q.size() << endl;
     cout << "Dati Rimasti dopo il ciclo: " << q << endl << "\n";
 
     cout << "----------------------------------" << endl;
     cout << "Test elementi contenuti nella coda" << endl;
     cout << "----------------------------------" << endl;
 
     cout << "La coda contiene l'elemento '50': " << (q.contains("50") ? "Si" : "No") << endl;
     cout << "La coda contiene l'elemento 'A': " << (q.contains("A") ? "Si" : "No") << endl;
 
     cout << "\n" << endl;
 
     cout << "----------------------------------" << endl;
     cout << "Test push nella coda già esistente" << endl;
     cout << "----------------------------------" << endl;
 
     cout << "Inserimento dati..." << endl;
     q.push("Vinto");
     q.push("30");
     q.push("Oggi");
 
     assert(!q.isEmpty());
     assert(q.size() == 6);
     assert(q.front() == "Euro");
     assert(q.back() == "Oggi");
     assert(q.contains("30"));
     assert(!q.contains("Perso"));
 
     cout << "\nSize della coda dopo l'aggiunta di nuovi elementi: " << q.size() << endl;
     cout << "Dati della coda dopo l'aggiunta di nuovi elementi: " << q << endl << "\n";
 
     cout << "----------------------------------------" << endl;
     cout << "Test rimozione degli elementi della coda" << endl;
     cout << "----------------------------------------" << endl;
 
     cout << "Rimozione coda..." << endl;
     q.clear();
 
     assert(q.isEmpty());
     assert(q.size() == 0);
 
     cout << "La coda e' vuota? " << (q.isEmpty() ? "Si" : "No") << endl;
     cout << "Size coda: " << q.size() << endl << "\n";
 
     cout << "----------------------------------------------------" << endl;
     cout << "Test inserimento dati dopo rimozione dati dalla coda" << endl;
     cout << "----------------------------------------------------" << endl;
 
     cout << "Inserimento dati..." << endl;
     q.push("Capo");
     q.push("Sono");
     q.push("Stanco");
     q.push("No");
     q.push("Lavoro");
     q.push("Piu'");
 
     assert(!q.isEmpty());
     assert(q.size() == 6);
     assert(q.front() == "Capo");
     assert(q.back() == "Piu'");
     assert(q.contains("Stanco"));
     assert(!q.contains("Vecchio"));
 
     cout << "\nSize della coda: " << q.size() << endl;
     cout << "Dati Inseriti: " << q << endl << "\n";
 
     cout << "------------------------------------" << endl;
     cout << "Test Copy Constructor con nuova coda" << endl;
     cout << "------------------------------------" << endl;
 
     const Queue<string> q2(q);
 
     assert(!q2.isEmpty());
     assert(q2.size() == 6);
     assert(q2.front() == "Capo");
     assert(q2.back() == "Piu'");
     assert(q2.contains("Stanco"));
     assert(!q2.contains("Vecchio'"));
 
     cout << "\nSize della coda: " << q2.size() << endl;
     cout << "Dati Inseriti: " << q2 << endl << "\n";
 
     cout << "--------------------------------------------" << endl;
     cout << "Test front() e back() in solo lettura" << endl;
     cout << "--------------------------------------------" << endl;
 
     cout << "Il front della coda e': " << q2.front() << endl;
     cout << "Il back della coda e': " << q2.back() << endl << "\n";
 
     cout << "---------------------------------------------" << endl;
     cout << "Test Operatore di Assegnamento con nuova coda" << endl;
     cout << "---------------------------------------------" << endl;
 
     Queue<string> q3;
 
     cout << "Inserimento dati..." << endl;
     q3.push("Non");
     q3.push("Si");
     q3.push("Puo'");
     q3.push("Dire");
     q3.push("Croccante?");
 
     assert(!q3.isEmpty());
     assert(q3.size() == 5);
     assert(q3.front() == "Non");
     assert(q3.back() == "Croccante?");
     assert(q3.contains("Dire"));
     assert(!q3.contains("Crunchy"));
 
     q3 = q;
 
     assert(!q3.isEmpty());
     assert(q3.size() == 6);
     assert(q3.front() == "Capo");
     assert(q3.back() == "Piu'");
     assert(q3.contains("Stanco"));
     assert(!q3.contains("Vecchio'"));
 
     cout << "\nSize della nuova coda: " << q3.size() << endl;
     cout << "Dati Inseriti: " << q3 << endl;
 }
 
 /**
  * @brief Struct per testare un tipo custom con Queue.
  */
 
 struct Film{
 
     string titolo;
     int anno;
 
     Film(const string& t, int a) : titolo(t), anno(a) {}
 
     bool operator==(const Film& other) const {
         return titolo == other.titolo && anno == other.anno;
     }
 
     friend ostream& operator<<(ostream& os, const Film& f){
         os << "\n" << "Titolo: " << f.titolo << " Data Rilascio: " << f.anno;
         return os;
     }
 };
 
 /**
  * @brief Test dei metodi principlai della coda con tipo custom.
  */
 
 void testTipoCustom(){
     cout << "------------------------------------------------" << endl;
     cout << "-       TEST METODI PRINCIPALI TIPO CUSTOM     -" << endl;
     cout << "------------------------------------------------" << endl;
 
     cout << "---------------------------------" << endl;
     cout << "Test con coda FIFO di tipo custom" << endl;
     cout << "---------------------------------" << endl;
 
     cout << "Creazione coda FIFO di tipo custom..." << endl;
     Queue<Film> f;
 
     assert(f.isEmpty());
 
     cout << "Inserimento dati..." << endl;
 
     f.push(Film("Interstellar", 2014));
     f.push(Film("The Godfather", 1972));
     f.push(Film("Deadpool", 2016));
     f.push(Film("2001: A Space Odyssey", 1968));
     f.push(Film("Cars", 2006));
     f.push(Film("Inglorious Bastards", 2009));
 
     assert(!f.isEmpty());
     assert(f.size() == 6);
     assert(f.front() == Film("Interstellar", 2014));
     assert(f.back() == Film("Inglorious Bastards", 2009));
     assert(f.contains(Film("2001: A Space Odyssey", 1968)));
     assert(!f.contains(Film("The Marvels", 2023)));
 
     cout << "\nSize della coda: " << f.size() << endl;
 
     cout << "Dati Inseriti: " << f<< endl;
 
     cout << "\n" << endl;
 
     cout << "--------------------------------------------" << endl;
     cout << "Test front() e back() in scrittura e lettura" << endl;
     cout << "--------------------------------------------" << endl;
 
     cout << "Il front della coda e': " << f.front() << endl;
     Film nHead = Film("Avengers: Infinity War", 2018);
     f.front() = nHead;
     cout << "Il front della coda e' cambiato a: " << f.front() << endl;
 
     cout << endl;
 
     cout << "Il back della coda e': " << f.back() << endl;
     Film nTail = Film("Avengers: Endgame", 2019);
     f.back() = nTail;
     cout << "Il back della coda e' cambiato a: " << f.back() << endl;
 
     cout << "\n" << endl;
 
     cout << "----------------------------------" << endl;
     cout << "Test rimozione elementi della coda" << endl;
     cout << "----------------------------------" << endl;
 
     cout << "Rimozione di tre elementi dalla coda..." << endl;
 
     for(int i = 0; i != 3; i++){
         f.pop();
     }
 
     assert(!f.isEmpty());
     assert(f.size() == 3);
     assert(f.front() == Film("2001: A Space Odyssey", 1968));
     assert(f.back() == Film("Avengers: Endgame", 2019));
     assert(f.contains(Film("Cars", 2006)));
     assert(!f.contains(Film("The Marvels", 2023)));
 
     cout << "La coda e' vuota? " << (f.isEmpty() ? "Si" : "No") << endl;
 
     cout << "\nSize della coda dopo il ciclo: " << f.size() << endl;
 
     cout << "Dati Rimasti dopo il ciclo:" << endl;
     cout << f << endl;
 
     cout << "\n" << endl;
 
     
     cout << "----------------------------------" << endl;
     cout << "Test elementi contenuti nella coda" << endl;
     cout << "----------------------------------" << endl;
 
     cout << "La coda contiene l'elemento [Avengers: Endgame, 2019]: " << (f.contains(Film("Avengers: Endgame", 2019)) ? "Si" : "No") << endl;
     cout << "La coda contiene l'elemento [The Marvels, 2023]: " << (f.contains(Film("The Marvels", 2023)) ? "Si" : "No") << endl;
 
     cout << "\n" << endl;
 
     cout << "----------------------------------" << endl;
     cout << "Test push nella coda già esistente" << endl;
     cout << "----------------------------------" << endl;
 
     cout << "Inserimento dati..." << endl;
     f.push(Film("The Dark Knight", 2008));
     f.push(Film("Barbenheimer", 2023));
     f.push(Film("A Minecraft Movie", 2025));
 
     assert(!f.isEmpty());
     assert(f.size() == 6);
     assert(f.front() == Film("2001: A Space Odyssey", 1968));
     assert(f.back() == Film("A Minecraft Movie", 2025));
     assert(f.contains(Film("Cars", 2006)));
     assert(!f.contains(Film("The Marvels", 2023)));
 
     cout << "\nSize della coda dopo l'aggiunta di nuovi elementi: " << f.size() << endl;
 
     cout << "Dati della coda dopo l'aggiunta di nuovi elementi:" << endl;
     cout << f << endl;
 
     cout << "\n" << endl;
 
     cout << "----------------------------------------" << endl;
     cout << "Test rimozione degli elementi della coda" << endl;
     cout << "----------------------------------------" << endl;
 
     cout << "Rimozione coda..." << endl;
     f.clear();
 
     assert(f.isEmpty());
     assert(f.size() == 0);
 
     cout << "La coda e' vuota? " << (f.isEmpty() ? "Si" : "No") << endl;
 
     cout << "Size coda: " << f.size() << endl;
 
     cout << "\n" << endl;
 
     cout << "----------------------------------------------------" << endl;
     cout << "Test inserimento dati dopo rimozione dati dalla coda" << endl;
     cout << "----------------------------------------------------" << endl;
 
     cout << "Inserimento dati..." << endl;
     f.push(Film("Sharknado", 2013));
     f.push(Film("Sharknado 2", 2014));
     f.push(Film("Sharknado 3", 2015));
     f.push(Film("Sharknado: The 4th Awakens", 2016));
 
     assert(!f.isEmpty());
     assert(f.size() == 4);
     assert(f.front() == Film("Sharknado", 2013));
     assert(f.back() == Film("Sharknado: The 4th Awakens", 2016));
     assert(f.contains(Film("Sharknado 3", 2015)));
     assert(!f.contains(Film("Sharknado 5: Global Swarming", 2017)));
 
     cout << "\nSize della coda: " << f.size() << endl;
 
     cout << "Dati Inseriti: " << f<< endl;
 
     cout << "\n" << endl;
     
     cout << "------------------------------------" << endl;
     cout << "Test Copy Constructor con nuova coda" << endl;
     cout << "------------------------------------" << endl;
 
     cout << "Creazione nuova coda const utilizzando Copy Constructor..." << endl;
 
     const Queue<Film> f2(f);
 
     assert(!f.isEmpty());
     assert(f.size() == 4);
     assert(f.front() == Film("Sharknado", 2013));
     assert(f.back() == Film("Sharknado: The 4th Awakens", 2016));
     assert(f.contains(Film("Sharknado 3", 2015)));
     assert(!f.contains(Film("Sharknado 5: Global Swarming", 2017)));
 
     cout << "\nSize della coda: " << f2.size() << endl;
 
     cout << "Dati Inseriti: " << f2 << endl;
 
     cout << "\n" << endl;
 
     cout << "--------------------------------------------" << endl;
     cout << "Test front() e back() in solo lettura" << endl;
     cout << "--------------------------------------------" << endl;
 
     cout << "Il front della coda e': " << f2.front() << endl;
 
     cout << endl;
 
     cout << "Il back della coda e': " << f2.back() << endl;
 
     cout << "\n" << endl;
 
     cout << "---------------------------------------------" << endl;
     cout << "Test Operatore di Assegnamento con nuova coda" << endl;
     cout << "---------------------------------------------" << endl;
 
     Queue<Film> f3;
 
     cout << "Inserimento dati..." << endl;
     f3.push(Film("Star Wars: The Phantom Menace", 1999));
     f3.push(Film("Star Wars: Attack of the Clones", 2002));
     f3.push(Film("Star Wars: Revenge of the Sith", 2005));
     f3.push(Film("Star Wars: A New Hope", 1977));
     f3.push(Film("Star Wars: The Empire Strikes Back", 1980));
     f3.push(Film("Star Wars: Return of the Jedi", 1983));
 
     assert(!f3.isEmpty());
     assert(f3.size() == 6);
     assert(f3.front() == Film("Star Wars: The Phantom Menace", 1999));
     assert(f3.back() == Film("Star Wars: Return of the Jedi", 1983));
     assert(f3.contains(Film("Star Wars: A New Hope", 1977)));
     assert(!f3.contains(Film("Star Wars: The Force Awakens", 2015)));
 
     cout << "\nSize della coda: " << f3.size() << endl;
 
     cout << "Dati Inseriti: " << f3 << endl;
 
     cout << "Utilizzo dell'operatore di assegnamento su f3..." << endl;
 
     f3 = f;
 
     assert(!f.isEmpty());
     assert(f.size() == 4);
     assert(f.front() == Film("Sharknado", 2013));
     assert(f.back() == Film("Sharknado: The 4th Awakens", 2016));
     assert(f.contains(Film("Sharknado 3", 2015)));
     assert(!f.contains(Film("Sharknado 5: Global Swarming", 2017)));
 
     cout << "\nSize della coda: " << f3.size() << endl;
 
     cout << "Dati Inseriti: " << f3 << endl;
 }
 
 /**
  * @brief Test dell'inserimento elementi tramite const_iterator.
  */
 
 void testIteratori(){
 
     cout << "-----------------------------" << endl;
     cout << "-       TEST ITERATORI      -" << endl;
     cout << "-----------------------------" << endl;
 
     cout << "Creazione coda FIFO di tipo Int..." << endl;
     Queue<int> q;
 
     assert(q.isEmpty());
 
     cout << "Inserimento dati..." << endl;
     q.push(1);
     q.push(2);
     q.push(3);
     q.push(4);
     q.push(5);
 
     assert(!q.isEmpty());
     assert(q.size() == 5);
     assert(q.front() == 1);
     assert(q.back() == 5);
     assert(q.contains(3));
     assert(!q.contains(9));
 
     cout << "\nSize della coda: " << q.size() << endl;
 
     cout << "Dati Inseriti: " << q << endl;
 
     cout << "Creazione seconda coda FIFO di tipo Int..." << endl;
     Queue<int> q2;
 
     assert(q2.isEmpty());
 
     cout << "Inserimento dati..." << endl;
     q2.push(6);
     q2.push(7);
     q2.push(8);
 
     assert(!q2.isEmpty());
     assert(q2.size() == 3);
     assert(q2.front() == 6);
     assert(q2.back() == 8);
     assert(q2.contains(7));
     assert(!q2.contains(9));
 
     cout << "\nSize della seconda coda: " << q2.size() << endl;
 
     cout << "Dati Inseriti: " << q2 << endl;
 
     cout << "--------------------------------------------------------------------------------" << endl;
     cout << "Test inserimento di tutti gli elementi da coda q a coda q2 utilizzando Iteratori" << endl;
     cout << "--------------------------------------------------------------------------------" << endl;
 
     cout << "Inserimento di tutti i dati di q in q2..." << endl;
 
     q2.push(q.begin(), q.end());
 
     assert(!q2.isEmpty());
     assert(q2.size() == 8);
     assert(q2.front() == 6);
     assert(q2.back() == 5);
     assert(q2.contains(4));
     assert(!q2.contains(9));
 
     cout << "\nSize della seconda coda dopo la fine del ciclo: " << q2.size() << endl;
 
     cout << "Dati della seconda coda dopo la fine del ciclo: ";
     cout << q2 << endl;
 
     cout << "La prima coda rimane invariata" << endl;
     cout << "\nSize della prima coda dopo la fine del ciclo: " << q.size() << endl;
 
     cout << "Dati della prima coda dopo la fine del ciclo: ";
     cout << q << endl;
 
     cout << "\n" << endl;
 
     cout << "----------------------------------------------------------------------------------" << endl;
     cout << "Test inserimento di parte degli elementi da coda q2 a coda q utilizzando Iteratori" << endl;
     cout << "----------------------------------------------------------------------------------" << endl;
 
     Queue<int>::const_iterator it_begin = q2.begin();
 
     for(int i = 0; i != 2; i++){
         it_begin++;
     }
 
     Queue<int>::const_iterator it_end = it_begin;
 
     for(int i = 0; i!= 3; i++){
         it_end++;
     }
 
     cout << "Inserimento dal 3* al 5* elemento della coda q in q2" << endl;
 
     q.push(it_begin, it_end);
 
     cout << "\nSize della prima coda dopo la fine del ciclo: " << q.size() << endl;
 
     cout << "Dati della prima coda dopo la fine del ciclo: ";
     cout << q << endl;
 }
 
 /**
  * @brief Predicato che verifica se un intero è dispari.
  */
 
 struct IsOdd {
     bool operator()(int x) const {
         return x % 2 != 0;
     }
 };
 
 /**
  * @brief Funtore che eleva al quadrato un intero.
  */
 
 struct Square {
     int operator()(int x) const {
         return x * x;
     }
 };
 
 /**
  * @brief Predicato che verifica se la lughezza di una sringa è <= 4.
  */
 
 struct IsShort {
     bool operator()(const string& s) const {
         return s.size() <= 4;
     }
 };
 
 /**
  * @brief Funtore che trasforma una stringa in maiuscolo.
  */
 
 struct ToUpper {
     string operator()(const string& s) const {
         string result = s;
         for (size_t i = 0; i < result.size(); ++i) {
             result[i] = toupper(result[i]);
         }
         return result;
     }
 };
 
 /**
  * @brief Predicato che verifica se la data di rilascio di un film è minore dell'anno 2000.
  */
 
 struct IsOldFilm {
     bool operator()(const Film& f) const {
         return f.anno < 2000;
     }
 };
 
 /**
  * @brief Funtore che aggiunge prefisso "Classic - " al titolo di un film.
  */
 
 struct Classic {
     Film operator()(const Film& f) const {
         return Film("Classic - " + f.titolo, f.anno);
     }
 };
 
 /**
  * @brief Test del metodo transformif su code di tipo int, string e custom.
  */
 
 void testTransformif(){
 
     cout << "--------------------------------------" << endl;
     cout << "-       TEST METODO TRANSFORMIF      -" << endl;
     cout << "--------------------------------------" << endl;
 
     cout << "-------------------------------" << endl;
     cout << "     Test Transformif Int      " << endl;
     cout << "-------------------------------" << endl;
 
     cout << "Creazione coda FIFO di tipo Int..." << endl;
     Queue<int> q;
 
     assert(q.isEmpty());
 
     cout << "Inserimento dati..." << endl;
     q.push(1);
     q.push(2);
     q.push(3);
     q.push(4);
     q.push(5);
 
     assert(!q.isEmpty());
     assert(q.size() == 5);
     assert(q.front() == 1);
     assert(q.back() == 5);
     assert(q.contains(3));
     assert(!q.contains(9));
 
     cout << "\nSize della coda: " << q.size() << endl;
 
     cout << "Dati Inseriti: " << q << endl;
 
     cout << "Prima di transformif (int): " << q << endl;
     transformif(q, IsOdd(), Square());
     cout << "Dopo transformif (int): " << q << endl;
 
     cout << "----------------------------------" << endl;
     cout << "     Test Transformif String      " << endl;
     cout << "----------------------------------" << endl;
 
     cout << "Creazione coda FIFO di tipo String..." << endl;
     Queue<string> q2;
 
     assert(q2.isEmpty());
 
     cout << "Inserimento dati..." << endl;
 
     q2.push("Oggi");
     q2.push("Ho");
     q2.push("Vinto");
     q2.push("30");
     q2.push("Euro");
     q2.push("Alle");
     q2.push("Macchinette");
 
     assert(!q2.isEmpty());
     assert(q2.size() == 7);
     assert(q2.front() == "Oggi");
     assert(q2.back() == "Macchinette");
     assert(q2.contains("Euro"));
     assert(!q2.contains("Perso"));
 
 
     cout << "\nPrima di transformif (string): " << q2 << endl;
     transformif(q2, IsShort(), ToUpper());
     cout << "Dopo transformif (string): " << q2 << endl;
 
     cout << "---------------------------------------" << endl;
     cout << "     Test Transformif Tipo Custom      " << endl;
     cout << "---------------------------------------" << endl;
 
     cout << "Creazione coda FIFO di tipo Film..." << endl;
     Queue<Film> f;
 
     assert(f.isEmpty());
 
     cout << "Inserimento dati..." << endl;
 
     f.push(Film("Pulp Fiction", 1994));
     f.push(Film("Inception", 2010));
     f.push(Film("The Matrix", 1999));
     f.push(Film("Dune", 2021));
 
     assert(!f.isEmpty());
     assert(f.size() == 4);
     assert(f.front() == Film("Pulp Fiction", 1994));
     assert(f.back() == Film("Dune", 2021));
     assert(f.contains(Film("The Matrix", 1999)));
     assert(!f.contains(Film("The Marvels", 2023)));
 
     cout << "\nPrima di transformif (Film): " << f << endl;
     transformif(f, IsOldFilm(), Classic());
     cout << "Dopo transformif (Film): " << f << endl;
 
     cout << "-----------------------------------------" << endl;
     cout << "     Test Transformif Su Coda Vuota      " << endl;
     cout << "-----------------------------------------" << endl;
 
     cout << "Creazione coda FIFO di tipo Int..." << endl;
     Queue<int> q3;
 
     assert(q3.isEmpty());
 
     cout << "\nLa coda e' vuota? " << (q3.isEmpty() ? "Si" : "No") << endl;
 
     transformif(q, IsOdd(), Square());
 
     assert(q3.isEmpty());
 
     cout << "Transformif su coda vuota completato senza errori" << endl;

     cout << endl;
 }
 
 /**
  * @brief Test delle eccezioni su front(), back() e pop() con coda vuota.
  */
 
 void testCodaVuota() {
     cout << "-----------------------------------------------------------" << endl;
     cout << "-       TEST front(), back() e pop() CON CODA VUOTA       -" << endl;
     cout << "-----------------------------------------------------------" << endl;
 
     cout << "Creazione coda FIFO di tipo Int..." << endl;
     Queue<int> q;
 
     assert(q.isEmpty());
     assert(q.size() == 0);
 
     cout << "\nLa coda e' vuota? " << (q.isEmpty() ? "Si" : "No") << endl;
 
     cout << "---------------------------" << endl;
     cout << "Test front() con coda vuota" << endl;
     cout << "---------------------------" << endl;
 
     try {
         q.front();
         assert(false);
     } catch (const out_of_range& e) {
         cout << "Eccezione: " << e.what() << endl;
     }
 
     cout << "--------------------------" << endl;
     cout << "Test back() con coda vuota" << endl;
     cout << "--------------------------" << endl;
 
     try {
         q.back();
         assert(false);
     } catch (const out_of_range& e) {
         cout << "Eccezione: " << e.what() << endl;
     }
 
     cout << "-------------------------" << endl;
     cout << "Test pop() con coda vuota" << endl;
     cout << "-------------------------" << endl;
 
     try {
         q.pop();
         assert(false);
     } catch (const out_of_range& e) {
         cout << "Eccezione: " << e.what() << endl;
     }
 }
 
 int main()
 {
     testPrincipaliInt();
 
     cout << "\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
     cout << "\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n" << endl;
 
     testPrinciapliString();
 
     cout << "\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
     cout << "\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n" << endl;
 
     testTipoCustom();
 
     cout << "\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
     cout << "\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n" << endl;
 
     testIteratori();
 
     cout << "\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
     cout << "\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n" << endl;
 
     testTransformif();
 
     cout << "\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
     cout << "\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n" << endl;
 
     testCodaVuota();
 
     return 0;
 }