/*
    make base_converter
    ./base_converter
    make base_converter && ./base_converter
*/

#include "base.h"

String characters = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
/*Berechnet die Länge der Zahl nach der Konvertierung. 
@param number Zahl, die in der Zielbasis dargestellt werden soll.
@param base Zielbasis, in der die Zahl number dargestellt werden soll.
@return eine Zahl die angibt wie lange die Zahl zur Zielbasis sein soll.
*/
int length_for_base(int number, int base){
    if(number == 0) {
        return 1;
    }
    double needed_chars = log(number + 1)/log(base);
    int length = ceil(needed_chars);
    return length;
}
/*
    Gibt einen dynamisch allokierte String zurueck, der so viele Zeichen hat wie noetig sind um die Zahl in der Zielbasis darzustellen. 
    @param number Zahl, die in der Zielbasis dargestellt wird.
    @param base Zielbasis, in der die Zahl number dargestellt werden soll.  
    @return Eine Zeichenkette mit der noetigen Anzahl an Stellen mit '#' initialisiert.
*/
String get_string_for_number_and_base(int number, int base){
    int length = length_for_base(number, base);
    String s = xcalloc(sizeof(char), length + 1);
    for(int i = 0; i< length; i++){
        s[i] = '#';
    }
    return s;
}

/*
    Gibt die Zahl number in der Zielbasis als Zeichenkette zurueck.
    @param number Zahl, die in der Zielbasis dargestellt wird.
    @param base Zielbasis, in der die Zahl number dargestellt werden soll.  
    @return String der die Zahl in der Zielbasis enthaelt.
*/
String convert_to_base(int number, int base){
    int len = length_for_base(number, base);
    printiln(len);
    String s = get_string_for_number_and_base(number, base);
    printsln(s);
    for (int i = len - 1; i >= 0; i--) {
        s_set(s, i, s_get(characters, number % base));
        number /= base;
    }
    printsln(s);
	//char c = s_get(characters, 12);
    return s;
}

/*
    Schoen formatierte Ausgabe der Zahl, die zu konvertieren ist, sowie des Ergebnisses.
    @param number Zahl, die in der Zielbasis dargestellt wird.
    @param base Zielbasis, in der die Zahl number dargestellt werden soll.  
*/
void print_convert(int number, int base){
    printf("Convert %4d to base %2d: %s\n", number, base, convert_to_base(number, base));
}
/*
    Testfaelle fuer convert_to_base.
*/
void test_convert_to_base(){
        
    print_convert(0, 2);
    test_equal_s(convert_to_base(0, 2), "0");
    
    print_convert(16, 3);
    test_equal_s(convert_to_base(16, 3), "121");
    
    print_convert(16, 16);
    test_equal_s(convert_to_base(16, 16), "10");
    
    print_convert(100, 10);
    test_equal_s(convert_to_base(100, 10), "100");
    
    print_convert(0, 2);
    test_equal_s(convert_to_base(0, 2), "0");
    
    print_convert(10, 16);
    test_equal_s(convert_to_base(10, 16), "A");
    
    print_convert(100, 2);
    test_equal_s(convert_to_base(100, 2), "1100100");
    
    print_convert(20, 5);
    test_equal_s(convert_to_base(20, 5), "40");
    
    print_convert(1300300300, 36);
    test_equal_s(convert_to_base(1300300300, 36), "LI5Y4S");
}

/**/

/*
Wandelt die gegebene Zahl in eine Binärzahl aus
@param number Nimmt eine Ganzzahl im Dezimalsystem.
@return Gibt die Zahl als Binärzahl in der Konsole aus.
*/
void print_bits(int number){
    String bits = convert_to_base(number, 2);
    printf("0x%4x : %16s\n", number, bits);
}


void bit_operations(){
    printsln("Bitmagic");
    //Es werden zwei Zahlen genommen und dann wird der Bitoperator und darauf angewendet. 
    //Damit bleiben werden alle Stellen an den die Zahlen a und b in Binär eine 1 haben 1 und alle anderen Stellen werden zu 0. 
    printsln("&");
    int a = 0xaf;
    int b = 0xa5;
    
    int c = a & b;
    print_bits(a);
    print_bits(b);
    print_bits(c);
    
    //Hier wird der Bitoperator oder verwendet. 
    //Bei diesem werden alle Stellen an denen eine der Zahlen in Binär eine 1 hat zu 1. 
    printsln("|");
    a = 0xb1;
    b = 0x93;
    c = a | b;
    print_bits(a);
    print_bits(b);
    print_bits(c);
    
    //Hier wird der Bitoperator entweder oder verwendet. 
    //Die Funktioniert wie Addition im F2 Körper, also 0+0=0, 0+1=1 und 1+1=0. 

    printsln("^");
    a = 0xb1;
    b = 0x33;
    c = a ^ b;
    print_bits(a);
    print_bits(b);
    print_bits(c);
    
    //Hier werden die Bitoperatoren left shift << und right shift >> verwendet. 
    //Die beiden Operatoren "verschieben" die binäre Zahl. 
    //Das bedeutet bei right shift wird die letzte Stelle der Binärzahl gekürtzt. 
    //Bei left shift wird eine neue Stelle nach der bisher letzten Stelle hinzugefügt.
    
    printsln("<< und >>");
    a = 0x30;
    print_bits(a);
    a <<= 2;
    print_bits(a);
    a >>= 3;
    print_bits(a);
    
}

/*
Die Funktion gibt den Wahrheitswert true zurück insofern die Zahl an der sovielten Stelle eine 1 hat.
@param value nimmt eine Ganzzahl im Dezimalsystem auf die die Funktion angewendet werden soll. 
@param index gibt die Stelle der Binärzahl an die überprüft werden soll.
@return Gibt einen Wahrheitswert zurück der angibt, ob die Binärzahl an der Stelle index eine 1 hat.
*/
bool get_bit(int value, int index ) {
    //Erstellt eine Zahl, die in Binär nur an der Stelle des Index eine 1 hat.
    int index_binary = 1;
    for (int i = 0; i < index; i++) {
        index_binary *= 2;
    }
    //value und index_binary werden mit einem Bit & verglichen. 
    //Daraus ergibt sich entweder 0, falls an der Stelle index keine 1 in binär ist. 
    int and = value & index_binary;
    return and != 0;
}


/*
Die Funktion setzt den Bit an der Stelle index auf den Wert 0,1 abhängig von bit. 
@param die Zahl, die verändert werden soll
@param die Stelle an der die Zahl verändert werden soll
@param der Wert auf den die Stelle gesetzt werden soll true=1 und false=0
*/
int set_bit(int value, int index, bool bit){
    //Erstellt eine Zahl, die in Binär nur an der Stelle des Index eine 1 hat.
    int index_binary = 1;
    for (int i = 0; i < index; i++) {
        index_binary *= 2;
    }
    if (bit) {
        value = value | index_binary;
    } else {
        if (get_bit(value, index)) {
            value = value ^ index_binary;
        }
    }
    return value;
}


/*
    Testfaelle fuer get_bit und set_bit
*/
void test_get_set_bit(){
    int a = 0x77;
    //print_bits(a);
    
    test_equal_b(get_bit(a,0), true);
    test_equal_b(get_bit(a,1), true);
    test_equal_b(get_bit(a,2), true);
    test_equal_b(get_bit(a,3), false);
    test_equal_b(get_bit(a,4), true);
    test_equal_b(get_bit(a,5), true);
    test_equal_b(get_bit(a,6), true);
    test_equal_b(get_bit(a,7), false);
    test_equal_b(get_bit(a,8), false);
    
    a = set_bit(a, 0, false);
    test_equal_i(a, 0x76);
    a = set_bit(a, 0, true);
    test_equal_i(a, 0x77);
    a = set_bit(a, 5, false);
    test_equal_i(a, 0x57);
    a = set_bit(a, 1, true);
    test_equal_i(a, 0x57);
    a = set_bit(a, 3, false);
    test_equal_i(a, 0x57);
}

//todo
int extract_bits(int value, int start, int end){

    return value;
}

/*
    Testfaelle fuer extract_bits.
*/
void test_extract_bits(){
    test_equal_s(convert_to_base(extract_bits(0x1805, 0, 4),2), "101");
    test_equal_s(convert_to_base(extract_bits(0x1404, 8, 16),2), "10100");
    test_equal_s(convert_to_base(extract_bits(0x1701, 12, 16),2), "1");
    test_equal_s(convert_to_base(extract_bits(0x1503, 1, 9),2), "10000001");
    test_equal_s(convert_to_base(extract_bits(0x1602, 0, 16),2), "1011000000010");
    test_equal_s(convert_to_base(extract_bits(0xABCD, 16, 0),2), "0");
    test_equal_s(convert_to_base(extract_bits(0xABCD, -1, 3),2), "0");
    test_equal_s(convert_to_base(extract_bits(0xABCD, 4, 34),2), "0");
}

int main(void){
    test_convert_to_base();
    /* Entfernen Sie Kommentierung der nachfolgenden Zeilen fuer Aufgabe 3 */
    printsln("------------------------------");
    bit_operations();
    printsln("------------------------------");
    test_get_set_bit();
    //test_extract_bits();
    return 0;
}