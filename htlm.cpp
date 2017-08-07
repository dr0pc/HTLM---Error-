/*
Autor:	Luis Carreto y Luis Fajardo
fecha:	22/7/2017
Descripcion:	Programa para leer archivos de texto caractr por caracter
Version:	1.0   Compilado en (gcc version 5.4.0 20160609 (Debian 5.4.0-6))
*/

#include<iostream>
#include<fstream>

using namespace std;
int n=0;

int main()
{


cout<<"██╗  ██╗████████╗██╗     ███╗   ███╗              ███████╗██████╗ ██████╗  ██████╗ ██████╗ ██╗██╗"<<endl;
cout<<"██║  ██║╚══██╔══╝██║     ████╗ ████║              ██╔════╝██╔══██╗██╔══██╗██╔═══██╗██╔══██╗██║██║"<<endl;
cout<<"███████║   ██║   ██║     ██╔████╔██║    █████╗    █████╗  ██████╔╝██████╔╝██║   ██║██████╔╝██║██║"<<endl;
cout<<"██╔══██║   ██║   ██║     ██║╚██╔╝██║    ╚════╝    ██╔══╝  ██╔══██╗██╔══██╗██║   ██║██╔══██╗╚═╝╚═╝"<<endl;
cout<<"██║  ██║   ██║   ███████╗██║ ╚═╝ ██║              ███████╗██║  ██║██║  ██║╚██████╔╝██║  ██║██╗██╗"<<endl;
cout<<"╚═╝  ╚═╝   ╚═╝   ╚══════╝╚═╝     ╚═╝              ╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝ ╚═════╝ ╚═╝  ╚═╝╚═╝╚═╝"<<endl;
cout<<"This is a program which analyzes the html file to check if there are syntax errors, made as a fucking project for the UMG."<<endl;
cout<<""<<endl;

	string nfichero;
	char letra;

	cout<<"Ingresa el nombre del documento [por ejemplo main]: ";
	cin>>nfichero;

		if (nfichero!="")
			{nfichero+=".html";	}


        ifstream fichero;			//declaramos una variable de tipo fichero


        fichero.open(nfichero.c_str());


/*		TRABAJANDO EN LA PARTE DEL ERROR SI EL ARCHIVO NO SE ABRE
	fichero.open(nfichero.c_str());

	        if (fichero.fail())
        {cerr <<"xxxx";
	exit(1);
}

*/

	if (!fichero.fail()){

/******************************EN ESTE PUNTO SE OBTIENE EL VALOR HACIA EL CARACTER************************/

		fichero.get(letra);
		while (!fichero.eof()){
//			cout << letra;

	if (letra == '<')
	cout<<"se iniciala etiqueta"<<endl;

	if (letra =='>')
	cout<<"se finaliza la etiqueta"<<endl;

	fichero.get(letra);
/*********************************************************************************************************/
	}

	fichero.close();
	}

        else {cout <<"error";}


return 0;
}
