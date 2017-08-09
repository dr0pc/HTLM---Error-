/*
Autor:	Luis Carreto & Luis Fajardo
fecha:	22/7/2017
Descripcion:	Programa para leer archivos de texto caractr por caracter
Version:	1.1   Compilado en (g++ version 5.4.0 20160609 (Debian 5.4.0-6))
*/

#include<iostream>
#include<fstream>

using namespace std;
int n=0;
bool head_start =true, head_end =true, html_s =true, html_e =true, my_h =true, body_s =true, title_s=true, body_e=true, title_e=true;

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

	cout<<"Ingresa el nombre del documento [por ejemplo index]: ";
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

		fichero.get(letra);

	if (letra == '<')
	{	fichero.get(letra);

		switch(letra)
		{
		case 'h':
			fichero.get(letra);
			switch(letra)
			{

				case 'e':
					fichero.get(letra);
					if (letra =='a')
					{

						fichero.get(letra);
						if (letra == 'd')
						{
							fichero.get(letra);
							if(letra == '>')
							head_start=false;
							cout<<"heee inicio  el head"<<endl;
						}
					}
					break;

				case 't':


                                        fichero.get(letra);
					if(letra =='m')
					{
						fichero.get(letra);
						if(letra =='l')
						{
                                                       fichero.get(letra);
                                                       if(letra == '>')
                                                       cout<<"heee inicia  el html"<<endl;
							html_s=false;
						}
					}

					break;

			}
		break;



		case 'b':
			fichero.get(letra);
			if (letra =='o')
			{
				fichero.get(letra);
				if(letra =='d')
				{
					fichero.get(letra);
					if(letra =='y')
					{
						fichero.get(letra);
	                                        if(letra =='>')
						cout<<"hee se inicio el body"<<endl;
						body_s=false;
					}
				}
			}
		break;


		case 't':
                        fichero.get(letra);
                        if(letra =='i')
			{
	                        fichero.get(letra);
	                        if(letra =='t')
	                        {
					fichero.get(letra);
                                        if(letra =='l')
					{
		                                fichero.get(letra);
		                                if(letra =='e')
        	                                {
                	                                fichero.get(letra);
                        	                        if(letra =='>')
                                	               { cout<<"hee se inicio el title"<<endl;
                                        	        title_s=false;}
  	                                     	 }
					}

				}
			}

		break;
/*
		case 'H':
			my_h=false;
			cout<<"verifica que el head o el html no esten escritos en MAYUSCULAS"<<endl;
		break;*/

		}

	}


/*********************************************************************************************************/
	}

	fichero.close();
	}

        else {cout <<"error";}


return 0;
}
