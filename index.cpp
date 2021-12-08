#include "fstream"
#include "iostream"
#include "windows.h"
using namespace std;

int time;
fstream notes;
string help = "Lector de notas v1.0\n\nUso: \n\nNOTES [archivo] [/?] \n\narchivo: Archivo para leer (opcional). Si no se especifica, la opci\xA2n por defecto ser\xA0\n \"notes.txt\". \nSi este archivo no existe, ocurrir\xA0 un error. \n\n/?: Muestra esta ayuda. \n\n";
const int len = 14;
int tones[len] = {
    523,
    587,
    659,
    698,
    783,
    880,
    983,
    1047,
    1174,
    1318,
    1396,
    1568,
    1760,
    1975
};
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

int main(int argc, char *argv[]) {
    


    SetConsoleTitle(__TEXT("Lector de notas v1.0"));
    system("cls");
    cout << "Bienvenido al lector de notas. \n\n";
    if (argc == 2 && strcmp(argv[1], "/?") == 0) {
        cout << help << endl;
        cout << ("Presiona una tecla para continuar. ");
        system("pause>nul");
        cout << ("\n\n");

        return EXIT_SUCCESS;
        
    }

    if (!argv[1]) {
        notes.open("notes.txt", ios::in);
    } else if (!(argc == 2 && strcmp(argv[1], "/?") == 0)) { 
        notes.open(argv[1], ios::in);
    }
	if (!notes) {
        SetConsoleTextAttribute(console, 12); 
        cout <<("\a");
        
        if (!argv[1]) {
            
            cout << "\n\xAD" << "Archivo \"notes.txt\" no encontrado! \n\nAseg\xA3rate de que existe y de que est\xA0 en la misma carpeta que este programa. \n";
        } else if (argv[1]) { 
            cout << "\n\xAD" << "Archivo \"" << argv[1] << "\" no encontrado! \n\nAseg\xA3rate de que existe y de que est\xA0 en la misma carpeta que este programa. \n"; // ...se emite el error con ese. 
        }
        SetConsoleTextAttribute(console, 7); // Vuelve a letras blancas. 
        cout <<("\nPresiona cualquier tecla para salir. \n");
        system("pause>nul");
        cout <<("\n");

        return EXIT_FAILURE; // Cierra el programa con errores. 
		
	} else {
		char ch;
        cout << "\xA8" << "Durante cu\xA0ntos milisegundos quieres que se toquen todas las notas? ";
        cin >> time;
		while (1) {
           
			notes >> ch;
            //cout << (ch);
			if (notes.eof()) {
                //cout <<("\nArchivo terminado");
                break;
            }

			switch (ch) {
                case 'c': Beep(tones[0], time); break;
                case 'd': Beep(tones[1], time); break;
                case 'e': Beep(tones[2], time); break;
                case 'f': Beep(tones[3], time); break;
                case 'g': Beep(tones[4], time); break;
                case 'a': Beep(tones[5], time); break;
                case 'b': Beep(tones[6], time); break;
                case 'C': Beep(tones[7], time); break;
                case 'D': Beep(tones[8], time); break;
                case 'E': Beep(tones[9], time); break;
                case 'F': Beep(tones[10], time); break;
                case 'G': Beep(tones[11], time); break;
                case 'A': Beep(tones[12], time); break;
                case 'B': Beep(tones[13], time); break;
            }
		}

	}
	notes.close();

    cout <<("\nPresiona cualquier tecla para salir. ");
    system("pause>nul");
    
	return EXIT_SUCCESS;
}