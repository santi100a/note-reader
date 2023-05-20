#include "fstream"
#include "iostream"
#include "string"
#include "makesound.h"

#include "windows.h"

int duration; // time
std::fstream notes;
std::string help = "Note reader v1.0.1\n\nUsage: \n\nNOTES [file [/?]";

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
    std::cout << "Bienvenido al lector de notas. \n\n";
    if (argc == 2 && strcmp(argv[1], "/?") == 0) {
        std::cout << help << std::endl;
        std::cout << ("Presiona una tecla para continuar. ");
        system("pause>nul");
        std::cout << ("\n\n");

        return EXIT_SUCCESS;
        
    }

    if (!argv[1]) {
        notes.open("notes.txt", std::ios::in);
    } else if (!(argc == 2 && strcmp(argv[1], "/?") == 0)) { 
        notes.open(argv[1], std::ios::in);
    }
	if (!notes) {
        SetConsoleTextAttribute(console, 12); 
        std::cout <<("\a");
        
        if (!argv[1]) {
            
            std::cout << "\n\xAD" << "Archivo \"notes.txt\" no encontrado! \n\nAseg\xA3rate de que existe y de que est\xA0 en la misma carpeta que este programa. \n";
        } else if (argv[1]) { 
            std::cout << "\n\xAD" << "Archivo \"" << argv[1] << "\" no encontrado! \n\nAseg\xA3rate de que existe y de que est\xA0 en la misma carpeta que este programa. \n"; // ...se emite el error con ese. 
        }
        SetConsoleTextAttribute(console, 7); // Vuelve a letras blancas. 
        std::cout <<("\nPresiona cualquier tecla para salir. \n");
        system("pause>nul");
        std::cout <<("\n");

        return EXIT_FAILURE; // Cierra el programa con errores. 
		
	} else {
		char ch;
        std::cout << "\xA8" << "Durante cu\xA0ntos milisegundos quieres que se toquen todas las notas? ";
        std::cin >> duration;
		while (1) {
           
			notes >> ch;
            //cout << (ch);
			if (notes.eof()) {
                //cout <<("\nArchivo terminado");
                break;
            }

			makesound(ch, duration);
		}

	}
	notes.close(); 

    std::cout <<("\nPresiona cualquier tecla para salir. ");
    system("pause>nul");
    
	return EXIT_SUCCESS;
}